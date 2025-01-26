################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/examples/libs/freetype/lv_example_freetype_1.c \
../Core/Src/lvgl/examples/libs/freetype/lv_example_freetype_2.c 

C_DEPS += \
./Core/Src/lvgl/examples/libs/freetype/lv_example_freetype_1.d \
./Core/Src/lvgl/examples/libs/freetype/lv_example_freetype_2.d 

OBJS += \
./Core/Src/lvgl/examples/libs/freetype/lv_example_freetype_1.o \
./Core/Src/lvgl/examples/libs/freetype/lv_example_freetype_2.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/examples/libs/freetype/%.o Core/Src/lvgl/examples/libs/freetype/%.su Core/Src/lvgl/examples/libs/freetype/%.cyclo: ../Core/Src/lvgl/examples/libs/freetype/%.c Core/Src/lvgl/examples/libs/freetype/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/ui/ -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-examples-2f-libs-2f-freetype

clean-Core-2f-Src-2f-lvgl-2f-examples-2f-libs-2f-freetype:
	-$(RM) ./Core/Src/lvgl/examples/libs/freetype/lv_example_freetype_1.cyclo ./Core/Src/lvgl/examples/libs/freetype/lv_example_freetype_1.d ./Core/Src/lvgl/examples/libs/freetype/lv_example_freetype_1.o ./Core/Src/lvgl/examples/libs/freetype/lv_example_freetype_1.su ./Core/Src/lvgl/examples/libs/freetype/lv_example_freetype_2.cyclo ./Core/Src/lvgl/examples/libs/freetype/lv_example_freetype_2.d ./Core/Src/lvgl/examples/libs/freetype/lv_example_freetype_2.o ./Core/Src/lvgl/examples/libs/freetype/lv_example_freetype_2.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-examples-2f-libs-2f-freetype

