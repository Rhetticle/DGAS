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
#include "lvgl.h"

#define SDRAM_START_ADDR 0xC0000000
#define SDRAM_SIZE 0x200000
#define SDRAM_TEST_ADDR 0xC0070800 // SDRAM_START_ADDR + size of frame buffer
#define SDRAM_WRITE_TEST_WORD 0xBEEF

#define FLASH_WRITE_TEST_BYTE 0xEE
#define FLASH_WRITE_TEST_ADDR 0x3FFFFF // last byte in flash memory

#define DEVICE_REPORT_MSG_MAX 100
#define DEVICE_STATISTIC_MSG_MAX 32

typedef struct {
	uint32_t readFailAddr;
	uint32_t writeFailAddr;
	uint16_t readBackExpect;
	uint16_t readBack;
	uint32_t readTime;
	uint32_t testTime;
	uint32_t speed;
	float usedSize;
}MemoryTestDesc;

typedef struct {
	uint8_t whoAmI;
	bool accMeasureOk;
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
void display_memory_device_statistics(MemoryTestDesc* desc, lv_obj_t* textArea);
void display_accelerometer_statistics(AccTestDesc* desc);
void display_memory_device_test_report(MemoryTestDesc* desc, lv_obj_t* textArea);
void display_accelerometer_test_report(AccTestDesc* desc);
void display_test_report(SelfTestReport* report);
void hide_report_objects(void);
void show_report_objects(void);
void clear_report_textareas(void);
void update_progress_bar(uint32_t value);
void dgas_self_test(void);

#endif /* INC_SELFTEST_H_ */
