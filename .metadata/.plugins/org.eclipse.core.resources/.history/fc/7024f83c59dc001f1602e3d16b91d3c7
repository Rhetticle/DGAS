/*
 * ISO9141_KWP.c
 *
 *  Created on: Jan 14, 2025
 *      Author: rhett
 */
#include <stm32f7xx.h>
#include "ISO9141_KWP.h"
#include "OBD2.h"
#include "OBD_Debug.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

extern UART_HandleTypeDef huart4;

/* This driver will support 3 out of 4 OBD2 physical layer protocols
	Supported:

		- CAN (Common on newer > 2010 cars)
		- ISO9141
		- ISO14230 (This is very similar to ISO9141 but has a different initialisation sequence,
		 	 	    also referred to as KWP2000)
*/

/* Send the first 5 bit/s sequence to initialise a ISO9141 bus or ISO14230 bus (Both use the same sequence here_
 * Will send 0x33 at 5 baud
 *
 * Return: HAL_OK
 * */
HAL_StatusTypeDef iso9141_kwp_init(void) {
	HAL_GPIO_WritePin(GPIOC, ISO9141_K, 1);
	HAL_GPIO_WritePin(GPIOA, ISO9141_L, 0);
	HAL_Delay(4000); //must be no traffic on bus for 3 seconds after K goes high
	HAL_GPIO_WritePin(GPIOC, ISO9141_K, 0);
	HAL_GPIO_WritePin(GPIOA, ISO9141_L, 1);
	HAL_Delay(205);
	HAL_GPIO_WritePin(GPIOC, ISO9141_K, 1);
	HAL_GPIO_WritePin(GPIOA, ISO9141_L, 0);
	HAL_Delay(405);
	HAL_GPIO_WritePin(GPIOC, ISO9141_K, 0);
	HAL_GPIO_WritePin(GPIOA, ISO9141_L, 1);
	HAL_Delay(405);
	HAL_GPIO_WritePin(GPIOC, ISO9141_K, 1);
	HAL_GPIO_WritePin(GPIOA, ISO9141_L, 0);
	HAL_Delay(405);
	HAL_GPIO_WritePin(GPIOC, ISO9141_K, 0);
	HAL_GPIO_WritePin(GPIOA, ISO9141_L, 1);
	HAL_Delay(405);
	HAL_GPIO_WritePin(GPIOC, ISO9141_K, 1);
	HAL_GPIO_WritePin(GPIOA, ISO9141_L, 0);
	HAL_Delay(205);
	return HAL_OK;
}

/* Get the ECU's response to the 5 baud init. Note that both ISO9141 and ISO14230 bus's are now
 * transmitting at 10400 baud. Both standards specify that the synchronisation byte will be 0x55 however
 * keyword1 and keyword2 will depend on the standard.
 *
 * response: InitResponse struct to store response bytes in
 *
 * Returns: HAL_OK if 3 bytes were received, HAL_ERROR otherwise
 * */
