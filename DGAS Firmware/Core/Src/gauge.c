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

static volatile uint32_t adcRaw;


const GaugeParam PARAM_RPM = {.min = 0, .max = 4200, .units = "RPM", .name = "#FF0000 ENGINE SPEED#", .color = 0xffff0000, .measure = obd2_get_rpm};
const GaugeParam PARAM_SPEED = {.min = 0, .max = 120, .units = "km/h", .name = "#00FFFF VEHICLE SPEED#", .color = 0xff00ffff, .measure = obd2_get_vehicle_speed};
const GaugeParam PARAM_LOAD = {.min = 0, .max = 100, .units = "%", .name = "#04FF40 ENGINE LOAD#", .color = 0xff04ff40, .measure = obd2_get_engine_load};
const GaugeParam PARAM_COOLANT_TEMP = {.min = 0, .max = 120, .units = "\u00B0 C", .name = "#2196f3 COOLANT TEMP#", .color = 0xff2196f3, .measure = obd2_get_coolant_temp};
const GaugeParam PARAM_BOOST = {.min = 0, .max = 60, .units = "PSI", .name = "#f600b0 BOOST#", .color = 0xfff600b0, .measure = obd2_get_boost};
const GaugeParam PARAM_INTAKE_TEMP = {.min = 0, .max = 60, .units = "\u00B0 C", .name = "#f6f200 INTAKE TEMP#", .color = 0xfff6f200, .measure = obd2_get_intake_temp};
const GaugeParam PARAM_MAF_FLOW_RATE = {.min = 0, .max = 120, .units = "gram/s", .name = "#6021f3 MAF FLOW RATE#", .color = 0xff6021f3, .measure = obd2_get_maf_flow_rate};
const GaugeParam PARAM_FUEL_RAIL_PRESSURE = {.min = 0, .max = 60, .units = "kPSI", .name = "#f3a521 FUEL PRESSURE#", .color = 0xfff3a521, .measure = obd2_get_fuel_pressure};

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
	if (hadc == &hadc1) {
		adcRaw = HAL_ADC_GetValue(hadc);
	}
}

void adjust_scale_labels(const GaugeParam* param, lv_obj_t** scaleLabels) {
	uint16_t step = (param->max - param->min) / (GAUGE_TICK_COUNT - 1);

	for (int i = 0; i < 7; i++) {
		char label[PARAM_MEAS_MAX_LEN];
		sprintf(label, "%d", param->min + i * step);
		lv_label_set_text(scaleLabels[i], label);
	}
}

void gauge_load_param(GaugeState* state, const GaugeParam* param) {
	lv_obj_t* scaleLabels[] = {objects.obj6, objects.obj7, objects.obj8, objects.obj9, objects.obj10, objects.obj11, objects.obj12};
	state->param = param;
	state->max = 0;

	lv_arc_set_range(objects.obj0, param->min, param->max);
	lv_scale_set_range(objects.obj1, param->min, param->max);
	lv_label_set_text(objects.obj5, param->name);
	lv_label_set_text(objects.obj14, param->units);

    lv_obj_set_style_arc_color(objects.obj0, lv_color_hex(param->color), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(objects.obj2, lv_color_hex(param->color), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(objects.obj13, lv_color_hex(param->color), LV_PART_MAIN | LV_STATE_DEFAULT);

    adjust_scale_labels(param, scaleLabels);
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
	char volt[PARAM_MEAS_MAX_LEN + 1];
	sprintf(volt, "%.1fV", ADC_TO_VOLTAGE(adcRaw));
	lv_label_set_text(objects.obj4, volt);
	HAL_ADC_Start_IT(&hadc1);
}
