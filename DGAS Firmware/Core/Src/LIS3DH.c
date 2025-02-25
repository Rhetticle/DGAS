/*
 * LIS3DH.c
 *
 *  Created on: 30 Dec. 2024
 *      Author: rhett
 */


/* Low level driver for STMicroelectronics LIS3DH accelerometers */
#include "stm32f7xx.h"
#include "LIS3DH.h"
#include "math.h"
#include <stdio.h>

extern I2C_HandleTypeDef hi2c4;

HAL_StatusTypeDef accel_init(void) {
		uint8_t ctr1Data = 1 << ODR2 | 1 << ODR1 | 1 << ODR0 | 1 << ZEN | 1 << YEN | 1 << XEN; // all axes enabled, 400Hz sample rate
		uint8_t whoAmI;

		// we will check the whoami register first just to verify the connection is working
		if (HAL_I2C_Mem_Read(&hi2c4, ACC_I2C_ADDR << 1, WHO_AM_I_REG, sizeof(uint8_t), &whoAmI, sizeof(uint8_t), 100) != HAL_OK) {
			return HAL_ERROR;
		}

		if (HAL_I2C_Mem_Write(&hi2c4, ACC_I2C_ADDR << 1, CTRL_REG_1, sizeof(uint8_t), &ctr1Data, sizeof(uint8_t), 100) != HAL_OK) {
			return HAL_ERROR;
		}
		uint8_t ctr4Data = 1 << FS1 | 1 << FS0; // make measurement range +/- 16g

		if (HAL_I2C_Mem_Write(&hi2c4, ACC_I2C_ADDR << 1, CTRL_REG_4, sizeof(uint8_t), &ctr4Data, sizeof(uint8_t), 100) != HAL_OK) {
			return HAL_ERROR;
		}

		return HAL_OK;
}

HAL_StatusTypeDef accel_read_reg(uint8_t* data, uint16_t regAddr) {
	if (HAL_I2C_Mem_Read(&hi2c4, ACC_I2C_ADDR << 1, regAddr, sizeof(uint8_t), data, sizeof(uint8_t), 100) != HAL_OK) {
		return HAL_ERROR;
	}
	return HAL_OK;
}

HAL_StatusTypeDef accel_read_data(float* data) {
	uint8_t accBytes[ACC_BYTES_NO];
	int16_t xAcc, yAcc, zAcc;

	// loop through and read all 6 bytes of acceleration data
	for (int i = 0; i < ACC_BYTES_NO; i++) {
		if (HAL_I2C_Mem_Read(&hi2c4, ACC_I2C_ADDR << 1, ACC_DATA_START_ADDR + i, sizeof(uint8_t), (uint8_t*) &accBytes[i], sizeof(uint8_t), 100) != HAL_OK) {
			return HAL_ERROR;
		}
	}

	xAcc = ((int16_t)accBytes[1]) << 8 |  accBytes[0];
	yAcc = ((int16_t)accBytes[3]) << 8 |  accBytes[2];
	zAcc = ((int16_t)accBytes[5]) << 8 |  accBytes[4];

	xAcc >>= 6;
	yAcc >>= 6;
	zAcc >>= 6;

	data[0] = (float)xAcc * 0.048;
	data[1] = (float)yAcc * 0.048;
	data[2] = (float)zAcc * 0.048;

	return HAL_OK;
}

HAL_StatusTypeDef accel_get_update(AccelData* update) {
	float accData[3];

	if (accel_read_data(accData) != HAL_OK) {
		return HAL_ERROR;
	}
	float accVecMag = sqrt(pow(accData[1], 2) + pow(accData[2], 2));

	if (accVecMag > update->max) {
		update->max = accVecMag;
		sprintf(update->maxStr, "%.2f G", update->max);
	}

	update->xRaw = accData[1];
	update->yRaw = accData[2];
	update->now = accVecMag;
	update->total += accVecMag;
	update->ave = update->total/update->count;
	update->count++;

	sprintf(update->nowStr, "%.2f G", accVecMag);
	sprintf(update->aveStr, "%.2f G", update->ave);
	sprintf(update->xStr, "%.2f G", accData[1]);
	sprintf(update->yStr, "%.2f G", -accData[2]); // negative to account for screen orientation
	return HAL_OK;
}
