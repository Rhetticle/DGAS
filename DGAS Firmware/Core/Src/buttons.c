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
#include "selftest.h"
#include <stm32f7xx.h>

static volatile uint8_t navPressed = 0;
static volatile uint32_t lastNavPress;
static volatile uint32_t lastSelRelease;
static lv_group_t* menuGroup;
static lv_group_t* measGroup;
static lv_group_t* debugGroup;
static lv_group_t* DTCGroup;
static lv_group_t* selfTestGroup;
static lv_group_t* settingsGroup;
static lv_group_t* aboutGroup;

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
	} else if (HAL_GetTick() > lastSelRelease + 200){
		data->state = LV_INDEV_STATE_RELEASED;
		lastSelRelease = HAL_GetTick();
	}
}

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
	} else if (screen == objects.diagnose) {
		lv_indev_set_group(indev, DTCGroup);
	} else if (screen == objects.self_test) {
		lv_indev_set_group(indev, selfTestGroup);
	} else if (screen == objects.settings) {
		lv_indev_set_group(indev, settingsGroup);
	} else if (screen == objects.about) {
		lv_indev_set_group(indev, aboutGroup);
	}

	lv_group_t* group = lv_indev_get_group(indev);
	// add this to make sure focus is shown on screen switch
	lv_group_focus_obj(lv_group_get_obj_by_index(group, 0));
}

void menu_event_handler(lv_event_t* e) {
	lv_event_code_t code = lv_event_get_code(e);
	lv_indev_t* indev = lv_indev_active();
	lv_group_t* group = lv_indev_get_group(indev);
	lv_obj_t* focused = lv_group_get_focused(group);

	if (code == LV_EVENT_CLICKED) {
		if (focused == objects.measure_btn) {
			load_screen_and_group(objects.measure, indev);
		} else if (focused == objects.obd2_debug_btn) {
			load_screen_and_group(objects.obd2_debug, indev);
		} else if (focused == objects.about_btn) {
			load_screen_and_group(objects.about, indev);
		} else if (focused == objects.settings_btn) {
			load_screen_and_group(objects.settings, indev);
		} else if (focused == objects.menu_exit_btn) {
			load_screen_and_group(objects.gauge_main_ui, indev);
		} else if (focused == objects.diagnose_btn) {
			load_screen_and_group(objects.diagnose, indev);
		} else if (focused == objects.self_test_btn) {
			load_screen_and_group(objects.self_test, indev);
			lv_label_set_text(lv_textarea_get_label(objects.self_test_textarea), "");
			lv_obj_add_flag(objects.self_test_progress_bar, LV_OBJ_FLAG_HIDDEN);
			lv_obj_remove_flag(objects.self_test_run_btn, LV_OBJ_FLAG_HIDDEN);
		} else if (focused == objects.about_btn) {
			load_screen_and_group(objects.about, indev);
		}
	}
}

void meas_event_handler(lv_event_t* e) {
	lv_event_code_t code = lv_event_get_code(e);
	GaugeState* state = (GaugeState*) lv_event_get_user_data(e);

	if (code == LV_EVENT_CLICKED) {
		lv_screen_load(objects.gauge_main_ui);
		lv_obj_t* chosen = lv_group_get_focused(measGroup);

		if (chosen == objects.eng_speed_btn) {
			gauge_load_param(state, &PARAM_RPM);
		} else if (chosen == objects.vehicle_speed_btn) {
			gauge_load_param(state, &PARAM_SPEED);
		} else if (chosen == objects.eng_load_btn) {
			gauge_load_param(state, &PARAM_LOAD);
		} else if (chosen == objects.coolant_temp_btn) {
			gauge_load_param(state, &PARAM_COOLANT_TEMP);
		} else if (chosen == objects.boost_btn) {
			gauge_load_param(state, &PARAM_BOOST);
		} else if (chosen == objects.intake_temp_btn) {
			gauge_load_param(state, &PARAM_INTAKE_TEMP);
		} else if (chosen == objects.maf_btn) {
			gauge_load_param(state, &PARAM_MAF_FLOW_RATE);
		} else if (chosen == objects.fuel_pressure_btn) {
			gauge_load_param(state, &PARAM_FUEL_RAIL_PRESSURE);
		}
	}
}

void debug_event_handler(lv_event_t* e) {
	lv_event_code_t code = lv_event_get_code(e);
	lv_indev_t* indev = lv_indev_active();

	if (code == LV_EVENT_CLICKED) {
		lv_obj_t* chosen = lv_group_get_focused(debugGroup);

		if (chosen == objects.obd2_exit_btn) {
			load_screen_and_group(objects.menu, indev);
		}
	}
}

void dtc_event_handler(lv_event_t* e) {
	lv_event_code_t code = lv_event_get_code(e);
	lv_indev_t* indev = lv_indev_active();

	if (code == LV_EVENT_CLICKED) {
		return;
	}
}

