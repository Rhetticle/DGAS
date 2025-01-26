################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_matrix.c 

CPP_SRCS += \
../Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_tvg.cpp 

C_DEPS += \
./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_matrix.d 

OBJS += \
./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_matrix.o \
./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_tvg.o 

CPP_DEPS += \
./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_tvg.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/others/vg_lite_tvg/%.o Core/Src/lvgl/src/others/vg_lite_tvg/%.su Core/Src/lvgl/src/others/vg_lite_tvg/%.cyclo: ../Core/Src/lvgl/src/others/vg_lite_tvg/%.c Core/Src/lvgl/src/others/vg_lite_tvg/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/ui/ -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/lvgl/src/others/vg_lite_tvg/%.o Core/Src/lvgl/src/others/vg_lite_tvg/%.su Core/Src/lvgl/src/others/vg_lite_tvg/%.cyclo: ../Core/Src/lvgl/src/others/vg_lite_tvg/%.cpp Core/Src/lvgl/src/others/vg_lite_tvg/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/ui/ -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-others-2f-vg_lite_tvg

clean-Core-2f-Src-2f-lvgl-2f-src-2f-others-2f-vg_lite_tvg:
	-$(RM) ./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_matrix.cyclo ./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_matrix.d ./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_matrix.o ./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_matrix.su ./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_tvg.cyclo ./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_tvg.d ./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_tvg.o ./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_tvg.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-others-2f-vg_lite_tvg

