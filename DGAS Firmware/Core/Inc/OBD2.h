/*
 * OBD2.h
 *
 *  Created on: Jan 11, 2025
 *      Author: rhett
 */

#ifndef INC_OBD2_H_
#define INC_OBD2_H_

typedef struct {
	uint8_t synchro;
	uint8_t keyWord1;
	uint8_t keyWord2;
}InitResponse;

typedef struct {
	HAL_StatusTypeDef (*send) (uint8_t* data, uint32_t size);
	HAL_StatusTypeDef (*receive) (uint8_t* rec, uint32_t size);
}OBDBus;

// ISO9141 initialisation values
#define ISO9141_ADDRESS 0x33
#define ISO9141_KW1 0x08
#define ISO9141_KW2 0x08
#define ISO9141_HEADER_1 0x68
#define ISO9141_HEADER_2 0x6A
#define ISO9141_HEADER_3 0xF1

#define ISO9141_K GPIO_PIN_10 // port C. This is also UART4_TX

// initialisation timing parameters (ms)
#define W1_TIMEOUT_MAX 300
#define W2_TIMEOUT_MAX 20
#define W3_TIMEOUT_MAX 20
#define W4_TIMEOUT_MAX 50

/////////////////////////// OBD2 Related constants //////////////////////////////////////////////
#define OBD2_LIVE_MODE 0x01

HAL_StatusTypeDef iso9141_init(void);
HAL_StatusTypeDef iso9141_get_init_response(InitResponse* response);
HAL_StatusTypeDef iso9141_listen(void);
HAL_StatusTypeDef iso9141_send(uint8_t* data, uint32_t size);
uint8_t iso9141_checksum(uint8_t* data, uint32_t size);
HAL_StatusTypeDef obd2_get_parameter(uint8_t parameter);
#endif /* INC_OBD2_H_ */
