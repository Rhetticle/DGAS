/*
 * debug.h
 *
 *  Created on: Jan 21, 2025
 *      Author: rhett
 */

#ifndef INC_OBD_DEBUG_H_
#define INC_OBD_DEBUG_H_

#include <stdbool.h>
#include "OBD2.h"

#define DBG_MSG_MAX_SIZE 256
#define DBG_WINDOW_MAX_TEXT 600

typedef enum {
	ERROR_TIMEOUT,
	ERROR_KWP_FORMAT,
} BusError;

void debug_init(BusID id);
void debug_add_text(char* text);
void debug_send_data(uint8_t* data, uint32_t size);
void add_bus_name_to_header(char* header);
void debug_send_header(bool receiving, bool error);
void debug_send_message(uint8_t* data, uint32_t size, bool receiving);
void debug_send_error(bool receiving, BusError error);
#endif /* INC_OBD_DEBUG_H_ */
