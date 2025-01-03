/*
 * LIS3DH.c
 *
 *  Created on: 30 Dec. 2024
 *      Author: rhett
 */


/* Low level driver for STMicroelectronics LIS3DH accelerometers */
#include "stm32f7xx.h"
#include "LIS3DH.h"

extern I2C_HandleTypeDef hi2c4;

HAL_StatusTypeDef accel_init(void) {
		uint8_t ctr1Data = 1 << ODR1 | 1 << ODR2 | 1 << ODR3; // all axes enabled, 400Hz sample rate
		uint8_t whoAmI;

		// we will check the whoami register first just to verify the connection is working
		if (HAL_I2C_Mem_Read(&hi2c4, ACC_I2C_ADDR, WHO_AM_I_REG, sizeof(uint8_t), &whoAmI, sizeof(uint8_t), 100) != HAL_OK ||
				whoAmI != WHO_AM_I) {
			return HAL_ERROR;
		}

		if (HAL_I2C_Master_Transmit(&hi2c4, ACC_I2C_ADDR, &ctr1Data, sizeof(uint8_t), 100) != HAL_OK) {
			return HAL_ERROR;
		}
		uint8_t ctr4Data = 1 << FS1 | 1 << FS0; // make measurement range +/- 16g

		if (HAL_I2C_Master_Transmit(&hi2c4, ACC_I2C_ADDR, &ctr4Data, sizeof(uint8_t), 100) != HAL_OK) {
			return HAL_ERROR;
		}

		return HAL_OK;
}

HAL_StatusTypeDef accel_read_reg(uint8_t* data, uint16_t regAddr) {
	if (HAL_I2C_Mem_Read(&hi2c4, ACC_I2C_ADDR, regAddr, sizeof(uint8_t), data, sizeof(uint8_t), 100) != HAL_OK) {
		return HAL_ERROR;
	}
	return HAL_OK;
}

HAL_StatusTypeDef accel_read_data(uint8_t* data) {
	int8_t accBytes[ACC_BYTES_NO];
	int16_t xAcc, yAcc, zAcc;

	// loop through and read all 6 bytes of acceleration data
	for (int i = 0; i < sizeof(accBytes); i++) {
		if (HAL_I2C_Mem_Read(&hi2c4, ACC_I2C_ADDR, ACC_DATA_START_ADDR + i, sizeof(uint8_t), (uint8_t*) &accBytes[i], sizeof(int8_t), 10) != HAL_OK) {
			return HAL_ERROR;
		}
	}

	xAcc = ((int16_t)accBytes[1] << 8) | accBytes[0];
	yAcc = ((int16_t)accBytes[3] << 8) | accBytes[2];
	zAcc = ((int16_t)accBytes[5] << 8) | accBytes[4];

	data[0] = xAcc;
	data[1] = yAcc;
	data[2] = zAcc;

	return HAL_OK;
}
