# DGAS
Digital Gauge Awareness System to be used with any car with an OBD-2 port. 

![dgas front](https://github.com/user-attachments/assets/4102765d-777d-4289-b9a9-83bf9e47d28d)
![dgas back internal](https://github.com/user-attachments/assets/09ee38b3-d3df-434a-9011-0c4df18be34a)
![dgas bottom](https://github.com/user-attachments/assets/d280e5c2-f795-45fa-a756-9daf1feb0dcf)
![dgas](https://github.com/user-attachments/assets/c8e31653-60a0-48b3-ad2a-e73054a8c513)


## Overview
DGAS is a multi-function digital gauge that can measure any data available on a car's OBD-2 diagnostic port such as engine speed, vehicle speed, coolant temperature, manifold pressure etc. DGAS supports 3 out of the 4 OBD-2 buses namely ISO-9141, ISO-14320 (also known as KWP2000) and ISO-15765 (CAN, most common for newer cars) (SAE J-1850 is not supported). All data measured from the car's ECU is displayed on a 2.1 inch circular TFT-LCD display with a 16-bit color depth.  

## UI

The DGAS UI allows the user to configure and interact with multiple features of the gauge such as measurement parameter as well as watch live OBD2 messages sent from DGAS to the ECU and the response from the ECU which is useful for debugging purposes.

### Main Gauge UI
The gauge UI display the current parameter being measured as well as OBD2 status, maximum parameter value reached so far and battery voltage. Each parameter is color coded.

  <img src="https://github.com/user-attachments/assets/84c1c996-d487-4344-8f31-6e3db4293b99" width=350>

  <img src="https://github.com/user-attachments/assets/9a40f290-b8d7-44fc-ba0f-9639eacd7970" width=350>
  <img src="https://github.com/user-attachments/assets/c2b032ee-7bcb-4c30-869d-11a77f008d2c" width=350>

  <img src="https://github.com/user-attachments/assets/ac6e1ff6-1651-4a64-93a1-6f7c5c58ebfa" width=350>

### Menu
![menu](https://github.com/user-attachments/assets/574ff377-b4c9-4d3e-a682-dd45c8ef6f99)

### Measure
The measure UI let's the user chose between 1 of 8 different parameters assuming the vehicle DGAS is connected to supports these parameters.

![measure](https://github.com/user-attachments/assets/69bf3344-7432-4310-8c5a-d72bc6c16d19)

### OBD2 Debug
The OBD2 Debug shows the live data being sent from DGAS and received from the ECU. Each message consists of a header with a status (green tick for ok or red cross for error), a device (either DGAS or ECU) and the bus being used as well as the raw data itself, or an error message if an error occurred on the bus.

![obd2 debug](https://github.com/user-attachments/assets/396a608b-9122-4c48-911e-2ac7b1759064)

### About
This screen explains what DGAS is and has a QR code which directs users to this GitHub repository

![about](https://github.com/user-attachments/assets/83db0be0-a343-4c5a-9e98-5e121123ab50)


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
