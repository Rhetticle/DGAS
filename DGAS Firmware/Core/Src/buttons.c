/*
 * buttons.c
 *
 *  Created on: Jan 28, 2025
 *      Author: rhett
 */

#include "ui.h"
#include "lvgl.h"
#include "buttons.h"
#include "gauge.h"
#include <stm32f7xx.h>

static volatile uint16_t navPressed = 0;
static lv_group_t* menuGroup;
static lv_group_t* measGroup;

void HAL_GPIO_EXTI_Callback(uint16_t pin) {
	if (pin == BTN_NAV) {
		navPressed = 1;
	}
}

void enc_read(lv_indev_t* indev, lv_indev_data_t* data) {
	if (navPressed) {
		data->enc_diff += 1;
		navPressed = 0;
	}

	if (HAL_GPIO_ReadPin(GPIOB, BTN_SEL) == 0) {
		data->state = LV_INDEV_STATE_PRESSED;
	} else {
		data->state = LV_INDEV_STATE_RELEASED;
	}
}

void menu_event_handler(lv_event_t* e) {
	lv_event_code_t code = lv_event_get_code(e);

	if (code == LV_EVENT_PRESSED || code == LV_EVENT_LONG_PRESSED) {
		lv_screen_load(lv_event_get_user_data(e));
		lv_indev_set_group(lv_indev_active(), measGroup);
	}
}

void meas_event_handler(lv_event_t* e) {
	lv_event_code_t code = lv_event_get_code(e);

	if (code == LV_EVENT_PRESSED || code == LV_EVENT_LONG_PRESSED) {
		lv_screen_load(objects.gauge_main_ui);
		gauge_load_param(lv_event_get_user_data(e), &PARAM_LOAD);
	}
}

void init_groups(void) {
	menuGroup = lv_group_create();
	lv_group_add_obj(menuGroup, objects.obj16);
	lv_group_add_obj(menuGroup, objects.obj17);
	lv_group_add_obj(menuGroup, objects.obj19);
	lv_group_add_obj(menuGroup, objects.obj18);
	lv_group_add_obj(menuGroup, objects.obj20);

	measGroup = lv_group_create();
	lv_group_add_obj(measGroup, objects.obj37);
	lv_group_add_obj(measGroup, objects.obj39);
	lv_group_add_obj(measGroup, objects.obj40);
	lv_group_add_obj(measGroup, objects.obj41);
	lv_group_add_obj(measGroup, objects.obj42);
	lv_group_add_obj(measGroup, objects.obj43);
	lv_group_add_obj(measGroup, objects.obj44);
	lv_group_add_obj(measGroup, objects.obj45);
}

void init_events(GaugeState* state) {
	EventData eData = {.state = state, .nextGroup = NULL, .nextScreen = objects.gauge_main_ui, .nextParam = NULL};
	eData.nextParam = &PARAM_RPM;
	lv_obj_add_event_cb(objects.obj37, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.obj16, menu_event_handler, LV_EVENT_ALL, objects.measure);
}

void init_buttons(lv_indev_t* indev) {
	lv_indev_set_type(indev, LV_INDEV_TYPE_ENCODER);
	lv_indev_set_read_cb(indev, enc_read);
	init_groups();
	lv_indev_set_group(indev, menuGroup);
}
