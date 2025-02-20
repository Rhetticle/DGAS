/*
 * ISO9141_KWP.h
 *
 *  Created on: Jan 14, 2025
 *      Author: rhett
 */

#ifndef INC_ISO9141_KWP_H_
#define INC_ISO9141_KWP_H_

#include <stdbool.h>

typedef struct {
	uint8_t synchro;
	uint8_t keyWord1;
	uint8_t keyWord2;
}InitResponse;

// ISO9141 initialisation values and header values

#define ISO9141_ADDRESS 0x33
#define ISO9141_KW1 0x08
#define ISO9141_KW2 0x08
#define ISO9141_HEADER_1 0x68
#define ISO9141_HEADER_2 0x6A
#define ISO9141_HEADER_3 0xF1
#define ISO9141_OBD_PID_REQ_SIZE 6 // 3 header bytes, 1 byte for mode, 1 byte for PID, 1 byte for checksum
#define ISO9141_OBD_DTC_REQ_SIZE 5 // 3 header bytes, 1 mode byte, 1 byte for checksum
#define ISO9141_OBD_MAX_REC_SIZE 10 // 3 preamble bytes, 1 byte for mode, 1 byte for PID, 4 data bytes, 1 checksum byte
#define ISO9141_PID_INDEX 3

// KWP2000 initialisation values and header values

#define KWP_ADDRESS 0x33
#define KWP_HEADER_SIZE 3 // 3 header bytes
#define KWP_PID_HEADER_1 0xC2
#define KWP_DTC_HEADER_1 0xC1
#define KWP_HEADER_2 0x33
#define KWP_HEADER_3 0xF1
#define KWP_OBD_PID_REQ_SIZE 6 // same format as ISO9141
#define KWP_OBD_DTC_REQ_SIZE 5 // same format as ISO9141
#define KWP_DATA_SIZE_MASK 0b111111 // mask to apply to format byte to extract data size of message
#define KWP_DATA_START_INDEX 4 // 5th byte (counting from zero) of response will be first data byte
#define KWP_PID_INDEX 3
#define KWP_DTC_HEADER_SIZE 2 // one byte is the mode and the other is the number of DTCs to follow

#define ISO9141_K GPIO_PIN_10 // port C. This is also UART4_TX
#define ISO9141_L GPIO_PIN_10 // port A

// initialisation timing parameters (ms)
#define W1_TIMEOUT_MAX 300
#define W2_TIMEOUT_MAX 20
#define W3_TIMEOUT_MAX 20
#define W4_TIMEOUT_MAX 50

#define INTERBYTE_DELAY 5 // (ms)
#define RESPONSE_WAIT 30 //(ms)
#define GENERAL_DELAY 100 //(ms)

/////////////////////////// OBD2 Related constants //////////////////////////////////////////////
#define OBD2_RESPONSE_WAIT_MAX 1000 // (ms)


HAL_StatusTypeDef iso9141_kwp_five_baud(void);
void init_tx_gpio(void);
void iso9141_kwp_uart_init(void);
HAL_StatusTypeDef iso9141_kwp_send_data(uint8_t* data, uint32_t size);
HAL_StatusTypeDef kwp_get_response(uint8_t* data, uint32_t size, uint32_t timeout);
uint8_t iso9141_get_response(uint8_t* data);
HAL_StatusTypeDef kwp_get_format_byte(uint8_t* fByte);
HAL_StatusTypeDef iso9141_init(void);
HAL_StatusTypeDef kwp_init(void);
HAL_StatusTypeDef iso9141_kwp_get_init_response(InitResponse* response);
HAL_StatusTypeDef iso9141_kwp_listen(bool check_key_words);
HAL_StatusTypeDef iso9141_get_pid(uint8_t pid, uint8_t* response);
HAL_StatusTypeDef iso9141_get_dtcs(uint8_t* response);
HAL_StatusTypeDef iso9141_clear_dtcs(void);
HAL_StatusTypeDef kwp_get_pid(uint8_t pid, uint8_t* response);
HAL_StatusTypeDef kwp_get_dtcs(uint8_t* response);
HAL_StatusTypeDef kwp_clear_dtcs(void);
uint8_t iso9141_kwp_checksum(uint8_t* data, uint32_t size);
#endif /* INC_ISO9141_KWP_H_ */
