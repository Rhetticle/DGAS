/*
 * selftest.c
 *
 *  Created on: Feb 9, 2025
 *      Author: rhett
 */

#include <stm32f7xx.h>
#include <string.h>
#include "selftest.h"
#include "LIS3DH.h"
#include "quadspi.h"

extern SDRAM_HandleTypeDef hsdram1;

HAL_StatusTypeDef dram_test(MemoryTestDesc* desc) {
	// we should not use pointers here as if DRAM is not ok we will segfault (go to hard fault handler)
	uint16_t readTest;

	// test we can read entire memory array
	for (uint32_t i = 0; i < SDRAM_SIZE; i++) {
		if (HAL_SDRAM_Read_16b(&hsdram1, (uint32_t*) i, &readTest, sizeof(uint16_t)) != HAL_OK) {
			desc->readFailAddr = i + SDRAM_START_ADDR;
			return HAL_OK;
		}
	}
	uint16_t writeTest = SDRAM_WRITE_TEST_WORD;
	// test we can write and then read what was written (
	if (HAL_SDRAM_Write_16b(&hsdram1, (uint32_t*) SDRAM_TEST_ADDR - SDRAM_START_ADDR, &writeTest, sizeof(uint16_t)) != HAL_OK) {
		desc->writeFailAddr = SDRAM_TEST_ADDR;
		return HAL_ERROR;
	}
	uint16_t readBack = 0;

	if (HAL_SDRAM_Read_16b(&hsdram1, (uint32_t*) SDRAM_TEST_ADDR - SDRAM_START_ADDR, &readBack, sizeof(uint16_t)) != HAL_OK) {
		desc->readFailAddr = SDRAM_TEST_ADDR;
		return HAL_ERROR;
	}
	if (readBack != writeTest) {
		desc->readBack = readBack;
		return HAL_ERROR;
	}
	return HAL_OK;
}

HAL_StatusTypeDef accelerometer_test(AccTestDesc* desc) {
	if ((accel_read_reg(&desc->whoAmI, WHO_AM_I_REG) != HAL_OK) || (desc->whoAmI != WHO_AM_I)) {
		return HAL_ERROR;
	}
	if (accel_read_data(desc->acceleration) != HAL_OK) {
		return HAL_ERROR;
	}
	return HAL_OK;
}

HAL_StatusTypeDef flash_test(MemoryTestDesc* desc) {
	uint8_t readTest;

	for (int i = 0; i < MEMORY_FLASH_SIZE; i++) {
		if (CSP_QSPI_Read(&readTest, i, sizeof(uint8_t)) != HAL_OK) {
			desc->readFailAddr = i;
			return HAL_ERROR;
		}
	}
	return HAL_OK;
}

void display_test_report(SelfTestReport* report) {
	return;
}

// run a self test on peripherals (DRAM, flash, accelerometer)
void dgas_self_test(void) {
	SelfTestReport report;
	MemoryTestDesc dramTest, flashTest;
	AccTestDesc accTest;
	memset(&dramTest, 0, sizeof(MemoryTestDesc));
	memset(&flashTest, 0, sizeof(MemoryTestDesc));

	report.dramTest = &dramTest;
	report.flashTest = &flashTest;
	report.accTest = &accTest;

	dram_test(&dramTest);
	accelerometer_test(&accTest);
	display_test_report(&report);
}
