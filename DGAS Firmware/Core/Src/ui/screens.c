#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_gauge_main_ui() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.gauge_main_ui = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // gauge_arc
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.gauge_arc = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_arc_set_range(obj, 0, 4200);
            lv_arc_set_value(obj, 700);
            lv_arc_set_bg_start_angle(obj, 135);
            lv_arc_set_bg_end_angle(obj, 45);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xff00ff00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 50, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_rounded(obj, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // gauge_scale
            lv_obj_t *obj = lv_scale_create(parent_obj);
            objects.gauge_scale = obj;
            lv_obj_set_pos(obj, 49, 49);
            lv_obj_set_size(obj, 383, 382);
            lv_scale_set_mode(obj, LV_SCALE_MODE_ROUND_OUTER);
            lv_scale_set_range(obj, 0, 6000);
            lv_scale_set_total_tick_count(obj, 31);
            lv_scale_set_major_tick_every(obj, 5);
            lv_scale_set_label_show(obj, false);
            lv_obj_set_style_length(obj, 30, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_AUTO, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xffffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_line_width(obj, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xffffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_line_rounded(obj, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_length(obj, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_max_width(obj, 536870911, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_line_width(obj, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // param_val
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.param_val = obj;
            lv_obj_set_pos(obj, 178, 199);
            lv_obj_set_size(obj, 125, 52);
            lv_label_set_text(obj, "XXXX");
            lv_label_set_recolor(obj, true);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 104, 383);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "OBD2");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 311, 383);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "VBAT");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // obd_status_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obd_status_label = obj;
            lv_obj_set_pos(obj, 94, 410);
            lv_obj_set_size(obj, 84, 24);
            lv_label_set_text(obj, "LIVE");
            lv_label_set_recolor(obj, true);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // vbat_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.vbat_label = obj;
            lv_obj_set_pos(obj, 307, 410);
            lv_obj_set_size(obj, 68, 24);
            lv_label_set_text(obj, "XX.XV");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 215, 383);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "MAX");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // parameter_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.parameter_label = obj;
            lv_obj_set_pos(obj, 112, 303);
            lv_obj_set_size(obj, 256, 30);
            lv_label_set_text(obj, "PARAMETER");
            lv_label_set_recolor(obj, true);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // gauge_tick_0
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.gauge_tick_0 = obj;
            lv_obj_set_pos(obj, 115, 341);
            lv_obj_set_size(obj, 19, 30);
            lv_label_set_text(obj, "0");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // gauge_tick_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.gauge_tick_1 = obj;
            lv_obj_set_pos(obj, 58, 225);
            lv_obj_set_size(obj, 54, 30);
            lv_label_set_text(obj, "700");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_FOCUSED);
        }
        {
            // gauge_tick_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.gauge_tick_2 = obj;
            lv_obj_set_pos(obj, 111, 115);
            lv_obj_set_size(obj, 67, 30);
            lv_label_set_text(obj, "1400");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_FOCUSED);
        }
        {
            // gauge_tick_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.gauge_tick_3 = obj;
            lv_obj_set_pos(obj, 208, 63);
            lv_obj_set_size(obj, 64, 30);
            lv_label_set_text(obj, "2100");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // gauge_tick_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.gauge_tick_4 = obj;
            lv_obj_set_pos(obj, 299, 115);
            lv_obj_set_size(obj, 72, 30);
            lv_label_set_text(obj, "2800");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // gauge_tick_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.gauge_tick_5 = obj;
            lv_obj_set_pos(obj, 352, 225);
            lv_obj_set_size(obj, 70, 30);
            lv_label_set_text(obj, "3500");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // gauge_tick_6
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.gauge_tick_6 = obj;
            lv_obj_set_pos(obj, 295, 341);
            lv_obj_set_size(obj, 73, 30);
            lv_label_set_text(obj, "4200");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // param_max_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.param_max_label = obj;
            lv_obj_set_pos(obj, 187, 410);
            lv_obj_set_size(obj, 108, 24);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
            lv_label_set_text(obj, "XXXX");
            lv_label_set_recolor(obj, true);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // param_units_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.param_units_label = obj;
            lv_obj_set_pos(obj, 189, 255);
            lv_obj_set_size(obj, 103, 35);
            lv_label_set_text(obj, "UNITS");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_gauge_main_ui() {
}

void create_screen_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 173, 62);
            lv_obj_set_size(obj, 133, 44);
            lv_label_set_text(obj, "MENU");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff700dd), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // measure_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.measure_btn = obj;
            lv_obj_set_pos(obj, 91, 119);
            lv_obj_set_size(obj, 132, 66);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00fff4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_stop(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00fff4), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Measure");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff00fff4), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_FOCUSED);
                }
            }
        }
        {
            // obd2_debug_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obd2_debug_btn = obj;
            lv_obj_set_pos(obj, 298, 119);
            lv_obj_set_size(obj, 132, 66);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe6af00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xffe6af00), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "OBD2 Debug");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffe6af00), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffe6af00), LV_PART_MAIN | LV_STATE_PRESSED);
                }
            }
        }
        {
            // about_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.about_btn = obj;
            lv_obj_set_pos(obj, 297, 272);
            lv_obj_set_size(obj, 132, 66);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff04ff40), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff04ff40), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj3 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "About");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff04ff40), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff04ff40), LV_PART_MAIN | LV_STATE_FOCUSED);
                }
            }
        }
        {
            // settings_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.settings_btn = obj;
            lv_obj_set_pos(obj, 94, 271);
            lv_obj_set_size(obj, 132, 66);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj4 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Settings");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // menu_exit_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.menu_exit_btn = obj;
            lv_obj_set_pos(obj, 174, 386);
            lv_obj_set_size(obj, 132, 66);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_SCROLLED);
            lv_obj_set_style_outline_width(obj, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj5 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Exit");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_PRESSED);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 211, 0);
            lv_obj_set_size(obj, 58, 62);
            lv_label_set_text(obj, "\uf03a");
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff700dd), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 21, 125);
            lv_obj_set_size(obj, 47, 62);
            lv_label_set_text(obj, "\uf0ad");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff00fff4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 23, 277);
            lv_obj_set_size(obj, 53, 61);
            lv_label_set_text(obj, "\uf013");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 231, 123);
            lv_obj_set_size(obj, 56, 63);
            lv_label_set_text(obj, "\uf188");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe6af00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 231, 277);
            lv_obj_set_size(obj, 56, 63);
            lv_label_set_text(obj, "\uf129");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff04ff40), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // diagnose_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.diagnose_btn = obj;
            lv_obj_set_pos(obj, 94, 196);
            lv_obj_set_size(obj, 132, 66);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj11 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "DTC");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj12 = obj;
            lv_obj_set_pos(obj, 21, 200);
            lv_obj_set_size(obj, 59, 62);
            lv_label_set_text(obj, "\uf071");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // self_test_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.self_test_btn = obj;
            lv_obj_set_pos(obj, 297, 197);
            lv_obj_set_size(obj, 132, 66);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffa000bf), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xffa000bf), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj13 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Self Test");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffa000bf), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj14 = obj;
            lv_obj_set_pos(obj, 239, 200);
            lv_obj_set_size(obj, 41, 62);
            lv_label_set_text(obj, "\uf46c");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffa000bf), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_menu() {
}

