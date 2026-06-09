#if defined(VIEW_320x240) || defined(VIEW_240x320)

#include "graphics/view/TFT/Themes.h"
#include "stdint.h"

static enum Themes::Theme theme = Themes::eDark;

Themes::Theme Themes::get(void)
{
    return theme;
}

enum ThemeColor {
    eMainScreenStyle,
    eTopPanelBg,
    eTopPanelText,
    eTopImageBg,
    eTopImageRecolor,
    eTopImageRecolorOpa,
    ePositiveImageRecolor,
    ePanelBg,
    ePanelPressedBg,
    ePanelText,
    ePanelBorder,
    eNodePanelBg,
    eNodePanelBorder,
    eNodePanelText,
    eNodeButtonBg,
    eNodeButtonBgOpa,
    eButtonPanelBg,
    eMainButtonBg,
    eMainButtonText,
    eMainButtonBorder,
    eMainButtonShadow,
    eMainButtonImageRecolor,
    eMainButtonImageRecolorOpa,
    eHomeContainerBg,
    eHomeContainerBorder,
    eHomeContainerShadow,
    eHomeContainerText,
    eHomeButtonBg,
    eHomeButtonText,
    eHomeButtonBorder,
    eHomeButtonImageRecolor,
    eHomeButtonImageRecolorOpa,
    eChannelButtonBg,
    eChannelButtonBorder,
    eChannelButtonText,
    eSettingsPanelBg,
    eSettingsPanelText,
    eSettingsPanelBorder,
    eSettingsPanelShadow,
    eSettingsPanelBgOpa,
    eSettingsButtonBg,
    eSettingsButtonText,
    eSettingsButtonBorder,
    eSettingsButtonImageRecolor,
    eSettingsButtonImageRecolorOpa,
    eSettingsLabelBg,
    eSettingsLabelBorder,
    eTabViewBg,
    eTabViewText,
    eTabButtonDefaultBg,
    eTabButtonActiveBg,
    eTabButtonPressedBg,
    eTabButtonDefaultText,
    eTabButtonActiveText,
    eTabButtonPressedText,
    eTabButtonDefaultBorder,
    eChatMessageBg,
    eChatMessageBgOpa,
    eChatMessageText,
    eChatMessageBorder,
    eNewMessageBg,
    eNewMessageBgOpa,
    eNewMessageText,
    eNewMessageBorder,
    eAlertPanelBg,
    eBtnMatrixBorderMain,
    eBtnMatrixBorderItems,
    eBtnMatrixBgItems,
    eBtnMatrixTextItems,
    eBatteryPercentageText,
    eColorTextLabel,
    eSpinnerMainArc,
    eSpinnerIndicatorArc,
    eTableHeadingText,
    eTableHeadingBg,
    eTableItemText,
    eTableItemBg,
    eTableItemDarkBg,
    eTableBorder,
    eTableCellBorder
};

