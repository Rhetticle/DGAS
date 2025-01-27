/*
 * gauge.c
 *
 *  Created on: Jan 26, 2025
 *      Author: rhett
 */
#include "gauge.h"
#include "ui.h"
#include "lvgl.h"
#include <stdio.h>

extern ADC_HandleTypeDef hadc1;

static uint32_t adcRaw;

const GaugeParam PARAM_RPM = {.min = 0, .max = 4200, .step = 700, .units = "RPM", .name = "#FF0000 ENGINE SPEED", .measure = obd2_get_rpm};

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
	adcRaw = HAL_ADC_GetValue(&hadc1);
	//HAL_ADC_Start_IT(&hadc1);
}

void gauge_set_param(GaugeParam* param) {
	return;
}

void gauge_update(GaugeState* state, uint32_t measured) {
	lv_arc_set_value(objects.obj0, measured);
	char val[PARAM_MEAS_MAX_LEN];
	sprintf(val, "%d", measured);
	lv_label_set_text(objects.obj2, val);

	if (measured > state->max) {
		state->max = measured;
		lv_label_set_text(objects.obj13, val);
	}
	float vBat = (adcRaw/4096) * 15;
	char volt[PARAM_MEAS_MAX_LEN + 1];
	sprintf(volt, "%.1fV", vBat);
	lv_label_set_text(objects.obj4, volt);
}