void create_screen_obd2_debug() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.obd2_debug = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj15 = obj;
            lv_obj_set_pos(obj, 127, 63);
            lv_obj_set_size(obj, 227, 40);
            lv_label_set_text(obj, "OBD2 DEBUG");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe6af00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // obd2_debug_textarea
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.obd2_debug_textarea = obj;
            lv_obj_set_pos(obj, 54, 123);
            lv_obj_set_size(obj, 372, 274);
            lv_textarea_set_max_length(obj, 0);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_label_set_recolor(lv_textarea_get_label(obj), true);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff00ff00), LV_PART_CURSOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_CURSOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_CURSOR | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffff00ff), LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj16 = obj;
            lv_obj_set_pos(obj, 140, 103);
            lv_obj_set_size(obj, 205, 20);
            lv_label_set_text(obj, "Live OBD 2 messages");
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // obd2_pause_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obd2_pause_btn = obj;
            lv_obj_set_pos(obj, 110, 397);
            lv_obj_set_size(obj, 79, 37);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj17 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Pause");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // obd2_resume_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obd2_resume_btn = obj;
            lv_obj_set_pos(obj, 203, 398);
            lv_obj_set_size(obj, 79, 37);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj18 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Resume");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // obd2_exit_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obd2_exit_btn = obj;
            lv_obj_set_pos(obj, 293, 398);
            lv_obj_set_size(obj, 79, 37);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj19 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Exit");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj20 = obj;
            lv_obj_set_pos(obj, 212, 0);
            lv_obj_set_size(obj, 56, 63);
            lv_label_set_text(obj, "\uf188");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe6af00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_obd2_debug() {
}

