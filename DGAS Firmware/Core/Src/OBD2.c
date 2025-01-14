/*
 * OBD2.c
 *
 *  Created on: Jan 11, 2025
 *      Author: rhett
 */

#include <stm32f7xx.h>
#include "OBD2.h"
#include <stdlib.h>
#include <string.h>

extern UART_HandleTypeDef huart4;

HAL_StatusTypeDef iso9141_init(void) {
	HAL_GPIO_WritePin(GPIOC, ISO9141_K, 1);
	HAL_GPIO_WritePin(GPIOG, ISO9141_L, 1);
	HAL_Delay(3000); //must be no traffic on bus for 3 seconds after K goes high
	HAL_GPIO_WritePin(GPIOC, ISO9141_K, 0); // start b
	HAL_GPIO_WritePin(GPIOG, ISO9141_L, 0);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOC, ISO9141_K, 1);
	HAL_GPIO_WritePin(GPIOG, ISO9141_L, 1);
	HAL_Delay(400);
	HAL_GPIO_WritePin(GPIOC, ISO9141_K, 0);
	HAL_GPIO_WritePin(GPIOG, ISO9141_L, 0);
	HAL_Delay(400);
	HAL_GPIO_WritePin(GPIOC, ISO9141_K, 1);
	HAL_GPIO_WritePin(GPIOG, ISO9141_L, 1);
	HAL_Delay(400);
	HAL_GPIO_WritePin(GPIOC, ISO9141_K, 0);
	HAL_GPIO_WritePin(GPIOG, ISO9141_L, 0);
	HAL_Delay(400);
	HAL_GPIO_WritePin(GPIOC, ISO9141_K, 1);
	HAL_GPIO_WritePin(GPIOG, ISO9141_L, 1);
	HAL_Delay(200);
	return HAL_OK;
}

HAL_StatusTypeDef iso9141_get_init_response(InitResponse* response) {
	if (HAL_UART_Receive(&huart4, &response->synchro, sizeof(uint8_t), 2000) != HAL_OK) {
		return HAL_ERROR;
	}
	if (HAL_UART_Receive(&huart4, &response->keyWord1, sizeof(uint8_t), 2000) != HAL_OK) {
		return HAL_ERROR;
	}
	if (HAL_UART_Receive(&huart4, &response->keyWord2, sizeof(uint8_t), 2000) != HAL_OK) {
		return HAL_ERROR;
	}
	return HAL_OK;
}

HAL_StatusTypeDef iso9141_listen(void) {
	InitResponse response;

	if (iso9141_get_init_response(&response) != HAL_OK) {
		return HAL_ERROR;
	}
	//if ((response.keyWord1 != ISO9141_KW1) || (response.keyWord2 != ISO9141_KW2)) {
	//	return HAL_ERROR;
	//}
	HAL_Delay(30);
	uint8_t nKeyWord2 = 0b01110000;
	uint8_t nAddress;

	HAL_UART_Transmit(&huart4, &nKeyWord2, sizeof(uint8_t), 100);
	if (HAL_UART_Receive(&huart4, &nAddress, sizeof(uint8_t), 100) != HAL_OK) {
		return HAL_ERROR;
	}
	if (HAL_UART_Receive(&huart4, &nAddress, sizeof(uint8_t), 100) != HAL_OK) {
		return HAL_ERROR;
	}
	//if (nAddress != ~ISO9141_ADDRESS) {
	//	return HAL_ERROR;
	//}
	/* all ECU responses were as expected, we now need to reconfigure UART4 to not use
	   a parity bit anymore (see ISO9141 spec).
	*/
	// The bus is now ready for OBD2
	return HAL_OK;
}

HAL_StatusTypeDef iso9141_send(uint8_t* data, uint32_t size) {
	uint8_t message [size + 1];
	// calculate checksum and add as part of message
	memcpy(message, data, size);
	uint8_t checksum = iso9141_checksum(data, size);
	message[size] = checksum;
	return kwp_send_data(message, size + 1);
}

uint8_t iso9141_checksum(uint8_t* data, uint32_t size) {
	uint8_t sum = 0;

	for (int i = 0; i < size; i++) {
		sum += data[i];
	}
	return sum;
}

HAL_StatusTypeDef kwp_send_data(uint8_t* data, uint32_t size) {
	for (int i = 0; i < size; i++) {
		uint8_t echo;
		if (HAL_UART_Transmit(&huart4, &data[i], sizeof(uint8_t), 100) != HAL_OK) {
			return HAL_ERROR;
		}
		// the byte we just sent will be echoed back since it's all on the K-Line so we will read it back
		if (HAL_UART_Receive(&huart4, &echo, sizeof(uint8_t), 100) != HAL_OK) {
			return HAL_ERROR;
		}
		HAL_Delay(5); // must wait 5ms between bytes according to spec
	}
	return HAL_OK;
}

HAL_StatusTypeDef obd2_get_parameter(uint8_t parameter, uint32_t* a, uint32_t* b) {
	uint8_t message [5] = {ISO9141_HEADER_1, ISO9141_HEADER_2, ISO9141_HEADER_3, 0x01, parameter};
	uint8_t othermess[] = {0xC2, 0x33, 0xF1, 0x01, parameter};
	uint8_t format;

	if (iso9141_send(othermess, sizeof(othermess)) != HAL_OK) {
		return HAL_ERROR;
	}
	if (HAL_UART_Receive(&huart4, &format, sizeof(uint8_t), 100) != HAL_OK) {
		return HAL_ERROR;
	}
	uint8_t data_len = format & 0b111111;
	uint8_t remain = data_len + 2 + 1;
	uint8_t response[remain];

	if (HAL_UART_Receive(&huart4, response, sizeof(response), 1000) != HAL_OK) {
		return HAL_ERROR;
	}
	*a = response[remain - 3];
	*b = response[remain - 2];
	return HAL_OK;
}
