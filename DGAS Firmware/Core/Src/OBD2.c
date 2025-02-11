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
#include "OBD_Debug.h"
#include "ISO9141_KWP.h"
#include "iso15765.h"
#include "lvgl.h"
#include "ui.h"

HAL_StatusTypeDef obd2_get_pid(OBDBus* bus, uint8_t pid, uint8_t* response) {
	if (bus->get_pid(pid, response) != HAL_OK) {
		return HAL_ERROR;
	}
	return HAL_OK;
}

HAL_StatusTypeDef obd2_get_dtcs(OBDBus* bus, uint8_t* response) {
	if (bus->get_dtcs(response) != HAL_OK) {
		return HAL_ERROR;
	}
	return HAL_OK;
}

HAL_StatusTypeDef obd2_clear_dtcs(OBDBus* bus) {
	if (bus->clear_dtcs() != HAL_OK) {
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

HAL_StatusTypeDef obd2_get_boost(OBDBus* bus, uint16_t* boost) {
	uint8_t response[OBD2_DATA_MAX] = {0};

	if (obd2_get_pid(bus, OBD2_PID_MANIFOLD_PRESSURE, response) != HAL_OK) {
		return HAL_ERROR;
	}
	*boost = CONV_KPA_TO_PSI(response[0]);
	return HAL_OK;
}

HAL_StatusTypeDef obd2_get_fuel_pressure(OBDBus* bus, uint16_t* pressure) {
	uint8_t response[OBD2_DATA_MAX] = {0};

	if (obd2_get_pid(bus, OBD2_PID_FUEL_PRESSURE, response) != HAL_OK) {
		return HAL_ERROR;
	}
	*pressure = CONV_KPA_TO_PSI(10 * (256 * response[0] + response[1])) / 1000;
	return HAL_OK;
}

HAL_StatusTypeDef obd2_get_fuel_pressure_manifold_relative(OBDBus* bus, uint16_t* pressure) {
	uint8_t response[OBD2_DATA_MAX] = {0};

	if (obd2_get_pid(bus, OBD2_PID_FUEL_PRESSURE_MANIFOLD_RELATIVE, response) != HAL_OK) {
		return HAL_ERROR;
	}
	*pressure = CONV_KPA_TO_PSI(0.079 * (256 * response[0] + response[1]));
	return HAL_OK;
}

HAL_StatusTypeDef obd2_dummy_request(OBDBus* bus) {
	uint8_t response[OBD2_DATA_MAX] = {0};

	if (obd2_get_pid(bus, OBD2_PID_SUPPORTED_PIDS, response) != HAL_OK) {
		return HAL_ERROR;
	}
	return HAL_OK;
}

void init_bus_struct_from_id(OBDBus* bus, BusID id) {
	if (id == BUS_ID_KWP) {
		bus->init_bus = kwp_init;
		bus->get_pid = kwp_get_pid;
		bus->get_dtcs = kwp_get_dtcs;
		bus->clear_dtcs = kwp_clear_dtcs;
	} else if (id == BUS_ID_9141) {
		bus->init_bus = iso9141_init;
		bus->get_pid = iso9141_get_pid;
		bus->get_dtcs = iso9141_get_dtcs;
		bus->clear_dtcs = iso9141_clear_dtcs;
	} else if (id == BUS_ID_CAN) {
		bus->init_bus = can_obd2_init;
		bus->get_pid = can_get_pid;
	}
	bus->id = id;
}

HAL_StatusTypeDef obd2_bus_auto_detect(OBDBus* bus) {
	bool foundBus = false;

	// go through and try to each bus to see which, if any, succeed
	if (kwp_init() == HAL_OK) {
		bus->id = BUS_ID_KWP;
		foundBus = true;
	} else if (iso9141_init() == HAL_OK) {
		bus->id = BUS_ID_9141;
		foundBus = true;
	} else if (can_obd2_init() == HAL_OK) {
		bus->id = BUS_ID_CAN;
		foundBus = true;
	}

	if (foundBus) {
		init_bus_struct_from_id(bus, bus->id);
		bus->status = OBD_LIVE;
		return HAL_OK;
	}
	return HAL_ERROR;
}