// Material 3 Expressive token palette — unified with Voicetastic
// (MaterialKolor seed 0xFFFFBDA8, peach/salmon, HighContrast spec for BOTH
// modes). Tonal containers therefore invert (light-on-dark / dark-on-light)
// for maximum legibility on small TFTs; sourced from
// AndroidStudioProjects/voicetastic/app/.../ui/theme/Color.kt.
// Token names in the trailing comment reference the M3 role.
uint32_t themeColor[][2] = {
    // dark HC,    light HC
    {0xff100e0d, 0xfffff8f6}, // eMainScreenStyle              -> surface
    {0xff1c1918, 0xfff5ecea}, // eTopPanelBg                   -> surfaceContainer
    {0xffffffff, 0xff000000}, // eTopPanelText                 -> onSurface
    {0xff1c1918, 0xfff5ecea}, // eTopImageBg                   -> surfaceContainer
    {0xffeee3e0, 0xff282321}, // eTopImageRecolor              -> onSurfaceVariant
    {255, 255},               // eTopImageRecolorOpa
    {0xffffdfd5, 0xff3e190c}, // ePositiveImageRecolor         -> primary
    {0xff100e0d, 0xfffff8f6}, // ePanelBg                      -> surface
    {0xff231f1d, 0xfff0e6e4}, // ePanelPressedBg               -> surfaceContainerHigh
    {0xffffffff, 0xff000000}, // ePanelText                    -> onSurface
    {0xffaba29f, 0xff57514f}, // ePanelBorder                  -> outlineVariant
    {0xff161312, 0xfffaf2f0}, // eNodePanelBg                  -> surfaceContainerLow
    {0xffaba29f, 0xff57514f}, // eNodePanelBorder              -> outlineVariant
    {0xffffffff, 0xff000000}, // eNodePanelText                -> onSurface
    {0xffaca19e, 0xff59504e}, // eNodeButtonBg                 -> secondaryContainer
    {0, 0},                   // eNodeButtonBgOpa (transparent — icon sits alone, no chip behind it)
    {0xff161312, 0xfffaf2f0}, // eButtonPanelBg                -> surfaceContainerLow
    {0xff231f1d, 0xfff0e6e4}, // eMainButtonBg                 -> surfaceContainerHigh (dark default; light peach when active)
    {0xffffffff, 0xff000000}, // eMainButtonText               -> onSurface
    {0xff231f1d, 0xfff0e6e4}, // eMainButtonBorder             -> surfaceContainerHigh
    {0xff000000, 0xff000000}, // eMainButtonShadow             -> shadow
    {0xffffffff, 0xff000000}, // eMainButtonImageRecolor       -> onSurface (uniform dark/light per theme)
    {255, 255},               // eMainButtonImageRecolorOpa
    {0xff231f1d, 0xfff0e6e4}, // eHomeContainerBg              -> surfaceContainerHigh
    {0xffaba29f, 0xff57514f}, // eHomeContainerBorder          -> outlineVariant
    {0xff000000, 0xff000000}, // eHomeContainerShadow          -> shadow
    {0xffffffff, 0xff000000}, // eHomeContainerText            -> onSurface
    {0xff231f1d, 0xfff0e6e4}, // eHomeButtonBg                 -> surfaceContainerHigh (dark default; primaryContainer light when pressed/active)
    {0xffffffff, 0xff000000}, // eHomeButtonText               -> onSurface
    {0xff231f1d, 0xfff0e6e4}, // eHomeButtonBorder             -> surfaceContainerHigh (flat)
    {0xffffffff, 0xff000000}, // eHomeButtonImageRecolor       -> onSurface (uniform — all icons same colour)
    {255, 255},               // eHomeButtonImageRecolorOpa
    {0xffd29582, 0xff754636}, // eChannelButtonBg              -> primaryContainer
    {0xffaba29f, 0xff57514f}, // eChannelButtonBorder          -> outlineVariant
    {0xff000000, 0xffffffff}, // eChannelButtonText            -> onPrimaryContainer
    {0xff161312, 0xfffaf2f0}, // eSettingsPanelBg              -> surfaceContainerLow
    {0xffffffff, 0xff000000}, // eSettingsPanelText            -> onSurface
    {0xffaba29f, 0xff57514f}, // eSettingsPanelBorder          -> outlineVariant
    {0xff000000, 0xff000000}, // eSettingsPanelShadow          -> shadow
    {255, 255},               // eSettingsPanelBgOpa
    {0xffaca19e, 0xff59504e}, // eSettingsButtonBg             -> secondaryContainer
    {0xff000000, 0xffffffff}, // eSettingsButtonText           -> onSecondaryContainer
    {0xffaca19e, 0xff59504e}, // eSettingsButtonBorder         -> secondaryContainer
    {0xff000000, 0xffffffff}, // eSettingsButtonImageRecolor   -> onSecondaryContainer
    {255, 255},               // eSettingsButtonImageRecolorOpa
    {0xff1c1918, 0xfff5ecea}, // eSettingsLabelBg              -> surfaceContainer
    {0xffaba29f, 0xff57514f}, // eSettingsLabelBorder          -> outlineVariant
    {0xff100e0d, 0xfffff8f6}, // eTabViewBg                    -> surface
    {0xffffffff, 0xff000000}, // eTabViewText                  -> onSurface
    {0xff100e0d, 0xfffff8f6}, // eTabButtonDefaultBg           -> surface
    {0xff231f1d, 0xfff0e6e4}, // eTabButtonActiveBg            -> surfaceContainerHigh
    {0xffd29582, 0xff754636}, // eTabButtonPressedBg           -> primaryContainer
    {0xffeee3e0, 0xff282321}, // eTabButtonDefaultText         -> onSurfaceVariant
    {0xffffdfd5, 0xff3e190c}, // eTabButtonActiveText          -> primary
    {0xff000000, 0xffffffff}, // eTabButtonPressedText         -> onPrimaryContainer
    {0xffaba29f, 0xff57514f}, // eTabButtonDefaultBorder       -> outlineVariant
    {0xffd29582, 0xff754636}, // eChatMessageBg                -> primaryContainer
    {255, 255},               // eChatMessageBgOpa
    {0xff000000, 0xffffffff}, // eChatMessageText              -> onPrimaryContainer
    {0xffd29582, 0xff754636}, // eChatMessageBorder            -> primaryContainer (flat)
    {0xff231f1d, 0xfff0e6e4}, // eNewMessageBg                 -> surfaceContainerHigh
    {255, 255},               // eNewMessageBgOpa
    {0xffffffff, 0xff000000}, // eNewMessageText               -> onSurface
    {0xffaba29f, 0xff57514f}, // eNewMessageBorder             -> outlineVariant
    {0xff2a2523, 0xffebe0dd}, // eAlertPanelBg                 -> surfaceContainerHighest
    {0xff1c1918, 0xfff5ecea}, // eBtnMatrixBorderMain          -> surfaceContainer
    {0xffaba29f, 0xff57514f}, // eBtnMatrixBorderItems         -> outlineVariant
    {0xffaca19e, 0xff59504e}, // eBtnMatrixBgItems             -> secondaryContainer
    {0xff000000, 0xffffffff}, // eBtnMatrixTextItems           -> onSecondaryContainer
    {0xffffffff, 0xff000000}, // eBatteryPercentageText        -> onSurface
    {0xffffdfd5, 0xff3e190c}, // eColorTextLabel               -> primary
    {0xff231f1d, 0xfff0e6e4}, // eSpinnerMainArc               -> surfaceContainerHigh
    {0xffffdfd5, 0xff3e190c}, // eSpinnerIndicatorArc          -> primary
    {0xffffffff, 0xff000000}, // eTableHeadingText             -> onSurface
    {0xff1c1918, 0xfff5ecea}, // eTableHeadingBg               -> surfaceContainer
    {0xffffffff, 0xff000000}, // eTableItemText                -> onSurface
    {0xff161312, 0xfffaf2f0}, // eTableItemBg                  -> surfaceContainerLow
    {0xff100e0d, 0xfffff8f6}, // eTableItemDarkBg              -> surface
    {0xffaba29f, 0xff57514f}, // eTableBorder                  -> outlineVariant
    {0xffaba29f, 0xff57514f}  // eTableCellBorder              -> outlineVariant
};

#include "fonts.h"
#include "images.h"
#include "screens.h"
#include "styles.h"

#define THEME(COLOR) (themeColor[COLOR][theme])

