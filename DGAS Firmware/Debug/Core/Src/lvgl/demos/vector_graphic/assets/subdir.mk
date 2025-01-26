################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/demos/vector_graphic/assets/img_demo_vector_avatar.c 

C_DEPS += \
./Core/Src/lvgl/demos/vector_graphic/assets/img_demo_vector_avatar.d 

OBJS += \
./Core/Src/lvgl/demos/vector_graphic/assets/img_demo_vector_avatar.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/demos/vector_graphic/assets/%.o Core/Src/lvgl/demos/vector_graphic/assets/%.su Core/Src/lvgl/demos/vector_graphic/assets/%.cyclo: ../Core/Src/lvgl/demos/vector_graphic/assets/%.c Core/Src/lvgl/demos/vector_graphic/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/ui/ -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-demos-2f-vector_graphic-2f-assets

clean-Core-2f-Src-2f-lvgl-2f-demos-2f-vector_graphic-2f-assets:
	-$(RM) ./Core/Src/lvgl/demos/vector_graphic/assets/img_demo_vector_avatar.cyclo ./Core/Src/lvgl/demos/vector_graphic/assets/img_demo_vector_avatar.d ./Core/Src/lvgl/demos/vector_graphic/assets/img_demo_vector_avatar.o ./Core/Src/lvgl/demos/vector_graphic/assets/img_demo_vector_avatar.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-demos-2f-vector_graphic-2f-assets