HAL_StatusTypeDef iso9141_kwp_get_init_response(InitResponse* response) {
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

HAL_StatusTypeDef iso9141_kwp_listen(bool check_key_words) {
	InitResponse response;
	uint8_t nKeyword2, nAddress;

	if (iso9141_kwp_get_init_response(&response) != HAL_OK) {
		return HAL_ERROR;
	}

	if (check_key_words) {
		// this is only for ISO9141
		if (response.keyWord1 != response.keyWord2) {
			return HAL_ERROR;
		}
	}
	HAL_Delay(RESPONSE_WAIT);
	nKeyword2 = ~response.keyWord2;

	// send the inversion of keyword 2 as per both specs
	if (iso9141_kwp_send_data(&nKeyword2, sizeof(uint8_t)) != HAL_OK) {
		return HAL_ERROR;
	}
	// We expect the inversion of the initial 5 baud address bytes (0x33) which would be
	// 0xCC
	if (HAL_UART_Receive(&huart4, &nAddress, sizeof(uint8_t), 1000) != HAL_OK) {
		return HAL_ERROR;
	}
	if (nAddress != ~ISO9141_ADDRESS) {
		return HAL_ERROR;
	}
	// The ISO9141/KWP2000 bus is now ready for requests. Note that requests must be sent at least every 5 seconds
	// otherwise the bus will need to be initialised again
	return HAL_OK;
}

HAL_StatusTypeDef iso9141_get_pid(uint8_t mode, uint8_t pid, uint8_t* response) {
	uint8_t message [ISO9141_OBD_REQ_SIZE] = {ISO9141_HEADER_1, ISO9141_HEADER_2, ISO9141_HEADER_3, mode, pid};
	HAL_StatusTypeDef status = HAL_OK;
	uint8_t recTemp [ISO9141_OBD_MAX_REC_SIZE];
	uint8_t bytesRec = 0;
	// add check sum to end of message array
	message[ISO9141_OBD_REQ_SIZE - 1] = iso9141_kwp_checksum(message, sizeof(message) - 1);

	if (iso9141_kwp_send_data(message, sizeof(message)) != HAL_OK) {
		return HAL_ERROR;
	}

	// won't know the response length so we will loop until UART receives fails
	while(status == HAL_OK) {
		status = HAL_UART_Receive(&huart4, &recTemp[bytesRec], sizeof(uint8_t), OBD2_RESPONSE_WAIT_MAX);
		bytesRec++;
	}

	bytesRec--;

	if (bytesRec == 0) {
		// status became HAL_ERROR on first HAL_UART_Receive() call
		return HAL_ERROR;
	}
	uint8_t dataSize = bytesRec - ISO9141_OBD_REQ_SIZE;

	for (int i = 0; i < dataSize; i++) {
		response[i] = recTemp[ISO9141_OBD_REQ_SIZE + i - 1]; // -1 to account for checksum
	}
	return HAL_OK;
}

HAL_StatusTypeDef kwp_get_pid(uint8_t pid, uint8_t* response) {
	uint8_t message[KWP_OBD_REQ_SIZE] = {KWP_HEADER_1, KWP_HEADER_2, KWP_HEADER_3, OBD2_LIVE_MODE, pid};
	uint8_t formatByte;
	// add checksum to end of message array
	message[KWP_OBD_REQ_SIZE - 1] = iso9141_kwp_checksum(message, sizeof(message) - 1);

	if (iso9141_kwp_send_data(message, sizeof(message)) != HAL_OK) {
		return HAL_ERROR;
	}
	/* Example response for vehicle speed (0x0D):
	 *
	 * 0x83 0xF1 0x11 0x41 0x0D 0x0 0xD3
	 *
	 * We see 0x83 & 0b111111 = 3, so 0x41 0x0D 0x00 is our "data" although only 0x00 is useful data here
	 */

	// we will read the format bytes which can be used to determine the remaining bytes that the ECU is about to
	// send
	if (HAL_UART_Receive(&huart4, &formatByte, sizeof(uint8_t), GENERAL_DELAY) != HAL_OK) {
		return HAL_ERROR;
	}
	uint8_t dataSize = formatByte & KWP_DATA_SIZE_MASK;
	uint8_t remain[dataSize + 2 + 1];  // +2 for address bytes echoed back and +1 for checksum

	if (HAL_UART_Receive(&huart4, remain, sizeof(remain), 1000) != HAL_OK) {
		return HAL_ERROR;
	}
	for (int i = 0; i < dataSize - 2; i++) { // -2 because two of the data bytes will be the mode and PID echoed back
		response[i] = remain[i + 4];
	}
	return HAL_OK;
}

uint8_t iso9141_kwp_checksum(uint8_t* data, uint32_t size) {
	uint8_t sum = 0;

	for (int i = 0; i < size; i++) {
		sum += data[i];
	}
	return sum;
}



HAL_StatusTypeDef iso9141_kwp_send_data(uint8_t* data, uint32_t size) {

	for (int i = 0; i < size; i++) {
		uint8_t echo;
		if (HAL_UART_Transmit(&huart4, &data[i], sizeof(uint8_t), 100) != HAL_OK) {
			return HAL_ERROR;
		}
		// the byte we just sent will be echoed back since it's all on the K-Line so we will read it back
		if (HAL_UART_Receive(&huart4, &echo, sizeof(uint8_t), 100) != HAL_OK) {
			return HAL_ERROR;
		}
		HAL_Delay(INTERBYTE_DELAY); // must wait 5ms between bytes according to spec
	}
	return HAL_OK;
}

/*
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
*/
