/*
 * ST7701.c
 *
 *  Created on: Jan 4, 2025
 *      Author: rhett
 */

#include <stm32f7xx.h>
#include "ST7701.h"

extern SPI_HandleTypeDef hspi1;

HAL_StatusTypeDef lcd_command(uint16_t cmd, uint16_t arg) {
	uint8_t args[] = {cmd >> 8, cmd, arg >> 8};

	HAL_GPIO_WritePin(GPIOB, LCD_CS, 0);
	if (HAL_SPI_Transmit(&hspi1, args, 3, 100) != HAL_OK) {
		HAL_GPIO_WritePin(GPIOB, LCD_CS, 1);
		return HAL_ERROR;
	}
	HAL_GPIO_WritePin(GPIOB, LCD_CS, 1);
	return HAL_OK;
}

void lcd_reset(void) {
	HAL_GPIO_WritePin(GPIOB, LCD_NRST, 0);
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOB, LCD_NRST, 1);
	HAL_Delay(10);
}

void sendCommand(uint8_t cmd) {
	uint16_t send = cmd;
	HAL_GPIO_WritePin(GPIOB, LCD_CS, 0);
	HAL_Delay(1);
	HAL_SPI_Transmit(&hspi1, &send, 1, 100);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOB, LCD_CS, 1);
}

void sendData(uint8_t data) {
	uint16_t send = 1 << 8 | data;
	HAL_GPIO_WritePin(GPIOB, LCD_CS, 0);
	HAL_Delay(1);
	HAL_SPI_Transmit(&hspi1, &send, 1, 100);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOB, LCD_CS, 1);
}