void create_screen_measure() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.measure = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj21 = obj;
            lv_obj_set_pos(obj, 159, 63);
            lv_obj_set_size(obj, 162, 34);
            lv_label_set_text(obj, "MEASURE");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff00fff4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 134, 97);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Select parameter to measure");
        }
        {
            // eng_speed_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.eng_speed_btn = obj;
            lv_obj_set_pos(obj, 72, 126);
            lv_obj_set_size(obj, 133, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj22 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "ENGINE SPEED");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // vehicle_speed_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.vehicle_speed_btn = obj;
            lv_obj_set_pos(obj, 72, 190);
            lv_obj_set_size(obj, 133, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "VEHICLE SPEED");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // eng_load_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.eng_load_btn = obj;
            lv_obj_set_pos(obj, 72, 262);
            lv_obj_set_size(obj, 133, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff26), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "ENGINE LOAD");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // coolant_temp_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.coolant_temp_btn = obj;
            lv_obj_set_pos(obj, 72, 342);
            lv_obj_set_size(obj, 133, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "COOLANT TEMP");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // boost_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.boost_btn = obj;
            lv_obj_set_pos(obj, 267, 126);
            lv_obj_set_size(obj, 126, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff600b0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "BOOST");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // intake_temp_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.intake_temp_btn = obj;
            lv_obj_set_pos(obj, 267, 190);
            lv_obj_set_size(obj, 128, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff6f200), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "INTAKE AIR TEMP");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // maf_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.maf_btn = obj;
            lv_obj_set_pos(obj, 269, 262);
            lv_obj_set_size(obj, 128, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff6021f3), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "MAF FLOW RATE");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // fuel_pressure_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fuel_pressure_btn = obj;
            lv_obj_set_pos(obj, 270, 342);
            lv_obj_set_size(obj, 127, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3a521), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "FUEL PRESSURE");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj23 = obj;
            lv_obj_set_pos(obj, 217, 1);
            lv_obj_set_size(obj, 47, 62);
            lv_label_set_text(obj, "\uf0ad");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff00fff4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_measure() {
}

