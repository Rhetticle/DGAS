/*
 * debug.h
 *
 *  Created on: Jan 21, 2025
 *      Author: rhett
 */

#ifndef INC_OBD_DEBUG_H_
#define INC_OBD_DEBUG_H_

#include <stdbool.h>

#define DBG_MSG_MAX_SIZE 256
#define DBG_WINDOW_MAX_TEXT 600

typedef enum {
	ERROR_NO_RESPONSE,
	ERROR_KWP_FORMAT
} bus_error_t;

void debug_send_data(uint8_t* data, uint32_t size);
void debug_send_header(bool receiving, bool error);
void debug_send_message(uint8_t* data, uint32_t size, bool receiving);
void debug_send_error(bool receiving, bus_error_t error);
#endif /* INC_OBD_DEBUG_H_ */
