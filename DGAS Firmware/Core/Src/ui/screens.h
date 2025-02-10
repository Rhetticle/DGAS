#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *gauge_main_ui;
    lv_obj_t *menu;
    lv_obj_t *obd2_debug;
    lv_obj_t *measure;
    lv_obj_t *settings;
    lv_obj_t *about;
    lv_obj_t *diagnose;
    lv_obj_t *self_test;
    lv_obj_t *gauge_arc;
    lv_obj_t *gauge_scale;
    lv_obj_t *param_val;
    lv_obj_t *obd_status_label;
    lv_obj_t *vbat_label;
    lv_obj_t *parameter_label;
    lv_obj_t *gauge_tick_0;
    lv_obj_t *gauge_tick_1;
    lv_obj_t *gauge_tick_2;
    lv_obj_t *gauge_tick_3;
    lv_obj_t *gauge_tick_4;
    lv_obj_t *gauge_tick_5;
    lv_obj_t *gauge_tick_6;
    lv_obj_t *param_max_label;
    lv_obj_t *param_units_label;
    lv_obj_t *obj0;
    lv_obj_t *measure_btn;
    lv_obj_t *obj1;
    lv_obj_t *obd2_debug_btn;
    lv_obj_t *obj2;
    lv_obj_t *about_btn;
    lv_obj_t *obj3;
    lv_obj_t *settings_btn;
    lv_obj_t *obj4;
    lv_obj_t *menu_exit_btn;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *obj10;
    lv_obj_t *diagnose_btn;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *self_test_btn;
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *obj15;
    lv_obj_t *obd2_debug_textarea;
    lv_obj_t *obj16;
    lv_obj_t *obd2_pause_btn;
    lv_obj_t *obj17;
    lv_obj_t *obd2_resume_btn;
    lv_obj_t *obj18;
    lv_obj_t *obd2_exit_btn;
    lv_obj_t *obj19;
    lv_obj_t *obj20;
    lv_obj_t *obj21;
    lv_obj_t *eng_speed_btn;
    lv_obj_t *obj22;
    lv_obj_t *vehicle_speed_btn;
    lv_obj_t *eng_load_btn;
    lv_obj_t *coolant_temp_btn;
    lv_obj_t *boost_btn;
    lv_obj_t *intake_temp_btn;
    lv_obj_t *maf_btn;
    lv_obj_t *fuel_pressure_btn;
    lv_obj_t *obj23;
    lv_obj_t *obj24;
    lv_obj_t *obj25;
    lv_obj_t *settings_bus_dropdown;
    lv_obj_t *obj26;
    lv_obj_t *obj27;
    lv_obj_t *obj28;
    lv_obj_t *obj29;
    lv_obj_t *settings_param_dropdown;
    lv_obj_t *settings_exit_btn;
    lv_obj_t *obj30;
    lv_obj_t *obj31;
    lv_obj_t *obj32;
    lv_obj_t *obj33;
    lv_obj_t *obj34;
    lv_obj_t *about_exit_btn;
    lv_obj_t *diagnose_textarea;
    lv_obj_t *obj35;
    lv_obj_t *obj36;
    lv_obj_t *diagnose_status_label;
    lv_obj_t *diagnose_clear_btn;
    lv_obj_t *obj37;
    lv_obj_t *diagnose_exit_btn;
    lv_obj_t *obj38;
    lv_obj_t *obj39;
    lv_obj_t *obj40;
    lv_obj_t *self_test_run_btn;
    lv_obj_t *obj41;
    lv_obj_t *self_test_exit_btn;
    lv_obj_t *obj42;
    lv_obj_t *self_test_description_label;
    lv_obj_t *self_test_progress_bar;
    lv_obj_t *self_test_dram_icon;
    lv_obj_t *self_test_flash_icon;
    lv_obj_t *self_test_accel_icon;
    lv_obj_t *self_test_dram_label;
    lv_obj_t *self_test_flash_label;
    lv_obj_t *self_test_accel_label;
    lv_obj_t *self_test_dram_textarea;
    lv_obj_t *self_test_flash_textarea;
    lv_obj_t *self_test_accel_textarea;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_GAUGE_MAIN_UI = 1,
    SCREEN_ID_MENU = 2,
    SCREEN_ID_OBD2_DEBUG = 3,
    SCREEN_ID_MEASURE = 4,
    SCREEN_ID_SETTINGS = 5,
    SCREEN_ID_ABOUT = 6,
    SCREEN_ID_DIAGNOSE = 7,
    SCREEN_ID_SELF_TEST = 8,
};

void create_screen_gauge_main_ui();
void tick_screen_gauge_main_ui();

void create_screen_menu();
void tick_screen_menu();

void create_screen_obd2_debug();
void tick_screen_obd2_debug();

void create_screen_measure();
void tick_screen_measure();

void create_screen_settings();
void tick_screen_settings();

void create_screen_about();
void tick_screen_about();

void create_screen_diagnose();
void tick_screen_diagnose();

void create_screen_self_test();
void tick_screen_self_test();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/