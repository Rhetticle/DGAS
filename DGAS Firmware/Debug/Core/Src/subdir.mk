################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ISO9141_KWP.c \
../Core/Src/LIS3DH.c \
../Core/Src/OBD2.c \
../Core/Src/OBD_Debug.c \
../Core/Src/ST7701.c \
../Core/Src/buttons.c \
../Core/Src/gauge.c \
../Core/Src/iso15765.c \
../Core/Src/main.c \
../Core/Src/quadspi.c \
../Core/Src/stm32f7xx_hal_msp.c \
../Core/Src/stm32f7xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f7xx.c 

C_DEPS += \
./Core/Src/ISO9141_KWP.d \
./Core/Src/LIS3DH.d \
./Core/Src/OBD2.d \
./Core/Src/OBD_Debug.d \
./Core/Src/ST7701.d \
./Core/Src/buttons.d \
./Core/Src/gauge.d \
./Core/Src/iso15765.d \
./Core/Src/main.d \
./Core/Src/quadspi.d \
./Core/Src/stm32f7xx_hal_msp.d \
./Core/Src/stm32f7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f7xx.d 

OBJS += \
./Core/Src/ISO9141_KWP.o \
./Core/Src/LIS3DH.o \
./Core/Src/OBD2.o \
./Core/Src/OBD_Debug.o \
./Core/Src/ST7701.o \
./Core/Src/buttons.o \
./Core/Src/gauge.o \
./Core/Src/iso15765.o \
./Core/Src/main.o \
./Core/Src/quadspi.o \
./Core/Src/stm32f7xx_hal_msp.o \
./Core/Src/stm32f7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f7xx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/ui/ -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/ISO9141_KWP.cyclo ./Core/Src/ISO9141_KWP.d ./Core/Src/ISO9141_KWP.o ./Core/Src/ISO9141_KWP.su ./Core/Src/LIS3DH.cyclo ./Core/Src/LIS3DH.d ./Core/Src/LIS3DH.o ./Core/Src/LIS3DH.su ./Core/Src/OBD2.cyclo ./Core/Src/OBD2.d ./Core/Src/OBD2.o ./Core/Src/OBD2.su ./Core/Src/OBD_Debug.cyclo ./Core/Src/OBD_Debug.d ./Core/Src/OBD_Debug.o ./Core/Src/OBD_Debug.su ./Core/Src/ST7701.cyclo ./Core/Src/ST7701.d ./Core/Src/ST7701.o ./Core/Src/ST7701.su ./Core/Src/buttons.cyclo ./Core/Src/buttons.d ./Core/Src/buttons.o ./Core/Src/buttons.su ./Core/Src/gauge.cyclo ./Core/Src/gauge.d ./Core/Src/gauge.o ./Core/Src/gauge.su ./Core/Src/iso15765.cyclo ./Core/Src/iso15765.d ./Core/Src/iso15765.o ./Core/Src/iso15765.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/quadspi.cyclo ./Core/Src/quadspi.d ./Core/Src/quadspi.o ./Core/Src/quadspi.su ./Core/Src/stm32f7xx_hal_msp.cyclo ./Core/Src/stm32f7xx_hal_msp.d ./Core/Src/stm32f7xx_hal_msp.o ./Core/Src/stm32f7xx_hal_msp.su ./Core/Src/stm32f7xx_it.cyclo ./Core/Src/stm32f7xx_it.d ./Core/Src/stm32f7xx_it.o ./Core/Src/stm32f7xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f7xx.cyclo ./Core/Src/system_stm32f7xx.d ./Core/Src/system_stm32f7xx.o ./Core/Src/system_stm32f7xx.su

.PHONY: clean-Core-2f-Src

