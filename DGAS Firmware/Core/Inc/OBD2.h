/*
 * OBD2.h
 *
 *  Created on: Jan 11, 2025
 *      Author: rhett
 */

#ifndef INC_OBD2_H_
#define INC_OBD2_H_

#include <stdbool.h>

typedef enum {
	OBD_INIT,
	OBD_LIVE,
	OBD_TIMEOUT,
} OBDBus_StatusTypeDef;

typedef struct {
	OBDBus_StatusTypeDef status;
	HAL_StatusTypeDef (*init_bus)(void);
	HAL_StatusTypeDef (*get_pid)(uint8_t, uint8_t*);
}OBDBus;

#define DBG_MSG_MAX_SIZE 256

#define OBD2_DATA_MAX 4 // maximum of four bytes sent in OBD2 response

#define OBD2_MODE_LIVE 0x01

#define OBD2_PID_SUPPORTED_PIDS 0x00
#define OBD2_PID_RPM 0x0C
#define OBD2_PID_SPEED 0x0D

HAL_StatusTypeDef obd2_get_rpm(OBDBus* bus, uint16_t* rpm);
#endif /* INC_OBD2_H_ */
