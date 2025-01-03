/*
 * LIS3DH.h
 *
 *  Created on: 30 Dec. 2024
 *      Author: rhett
 */

#ifndef INC_LIS3DH_H_
#define INC_LIS3DH_H_

#define ACC_I2C_ADDR 0x18 // (0b0011000) since SA0 connected to GND

#define ACC_BYTES_NO 6 // number of acceleration data bytes (2 for each of the 3 axes)
#define WHO_AM_I 0x33 // constant value stored in the WHO_AM_I register
/* Important register addresses*/

// Acceleration output registers
#define OUT_X_L 0x28
#define OUT_X_H 0x29
#define OUT_Y_L 0x2A
#define OUT_Y_H 0x2B
#define OUT_Z_L 0x2C
#define OUT_Z_H 0x2D
#define ACC_DATA_START_ADDR 0x28

// Control regsiters

#define CTRL_REG_0 0x1E
#define CTRL_REG_1 0x20
#define CTRL_REG_2 0x21
#define CTRL_REG_3 0x22
#define CTRL_REG_4 0x23
#define CTRL_REG_5 0x24
#define CTRL_REG_6 0x25

//Status regsiter
#define STATUS_REG 0x27

#define WHO_AM_I_REG 0x0F

// CTRL_REG_1 bit positions

#define ODR0 4
#define ODR1 5
#define ODR2 6
#define ODR3 7

// CTRL_REG_4 bit positions

#define FS1 5
#define FS0 4

HAL_StatusTypeDef accel_init(void);
HAL_StatusTypeDef accel_read_reg(uint8_t* data, uint16_t regAddr);
HAL_StatusTypeDef accel_read_data(uint8_t* data);

#endif /* INC_LIS3DH_H_ */
