################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_1.c \
../Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_2.c \
../Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_3.c \
../Core/Src/lvgl/examples/libs/tiny_ttf/ubuntu_font.c 

C_DEPS += \
./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_1.d \
./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_2.d \
./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_3.d \
./Core/Src/lvgl/examples/libs/tiny_ttf/ubuntu_font.d 

OBJS += \
./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_1.o \
./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_2.o \
./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_3.o \
./Core/Src/lvgl/examples/libs/tiny_ttf/ubuntu_font.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/examples/libs/tiny_ttf/%.o Core/Src/lvgl/examples/libs/tiny_ttf/%.su Core/Src/lvgl/examples/libs/tiny_ttf/%.cyclo: ../Core/Src/lvgl/examples/libs/tiny_ttf/%.c Core/Src/lvgl/examples/libs/tiny_ttf/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/ui/ -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-examples-2f-libs-2f-tiny_ttf

clean-Core-2f-Src-2f-lvgl-2f-examples-2f-libs-2f-tiny_ttf:
	-$(RM) ./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_1.cyclo ./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_1.d ./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_1.o ./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_1.su ./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_2.cyclo ./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_2.d ./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_2.o ./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_2.su ./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_3.cyclo ./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_3.d ./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_3.o ./Core/Src/lvgl/examples/libs/tiny_ttf/lv_example_tiny_ttf_3.su ./Core/Src/lvgl/examples/libs/tiny_ttf/ubuntu_font.cyclo ./Core/Src/lvgl/examples/libs/tiny_ttf/ubuntu_font.d ./Core/Src/lvgl/examples/libs/tiny_ttf/ubuntu_font.o ./Core/Src/lvgl/examples/libs/tiny_ttf/ubuntu_font.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-examples-2f-libs-2f-tiny_ttf