void create_screen_settings() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj24 = obj;
            lv_obj_set_pos(obj, 151, 61);
            lv_obj_set_size(obj, 178, 41);
            lv_label_set_text(obj, "SETTINGS");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj25 = obj;
            lv_obj_set_pos(obj, 214, 0);
            lv_obj_set_size(obj, 53, 61);
            lv_label_set_text(obj, "\uf013");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // settings_bus_dropdown
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.settings_bus_dropdown = obj;
            lv_obj_set_pos(obj, 261, 211);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, "KWP2000\nISO-9141\nISO-15765 (CAN)\nAuto Detect ");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd5ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_EDITED);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj26 = obj;
            lv_obj_set_pos(obj, 70, 202);
            lv_obj_set_size(obj, 63, 58);
            lv_label_set_text(obj, "\uf6ff");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffd5ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj27 = obj;
            lv_obj_set_pos(obj, 145, 218);
            lv_obj_set_size(obj, 116, 27);
            lv_label_set_text(obj, "OBD2 Bus");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj28 = obj;
            lv_obj_set_pos(obj, 70, 110);
            lv_obj_set_size(obj, 63, 58);
            lv_label_set_text(obj, "\uf0ad");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff00ffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj29 = obj;
            lv_obj_set_pos(obj, 145, 110);
            lv_obj_set_size(obj, 116, 50);
            lv_label_set_text(obj, "Default Parameter");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // settings_param_dropdown
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.settings_param_dropdown = obj;
            lv_obj_set_pos(obj, 261, 111);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, "ENGINE SPEED\nVEHICLE SPEED\nENGINE LOAD\nCOOLANT TEMP\nBOOST\nINTAKE TEMP\nMAF \nFUEL PRESSURE");
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        }
        {
            // settings_exit_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.settings_exit_btn = obj;
            lv_obj_set_pos(obj, 148, 400);
            lv_obj_set_size(obj, 184, 50);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff1b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj30 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "SAVE AND EXIT");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_settings() {
}

void create_screen_about() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.about = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj31 = obj;
            lv_obj_set_pos(obj, 180, 15);
            lv_obj_set_size(obj, 120, 36);
            lv_label_set_text(obj, "ABOUT");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff04ff40), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj32 = obj;
            lv_obj_set_pos(obj, 92, 394);
            lv_obj_set_size(obj, 297, 52);
            lv_label_set_text(obj, "Designed and Built by Rhett Humphreys");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj33 = obj;
            lv_obj_set_pos(obj, 64, 66);
            lv_obj_set_size(obj, 352, 70);
            lv_label_set_text(obj, "DGAS is an all-in-one digital gauge capable of measuring any data avaiable on a car's OBD2 interface. \n\n");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj34 = obj;
            lv_obj_set_pos(obj, 27, 141);
            lv_obj_set_size(obj, 427, 47);
            lv_label_set_text(obj, "For technical details check out the GitHub page using the QR code below");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // about_exit_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.about_exit_btn = obj;
            lv_obj_set_pos(obj, 207, 445);
            lv_obj_set_size(obj, 67, 35);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff04ff40), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Exit");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 166, 217);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_qr_code);
            lv_img_set_zoom(obj, 350);
        }
    }
}

void tick_screen_about() {
}

void create_screen_diagnose() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.diagnose = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // diagnose_textarea
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.diagnose_textarea = obj;
            lv_obj_set_pos(obj, 43, 120);
            lv_obj_set_size(obj, 390, 249);
            lv_textarea_set_max_length(obj, 256);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_label_set_recolor(lv_textarea_get_label(obj), true);
            lv_textarea_set_max_length(obj, 0);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_CURSOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj35 = obj;
            lv_obj_set_pos(obj, 211, 0);
            lv_obj_set_size(obj, 59, 62);
            lv_label_set_text(obj, "\uf071");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj36 = obj;
            lv_obj_set_pos(obj, 0, -166);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "DTC");
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // diagnose_status_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.diagnose_status_label = obj;
            lv_obj_set_pos(obj, 179, 306);
            lv_obj_set_size(obj, 122, 30);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 147, 95);
            lv_obj_set_size(obj, 187, 16);
            lv_label_set_text(obj, "Diagnostic Touble Codes");
        }
        {
            // diagnose_clear_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.diagnose_clear_btn = obj;
            lv_obj_set_pos(obj, 120, 381);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj37 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "CLEAR");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // diagnose_exit_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.diagnose_exit_btn = obj;
            lv_obj_set_pos(obj, 251, 381);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj38 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "EXIT");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_diagnose() {
}

