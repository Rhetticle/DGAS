################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/indev/lv_indev.c \
../Core/Src/lvgl/src/indev/lv_indev_gesture.c \
../Core/Src/lvgl/src/indev/lv_indev_scroll.c 

C_DEPS += \
./Core/Src/lvgl/src/indev/lv_indev.d \
./Core/Src/lvgl/src/indev/lv_indev_gesture.d \
./Core/Src/lvgl/src/indev/lv_indev_scroll.d 

OBJS += \
./Core/Src/lvgl/src/indev/lv_indev.o \
./Core/Src/lvgl/src/indev/lv_indev_gesture.o \
./Core/Src/lvgl/src/indev/lv_indev_scroll.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/indev/%.o Core/Src/lvgl/src/indev/%.su Core/Src/lvgl/src/indev/%.cyclo: ../Core/Src/lvgl/src/indev/%.c Core/Src/lvgl/src/indev/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/ui/ -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-indev

clean-Core-2f-Src-2f-lvgl-2f-src-2f-indev:
	-$(RM) ./Core/Src/lvgl/src/indev/lv_indev.cyclo ./Core/Src/lvgl/src/indev/lv_indev.d ./Core/Src/lvgl/src/indev/lv_indev.o ./Core/Src/lvgl/src/indev/lv_indev.su ./Core/Src/lvgl/src/indev/lv_indev_gesture.cyclo ./Core/Src/lvgl/src/indev/lv_indev_gesture.d ./Core/Src/lvgl/src/indev/lv_indev_gesture.o ./Core/Src/lvgl/src/indev/lv_indev_gesture.su ./Core/Src/lvgl/src/indev/lv_indev_scroll.cyclo ./Core/Src/lvgl/src/indev/lv_indev_scroll.d ./Core/Src/lvgl/src/indev/lv_indev_scroll.o ./Core/Src/lvgl/src/indev/lv_indev_scroll.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-indev

