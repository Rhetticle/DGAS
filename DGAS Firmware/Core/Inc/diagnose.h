/*
 * diagnose.h
 *
 *  Created on: Feb 11, 2025
 *      Author: rhett
 */

#ifndef INC_DIAGNOSE_H_
#define INC_DIAGNOSE_H_

#include "OBD2.h"

#define A5_A4_MASK 0x3000
#define DTC_CODE_NUM_MASK 0x0FFF

#define DTC_GET_UPPER_TWO_BITS(x) (x >> 14)
#define DTC_GET_A5_A4_BITS(x) ((x & A5_A4_MASK) >> 12)
#define DTC_GET_CODE_NUM(x) (x & DTC_CODE_NUM_MASK)

#define DTC_CODE_STRING_LEN 5
#define DTC_CODE_FOUND_MSG_MAX_LEN 256

void decode_dtc(uint16_t dtc, char* result);
void display_dtcs(OBDBus* bus);

#endif /* INC_DIAGNOSE_H_ */
