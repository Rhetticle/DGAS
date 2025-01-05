################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl-master/demos/widgets/lv_demo_widgets.c 

OBJS += \
./Core/Src/lvgl-master/demos/widgets/lv_demo_widgets.o 

C_DEPS += \
./Core/Src/lvgl-master/demos/widgets/lv_demo_widgets.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl-master/demos/widgets/%.o Core/Src/lvgl-master/demos/widgets/%.su Core/Src/lvgl-master/demos/widgets/%.cyclo: ../Core/Src/lvgl-master/demos/widgets/%.c Core/Src/lvgl-master/demos/widgets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F750xx -c -I../Core/Inc -I../Core/Src/lvgl-master/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2d-master-2f-demos-2f-widgets

clean-Core-2f-Src-2f-lvgl-2d-master-2f-demos-2f-widgets:
	-$(RM) ./Core/Src/lvgl-master/demos/widgets/lv_demo_widgets.cyclo ./Core/Src/lvgl-master/demos/widgets/lv_demo_widgets.d ./Core/Src/lvgl-master/demos/widgets/lv_demo_widgets.o ./Core/Src/lvgl-master/demos/widgets/lv_demo_widgets.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2d-master-2f-demos-2f-widgets