// the following styles are copied from eez-studio generated styles and parametrized
extern "C" {
void apply_style_top_panel_style(void)
{
    lv_style_t *style = get_style_top_panel_style_MAIN_DEFAULT();
    lv_style_set_bg_color(style, lv_color_hex(THEME(eTopPanelBg)));
    lv_style_set_text_color(style, lv_color_hex(THEME(eTopPanelText)));
    // M3 small top app bar: flat surface, no border, no shadow.
    lv_style_set_border_width(style, 0);
    lv_style_set_shadow_width(style, 0);
    lv_style_set_radius(style, 0);
    // lv_style_set_text_font(style, &ui_font_montserrat_16);
};
void apply_style_panel_style_MAIN_DEFAULT(void)
{
    lv_style_t *style = get_style_panel_style_MAIN_DEFAULT();
    lv_style_set_bg_color(style, lv_color_hex(THEME(ePanelBg)));
    lv_style_set_text_color(style, lv_color_hex(THEME(ePanelText)));
    lv_style_set_border_color(style, lv_color_hex(THEME(ePanelBorder)));
    // Panel is the chrome around home_container; let the inner card carry the surface.
    lv_style_set_border_width(style, 0);
    lv_style_set_bg_opa(style, LV_OPA_TRANSP);
    // lv_style_set_shadow_color(style, lv_color_hex(0xffe0e0e0));
};
void apply_style_panel_style_MAIN_PRESSED(void)
{
    lv_style_t *style = get_style_panel_style_MAIN_PRESSED();
    lv_style_set_bg_color(style, lv_color_hex(THEME(ePanelPressedBg)));
};
void apply_style_home_container_style(void)
{
    lv_style_t *style = get_style_home_container_style_MAIN_DEFAULT();
    lv_style_set_border_color(style, lv_color_hex(THEME(eHomeContainerBorder)));
    // M3 outlined card: 1px outlineVariant, large 20px radius.
    lv_style_set_border_width(style, 1);
    lv_style_set_border_side(style, LV_BORDER_SIDE_FULL);
    lv_style_set_bg_color(style, lv_color_hex(THEME(eHomeContainerBg)));
    lv_style_set_shadow_width(style, 0);
    lv_style_set_text_font(style, &ui_font_montserrat_16);
    lv_style_set_radius(style, 20);
    lv_style_set_text_color(style, lv_color_hex(THEME(eHomeContainerText)));
};
void apply_style_settings_panel_style(void)
{
    lv_style_t *style = get_style_settings_panel_style_MAIN_DEFAULT();
    lv_style_set_bg_color(style, lv_color_hex(THEME(eSettingsPanelBg)));
    lv_style_set_text_color(style, lv_color_hex(THEME(eSettingsPanelText)));
    lv_style_set_shadow_color(style, lv_color_hex(THEME(eSettingsPanelShadow)));
    lv_style_set_border_color(style, lv_color_hex(THEME(eSettingsPanelBorder)));
    lv_style_set_bg_opa(style, THEME(eSettingsPanelBgOpa));
    // M3 surface-low card: 16px radius, hairline outline, no shadow.
    lv_style_set_radius(style, 16);
    lv_style_set_border_width(style, 1);
    lv_style_set_shadow_width(style, 0);
};
void apply_style_node_panel_style(void)
{
    lv_style_t *style = get_style_node_panel_style_MAIN_DEFAULT();
    lv_style_set_bg_color(style, lv_color_hex(THEME(eNodePanelBg)));
    lv_style_set_border_color(style, lv_color_hex(THEME(eNodePanelBorder)));
    lv_style_set_text_font(style, &ui_font_montserrat_12);
    lv_style_set_text_color(style, lv_color_hex(THEME(eNodePanelText)));
    // M3 list-card row: 16px radius, hairline outline.
    lv_style_set_radius(style, 16);
    lv_style_set_border_width(style, 1);
    lv_style_set_shadow_width(style, 0);
};
void apply_style_node_button_style(void)
{
    lv_style_t *style = get_style_node_button_style_MAIN_DEFAULT();
    lv_style_set_bg_color(style, lv_color_hex(THEME(eNodeButtonBg)));
    lv_style_set_bg_opa(style, THEME(eNodeButtonBgOpa));
    // M3 list-row affordance: full pill so it tracks any aspect ratio.
    lv_style_set_radius(style, LV_RADIUS_CIRCLE);
    lv_style_set_border_width(style, 0);
};
void apply_style_button_panel_style(void)
{
    lv_style_t *style = get_style_button_panel_style_MAIN_DEFAULT();
    lv_style_set_bg_color(style, lv_color_hex(THEME(eButtonPanelBg)));
    // M3 surface-low strip used as a bottom action bar.
    lv_style_set_radius(style, 16);
    lv_style_set_border_width(style, 0);
};
void apply_style_home_button_style(void)
{
    lv_style_t *style = get_style_home_button_style_MAIN_DEFAULT();
    lv_style_set_bg_color(style, lv_color_hex(THEME(eHomeButtonBg)));
    lv_style_set_bg_opa(style, LV_OPA_COVER);
    lv_style_set_bg_image_recolor_opa(style, THEME(eHomeButtonImageRecolorOpa));
    lv_style_set_bg_image_recolor(style, lv_color_hex(THEME(eHomeButtonImageRecolor)));
    lv_style_set_border_color(style, lv_color_hex(THEME(eHomeButtonBorder)));
    lv_style_set_text_color(style, lv_color_hex(THEME(eHomeButtonText)));
    // M3 tonal icon button: full-radius circle, no border, no shadow.
    lv_style_set_radius(style, LV_RADIUS_CIRCLE);
    lv_style_set_border_width(style, 0);
    lv_style_set_shadow_width(style, 0);
};
void apply_style_settings_button_style(void)
{
    lv_style_t *style = get_style_settings_button_style_MAIN_DEFAULT();
    lv_style_set_bg_color(style, lv_color_hex(THEME(eSettingsButtonBg)));
    lv_style_set_bg_image_recolor_opa(style, THEME(eSettingsButtonImageRecolorOpa));
    lv_style_set_bg_image_recolor(style, lv_color_hex(THEME(eSettingsButtonImageRecolor)));
    lv_style_set_border_color(style, lv_color_hex(THEME(eSettingsButtonBorder)));
    lv_style_set_text_color(style, lv_color_hex(THEME(eSettingsButtonText)));
    // M3 tonal button: pill, flat.
    lv_style_set_radius(style, LV_RADIUS_CIRCLE);
    lv_style_set_border_width(style, 0);
    lv_style_set_shadow_width(style, 0);
};
void apply_style_main_button_style(void)
{
    lv_style_t *style = get_style_main_button_style_MAIN_DEFAULT();
    lv_style_set_bg_image_recolor_opa(style, THEME(eMainButtonImageRecolorOpa));
    lv_style_set_bg_image_recolor(style, lv_color_hex(THEME(eMainButtonImageRecolor)));
    lv_style_set_border_color(style, lv_color_hex(THEME(eMainButtonBorder)));
    lv_style_set_bg_color(style, lv_color_hex(THEME(eMainButtonBg)));
    lv_style_set_text_color(style, lv_color_hex(THEME(eMainButtonText)));
    // M3 nav pill — flat: no border, no shadow.
    lv_style_set_radius(style, LV_RADIUS_CIRCLE);
    lv_style_set_border_width(style, 0);
    lv_style_set_shadow_width(style, 0);
};
void apply_style_new_message_style(void)
{
    lv_style_t *style = get_style_new_message_style_MAIN_DEFAULT();
    lv_style_set_border_color(style, lv_color_hex(THEME(eNewMessageBorder)));
    lv_style_set_bg_color(style, lv_color_hex(THEME(eNewMessageBg)));
    lv_style_set_text_color(style, lv_color_hex(THEME(eNewMessageText)));
    lv_style_set_bg_opa(style, THEME(eNewMessageBgOpa));
    // M3 incoming chat bubble: rounded surface tile, no outline.
    lv_style_set_radius(style, 18);
    lv_style_set_border_width(style, 0);
};
void apply_style_chat_message_style(void)
{
    lv_style_t *style = get_style_chat_message_style_MAIN_DEFAULT();
    lv_style_set_border_color(style, lv_color_hex(THEME(eChatMessageBorder)));
    lv_style_set_bg_color(style, lv_color_hex(THEME(eChatMessageBg)));
    lv_style_set_text_color(style, lv_color_hex(THEME(eChatMessageText)));
    lv_style_set_bg_opa(style, THEME(eChatMessageBgOpa));
    // M3 sent chat bubble: primary-container fill, large radius, no outline.
    lv_style_set_radius(style, 18);
    lv_style_set_border_width(style, 0);
};
void apply_style_tab_view_style(void)
{
    lv_style_t *style = get_style_tab_view_style_MAIN_DEFAULT();
    lv_style_set_bg_color(style, lv_color_hex(THEME(eTabViewBg)));
    lv_style_set_text_color(style, lv_color_hex(THEME(eTabViewText)));
    // M3 tabs sit on surface, no chrome of their own.
    lv_style_set_border_width(style, 0);
    lv_style_set_radius(style, 0);
};
void apply_style_drop_down_style(void){};
void apply_style_bw_label_style(void)
{
    lv_style_t *style = get_style_bw_label_style_MAIN_DEFAULT();
    lv_style_set_text_color(style, lv_color_hex(THEME(eBatteryPercentageText)));
};
void apply_style_color_label_style(void)
{
    lv_style_t *style = get_style_color_label_style_MAIN_DEFAULT();
    lv_style_set_text_color(style, lv_color_hex(THEME(eColorTextLabel)));
};
void apply_style_top_image_style(void)
{
    lv_style_t *style = get_style_top_image_style_MAIN_DEFAULT();
    lv_style_set_bg_image_recolor(style, lv_color_hex(THEME(eTopImageRecolor)));
    lv_style_set_bg_image_recolor_opa(style, THEME(eTopImageRecolorOpa));
    lv_style_set_image_recolor(style, lv_color_hex(THEME(eTopImageRecolor)));
    lv_style_set_image_recolor_opa(style, THEME(eTopImageRecolorOpa));
    lv_style_set_bg_color(style, lv_color_hex(THEME(eTopImageBg)));
};
void apply_style_alert_panel_style(void)
{
    lv_style_t *style = get_style_alert_panel_style_MAIN_DEFAULT();
    lv_style_set_bg_color(style, lv_color_hex(THEME(eAlertPanelBg)));
    lv_style_set_text_color(style, lv_color_hex(THEME(ePanelText)));
    // M3 dialog/basic dialog: extra-large radius on top-tier surface (flat).
    lv_style_set_radius(style, 24);
    lv_style_set_border_width(style, 0);
    lv_style_set_shadow_width(style, 0);
};
void apply_style_main_screen_style(void)
{
    lv_style_t *style = get_style_main_screen_style_MAIN_DEFAULT();
    lv_style_set_bg_color(style, lv_color_hex(THEME(eMainScreenStyle)));
};
void apply_style_channel_button_style(void)
{
    lv_style_t *style = get_style_channel_button_style_MAIN_DEFAULT();
    lv_style_set_bg_color(style, lv_color_hex(THEME(eChannelButtonBg)));
    lv_style_set_border_color(style, lv_color_hex(THEME(eChannelButtonBorder)));
    lv_style_set_text_color(style, lv_color_hex(THEME(eChannelButtonText)));
    // M3 input chip: pill, no border.
    lv_style_set_radius(style, LV_RADIUS_CIRCLE);
    lv_style_set_border_width(style, 0);
};
void apply_style_button_matrix_style_ITEMS_DEFAULT(void)
{
    lv_style_t *style = get_style_button_matrix_style_ITEMS_DEFAULT();
    lv_style_set_border_color(style, lv_color_hex(THEME(eBtnMatrixBorderItems)));
    lv_style_set_bg_color(style, lv_color_hex(THEME(eBtnMatrixBgItems)));
    lv_style_set_text_color(style, lv_color_hex(THEME(eBtnMatrixTextItems)));
    // M3 segmented-button cell: pill, hairline divider.
    lv_style_set_radius(style, LV_RADIUS_CIRCLE);
    lv_style_set_border_width(style, 1);
};
void apply_style_button_matrix_style_MAIN_DEFAULT(void)
{
    lv_style_t *style = get_style_button_matrix_style_MAIN_DEFAULT();
    lv_style_set_bg_color(style, lv_color_hex(THEME(eBtnMatrixBorderMain)));
    // M3 segmented-button container: matched pill, blends into surface.
    lv_style_set_radius(style, LV_RADIUS_CIRCLE);
    lv_style_set_border_width(style, 0);
};
void apply_style_spinner_style_MAIN_DEFAULT(void)
{
    lv_style_t *style = get_style_spinner_style_MAIN_DEFAULT();
    lv_style_set_arc_color(style, lv_color_hex(THEME(eSpinnerMainArc)));
};
void apply_style_spinner_style_INDICATOR_DEFAULT(void)
{
    lv_style_t *style = get_style_spinner_style_INDICATOR_DEFAULT();
    lv_style_set_arc_color(style, lv_color_hex(THEME(eSpinnerIndicatorArc)));
};
void apply_style_settings_label_style(void)
{
    lv_style_t *style = get_style_settings_label_style_MAIN_DEFAULT();
    lv_style_set_border_color(style, lv_color_hex(THEME(eSettingsLabelBorder)));
    // lv_style_set_bg_opa(style, 255);
    lv_style_set_bg_color(style, lv_color_hex(THEME(eSettingsLabelBg)));
    // M3 outlined text-field-style label: small radius, hairline outline.
    lv_style_set_radius(style, 8);
    lv_style_set_border_width(style, 1);
};
void apply_style_positive_image_style(void)
{
    lv_style_t *style = get_style_positive_image_style_MAIN_DEFAULT();
    lv_style_set_image_recolor(style, lv_color_hex(THEME(ePositiveImageRecolor)));
};
void apply_style_statistics_table_style_MAIN_DEFAULT(void)
{
    lv_style_t *style = get_style_statistics_table_style_MAIN_DEFAULT();
    lv_style_set_border_color(style, lv_color_hex(THEME(eTableBorder)));
    // M3 data-table container: medium radius, hairline outline.
    lv_style_set_radius(style, 12);
    lv_style_set_border_width(style, 1);
};
void apply_style_statistics_table_style_ITEMS_DEFAULT(void)
{
    lv_style_t *style = get_style_statistics_table_style_ITEMS_DEFAULT();
    lv_style_set_bg_color(style, lv_color_hex(THEME(eTableItemBg)));
    lv_style_set_text_color(style, lv_color_hex(THEME(eTableItemText)));
    lv_style_set_border_color(style, lv_color_hex(THEME(eTableCellBorder)));
};
}

