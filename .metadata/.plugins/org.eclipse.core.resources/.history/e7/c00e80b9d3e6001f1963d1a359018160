/*
 * selftest.h
 *
 *  Created on: Feb 9, 2025
 *      Author: rhett
 */

#ifndef INC_SELFTEST_H_
#define INC_SELFTEST_H_

#include <stm32f7xx.h>
#include <stdbool.h>
#include "LIS3DH.h"

#define SDRAM_START_ADDR 0xC0000000
#define SDRAM_SIZE 0x200000
#define SDRAM_TEST_ADDR 0xC0070800 // SDRAM_START_ADDR + size of frame buffer
#define SDRAM_WRITE_TEST_WORD 0xBEEF

#define FLASH_SIZE

typedef struct {
	uint32_t readFailAddr;
	uint32_t writeFailAddr;
	uint16_t readBack;
}MemoryTestDesc;

typedef struct {
	uint8_t whoAmI;
	float acceleration[ACC_AXIS_COUNT];
} AccTestDesc;

typedef struct {
	MemoryTestDesc* dramTest;
	AccTestDesc* accTest;
	MemoryTestDesc* flashTest;
	bool obdOk;
	float vbat;
} SelfTestReport;

HAL_StatusTypeDef dram_test(MemoryTestDesc* desc);
HAL_StatusTypeDef accelerometer_test(AccTestDesc* desc);
HAL_StatusTypeDef flash_test(MemoryTestDesc* desc);
void display_test_report(SelfTestReport* report);
void dgas_self_test(void);

#endif /* INC_SELFTEST_H_ */
