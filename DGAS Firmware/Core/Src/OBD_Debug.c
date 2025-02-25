/*
 * OBD_Debug.c
 *
 *  Created on: Jan 21, 2025
 *      Author: rhett
 */

#include <stm32f7xx.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "OBD_Debug.h"
#include "ISO9141_KWP.h"
#include "OBD2.h"
#include "ui.h"
#include "lvgl.h"

static BusID busActive;
static char debugLog[512];
static char debugBuffer[512];
static bool paused;

void debug_init(BusID id) {
	busActive = id;
}

char* get_debug_log(void) {
	return debugLog;
}

void pause_debugger(void) {
	paused = true;
}

void resume_debugger(void) {
	paused = false;
}

void debug_flush(void) {
	if (paused) {
		return;
	}
	lv_obj_t* label = lv_textarea_get_label(objects.obd2_debug_textarea);
	if (strlen(lv_label_get_text(label)) > DBG_WINDOW_MAX_TEXT) {
		// clear textarea to stop text from overflowing
		lv_textarea_set_text(objects.obd2_debug_textarea, "");
	}
	lv_textarea_add_text(objects.obd2_debug_textarea, debugBuffer);
	memset(debugBuffer, 0, sizeof(debugBuffer));
}

void debug_add_to_buffer(char* buff, char* text, uint32_t buffSize) {
	if (buffSize - strlen(buff) > strlen(text)) {
		sprintf(buff + strlen(buff), "%s", text);
	} else {
		memset(buff, 0, sizeof(buffSize));
		sprintf(buff, "%s", text);
	}
}

void debug_send_text(char* text) {
	// debug messages are buffered since writing to textarea is slow and can affect OBD related functionality
	// The buffer will be flushed to the debug window only if the debug screen is active. All messages will still be
	// logged to debugLog
	debug_add_to_buffer(debugLog, text, sizeof(debugLog));
	debug_add_to_buffer(debugBuffer, text, sizeof(debugBuffer));
}

void debug_add_data(char* message, uint8_t* data, uint32_t size) {
	sprintf(message + strlen(message), "{");

	for (int i = 0; i < size; i++) {
		if (data[i] <= 0xF) {
			sprintf(message + strlen(message), "0x0%X", data[i]);
		} else {
			sprintf(message + strlen(message), "0x%X", data[i]);
		}
		if (i == size - 1) {
			strcat(message, "}\n");
		} else {
			strcat(message, ", ");
		}
	}
}

void add_bus_name_to_header(char* header) {
	char* name = "";

	switch (busActive) {
		case BUS_ID_KWP:
			name = "#00FFFF <KWP># ";
			break;
		case BUS_ID_9141:
			name = "#00FFFF <9141># ";
			break;
		case BUS_ID_CAN:
			name = "#00FFFF <CAN># ";
			break;
		case BUS_ID_AUTO:
			name = "#00FFFF <AUTO>#";
			break;
	}
	sprintf(header + strlen(header), "%s", name);
}

void debug_add_header(char* message, bool receiving, bool error) {
	if (!receiving) {
		sprintf(message, "#00FF00 \uf00c [DGAS]# ");
	} else {
		if (error) {
			sprintf(message, "#FF0000 \uf00d# #AA11F0 [ECU]# ");
		} else {
			sprintf(message, "#00FF00 \uf00c# #AA11F0 [ECU]# ");
		}
	}
	add_bus_name_to_header(message);
}

uint8_t get_obd_mode(uint8_t* data, uint32_t size) {
	if (busActive == BUS_ID_KWP) {
		return data[KWP_PID_INDEX];
	} else if (busActive == BUS_ID_9141) {
		return data[ISO9141_PID_INDEX];
	}
	return 0;
}

void add_request_type_to_header(char* header, uint8_t obdMode) {
	if (CHECK_OBD_MODE(obdMode, OBD2_MODE_LIVE)) {
		sprintf(header + strlen(header), "#FF7200 (PID) #");
	} else if ((CHECK_OBD_MODE(obdMode, OBD2_MODE_DTC)) || (CHECK_OBD_MODE(obdMode, OBD2_MODE_CLEAR_DTC) ||
			CHECK_OBD_MODE(obdMode, OBD2_MODE_KWP_DTC))) {
		sprintf(header + strlen(header), "#FFFF00 (DTC) #");
	} else {
		sprintf(header + strlen(header), "#FF0000 (???) #");
	}
}

void debug_send_message(uint8_t* data, uint32_t size, bool receiving) {
	char message[DBG_MSG_MAX_SIZE];

	// add the header and data section to our debug message and send it
	debug_add_header(message, receiving, false);
	if (!receiving) {
		uint8_t obdMode = get_obd_mode(data, size);
		add_request_type_to_header(message, obdMode);
	}
	debug_add_data(message, data, size);
	debug_send_text(message);
}

void debug_send_error(bool receiving, BusError error) {
	char errorMsg[DBG_MSG_MAX_SIZE];
	char* errorReason = NULL;
	debug_add_header(errorMsg, receiving, true);

	switch(error) {
		case ERROR_TIMEOUT:
			errorReason = "#FF0000 ERROR: TIMEOUT#\n";
			break;
		case ERROR_KWP_9141_FORMAT:
			errorReason = "#FF0000 ERROR: FORMAT BYTE#\n";
			break;
		case ERROR_RECEIVE:
			errorReason = "#FF0000 ERROR: RECEIVE#\n";
			break;
		case ERROR_KWP_9141_ECHO:
			errorReason = "#FF0000 ERROR: NO ECHO#\n";
			break;
		case ERROR_TRANSMIT:
			errorReason = "#FF0000 ERROR: TRANSMIT#\n";
			break;
	}
	if (errorReason == NULL) {
		sprintf(errorMsg + strlen(errorMsg), "#FF0000 ERROR IS UNKNOWN#");
	} else {
		sprintf(errorMsg + strlen(errorMsg), "%s", errorReason);
	}
	debug_send_text(errorMsg);
}