void Themes::set(enum Theme th)
{
    theme = th;
    apply_style_top_panel_style();
    apply_style_panel_style_MAIN_DEFAULT();
    apply_style_panel_style_MAIN_PRESSED();
    apply_style_home_container_style();
    apply_style_settings_panel_style();
    apply_style_node_panel_style();
    apply_style_node_button_style();
    apply_style_button_panel_style();
    apply_style_home_button_style();
    apply_style_settings_button_style();
    apply_style_main_button_style();
    apply_style_new_message_style();
    apply_style_chat_message_style();
    apply_style_tab_view_style();
    apply_style_drop_down_style();
    apply_style_bw_label_style();
    apply_style_color_label_style();
    apply_style_top_image_style();
    apply_style_alert_panel_style();
    apply_style_main_screen_style();
    apply_style_channel_button_style();
    apply_style_button_matrix_style_ITEMS_DEFAULT();
    apply_style_button_matrix_style_MAIN_DEFAULT();
    apply_style_spinner_style_MAIN_DEFAULT();
    apply_style_spinner_style_INDICATOR_DEFAULT();
    apply_style_settings_label_style();
    apply_style_positive_image_style();
    apply_style_statistics_table_style_MAIN_DEFAULT();
    apply_style_statistics_table_style_ITEMS_DEFAULT();
    // EEZ-generated screens.c sets per-object local styles that win over the
    // named styles above (notably home_container shadow + home_button PRESSED
    // colours). Re-apply them with current theme values.
    applyLocalOverrides();
}

