/*
 * OBD2.c
 *
 *  Created on: Jan 11, 2025
 *      Author: rhett
 */

#include <stm32f7xx.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "OBD2.h"
#include "lvgl.h"
#include "ui.h"

HAL_StatusTypeDef obd2_get_pid(OBDBus* bus, uint8_t pid, uint8_t* response) {
	if (bus->get_pid(pid, response) != HAL_OK) {
		return HAL_ERROR;
	}
	return HAL_OK;
}

HAL_StatusTypeDef obd2_get_rpm(OBDBus* bus, uint16_t* rpm) {
	uint8_t response[OBD2_DATA_MAX] = {0};

	if (obd2_get_pid(bus, OBD2_PID_RPM, response) != HAL_OK) {
		return HAL_ERROR;
	}
	*rpm = (256*response[0] + response[1]) / 4;
	return HAL_OK;
}

HAL_StatusTypeDef obd2_get_vehicle_speed(OBDBus* bus, uint16_t* speed) {
	uint8_t response[OBD2_DATA_MAX] = {0};

	if (obd2_get_pid(bus, OBD2_PID_VEHICLE_SPEED, response) != HAL_OK) {
		return HAL_ERROR;
	}
	*speed = response[0];
	return HAL_OK;
}

HAL_StatusTypeDef obd2_get_engine_load(OBDBus* bus, uint16_t* load) {
	uint8_t response[OBD2_DATA_MAX] = {0};

	if (obd2_get_pid(bus, OBD2_PID_ENG_LOAD, response) != HAL_OK) {
		return HAL_ERROR;
	}
	*load = response[0]/2.55;
	return HAL_OK;
}

HAL_StatusTypeDef obd2_get_coolant_temp(OBDBus* bus, uint16_t* temp) {
	uint8_t response[OBD2_DATA_MAX] = {0};

	if (obd2_get_pid(bus, OBD2_PID_COOLANT_TEMP, response) != HAL_OK) {
		return HAL_ERROR;
	}
	*temp = response[0] - 40;
	return HAL_OK;
}

HAL_StatusTypeDef obd2_get_throttle_pos(OBDBus* bus, uint16_t* pos) {
	uint8_t response[OBD2_DATA_MAX] = {0};

	if (obd2_get_pid(bus, OBD2_PID_THROTTLE_POS, response) != HAL_OK) {
		return HAL_ERROR;
	}
	*pos = response[0]/2.55;
	return HAL_OK;
}

HAL_StatusTypeDef obd2_get_intake_temp(OBDBus* bus, uint16_t* temp) {
	uint8_t response[OBD2_DATA_MAX] = {0};

	if (obd2_get_pid(bus, OBD2_PID_INTAKE_TEMP, response) != HAL_OK) {
		return HAL_ERROR;
	}
	*temp = response[0] - 40;
	return HAL_OK;
}

HAL_StatusTypeDef obd2_get_maf_flow_rate(OBDBus* bus, uint16_t* flowRate) {
	uint8_t response[OBD2_DATA_MAX] = {0};

	if (obd2_get_pid(bus, OBD2_PID_MAF_FLOW_RATE, response) != HAL_OK) {
		return HAL_ERROR;
	}
	*flowRate = (256*response[0] + response[1]) / 100;
	return HAL_OK;
}

HAL_StatusTypeDef obd2_get_fuel_pressure(OBDBus* bus, uint16_t* pressure) {
	uint8_t response[OBD2_DATA_MAX] = {0};

	if (obd2_get_pid(bus, OBD2_PID_FUEL_PRESSURE, response) != HAL_OK) {
		return HAL_ERROR;
	}
	*pressure = 3 * response[0];
	return HAL_OK;
}
