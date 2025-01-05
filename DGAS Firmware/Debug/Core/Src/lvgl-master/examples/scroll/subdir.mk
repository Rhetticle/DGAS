################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl-master/examples/scroll/lv_example_scroll_1.c \
../Core/Src/lvgl-master/examples/scroll/lv_example_scroll_2.c \
../Core/Src/lvgl-master/examples/scroll/lv_example_scroll_3.c \
../Core/Src/lvgl-master/examples/scroll/lv_example_scroll_4.c \
../Core/Src/lvgl-master/examples/scroll/lv_example_scroll_5.c \
../Core/Src/lvgl-master/examples/scroll/lv_example_scroll_6.c \
../Core/Src/lvgl-master/examples/scroll/lv_example_scroll_7.c 

OBJS += \
./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_1.o \
./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_2.o \
./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_3.o \
./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_4.o \
./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_5.o \
./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_6.o \
./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_7.o 

C_DEPS += \
./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_1.d \
./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_2.d \
./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_3.d \
./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_4.d \
./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_5.d \
./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_6.d \
./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_7.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl-master/examples/scroll/%.o Core/Src/lvgl-master/examples/scroll/%.su Core/Src/lvgl-master/examples/scroll/%.cyclo: ../Core/Src/lvgl-master/examples/scroll/%.c Core/Src/lvgl-master/examples/scroll/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F750xx -c -I../Core/Inc -I../Core/Src/lvgl-master/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2d-master-2f-examples-2f-scroll

clean-Core-2f-Src-2f-lvgl-2d-master-2f-examples-2f-scroll:
	-$(RM) ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_1.cyclo ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_1.d ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_1.o ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_1.su ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_2.cyclo ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_2.d ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_2.o ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_2.su ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_3.cyclo ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_3.d ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_3.o ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_3.su ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_4.cyclo ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_4.d ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_4.o ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_4.su ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_5.cyclo ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_5.d ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_5.o ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_5.su ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_6.cyclo ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_6.d ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_6.o ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_6.su ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_7.cyclo ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_7.d ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_7.o ./Core/Src/lvgl-master/examples/scroll/lv_example_scroll_7.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2d-master-2f-examples-2f-scroll

