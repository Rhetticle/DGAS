################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/widgets/bar/lv_bar.c 

OBJS += \
./Core/Src/lvgl/src/widgets/bar/lv_bar.o 

C_DEPS += \
./Core/Src/lvgl/src/widgets/bar/lv_bar.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/widgets/bar/%.o Core/Src/lvgl/src/widgets/bar/%.su Core/Src/lvgl/src/widgets/bar/%.cyclo: ../Core/Src/lvgl/src/widgets/bar/%.c Core/Src/lvgl/src/widgets/bar/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/ui/ -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-widgets-2f-bar

clean-Core-2f-Src-2f-lvgl-2f-src-2f-widgets-2f-bar:
	-$(RM) ./Core/Src/lvgl/src/widgets/bar/lv_bar.cyclo ./Core/Src/lvgl/src/widgets/bar/lv_bar.d ./Core/Src/lvgl/src/widgets/bar/lv_bar.o ./Core/Src/lvgl/src/widgets/bar/lv_bar.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-widgets-2f-bar

