# DGAS
Digital Gauge Awareness System to be used with any car with an OBD-2 port. 

![dgas top](https://github.com/user-attachments/assets/dd2fdf25-d20a-4a30-8308-69a44eec276e)
![dgas bottom](https://github.com/user-attachments/assets/46bd56b6-8ac8-402b-a4bc-bc87ed92a89d)

## Overview
DGAS is a multi-function digital gauge that can measure any data available on a car's OBD-2 diagnostic port such as engine speed, vehicle speed, coolant temperature, manifold pressure etc. DGAS supports 3 out of the 4 OBD-2 buses namely ISO-9141, ISO-14320 (also known as KWP2000) and ISO-15765 (CAN, most common for newer cars) (SAE J-1850 is not supported). All data measured from the car's ECU is displayed on a 2.1 inch circular TFT-LCD display with a 16-bit color depth.  

## Hardware Details
* Microcontroller - STM32F746ZGT7 (QFP-144)
* External DRAM - IS42S16100H-7TL (16-Mbit) (50-TSOP)
* External Flash - W25Q256JVEIQ (256-Mbit) (8-WSON)
* CAN Transceiver - SN65HVD232QDRQ1 (8-SOIC)
* ISO-9141 Transceiver - L9613B013TR (8-SOIC)
* Accelerometer - LIS3DHTR (16-LGA)

The STM32F746ZGT7 was chosen for it's large 1MB of internal flash (needed to store LVGL code) as well as it's LTDC and FMC peripherals needed to drive the TFT-LCD display and interface with external DRAM respectively. External DRAM was needed to store the frame buffers for the display. As the display was 480x480 with a 16-bit color depth, one frame buffer occupies 460800 bytes or twice that for DGAS as double buffering is being used. External flash is being used to store large GUI objects such as images and fonts.

DGAS connects to the car's OBD-2 port via the main DB-15 connector using a DB-15 to OBD-2 cable. The main power connection should be connected to any wire within the car which carries the ignition signal so that DGAS is only powered when the vehicle is on.

## Firmware Details
Checkout DGAS Firmware for more details on firmware and low-level drivers.
### LVGL
All UI elements for the display were done through the LVGL graphics library as well as the EEZ-Studio UI designer tool. 
