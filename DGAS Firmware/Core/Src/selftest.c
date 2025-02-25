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
#include "ui.h"
#include "lvgl.h"
#include <stdio.h>
#include <math.h>

extern SDRAM_HandleTypeDef hsdram1;
extern lv_display_t* display;

HAL_StatusTypeDef dram_test(MemoryTestDesc* desc) {
	// we should not use pointers here as if DRAM is not ok we will segfault (go to hard fault handler)
	uint16_t readTest;
	uint32_t testTick = HAL_GetTick();
	uint32_t readTick = HAL_GetTick();
	// test we can read entire memory array
	for (uint32_t i = 0; i < SDRAM_SIZE; i++) {
		if (HAL_SDRAM_Read_16b(&hsdram1, &i, &readTest, sizeof(uint16_t)) != HAL_OK) {
			desc->readFailAddr = i + SDRAM_START_ADDR;
			return HAL_OK;
		}
	}
	desc->readTime = HAL_GetTick() - readTick;

	uint16_t writeTest = SDRAM_WRITE_TEST_WORD;
	uint32_t testAddr = SDRAM_TEST_ADDR - SDRAM_START_ADDR;
	// test we can write and then read what was written (
	if (HAL_SDRAM_Write_16b(&hsdram1, &testAddr, &writeTest, sizeof(uint16_t)) != HAL_OK) {
		desc->writeFailAddr = SDRAM_TEST_ADDR;
		return HAL_ERROR;
	}
	uint16_t readBack = 0;

	if (HAL_SDRAM_Read_16b(&hsdram1, &testAddr, &readBack, sizeof(uint16_t)) != HAL_OK) {
		desc->readFailAddr = SDRAM_TEST_ADDR;
		return HAL_ERROR;
	}
	desc->readBack = readBack;
	desc->readBackExpect = SDRAM_WRITE_TEST_WORD;
	desc->testTime = HAL_GetTick() - testTick;
	desc->speed = (SDRAM_SIZE / ((float) desc->readTime / 1000)) / pow(2, 20);
	desc->usedSize = (2 * 480 * 480 * 2);
	return HAL_OK;
}

HAL_StatusTypeDef accelerometer_test(AccTestDesc* desc) {

	if ((accel_read_reg(&desc->whoAmI, WHO_AM_I_REG) != HAL_OK) || (desc->whoAmI != WHO_AM_I)) {
		return HAL_ERROR;
	}
	if (accel_read_data(desc->acceleration) != HAL_OK) {
		desc->accMeasureOk = false;
		return HAL_ERROR;
	}
	desc->accMeasureOk = true;
	return HAL_OK;
}

// need to remove optimisation for this function, for some reason gcc optimises out the return value of
// CSP_QSPI_Read()...
HAL_StatusTypeDef __attribute__((optimize(0))) flash_test(MemoryTestDesc* desc) {
	uint32_t testTick = HAL_GetTick();
	uint32_t readTick = HAL_GetTick();
	uint8_t readTest[MEMORY_SECTOR_SIZE];
	uint32_t usedSectorCount = 0;

	CSP_QSPI_DisableMemoryMappedMode();

	for (int i = 0; i < MEMORY_FLASH_SIZE / MEMORY_SECTOR_SIZE; i++) {
		if (CSP_QSPI_Read(readTest, i * MEMORY_SECTOR_SIZE, MEMORY_SECTOR_SIZE) != HAL_OK) {
			desc->readFailAddr = i;
			return HAL_ERROR;
		}
		if (readTest[0] != 0xFF) {
			usedSectorCount++;
		}
	}
	desc->readTime = HAL_GetTick() - readTick;
	uint8_t testByte = FLASH_WRITE_TEST_BYTE;
	uint8_t readBack = 0;

	if (CSP_QSPI_WriteMemory(&testByte, FLASH_WRITE_TEST_ADDR, sizeof(uint8_t)) != HAL_OK) {
		desc->writeFailAddr = FLASH_WRITE_TEST_ADDR;
		return HAL_ERROR;
	}
	if (CSP_QSPI_Read(&readBack, FLASH_WRITE_TEST_ADDR, sizeof(uint8_t)) != HAL_OK) {
		desc->readFailAddr = FLASH_WRITE_TEST_ADDR;
		return HAL_ERROR;
	}
	desc->readBack = readBack;
	desc->readBackExpect = FLASH_WRITE_TEST_BYTE;
	desc->testTime = HAL_GetTick() - testTick;
	desc->speed = (MEMORY_FLASH_SIZE / ((float) desc->readTime / 1000)) / pow(2, 20);
	desc->usedSize = usedSectorCount * MEMORY_SECTOR_SIZE;
	CSP_QSPI_EnableMemoryMappedModeDynamic();
	return HAL_OK;
}

void display_memory_device_statistics(MemoryTestDesc* desc, lv_obj_t* textArea) {
	char statistic[DEVICE_STATISTIC_MSG_MAX];

	sprintf(statistic, "Read Time: %ldms\n", desc->readTime);
	lv_textarea_add_text(textArea, statistic);

	sprintf(statistic, "Speed: %ldMiB/s\n", desc->speed);
	lv_textarea_add_text(textArea, statistic);

	sprintf(statistic, "Used: %.1fKiB\n", desc->usedSize / pow(2, 10));
	lv_textarea_add_text(textArea, statistic);

	sprintf(statistic, "Test Time: %ldms\n", desc->testTime);
	lv_textarea_add_text(textArea, statistic);
}

