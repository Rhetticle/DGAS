/*
 * iso15765.c
 *
 *  Created on: Feb 5, 2025
 *      Author: rhett
 */

#include <stm32f7xx.h>
#include "iso15765.h"
#include "OBD2.h"

extern CAN_HandleTypeDef hcan1;

static volatile CAN_RxHeaderTypeDef rxHeader;
static uint32_t txMailBox;


HAL_StatusTypeDef can_get_pid(uint8_t pid, uint8_t* response) {
	CAN_TxHeaderTypeDef txHeader;
	uint8_t txData[OBD2_CAN_REQ_SIZE] = {OBD2_CAN_DUMMY_BYTE};
	txData[0] = OBD2_LIVE_MODE;
	txData[1] = pid;

	txHeader.DLC = OBD2_CAN_REQ_SIZE;
	txHeader.StdId = OBD2_CAN_ID;
	txHeader.IDE = CAN_ID_STD;
	txHeader.RTR = CAN_RTR_DATA;

	if (HAL_CAN_AddTxMessage(&hcan1, &txHeader, txData, &txMailBox) != HAL_OK) {
		return HAL_ERROR;
	}
}
