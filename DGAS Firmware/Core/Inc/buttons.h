/*
 * buttons.h
 *
 *  Created on: Jan 28, 2025
 *      Author: rhett
 */

#ifndef INC_BUTTONS_H_
#define INC_BUTTONS_H_

#include "gauge.h"
#include "lvgl.h"

#define BTN_NAV GPIO_PIN_14 // port B active low
#define BTN_SEL GPIO_PIN_15 // port B active low

typedef struct {
	GaugeState* state;
	lv_group_t* nextGroup;
	lv_obj_t* nextScreen;
	const GaugeParam* nextParam;
} EventData;

void load_screen_and_group(lv_obj_t* screen, lv_indev_t* indev);
void enc_read(lv_indev_t* indev, lv_indev_data_t* data);
void menu_event_handler(lv_event_t* e);
void meas_event_handler(lv_event_t* e);
void exit_event_handler(lv_event_t* e);
void init_events(GaugeState* state);
void init_groups(void);
void init_buttons(lv_indev_t* indev);

#endif /* INC_BUTTONS_H_ */
