/*
 * gauge.h
 *
 *  Created on: Jan 26, 2025
 *      Author: rhett
 */

#ifndef INC_GAUGE_H_
#define INC_GAUGE_H_

#include <stm32f7xx.h>
#include <stdint.h>
#include "OBD2.h"
#include "lvgl.h"

typedef struct {
	uint32_t min;
	uint32_t max;
	char* units;
	char* name;
	uint32_t color;
	HAL_StatusTypeDef (*measure) (OBDBus*, uint16_t*);
} GaugeParam;

typedef struct {
	OBDBus* bus;
	const GaugeParam* param;
	uint32_t max;
	float vBat;
} GaugeState;

typedef enum {
	PARAM_ID_RPM,
	PARAM_ID_SPEED,
	PARAM_ID_LOAD,
	PARAM_ID_COOLANT_TEMP,
	PARAM_ID_BOOST,
	PARAM_ID_INTAKE_TEMP,
	PARAM_ID_MAF,
	PARAM_ID_FUEL_PRESSURE
} ParamID;

// config struct for gauge, will be stored in external flash and modifiable through settings
typedef struct {
	ParamID paramId;
	BusID busId;
} GaugeConfig;

extern const GaugeParam PARAM_RPM, PARAM_SPEED, PARAM_LOAD, PARAM_COOLANT_TEMP, PARAM_BOOST, PARAM_INTAKE_TEMP,
						PARAM_MAF_FLOW_RATE, PARAM_FUEL_RAIL_PRESSURE;


#define PARAM_MEAS_MAX_LEN 4 // maximum characters to be used to display a parameter measurement
#define GAUGE_TICK_COUNT 7 // 7 ticks along scale on gauge
#define ADC_TO_VOLTAGE(x) (((float)x /4096) * 15)
#define GAUGE_CONFIG_FLASH_ADDR 0x3FFFF0

void adjust_scale_labels(const GaugeParam* param, lv_obj_t** scaleLabels);
void gauge_load_param(GaugeState* state, const GaugeParam* param);
void gauge_update(GaugeState* state, uint32_t measured);
const GaugeParam* get_param_from_id(ParamID id);
void save_gauge_config(void);
void update_dropdown_selection(GaugeConfig* config);
HAL_StatusTypeDef read_gauge_config(GaugeState* state);
HAL_StatusTypeDef gauge_init(GaugeState* state, OBDBus* bus);

#endif /* INC_GAUGE_H_ */
