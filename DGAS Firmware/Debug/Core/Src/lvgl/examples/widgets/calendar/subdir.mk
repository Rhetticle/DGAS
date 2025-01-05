################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/examples/widgets/calendar/lv_example_calendar_1.c \
../Core/Src/lvgl/examples/widgets/calendar/lv_example_calendar_2.c 

OBJS += \
./Core/Src/lvgl/examples/widgets/calendar/lv_example_calendar_1.o \
./Core/Src/lvgl/examples/widgets/calendar/lv_example_calendar_2.o 

C_DEPS += \
./Core/Src/lvgl/examples/widgets/calendar/lv_example_calendar_1.d \
./Core/Src/lvgl/examples/widgets/calendar/lv_example_calendar_2.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/examples/widgets/calendar/%.o Core/Src/lvgl/examples/widgets/calendar/%.su Core/Src/lvgl/examples/widgets/calendar/%.cyclo: ../Core/Src/lvgl/examples/widgets/calendar/%.c Core/Src/lvgl/examples/widgets/calendar/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F750xx -c -I../Core/Inc -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-examples-2f-widgets-2f-calendar

clean-Core-2f-Src-2f-lvgl-2f-examples-2f-widgets-2f-calendar:
	-$(RM) ./Core/Src/lvgl/examples/widgets/calendar/lv_example_calendar_1.cyclo ./Core/Src/lvgl/examples/widgets/calendar/lv_example_calendar_1.d ./Core/Src/lvgl/examples/widgets/calendar/lv_example_calendar_1.o ./Core/Src/lvgl/examples/widgets/calendar/lv_example_calendar_1.su ./Core/Src/lvgl/examples/widgets/calendar/lv_example_calendar_2.cyclo ./Core/Src/lvgl/examples/widgets/calendar/lv_example_calendar_2.d ./Core/Src/lvgl/examples/widgets/calendar/lv_example_calendar_2.o ./Core/Src/lvgl/examples/widgets/calendar/lv_example_calendar_2.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-examples-2f-widgets-2f-calendar

