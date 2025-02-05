/*
 * OBD_Debug.c
 *
 *  Created on: Jan 21, 2025
 *      Author: rhett
 */

#include <stm32f7xx.h>
#include <stdio.h>
#include <string.h>
#include "OBD_Debug.h"
#include "OBD2.h"
#include "ui.h"
#include "lvgl.h"

void debug_send_data(uint8_t* data, uint32_t size) {
	if (lv_screen_active() != objects.obd2_debug) {
		return;
	}
	char msg[DBG_MSG_MAX_SIZE] = "{";

	for (int i = 0; i < size; i++) {
		if (data[i] <= 0xF) {
			sprintf(msg + strlen(msg), "0x0%X", data[i]);
		} else {
			sprintf(msg + strlen(msg), "0x%X", data[i]);
		}
		if (i == size - 1) {
			strcat(msg, "}\n");
		} else {
			strcat(msg, ", ");
		}
	}
	lv_textarea_add_text(objects.obj32, msg);
}

void debug_send_header(bool receiving, bool error) {
	if (lv_screen_active() != objects.obd2_debug) {
		return;
	}
	lv_obj_t* label = lv_textarea_get_label(objects.obj32);
	if (strlen(lv_label_get_text(label)) > DBG_WINDOW_MAX_TEXT) {
		lv_label_cut_text(label, 0, 70);
		lv_textarea_set_text(objects.obj32, lv_label_get_text(label));
	}

	char header[DBG_MSG_MAX_SIZE];

	if (!receiving) {
		sprintf(header, "#00FF00 \uf00c [DGAS]# ");
	} else {
		if (error) {
			sprintf(header, "#FF0000 \uf00d# #AA11F0 [ECU]# ");
		} else {
			sprintf(header, "#00FF00 \uf00c# #AA11F0 [ECU]# ");
		}
	}
	sprintf(header + strlen(header), "#00FFFF <KWP># ");

	lv_textarea_add_text(objects.obj32, header);
	lv_label_set_recolor(lv_textarea_get_label(objects.obj32), true);
}

void debug_send_message(uint8_t* data, uint32_t size, bool receiving) {
	debug_send_header(receiving, false);
	debug_send_data(data, size);
}

void debug_send_error(bool receiving, bus_error_t error) {
	if (lv_screen_active() != objects.obd2_debug) {
		return;
	}
	debug_send_header(receiving, true);

	switch(error) {
		case ERROR_NO_RESPONSE:
			lv_textarea_add_text(objects.obj32, "#FF0000 ERROR: NO RESPONSE#\n");
			break;
		case ERROR_KWP_FORMAT:
			lv_textarea_add_text(objects.obj32, "#FF0000 ERROR: FORMAT BYTE#\n");
			break;
	}
}
