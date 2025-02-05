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
static volatile uint32_t lastNavPress;
static lv_group_t* menuGroup;
static lv_group_t* measGroup;
static lv_group_t* debugGroup;

void load_screen_and_group(lv_obj_t* screen, lv_indev_t* indev) {
	lv_screen_load(screen);

	if (screen == objects.gauge_main_ui) {
		return;
	}
	if (screen == objects.menu) {
		lv_indev_set_group(indev, menuGroup);
	} else if (screen == objects.measure) {
		lv_indev_set_group(indev, measGroup);
	} else if (screen == objects.obd2_debug) {
		lv_indev_set_group(indev, debugGroup);
	}
	lv_group_t* group = lv_indev_get_group(indev);
	// add this to make sure focus is shown on screen switch
	lv_group_focus_next(group);
	lv_group_focus_prev(group);
}

void HAL_GPIO_EXTI_Callback(uint16_t pin) {
	// use HAL_GetTick() to do software de-bouncing of physical button
	if ((pin == BTN_NAV) && ((HAL_GetTick() - lastNavPress) > 200)) {
		navPressed = 1;
		lastNavPress = HAL_GetTick();
	}
}

void enc_read(lv_indev_t* indev, lv_indev_data_t* data) {
	if (navPressed && (lv_screen_active() == objects.gauge_main_ui)) {
		load_screen_and_group(objects.menu, indev);
		navPressed = 0;
		return;
	}
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
	lv_indev_t* indev = lv_indev_active();
	lv_group_t* group = lv_indev_get_group(indev);
	lv_obj_t* focused = lv_group_get_focused(group);

	if (code == LV_EVENT_PRESSED || code == LV_EVENT_LONG_PRESSED) {
		if (focused == objects.obj16) {
			load_screen_and_group(objects.measure, indev);
		} else if (focused == objects.obj18) {
			load_screen_and_group(objects.obd2_debug, indev);
		} else if (focused == objects.obj20) {
			load_screen_and_group(objects.about, indev);
		} else if (focused == objects.obj22) {
			load_screen_and_group(objects.settings, indev);
		} else if (focused == objects.obj24) {
			load_screen_and_group(objects.gauge_main_ui, indev);
		}
	}
}

void meas_event_handler(lv_event_t* e) {
	lv_event_code_t code = lv_event_get_code(e);
	GaugeState* state = (GaugeState*) lv_event_get_user_data(e);

	if (code == LV_EVENT_PRESSED || code == LV_EVENT_LONG_PRESSED) {
		lv_screen_load(objects.gauge_main_ui);
		lv_obj_t* chosen = lv_group_get_focused(measGroup);

		if (chosen == objects.obj42) {
			gauge_load_param(state, &PARAM_RPM);
		} else if (chosen == objects.obj44) {
			gauge_load_param(state, &PARAM_SPEED);
		} else if (chosen == objects.obj45) {
			gauge_load_param(state, &PARAM_LOAD);
		} else if (chosen == objects.obj46) {
			gauge_load_param(state, &PARAM_COOLANT_TEMP);
		} else if (chosen == objects.obj47) {
			gauge_load_param(state, &PARAM_BOOST);
		} else if (chosen == objects.obj48) {
			gauge_load_param(state, &PARAM_INTAKE_TEMP);
		} else if (chosen == objects.obj49) {
			gauge_load_param(state, &PARAM_MAF_FLOW_RATE);
		} else if (chosen == objects.obj50) {
			gauge_load_param(state, &PARAM_FUEL_RAIL_PRESSURE);
		}

	}
}

void debug_event_handler(lv_event_t* e) {
	lv_event_code_t code = lv_event_get_code(e);
	lv_indev_t* indev = lv_indev_active();

	if (code == LV_EVENT_PRESSED || code == LV_EVENT_LONG_PRESSED) {
		lv_obj_t* chosen = lv_group_get_focused(debugGroup);

		if (chosen == objects.obj38) {
			load_screen_and_group(objects.menu, indev);
		}
	}
}

void init_groups(void) {
	menuGroup = lv_group_create();
	lv_group_add_obj(menuGroup, objects.obj16);
	lv_group_add_obj(menuGroup, objects.obj18);
	lv_group_add_obj(menuGroup, objects.obj20);
	lv_group_add_obj(menuGroup, objects.obj22);
	lv_group_add_obj(menuGroup, objects.obj24);

	measGroup = lv_group_create();
	lv_group_add_obj(measGroup, objects.obj42);
	lv_group_add_obj(measGroup, objects.obj44);
	lv_group_add_obj(measGroup, objects.obj45);
	lv_group_add_obj(measGroup, objects.obj46);
	lv_group_add_obj(measGroup, objects.obj47);
	lv_group_add_obj(measGroup, objects.obj48);
	lv_group_add_obj(measGroup, objects.obj49);
	lv_group_add_obj(measGroup, objects.obj50);

	debugGroup = lv_group_create();
	lv_group_add_obj(debugGroup, objects.obj34);
	lv_group_add_obj(debugGroup, objects.obj36);
	lv_group_add_obj(debugGroup, objects.obj38);
}

void init_events(GaugeState* state) {
	// measure screen
	lv_obj_add_event_cb(objects.obj42, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.obj44, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.obj45, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.obj46, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.obj47, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.obj48, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.obj49, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.obj50, meas_event_handler, LV_EVENT_ALL, state);

	//menu
	lv_obj_add_event_cb(objects.obj16, menu_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.obj18, menu_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.obj20, menu_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.obj22, menu_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.obj24, menu_event_handler, LV_EVENT_ALL, NULL);

	// debug
	lv_obj_add_event_cb(objects.obj34, debug_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.obj36, debug_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.obj38, debug_event_handler, LV_EVENT_ALL, NULL);
}

void init_buttons(lv_indev_t* indev) {
	lv_indev_set_type(indev, LV_INDEV_TYPE_ENCODER);
	lv_indev_set_read_cb(indev, enc_read);
	init_groups();
	lv_indev_set_group(indev, menuGroup);
}