void display_accelerometer_statistics(AccTestDesc* desc) {
	char statistic[DEVICE_STATISTIC_MSG_MAX];

	sprintf(statistic, "WhoAmI: 0x%X\n", desc->whoAmI);
	lv_textarea_add_text(objects.self_test_accel_textarea, statistic);

	sprintf(statistic, "X-Axis: %.1f g\n", desc->acceleration[0]);
	lv_textarea_add_text(objects.self_test_accel_textarea, statistic);
	sprintf(statistic, "Y-Axis: %.1f g\n", desc->acceleration[1]);
	lv_textarea_add_text(objects.self_test_accel_textarea, statistic);
	sprintf(statistic, "Z-Axis: %.1f g\n", desc->acceleration[2]);
	lv_textarea_add_text(objects.self_test_accel_textarea, statistic);
}

void display_memory_device_test_report(MemoryTestDesc* desc, lv_obj_t* textArea) {
	if ((desc->readFailAddr == 0) && (desc->writeFailAddr == 0) && (desc->readBack == desc->readBackExpect)) {
		lv_textarea_add_text(textArea, "#00FF00 PASS#\n");
		display_memory_device_statistics(desc, textArea);
		return;
	}
	char errorMsg[DEVICE_REPORT_MSG_MAX];
	lv_textarea_add_text(textArea, "#FF0000 ERROR#\n");

	if (desc->readFailAddr != 0) {
		sprintf(errorMsg, "Read failure at 0x%lX\n", desc->readFailAddr);
		lv_textarea_add_text(textArea, errorMsg);
	}
	if (desc->writeFailAddr != 0) {
		sprintf(errorMsg, "Write failure at 0x%lX\n", desc->writeFailAddr);
		lv_textarea_add_text(textArea, errorMsg);
	}
	if (desc->readBack != desc->readBackExpect) {
		sprintf(errorMsg, "Read back failure, got #FF0000 0x%X# expected #00FF00 0x%X#\n",
				desc->readBack, desc->readBackExpect);
		lv_textarea_add_text(textArea, errorMsg);
	}
}

void display_accelerometer_test_report(AccTestDesc* desc) {
	if ((desc->whoAmI == WHO_AM_I) && (desc->accMeasureOk)) {
		lv_textarea_add_text(objects.self_test_accel_textarea, "#00FF00 PASS#\n");
		display_accelerometer_statistics(desc);
		return;
	}
	char errorMsg[DEVICE_REPORT_MSG_MAX];
	lv_textarea_add_text(objects.self_test_accel_textarea, "#FF0000 \uf00d#\n");

	if (desc->whoAmI != WHO_AM_I) {
		sprintf(errorMsg, "WhoAmI register value wrong, got 0x%X expected 0x%X\n", desc->whoAmI, WHO_AM_I);
		lv_textarea_add_text(objects.self_test_accel_textarea, errorMsg);
	}
	if (!desc->accMeasureOk) {
		sprintf(errorMsg, "Failed to read acceleration data\n");
		lv_textarea_add_text(objects.self_test_accel_textarea, errorMsg);
	}
}

void display_test_report(SelfTestReport* report) {
	display_memory_device_test_report(report->dramTest, objects.self_test_dram_textarea);
	display_memory_device_test_report(report->flashTest, objects.self_test_flash_textarea);
	display_accelerometer_test_report(report->accTest);
	return;
}

void hide_report_objects(void) {
	lv_obj_add_flag(objects.self_test_accel_icon, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(objects.self_test_accel_label, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(objects.self_test_accel_textarea, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(objects.self_test_dram_icon, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(objects.self_test_dram_label, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(objects.self_test_dram_textarea, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(objects.self_test_flash_icon, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(objects.self_test_flash_label, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(objects.self_test_flash_textarea, LV_OBJ_FLAG_HIDDEN);
}

void show_report_objects(void) {
	lv_obj_clear_flag(objects.self_test_accel_icon, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(objects.self_test_accel_label, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(objects.self_test_accel_textarea, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(objects.self_test_dram_icon, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(objects.self_test_dram_label, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(objects.self_test_dram_textarea, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(objects.self_test_flash_icon, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(objects.self_test_flash_label, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(objects.self_test_flash_textarea, LV_OBJ_FLAG_HIDDEN);
}

void clear_report_textareas(void) {
	lv_textarea_set_text(objects.self_test_dram_textarea, "");
	lv_textarea_set_text(objects.self_test_flash_textarea, "");
	lv_textarea_set_text(objects.self_test_accel_textarea, "");
}

void update_progress_bar(uint32_t value) {
	lv_bar_set_value(objects.self_test_progress_bar, value, 0);
	lv_refr_now(display);
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

	update_progress_bar(0);
	dram_test(&dramTest);
	update_progress_bar(33);
	flash_test(&flashTest);
	update_progress_bar(80);
	accelerometer_test(&accTest);
	update_progress_bar(100);

	lv_obj_add_flag(objects.self_test_progress_bar, LV_OBJ_FLAG_HIDDEN);
	show_report_objects();
	clear_report_textareas();
	display_test_report(&report);
}