HAL_StatusTypeDef lcd_init(void) {
	HAL_GPIO_WritePin(GPIOB, LCD_NRST, 1);
	HAL_GPIO_WritePin(GPIOB, LCD_CS, 1);
	lcd_reset();
#if 1
sendCommand(0xFF);
sendData(0x77);
sendData(0x01);
sendData(0x00);
sendData(0x00);
sendData(0x10);

 sendCommand(0xC0);
 sendData(0x3B);
 sendData(0x00);

 sendCommand(0xC1);
 sendData(0x0B); //VBP
 sendData(0x02);

 sendCommand(0xC2);
 sendData(0x00);
 sendData(0x02);

 sendCommand(0xCC);
 sendData(0x10);

 sendCommand(0xCD);
 sendData(0x08);

 sendCommand ( 0xB0); //Positive Voltage Gamma Control
 sendData ( 0x02);
 sendData ( 0x13);
 sendData ( 0x1B);
 sendData ( 0x0D);
 sendData ( 0x10);
 sendData ( 0x05);
 sendData ( 0x08);
 sendData ( 0x07);
 sendData ( 0x07);
 sendData ( 0x24);
 sendData ( 0x04);
 sendData ( 0x11);
 sendData ( 0x0E);
 sendData ( 0x2C);
 sendData ( 0x33);
 sendData ( 0x1D);

 sendCommand ( 0xB1); //Negative Voltage Gamma Control
 sendData ( 0x05);
 sendData ( 0x13);
 sendData ( 0x1B);
 sendData ( 0x0D);
 sendData ( 0x11);
 sendData ( 0x05);
 sendData ( 0x08);
 sendData ( 0x07);
 sendData ( 0x07);
 sendData ( 0x24);
 sendData ( 0x04);
 sendData ( 0x11);
 sendData ( 0x0E);
 sendData ( 0x2C);
 sendData ( 0x33);
 sendData ( 0x1D);

 sendCommand(0xFF);
 sendData(0x77);
 sendData(0x01);
 sendData(0x00);
 sendData(0x00);
 sendData(0x11);

 sendCommand(0xB0);
 sendData(0x5d);//5d

 sendCommand(0xB1); //VCOM amplitude setting
 sendData(0x43); //43

 sendCommand(0xB2); //VGH Voltage setting
 sendData(0x81); //12V

 sendCommand(0xB3);
 sendData(0x80);

 sendCommand(0xB5); //VGL Voltage setting
 sendData(0x43); //-8.3V

 sendCommand(0xB7);
 sendData(0x85);

 sendCommand(0xB8);
 sendData(0x20);

 sendCommand(0xC1);
 sendData(0x78);

 sendCommand(0xC2);
 sendData(0x78);

 sendCommand(0xD0);
 sendData(0x88);

 sendCommand(0xE0);
 sendData(0x00);
 sendData(0x00);
 sendData(0x02);

 sendCommand(0xE1);
 sendData(0x03);
 sendData(0xA0);
 sendData(0x00);
 sendData(0x00);
 sendData(0x04);
 sendData(0xA0);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x20);
 sendData(0x20);

 sendCommand(0xE2);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);

 sendCommand(0xE3);
 sendData(0x00);
 sendData(0x00);
 sendData(0x11);
 sendData(0x00);

 sendCommand(0xE4);
 sendData(0x22);
 sendData(0x00);

 sendCommand(0xE5);
 sendData(0x05);
 sendData(0xEC);
 sendData(0xA0);
 sendData(0xA0);
 sendData(0x07);
 sendData(0xEE);
 sendData(0xA0);
 sendData(0xA0);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);

 sendCommand(0xE6);
 sendData(0x00);
 sendData(0x00);
 sendData(0x11);
 sendData(0x00);

 sendCommand(0xE7);
 sendData(0x22);
 sendData(0x00);

 sendCommand(0xE8);
 sendData(0x06);
 sendData(0xED);
 sendData(0xA0);
 sendData(0xA0);
 sendData(0x08);
 sendData(0xEF);
 sendData(0xA0);
 sendData(0xA0);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);

 sendCommand(0xEB);
 sendData(0x00);
 sendData(0x00);
 sendData(0x40);
 sendData(0x40);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);

 sendCommand(0xED);
 sendData(0xFF);
 sendData(0xFF);
 sendData(0xFF);
 sendData(0xBA);
 sendData(0x0A);
 sendData(0xBF);
 sendData(0x45);
 sendData(0xFF);
 sendData(0xFF);
 sendData(0x54);
 sendData(0xFB);
 sendData(0xA0);
 sendData(0xAB);
 sendData(0xFF);
 sendData(0xFF);
 sendData(0xFF);

 sendCommand(0xEF);
 sendData(0x10);
 sendData(0x0D);
 sendData(0x04);
 sendData(0x08);
 sendData(0x3F);
 sendData(0x1F);

 sendCommand(0xFF);
 sendData(0x77);
 sendData(0x01);
 sendData(0x00);
 sendData(0x00);
 sendData(0x13);

 sendCommand(0xEF);
 sendData(0x08);

 sendCommand(0xFF);
 sendData(0x77);
 sendData(0x01);
 sendData(0x00);
 sendData(0x00);
 sendData(0x00);

#if 0
  sendCommand (0xFF);
WriteData (0x77);
WriteData (0x01);
WriteData (0x00);
WriteData (0x00);
WriteData (0x12);
  sendCommand (0xD1);
WriteData (0x81);
WriteData (0x08);
WriteData (0x03);
WriteData (0x20);
WriteData (0x08);
WriteData (0x01);
WriteData (0xA0);
WriteData (0x01);
WriteData (0xE0);
WriteData (0xA0);
WriteData (0x01);
WriteData (0xE0);
WriteData (0x03);
WriteData (0x20);
  sendCommand (0xD2);
WriteData (0x08);
#endif
/////////////////Bring up the internal test picture///////////////////////////////////
#endif
sendCommand(0x11);

HAL_Delay(120);

sendCommand(0x29);

sendCommand(0x36);
sendData(0x00);

sendCommand(0x3A);
sendData(0x60);//0x60 18bit 0x50 16bit
sendCommand(0x13);
//sendCommand(0x23);
	return HAL_OK;
}