void create_screen_self_test() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.self_test = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj39 = obj;
            lv_obj_set_pos(obj, 224, 0);
            lv_obj_set_size(obj, 33, 56);
            lv_label_set_text(obj, "\uf46c");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffa000bf), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj40 = obj;
            lv_obj_set_pos(obj, 0, -165);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Self-Test");
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffa000bf), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // self_test_run_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.self_test_run_btn = obj;
            lv_obj_set_pos(obj, 190, 215);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj41 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "RUN");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // self_test_exit_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.self_test_exit_btn = obj;
            lv_obj_set_pos(obj, 190, 420);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj42 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "EXIT");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // self_test_description_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.self_test_description_label = obj;
            lv_obj_set_pos(obj, 67, 262);
            lv_obj_set_size(obj, 353, 33);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // self_test_progress_bar
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.self_test_progress_bar = obj;
            lv_obj_set_pos(obj, 97, 227);
            lv_obj_set_size(obj, 292, 26);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffa000bf), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffa000bf), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // self_test_dram_icon
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.self_test_dram_icon = obj;
            lv_obj_set_pos(obj, 58, 110);
            lv_obj_set_size(obj, 66, 52);
            lv_label_set_text(obj, "\uf538");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffeb7f00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // self_test_flash_icon
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.self_test_flash_icon = obj;
            lv_obj_set_pos(obj, 216, 110);
            lv_obj_set_size(obj, 58, 52);
            lv_label_set_text(obj, "\uf0a0");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff00eacb), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // self_test_accel_icon
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.self_test_accel_icon = obj;
            lv_obj_set_pos(obj, 364, 105);
            lv_obj_set_size(obj, 51, 52);
            lv_label_set_text(obj, "\uf0b2");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff01ff60), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // self_test_dram_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.self_test_dram_label = obj;
            lv_obj_set_pos(obj, 49, 157);
            lv_obj_set_size(obj, 83, 27);
            lv_label_set_text(obj, "DRAM");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffeb7f00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // self_test_flash_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.self_test_flash_label = obj;
            lv_obj_set_pos(obj, 202, 157);
            lv_obj_set_size(obj, 83, 27);
            lv_label_set_text(obj, "FLASH");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff00eacb), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // self_test_accel_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.self_test_accel_label = obj;
            lv_obj_set_pos(obj, 348, 157);
            lv_obj_set_size(obj, 83, 27);
            lv_label_set_text(obj, "ACCEL");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff01ff60), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // self_test_dram_textarea
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.self_test_dram_textarea = obj;
            lv_obj_set_pos(obj, 11, 192);
            lv_obj_set_size(obj, 155, 124);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_label_set_recolor(lv_textarea_get_label(obj), true);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff282b30), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // self_test_flash_textarea
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.self_test_flash_textarea = obj;
            lv_obj_set_pos(obj, 167, 192);
            lv_obj_set_size(obj, 155, 124);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_label_set_recolor(lv_textarea_get_label(obj), true);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // self_test_accel_textarea
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.self_test_accel_textarea = obj;
            lv_obj_set_pos(obj, 323, 192);
            lv_obj_set_size(obj, 144, 124);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_label_set_recolor(lv_textarea_get_label(obj), true);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_self_test() {
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_gauge_main_ui();
    create_screen_menu();
    create_screen_obd2_debug();
    create_screen_measure();
    create_screen_settings();
    create_screen_about();
    create_screen_diagnose();
    create_screen_self_test();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_gauge_main_ui,
    tick_screen_menu,
    tick_screen_obd2_debug,
    tick_screen_measure,
    tick_screen_settings,
    tick_screen_about,
    tick_screen_diagnose,
    tick_screen_self_test,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
