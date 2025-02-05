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
    lv_obj_t *about;
    lv_obj_t *settings;
    lv_obj_t *safety;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *obj15;
    lv_obj_t *obj16;
    lv_obj_t *obj17;
    lv_obj_t *obj18;
    lv_obj_t *obj19;
    lv_obj_t *obj20;
    lv_obj_t *obj21;
    lv_obj_t *obj22;
    lv_obj_t *obj23;
    lv_obj_t *obj24;
    lv_obj_t *obj25;
    lv_obj_t *obj26;
    lv_obj_t *obj27;
    lv_obj_t *obj28;
    lv_obj_t *obj29;
    lv_obj_t *obj30;
    lv_obj_t *obj31;
    lv_obj_t *obj32;
    lv_obj_t *obj33;
    lv_obj_t *obj34;
    lv_obj_t *obj35;
    lv_obj_t *obj36;
    lv_obj_t *obj37;
    lv_obj_t *obj38;
    lv_obj_t *obj39;
    lv_obj_t *obj40;
    lv_obj_t *obj41;
    lv_obj_t *obj42;
    lv_obj_t *obj43;
    lv_obj_t *obj44;
    lv_obj_t *obj45;
    lv_obj_t *obj46;
    lv_obj_t *obj47;
    lv_obj_t *obj48;
    lv_obj_t *obj49;
    lv_obj_t *obj50;
    lv_obj_t *obj51;
    lv_obj_t *obj52;
    lv_obj_t *obj53;
    lv_obj_t *obj54;
    lv_obj_t *obj55;
    lv_obj_t *obj56;
    lv_obj_t *obj57;
    lv_obj_t *obj58;
    lv_obj_t *obj59;
    lv_obj_t *obj60;
    lv_obj_t *obj61;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_GAUGE_MAIN_UI = 1,
    SCREEN_ID_MENU = 2,
    SCREEN_ID_OBD2_DEBUG = 3,
    SCREEN_ID_MEASURE = 4,
    SCREEN_ID_ABOUT = 5,
    SCREEN_ID_SETTINGS = 6,
    SCREEN_ID_SAFETY = 7,
};

void create_screen_gauge_main_ui();
void tick_screen_gauge_main_ui();

void create_screen_menu();
void tick_screen_menu();

void create_screen_obd2_debug();
void tick_screen_obd2_debug();

void create_screen_measure();
void tick_screen_measure();

void create_screen_about();
void tick_screen_about();

void create_screen_settings();
void tick_screen_settings();

void create_screen_safety();
void tick_screen_safety();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/