/*
 * gauge.c
 *
 *  Created on: Jan 26, 2025
 *      Author: rhett
 */
#include "gauge.h"
#include "ui.h"
#include "lvgl.h"
#include "quadspi.h"
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

	for (int i = 0; i < GAUGE_TICK_COUNT; i++) {
		char label[PARAM_MEAS_MAX_LEN];
		sprintf(label, "%ld", param->min + i * step);
		lv_label_set_text(scaleLabels[i], label);
	}
}

void gauge_load_param(GaugeState* state, const GaugeParam* param) {
	lv_obj_t* scaleLabels[] = {objects.gauge_tick_0, objects.gauge_tick_1, objects.gauge_tick_2,
			objects.gauge_tick_3, objects.gauge_tick_4, objects.gauge_tick_5, objects.gauge_tick_6};
	state->param = param;
	state->max = 0;

	lv_arc_set_range(objects.gauge_arc, param->min, param->max);
	lv_scale_set_range(objects.gauge_scale, param->min, param->max);
	lv_label_set_text(objects.parameter_label, param->name);
	lv_label_set_text(objects.param_units_label, param->units);

    lv_obj_set_style_arc_color(objects.gauge_arc, lv_color_hex(param->color), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(objects.param_val, lv_color_hex(param->color), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(objects.parameter_label, lv_color_hex(param->color), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(objects.param_max_label, lv_color_hex(param->color), LV_PART_MAIN | LV_STATE_DEFAULT);

    adjust_scale_labels(param, scaleLabels);
}

void gauge_update(GaugeState* state, uint32_t measured) {
	lv_arc_set_value(objects.gauge_arc, measured);
	char val[PARAM_MEAS_MAX_LEN];
	sprintf(val, "%ld", measured);
	lv_label_set_text(objects.param_val, val);

	if (measured > state->max) {
		state->max = measured;
		lv_label_set_text(objects.param_max_label, val);
	}
	char volt[PARAM_MEAS_MAX_LEN + 1];
	sprintf(volt, "%.1fV", ADC_TO_VOLTAGE(adcRaw));
	lv_label_set_text(objects.vbat_label, volt);
	HAL_ADC_Start_IT(&hadc1);
}

const GaugeParam* get_param_from_id(ParamID id) {
	switch(id) {
		case PARAM_ID_RPM:
			return &PARAM_RPM;
		case PARAM_ID_SPEED:
			return &PARAM_SPEED;
		case PARAM_ID_LOAD:
			return &PARAM_LOAD;
		case PARAM_ID_COOLANT_TEMP:
			return &PARAM_COOLANT_TEMP;
		case PARAM_ID_BOOST:
			return &PARAM_BOOST;
		case PARAM_ID_INTAKE_TEMP:
			return &PARAM_INTAKE_TEMP;
		case PARAM_ID_MAF:
			return &PARAM_MAF_FLOW_RATE;
		case PARAM_ID_FUEL_PRESSURE:
			return &PARAM_FUEL_RAIL_PRESSURE;
	}
	// shouldn't get here
	return NULL;
}

void save_gauge_config(void) {
	GaugeConfig config;

	ParamID paramSelected = (ParamID) lv_dropdown_get_selected(objects.settings_param_dropdown);
	BusID busSelected = (BusID) lv_dropdown_get_selected(objects.settings_bus_dropdown);

	config.paramId = paramSelected;
	config.busId = busSelected;

	CSP_QSPI_DisableMemoryMappedMode();
	CSP_QSPI_EraseSector(GAUGE_CONFIG_FLASH_ADDR, GAUGE_CONFIG_FLASH_ADDR + 3);
	CSP_QSPI_WriteMemory((uint8_t*) &config, GAUGE_CONFIG_FLASH_ADDR, sizeof(GaugeConfig));
	CSP_QSPI_EnableMemoryMappedModeDynamic();
}

void update_dropdown_selection(GaugeConfig* config) {
	lv_dropdown_set_selected(objects.settings_param_dropdown, config->paramId, 0);
	lv_dropdown_set_selected(objects.settings_bus_dropdown, config->busId, 0);
}

HAL_StatusTypeDef read_gauge_config(GaugeState* state) {
	GaugeConfig config;
	HAL_StatusTypeDef configStatus;
	// we could use pointers here to read config since flash is memory mapped but if flash is faulty
	// we will segfault so use CSP functions instead
	CSP_QSPI_DisableMemoryMappedMode();
	configStatus = CSP_QSPI_Read((uint8_t*) &config, GAUGE_CONFIG_FLASH_ADDR, sizeof(GaugeConfig));
	CSP_QSPI_EnableMemoryMappedModeDynamic();

	if (((uint8_t) config.paramId == 0xFF) || (configStatus != HAL_OK)) {
		// no saved configuration so default to rpm
		gauge_load_param(state, &PARAM_RPM);
	} else {
		const GaugeParam* param = get_param_from_id(config.paramId);
		gauge_load_param(state, param);
	}

	if (((uint8_t) config.busId == 0xFF) || (config.busId == BUS_ID_AUTO) || (configStatus != HAL_OK)) {
		if (obd2_bus_auto_detect(state->bus) != HAL_OK) {
			// couldn't connect with any supported bus
			return HAL_ERROR;
		}
	} else {
		init_bus_struct_from_id(state->bus, config.busId);
	}
	update_dropdown_selection(&config);
	return HAL_OK;

}

HAL_StatusTypeDef gauge_init(GaugeState* state, OBDBus* bus) {
	state->bus = bus;
	state->max = 0;
	state->vBat = 0;

	if (read_gauge_config(state) != HAL_OK) {
		// only get here if we couldn't connect to an OBD bus
		return HAL_ERROR;

	}
	if (state->bus->id != BUS_ID_AUTO) {
		// need to check that bus wasn't auto-detected because if it was then it has already
		// been initialised
		if (state->bus->init_bus() != HAL_OK) {
			// bus init failed
			return HAL_ERROR;
		}
	}
	state->bus->status = OBD_LIVE;
	return HAL_OK;
}
