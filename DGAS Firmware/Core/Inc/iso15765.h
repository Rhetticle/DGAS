/*
 * iso15765.h
 *
 *  Created on: Feb 5, 2025
 *      Author: rhett
 */

#ifndef INC_ISO15765_H_
#define INC_ISO15765_H_

#define OBD2_CAN_ID 0x7DF
#define OBD2_CAN_REQ_SIZE 7
#define OBD2_CAN_DUMMY_BYTE 0xCC // recommended value for dummy byte
#define OBD2_CAN_ECU_ID_MAX 0x7EF // maximum CAN ID that ECU can respond to OBD2 request with
#define OBD2_CAN_DATA_START_INDEX 3 // example response for vehicle speed request may be 7E8 03 41 0D 32 AA AA AA AA

//////////////////////////// CAN Filter Mask///////////////////////////////////////////////////////////
/*
 * CAN ID of ECU will be from 0x7E8 to 0x7EF so we want to check the ID matches 0111 1110 1xxx i.e. the mask
 * should have a '1' where the bit should be checked against FilterIdHigh (FilterIdHigh can be any number of form 0111 1110 1xxx).
 * So the mask will be 1111 1111 1000 = 0xFF8
 * */
#define OBD2_CAN_ID_MASK 0xFF8

#define CAN_MSG_MAX_LEN 128
#define CAN_RESPONSE_TIMEOUT 100 // (100ms)

typedef struct {
	CAN_RxHeaderTypeDef* rxHeader;
	uint8_t buffer[CAN_MSG_MAX_LEN];
}CANResponse;

bool response_is_ready(void);
void response_ready_set(void);
void response_ready_clear(void);
HAL_StatusTypeDef can_get_pid(uint8_t pid, uint8_t* response);
HAL_StatusTypeDef can_obd2_init(void);

#endif /* INC_ISO15765_H_ */