void Themes::applyLocalOverrides(void)
{
    // Cancel every EEZ-hardcoded local shadow (screens.c sets shadow_width 1–3
    // and shadow_spread 1 on a handful of containers/buttons that survive the
    // named-style sweep). Wipe shadow_width + shadow_spread on each.
    lv_obj_t *no_shadow[] = {
        objects.home_container,  objects.msg_popup_panel, objects.msg_restore_panel,
        objects.alert_panel,     objects.reboot_button,   objects.progmode_button,
        objects.shutdown_button,
    };
    for (lv_obj_t *o : no_shadow) {
        if (!o) continue;
        lv_obj_set_style_shadow_width(o, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(o, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_ofs_x(o, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_ofs_y(o, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }

    // M3 tonal icon-button PRESSED state: primary-container fill with
    // on-primary-container icon recolor. screens.c hardcodes 0xff9b9bff/white
    // pressed values which would override our named style.
    lv_color_t pressed_bg = lv_color_hex(THEME(eChannelButtonBg));      // primaryContainer
    lv_color_t pressed_icon = lv_color_hex(THEME(eChannelButtonText));  // onPrimaryContainer
    lv_obj_t *btns[] = {
        objects.home_mail_button,      objects.home_nodes_button,    objects.home_time_button,
        objects.home_lora_button,      objects.home_signal_button,   objects.home_bell_button,
        objects.home_location_button,  objects.home_wlan_button,     objects.home_ethernet_button,
        objects.home_bluetooth_button, objects.home_mqtt_button,     objects.home_sd_card_button,
        objects.home_memory_button,    objects.home_qr_button,
    };
    for (lv_obj_t *b : btns) {
        if (!b) continue;
        lv_obj_set_style_bg_color(b, pressed_bg, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_image_recolor(b, pressed_icon, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_image_recolor_opa(b, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    }

    // Advanced Settings panel and its tab bar — ui_tabview_settings.c sets
    // every colour as a local-style hex, bypassing the named-style layer.
    if (ui_AdvancedSettingsPanel) {
        lv_obj_set_style_bg_color(ui_AdvancedSettingsPanel, lv_color_hex(THEME(eMainScreenStyle)),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if (ui_SettingsTabView) {
        lv_obj_set_style_bg_color(ui_SettingsTabView, lv_color_hex(THEME(eTabViewBg)),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_t *tbtns = lv_tabview_get_tab_bar(ui_SettingsTabView);
        // Default
        lv_obj_set_style_bg_color(tbtns, lv_color_hex(THEME(eTabButtonDefaultBg)),
                                  LV_PART_ITEMS | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_grad_color(tbtns, lv_color_hex(THEME(eTabButtonDefaultBg)),
                                       LV_PART_ITEMS | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(tbtns, lv_color_hex(THEME(eTabButtonDefaultText)),
                                    LV_PART_ITEMS | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(tbtns, lv_color_hex(THEME(eTabButtonDefaultBorder)),
                                      LV_PART_ITEMS | LV_STATE_DEFAULT);
        // Checked (active)
        lv_obj_set_style_bg_color(tbtns, lv_color_hex(THEME(eTabButtonActiveBg)),
                                  LV_PART_ITEMS | LV_STATE_CHECKED);
        lv_obj_set_style_text_color(tbtns, lv_color_hex(THEME(eTabButtonActiveText)),
                                    LV_PART_ITEMS | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(tbtns, lv_color_hex(THEME(eMainButtonBg)),  // primary indicator
                                      LV_PART_ITEMS | LV_STATE_CHECKED);
        // Pressed
        lv_obj_set_style_bg_color(tbtns, lv_color_hex(THEME(eTabButtonPressedBg)),
                                  LV_PART_ITEMS | LV_STATE_PRESSED);
        lv_obj_set_style_text_color(tbtns, lv_color_hex(THEME(eTabButtonPressedText)),
                                    LV_PART_ITEMS | LV_STATE_PRESSED);
    }

    // 24 sub-menu rows in Advanced Settings share an identical hard-coded
    // 0x404040 / 0x4DB270 palette in ui_tabview_settings.c. Re-bind to M3
    // tonal-button tokens and bump the radius to a soft 12px list-card shape.
    lv_color_t row_bg_def = lv_color_hex(THEME(eSettingsButtonBg));     // secondaryContainer
    lv_color_t row_fg_def = lv_color_hex(THEME(eSettingsButtonText));   // onSecondaryContainer
    lv_color_t row_bg_pr  = lv_color_hex(THEME(eChannelButtonBg));      // primaryContainer
    lv_color_t row_fg_pr  = lv_color_hex(THEME(eChannelButtonText));    // onPrimaryContainer
    lv_obj_t *menu_btns[] = {
        ui_GeneralLanguageButton,       ui_GeneralTimezoneButton,    ui_GeneralScreenButton,
        ui_GeneralMapsButton,           ui_GeneralAudioButton,
        ui_RadioBluetoothButton,        ui_RadioDeviceButton,        ui_RadioDisplayButton,
        ui_RadioLoRaButton,             ui_RadioNetworkButton,       ui_RadioPositionButton,
        ui_RadioPowerButton,
        ui_ModuleCannedMsgButton,       ui_ModuleSaFButton,          ui_ModuleTelemetryButton,
        ui_ModuleMQTTButton,            ui_ModuleRangeTestButton,    ui_ModuleAudioButton,
        ui_ModuleSerialButton,          ui_ModuleExtNotificationButton,
        ui_ModuleNeighborInfoButton,    ui_ModuleAmbientLightingButton,
        ui_ModuleDetectionSensorButton, ui_ModuleRemoteHardwareButton,
    };
    for (lv_obj_t *b : menu_btns) {
        if (!b) continue;
        lv_obj_set_style_bg_color(b, row_bg_def, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(b, row_fg_def, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(b, row_bg_pr, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_text_color(b, row_fg_pr, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_radius(b, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    }

    // 19 settings popup panels (theme, region, channel, language, …) all
    // inherit add_style_settings_panel_style then hardcode a blue 0xff216ad8
    // border and radius=12 as local properties — overriding our M3 outlineVariant
    // theme value. Restyle them to a soft M3 dialog: outlineVariant outline,
    // 16px radius, surface-container-high background.
    lv_color_t popup_border  = lv_color_hex(THEME(eSettingsPanelBorder));   // outlineVariant
    lv_color_t popup_bg      = lv_color_hex(THEME(eHomeContainerBg));        // surfaceContainerHigh
    lv_obj_t *popup_panels[] = {
        objects.settings_theme_panel,         objects.settings_alert_buzzer_panel,
        objects.settings_backup_restore_panel, objects.settings_brightness_panel,
        objects.settings_channel_panel,       objects.settings_device_role_panel,
        objects.settings_input_control_panel, objects.settings_language_panel,
        objects.settings_modem_preset_panel,  objects.settings_modify_channel_panel,
        objects.settings_reboot_panel,        objects.settings_region_panel,
        objects.settings_reset_panel,         objects.settings_screen_lock_panel,
        objects.settings_screen_timeout_panel, objects.settings_timezone,
        objects.settings_username_panel,      objects.settings_wifi_panel,
        objects.setup_panel,
    };
    for (lv_obj_t *p : popup_panels) {
        if (!p) continue;
        lv_obj_set_style_bg_color(p, popup_bg, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(p, popup_border, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(p, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(p, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    }

    // Dropdowns inside the popup panels carry a hard 0xffe0e0e0 grey border
    // and rely on raw LVGL defaults for fill/text. Re-bind to the M3 tonal
    // text-field palette: secondaryContainer fill, onSecondaryContainer text,
    // outlineVariant outline, small 8px radius.
    lv_color_t dd_bg     = lv_color_hex(THEME(eSettingsButtonBg));    // secondaryContainer
    lv_color_t dd_fg     = lv_color_hex(THEME(eSettingsButtonText));  // onSecondaryContainer
    lv_color_t dd_border = lv_color_hex(THEME(eSettingsPanelBorder)); // outlineVariant
    lv_obj_t *dropdowns[] = {
        objects.settings_theme_dropdown,        objects.settings_device_role_dropdown,
        objects.settings_keyboard_input_dropdown, objects.settings_language_dropdown,
        objects.settings_modem_preset_dropdown, objects.settings_mouse_input_dropdown,
        objects.settings_region_dropdown,       objects.settings_reset_dropdown,
        objects.settings_ringtone_dropdown,     objects.settings_backup_restore_dropdown,
        objects.setup_region_dropdown,          objects.nodes_filter_channel_dropdown,
        objects.nodes_filter_hops_dropdown,     objects.settings_tzcity,
        objects.settings_tzzone,
    };
    for (lv_obj_t *d : dropdowns) {
        if (!d) continue;
        lv_obj_set_style_bg_color(d, dd_bg, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(d, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(d, dd_fg, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(d, dd_border, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(d, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(d, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        // Open-list popup styling (LV_PART_INDICATOR drives the chevron;
        // the popup list is a child object styled separately by LVGL).
        lv_obj_t *list = lv_dropdown_get_list(d);
        if (list) {
            lv_obj_set_style_bg_color(list, popup_bg, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(list, dd_fg, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(list, dd_border, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(list, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(list, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            // Highlighted (selected) item in the open list.
            lv_obj_set_style_bg_color(list, lv_color_hex(THEME(eChannelButtonBg)),  // primaryContainer
                                      LV_PART_SELECTED | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(list, lv_color_hex(THEME(eChannelButtonText)),
                                        LV_PART_SELECTED | LV_STATE_CHECKED);
        }
    }

    // OK / Cancel widget instances — the EEZ user-widget hardcodes a
    // 0xff216ad8 (blue) fill and a 7px radius on every OK + Cancel pair.
    // Re-bind to M3 dialog action buttons: OK = primary filled pill,
    // Cancel = secondary-container tonal pill.
    lv_color_t ok_bg     = lv_color_hex(THEME(eMainButtonBg));        // primary
    lv_color_t ok_fg     = lv_color_hex(THEME(eMainButtonText));      // onPrimary
    lv_color_t cancel_bg = lv_color_hex(THEME(eSettingsButtonBg));    // secondaryContainer
    lv_color_t cancel_fg = lv_color_hex(THEME(eSettingsButtonText));  // onSecondaryContainer
    lv_obj_t *ok_btns[] = {
        objects.obj2__ok_button_w,  objects.obj3__ok_button_w,  objects.obj4__ok_button_w,
        objects.obj5__ok_button_w,  objects.obj6__ok_button_w,  objects.obj7__ok_button_w,
        objects.obj8__ok_button_w,  objects.obj9__ok_button_w,  objects.obj10__ok_button_w,
        objects.obj11__ok_button_w, objects.obj12__ok_button_w, objects.obj13__ok_button_w,
        objects.obj14__ok_button_w, objects.obj15__ok_button_w, objects.obj16__ok_button_w,
        objects.obj17__ok_button_w, objects.obj18__ok_button_w, objects.obj21__ok_button_w,
        objects.obj27__ok_button_w,
    };
    lv_obj_t *cancel_btns[] = {
        objects.obj2__cancel_button_w,  objects.obj3__cancel_button_w,  objects.obj4__cancel_button_w,
        objects.obj5__cancel_button_w,  objects.obj6__cancel_button_w,  objects.obj7__cancel_button_w,
        objects.obj8__cancel_button_w,  objects.obj9__cancel_button_w,  objects.obj10__cancel_button_w,
        objects.obj11__cancel_button_w, objects.obj12__cancel_button_w, objects.obj13__cancel_button_w,
        objects.obj14__cancel_button_w, objects.obj15__cancel_button_w, objects.obj16__cancel_button_w,
        objects.obj17__cancel_button_w, objects.obj18__cancel_button_w, objects.obj21__cancel_button_w,
        objects.obj27__cancel_button_w,
    };
    for (lv_obj_t *b : ok_btns) {
        if (!b) continue;
        lv_obj_set_style_bg_color(b, ok_bg, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(b, ok_fg, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(b, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    for (lv_obj_t *b : cancel_btns) {
        if (!b) continue;
        lv_obj_set_style_bg_color(b, cancel_bg, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(b, cancel_fg, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(b, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);
    }

    // Text input areas: M3 filled text-field — surface-container-low fill,
    // onSurface text, outlineVariant outline, 8px radius.
    lv_color_t ta_bg     = lv_color_hex(THEME(eNodePanelBg));       // surfaceContainerLow
    lv_color_t ta_fg     = lv_color_hex(THEME(eHomeContainerText)); // onSurface
    lv_color_t ta_border = lv_color_hex(THEME(eSettingsPanelBorder));
    lv_obj_t *textareas[] = {
        objects.message_input_area,                     objects.nodes_filter_name_area,
        objects.nodes_hl_name_area,                     objects.settings_modify_channel_name_textarea,
        objects.settings_modify_channel_psk_textarea,   objects.settings_screen_lock_password_textarea,
        objects.settings_user_long_textarea,            objects.settings_user_short_textarea,
        objects.settings_wifi_password_textarea,        objects.settings_wifi_ssid_textarea,
        objects.setup_user_long_textarea,               objects.setup_user_short_textarea,
    };
    for (lv_obj_t *t : textareas) {
        if (!t) continue;
        lv_obj_set_style_bg_color(t, ta_bg, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(t, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(t, ta_fg, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(t, ta_border, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(t, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(t, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    }

    // Small inline image-buttons (keyboard toggle, key generator) hardcode
    // a white fill with a dark-grey icon recolor — wrong on either theme.
    // Rebind to M3 tonal icon-button: secondaryContainer fill, onSecondaryContainer
    // icon, circular radius.
    lv_color_t kb_bg = lv_color_hex(THEME(eHomeButtonBg));
    lv_color_t kb_fg = lv_color_hex(THEME(eHomeButtonImageRecolor));
    lv_obj_t *icon_btns[] = {
        objects.keyboard_button_0,  objects.keyboard_button_1,  objects.keyboard_button_2,
        objects.keyboard_button_3,  objects.keyboard_button_4,  objects.keyboard_button_5,
        objects.keyboard_button_6,  objects.keyboard_button_7,  objects.keyboard_button_8,
        objects.keyboard_button_9,  objects.keyboard_button_10, objects.keyboard_button_11,
        objects.settings_modify_channel_key_generate_button,
    };
    for (lv_obj_t *b : icon_btns) {
        if (!b) continue;
        lv_obj_set_style_bg_color(b, kb_bg, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_image_recolor(b, kb_fg, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_image_recolor_opa(b, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(b, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if (objects.settings_modify_trash_button) {
        lv_obj_set_style_bg_color(objects.settings_modify_trash_button, kb_bg,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_image_recolor(objects.settings_modify_trash_button, kb_fg,
                                          LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_image_recolor_opa(objects.settings_modify_trash_button, 255,
                                              LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(objects.settings_modify_trash_button, LV_RADIUS_CIRCLE,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
        // Pressed → primaryContainer (matches our home-button pressed state).
        lv_obj_set_style_bg_color(objects.settings_modify_trash_button, pressed_bg,
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    }

    // Two inline labels in the modify-channel popup hardcode a cyan
    // 0xff7ff5f9 text colour. Re-bind to onSurface.
    if (objects.obj19) {
        lv_obj_set_style_text_color(objects.obj19, ta_fg, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if (objects.obj20) {
        lv_obj_set_style_text_color(objects.obj20, ta_fg, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

void Themes::initStyles(void)
{
    // set(get());
    //  lvgl v9 tabview buttons are not btn-matrix anymore but array of buttons
    //  see https://forum.lvgl.io/t/style-a-tabview-widget-in-v9-0-0/14747
    // M3 secondary tabs: inactive is text-only on surface; active draws a
    // primary-colored indicator along the bottom edge; pressed shows a
    // tonal state-layer fill.
    lv_style_init(&style_btn_default);
    lv_style_set_text_color(&style_btn_default, lv_color_hex(THEME(eTabButtonDefaultText)));
    lv_style_set_bg_color(&style_btn_default, lv_color_hex(THEME(eTabButtonDefaultBg)));
    lv_style_set_bg_opa(&style_btn_default, LV_OPA_COVER);
    lv_style_set_border_width(&style_btn_default, 0);
    lv_style_set_radius(&style_btn_default, 0);

    lv_style_init(&style_btn_active);
    lv_style_set_text_color(&style_btn_active, lv_color_hex(THEME(eTabButtonActiveText)));
    lv_style_set_bg_color(&style_btn_active, lv_color_hex(THEME(eTabButtonActiveBg)));
    lv_style_set_bg_opa(&style_btn_active, LV_OPA_COVER);
    lv_style_set_border_color(&style_btn_active, lv_color_hex(THEME(eMainButtonBg))); // primary token
    lv_style_set_border_opa(&style_btn_active, LV_OPA_COVER);
    lv_style_set_border_width(&style_btn_active, 3);
    lv_style_set_border_side(&style_btn_active, LV_BORDER_SIDE_BOTTOM);
    lv_style_set_radius(&style_btn_active, 0);

    lv_style_init(&style_btn_pressed);
    lv_style_set_text_color(&style_btn_pressed, lv_color_hex(THEME(eTabButtonPressedText)));
    lv_style_set_bg_color(&style_btn_pressed, lv_color_hex(THEME(eTabButtonPressedBg)));
    lv_style_set_bg_opa(&style_btn_pressed, LV_OPA_COVER);
    lv_style_set_border_color(&style_btn_pressed, lv_color_hex(THEME(eMainButtonBg))); // primary token
    lv_style_set_border_opa(&style_btn_pressed, LV_OPA_COVER);
    lv_style_set_border_width(&style_btn_pressed, 3);
    lv_style_set_border_side(&style_btn_pressed, LV_BORDER_SIDE_BOTTOM);
    lv_style_set_radius(&style_btn_pressed, 0);
}

// Used by home-grid buttons to indicate feature on/off (lora, wlan, mqtt, …).
// M3 toggle pattern: enabled -> light primary-container fill with dark icon;
// disabled -> dark surface-container-high fill with on-surface icon. Both the
// button fill AND the icon recolor are updated so theme switching stays
// consistent.
void Themes::recolorButton(lv_obj_t *obj, bool enabled, lv_opa_t opa)
{
    lv_color_t bg   = enabled ? lv_color_hex(THEME(eChannelButtonBg))    // primaryContainer
                              : lv_color_hex(THEME(eHomeButtonBg));      // surfaceContainerHigh
    lv_color_t icon = enabled ? lv_color_hex(THEME(eChannelButtonText))  // onPrimaryContainer
                              : lv_color_hex(THEME(eHomeButtonImageRecolor)); // onSurface
    lv_obj_set_style_bg_color(obj, bg, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(obj, icon, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(obj, opa, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void Themes::recolorImage(lv_obj_t *obj, bool enabled)
{
    lv_color_t color = enabled ? lv_color_hex(THEME(eChannelButtonText))     // onPrimaryContainer
                               : lv_color_hex(THEME(eHomeButtonImageRecolor)); // onSurface
    lv_obj_set_style_image_recolor(obj, color, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void Themes::recolorText(lv_obj_t *obj, bool enabled)
{
    // onSurface for both states — the home-container label sits on the
    // surface, not on the button, so only the button bg changes per state.
    lv_obj_set_style_text_color(obj, lv_color_hex(THEME(eHomeContainerText)),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
}

void Themes::recolorContainer(lv_obj_t *obj)
{
    // Theme a modal/popup surface to the same look as other popups
    // (surfaceContainerHigh bg, outlineVariant border, onSurface text), so it
    // stops rendering on LVGL's default theme.
    lv_obj_set_style_bg_color(obj, lv_color_hex(THEME(eHomeContainerBg)), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(obj, lv_color_hex(THEME(eHomeContainerBorder)), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(THEME(eHomeContainerText)), LV_PART_MAIN | LV_STATE_DEFAULT);
}

void Themes::recolorTopLabel(lv_obj_t *obj, bool alert)
{
    lv_color_t color;
    switch (theme) {
    case eLight:
        color = alert ? lv_color_hex(0xfff72b2b) : lv_color_hex(THEME(eTopPanelText));
        break;
    case eDark:
        color = alert ? lv_color_hex(0xfff72b2b) : lv_color_hex(THEME(eTopPanelText));
        break;
    default:
        break;
    }
    lv_obj_set_style_text_color(obj, color, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void Themes::recolorTableRow(lv_draw_fill_dsc_t *fill_draw_dsc, bool odd)
{
    if (odd) {
        fill_draw_dsc->color = lv_color_hex(THEME(eTableItemBg));
    } else {
        fill_draw_dsc->color = lv_color_hex(THEME(eTableItemDarkBg));
    }
}

void Themes::setMainButtonActive(lv_obj_t *obj, bool active)
{
    if (!obj) return;
    lv_color_t bg   = active ? lv_color_hex(THEME(eChannelButtonBg))     // primaryContainer
                             : lv_color_hex(THEME(eMainButtonBg));       // surfaceContainerHigh
    lv_color_t icon = active ? lv_color_hex(THEME(eChannelButtonText))   // onPrimaryContainer
                             : lv_color_hex(THEME(eMainButtonImageRecolor)); // onSurface
    lv_obj_set_style_bg_color(obj, bg, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(obj, icon, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
}

#endif // VIEW_320x240