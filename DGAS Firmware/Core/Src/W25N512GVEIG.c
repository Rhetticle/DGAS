/*
 * W25N512GVEIG.c
 *
 *  Created on: 30 Dec. 2024
 *      Author: rhett
 */

#include "stm32f7xx.h"
#include "W25N512GVEIG.h"
#include <string.h>

extern QSPI_HandleTypeDef hqspi;

HAL_StatusTypeDef flash_get_id(uint8_t* devId) {

	QSPI_CommandTypeDef com;

	memset(&com, 0, sizeof(QSPI_CommandTypeDef));

	// initialise command struct with necessary data
	com.Instruction = GET_ID;
	com.InstructionMode = QSPI_INSTRUCTION_1_LINE;
	com.DummyCycles = 8;
	com.NbData = sizeof(uint8_t);

	if (HAL_QSPI_Command(&hqspi, &com, 100) != HAL_OK) {
		return HAL_ERROR;
	}

	if (HAL_QSPI_Receive(&hqspi, devId, 100) != HAL_OK) {
		return HAL_ERROR;
	}
	return HAL_OK;
}
HAL_StatusTypeDef flash_read_reg(uint8_t regAddr, uint8_t* value) {
	return HAL_OK;
}

HAL_StatusTypeDef flash_write_reg(uint8_t regAddr, uint8_t value) {
	return HAL_OK;
}

HAL_StatusTypeDef flash_write(uint32_t addr, uint8_t* data, uint32_t size) {
	return HAL_OK;
}

HAL_StatusTypeDef flash_read(uint32_t addr, uint8_t* data, uint32_t size) {
	return HAL_OK;
}
