#pragma once

#include "lvgl.h"
class Themes
{
  public:
    enum Theme { eDark, eLight, eRed };

    static void initStyles(void);
    static enum Theme get(void);
    static void set(enum Theme th);
    // Re-applies M3 shape/colour to per-object local styles that EEZ-generated
    // screens.c hardcodes (notably home_container shadow and home_button
    // pressed state). Safe to call before or after ui_init(); guards on null.
    static void applyLocalOverrides(void);
    static void recolorButton(lv_obj_t *obj, bool enabled, lv_opa_t opa = 255);
    static void recolorImage(lv_obj_t *obj, bool enabled);
    static void recolorText(lv_obj_t *obj, bool enabled);
    // Theme a popup/modal surface (bg/border/text) so it matches the rest of the
    // UI instead of rendering on LVGL's default theme. Mirrors the
    // surfaceContainerHigh popup look used elsewhere.
    static void recolorContainer(lv_obj_t *obj);
    static void recolorTopLabel(lv_obj_t *obj, bool alert);
    static void recolorTableRow(lv_draw_fill_dsc_t *fill_draw_dsc, bool odd);
    // Apply M3 selected/unselected look to a top-nav button. Selected uses the
    // primary-container surface with on-primary-container icon; unselected
    // resets to surface-container-high with on-surface icon.
    static void setMainButtonActive(lv_obj_t *obj, bool active);

  private:
    Themes(void) = default;
};