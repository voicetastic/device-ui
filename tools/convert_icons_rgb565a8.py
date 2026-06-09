#!/usr/bin/env python3
"""Re-encode EEZ-exported LVGL image .c files from ARGB8888 to the more
compact format upstream uses (RGB565A8, or A8 for monochrome icons).

Only the pixel data array and three header fields (cf / stride / data_size)
are rewritten; all boilerplate, guards and symbol names are preserved so the
diff is minimal and the symbols stay identical.
"""

import re
import sys

CF = {
    "ARGB8888": "LV_COLOR_FORMAT_ARGB8888",
    "RGB565A8": "LV_COLOR_FORMAT_RGB565A8",
    "A8": "LV_COLOR_FORMAT_A8",
}


def parse(path):
    text = open(path, "r").read()

    def field(name):
        m = re.search(r"\.header\.%s\s*=\s*([^,\n]+)" % name, text)
        return m.group(1).strip() if m else None

    w = int(field("w"))
    h = int(field("h"))
    cf = field("cf")
    # data array bytes
    m = re.search(r"_map\[\]\s*=\s*\{(.*?)\};", text, re.S)
    body = m.group(1)
    data = bytes(int(x, 16) for x in re.findall(r"0x([0-9a-fA-F]{2})", body))
    return text, w, h, cf, data


def argb8888_to_rgba(data, w, h):
    """LVGL ARGB8888 is stored little-endian as B,G,R,A per pixel."""
    px = []
    for i in range(w * h):
        b, g, r, a = data[4 * i], data[4 * i + 1], data[4 * i + 2], data[4 * i + 3]
        px.append((r, g, b, a))
    return px


def encode_rgb565a8(px, w, h):
    """RGB565 plane (2 bytes LE / px) followed by the A8 plane (1 byte / px)."""
    rgb = bytearray()
    alpha = bytearray()
    for r, g, b, a in px:
        v = ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3)
        rgb += bytes((v & 0xFF, (v >> 8) & 0xFF))
        alpha.append(a)
    return bytes(rgb) + bytes(alpha)


def encode_a8(px, w, h):
    return bytes(a for (_, _, _, a) in px)


def render_c(text, w, h, target, data):
    """Swap cf, stride, data_size implicit (sizeof), and the byte array."""
    if target == "RGB565A8":
        stride = w * 2
    elif target == "A8":
        stride = w
    else:
        raise ValueError(target)
    text = re.sub(
        r"(\.header\.cf\s*=\s*)LV_COLOR_FORMAT_\w+", r"\g<1>" + CF[target], text
    )
    text = re.sub(r"(\.header\.stride\s*=\s*)\d+", r"\g<1>%d" % stride, text)
    # rebuild the byte array body, one stride per line (matches LVGLImage.py)
    lines = []
    for i in range(0, len(data), stride):
        chunk = data[i : i + stride]
        lines.append("    " + "".join("0x%02x," % byte for byte in chunk))
    body = "\n" + "\n".join(lines) + "\n"
    text = re.sub(
        r"(_map\[\]\s*=\s*\{).*?(\};)",
        lambda m: m.group(1) + body + m.group(2),
        text,
        flags=re.S,
    )
    return text


def convert(path, target):
    text, w, h, cf, data = parse(path)
    if cf != CF["ARGB8888"]:
        return False, "source not ARGB8888 (%s)" % cf
    if len(data) != w * h * 4:
        return False, "data size %d != w*h*4 (%d)" % (len(data), w * h * 4)
    px = argb8888_to_rgba(data, w, h)
    out = encode_rgb565a8(px, w, h) if target == "RGB565A8" else encode_a8(px, w, h)
    new_text = render_c(text, w, h, target, out)
    open(path, "w").write(new_text)
    return True, "%s -> %s (%d -> %d bytes)" % (
        cf.replace("LV_COLOR_FORMAT_", ""),
        target,
        len(data),
        len(out),
    )


if __name__ == "__main__":
    target = sys.argv[1]
    for p in sys.argv[2:]:
        ok, msg = convert(p, target)
        print(("OK  " if ok else "SKIP") + " " + p + "  " + msg)
