################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl-master/src/widgets/chart/lv_chart.c 

OBJS += \
./Core/Src/lvgl-master/src/widgets/chart/lv_chart.o 

C_DEPS += \
./Core/Src/lvgl-master/src/widgets/chart/lv_chart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl-master/src/widgets/chart/%.o Core/Src/lvgl-master/src/widgets/chart/%.su Core/Src/lvgl-master/src/widgets/chart/%.cyclo: ../Core/Src/lvgl-master/src/widgets/chart/%.c Core/Src/lvgl-master/src/widgets/chart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F750xx -c -I../Core/Inc -I../Core/Src/lvgl-master/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2d-master-2f-src-2f-widgets-2f-chart

clean-Core-2f-Src-2f-lvgl-2d-master-2f-src-2f-widgets-2f-chart:
	-$(RM) ./Core/Src/lvgl-master/src/widgets/chart/lv_chart.cyclo ./Core/Src/lvgl-master/src/widgets/chart/lv_chart.d ./Core/Src/lvgl-master/src/widgets/chart/lv_chart.o ./Core/Src/lvgl-master/src/widgets/chart/lv_chart.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2d-master-2f-src-2f-widgets-2f-chart