void self_test_event_handler(lv_event_t* e) {
	lv_event_code_t code = lv_event_get_code(e);

	if (code == LV_EVENT_CLICKED) {
		lv_obj_remove_flag(objects.self_test_progress_bar, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(objects.self_test_run_btn, LV_OBJ_FLAG_HIDDEN);
		dgas_self_test();
	}
}

void single_exit_event_handler(lv_event_t* e) {
	lv_event_code_t code = lv_event_get_code(e);
	lv_indev_t* indev = lv_indev_active();

	if (code == LV_EVENT_CLICKED) {
		load_screen_and_group(objects.menu, indev);
	}
}

void init_groups(void) {
	menuGroup = lv_group_create();
	lv_group_add_obj(menuGroup, objects.measure_btn);
	lv_group_add_obj(menuGroup, objects.obd2_debug_btn);
	lv_group_add_obj(menuGroup, objects.diagnose_btn);
	lv_group_add_obj(menuGroup, objects.self_test_btn);
	lv_group_add_obj(menuGroup, objects.settings_btn);
	lv_group_add_obj(menuGroup, objects.about_btn);
	lv_group_add_obj(menuGroup, objects.menu_exit_btn);

	measGroup = lv_group_create();
	lv_group_add_obj(measGroup, objects.eng_speed_btn);
	lv_group_add_obj(measGroup, objects.vehicle_speed_btn);
	lv_group_add_obj(measGroup, objects.eng_load_btn);
	lv_group_add_obj(measGroup, objects.coolant_temp_btn);
	lv_group_add_obj(measGroup, objects.boost_btn);
	lv_group_add_obj(measGroup, objects.intake_temp_btn);
	lv_group_add_obj(measGroup, objects.maf_btn);
	lv_group_add_obj(measGroup, objects.fuel_pressure_btn);

	debugGroup = lv_group_create();
	lv_group_add_obj(debugGroup, objects.obd2_pause_btn);
	lv_group_add_obj(debugGroup, objects.obd2_resume_btn);
	lv_group_add_obj(debugGroup, objects.obd2_exit_btn);

	//DTC
	DTCGroup = lv_group_create();
	lv_group_add_obj(DTCGroup, objects.diagnose_clear_btn);
	lv_group_add_obj(DTCGroup, objects.diagnose_exit_btn);

	//Self Test
	selfTestGroup = lv_group_create();
	lv_group_add_obj(selfTestGroup, objects.self_test_run_btn);
	lv_group_add_obj(selfTestGroup, objects.self_test_exit_btn);

	// settings
	settingsGroup = lv_group_create();
	lv_group_add_obj(settingsGroup, objects.settings_param_dropdown);
	lv_group_add_obj(settingsGroup, objects.settings_bus_dropdown);
	lv_group_add_obj(settingsGroup, objects.settings_exit_btn);

	//about
	aboutGroup = lv_group_create();
	lv_group_add_obj(aboutGroup, objects.about_exit_btn);

}

void init_events(GaugeState* state) {
	// measure screen
	lv_obj_add_event_cb(objects.eng_speed_btn, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.vehicle_speed_btn, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.eng_load_btn, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.coolant_temp_btn, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.boost_btn, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.intake_temp_btn, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.maf_btn, meas_event_handler, LV_EVENT_ALL, state);
	lv_obj_add_event_cb(objects.fuel_pressure_btn, meas_event_handler, LV_EVENT_ALL, state);

	//menu
	lv_obj_add_event_cb(objects.measure_btn, menu_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.obd2_debug_btn, menu_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.diagnose_btn, menu_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.self_test_btn, menu_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.settings_btn, menu_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.about_btn, menu_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.menu_exit_btn, menu_event_handler, LV_EVENT_ALL, NULL);

	// debug
	lv_obj_add_event_cb(objects.obd2_pause_btn, debug_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.obd2_resume_btn, debug_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.obd2_exit_btn, debug_event_handler, LV_EVENT_ALL, NULL);

	//DTC
	lv_obj_add_event_cb(objects.diagnose_clear_btn, dtc_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.diagnose_exit_btn, single_exit_event_handler, LV_EVENT_ALL, NULL);

	//self test
	lv_obj_add_event_cb(objects.self_test_run_btn, self_test_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(objects.self_test_exit_btn, single_exit_event_handler, LV_EVENT_ALL, NULL);

	//settings
	lv_obj_add_event_cb(objects.settings_exit_btn, single_exit_event_handler, LV_EVENT_ALL, NULL);

	//about
	lv_obj_add_event_cb(objects.about_exit_btn, single_exit_event_handler, LV_EVENT_ALL, NULL);
}

void init_buttons(lv_indev_t* indev) {
	lv_indev_set_type(indev, LV_INDEV_TYPE_ENCODER);
	lv_indev_set_read_cb(indev, enc_read);
	init_groups();
	lv_indev_set_group(indev, menuGroup);
}
