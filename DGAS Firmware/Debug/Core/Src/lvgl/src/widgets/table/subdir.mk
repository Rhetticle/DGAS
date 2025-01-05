################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/widgets/table/lv_table.c 

OBJS += \
./Core/Src/lvgl/src/widgets/table/lv_table.o 

C_DEPS += \
./Core/Src/lvgl/src/widgets/table/lv_table.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/widgets/table/%.o Core/Src/lvgl/src/widgets/table/%.su Core/Src/lvgl/src/widgets/table/%.cyclo: ../Core/Src/lvgl/src/widgets/table/%.c Core/Src/lvgl/src/widgets/table/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F750xx -c -I../Core/Inc -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-widgets-2f-table

clean-Core-2f-Src-2f-lvgl-2f-src-2f-widgets-2f-table:
	-$(RM) ./Core/Src/lvgl/src/widgets/table/lv_table.cyclo ./Core/Src/lvgl/src/widgets/table/lv_table.d ./Core/Src/lvgl/src/widgets/table/lv_table.o ./Core/Src/lvgl/src/widgets/table/lv_table.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-widgets-2f-table

