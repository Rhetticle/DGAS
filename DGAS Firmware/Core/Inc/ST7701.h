/*
 * ST7701.h
 *
 *  Created on: Jan 4, 2025
 *      Author: rhett
 */

#ifndef INC_ST7701_H_
#define INC_ST7701_H_

// both pins on port B
#define LCD_CS GPIO_PIN_4
#define LCD_NRST GPIO_PIN_7

/* Configurations commands to use via SPI interface. Note that when using SPI to send commands, each
   command is 16 bits long rather than 8 bits.
*/
#define LCD_NORM_DISPLAY_ON 0x1300
#define LCD_INV_OFF 0x2000
#define LCD_INV_ON 0x2100
#define LCD_ALL_PIX_OFF 0x2200
#define LCD_ALL_PIX_ON 0x2300
#define LCD_DISP_OFF 0x2800
#define LCD_DISP_ON 0x2900
#define LCD_MADCTL 0x3600
#define LCD_IDLE_OFF 0x3800
#define LCD_IDLE_ON 0x3900
#define LCD_COLMOD 0x3A00
#define LCD_SET_BRIGHTNESS 0x5100
#define LCD_RGB_CTRL 0xC300

// function prototypes
HAL_StatusTypeDef lcd_command(uint16_t cmd, uint16_t arg);
void lcd_reset(void);
HAL_StatusTypeDef lcd_init(void);


#endif /* INC_ST7701_H_ */
