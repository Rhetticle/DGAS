################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl-master/demos/ebike/lv_demo_ebike.c \
../Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_home.c \
../Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_settings.c \
../Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_stats.c 

OBJS += \
./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike.o \
./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_home.o \
./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_settings.o \
./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_stats.o 

C_DEPS += \
./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike.d \
./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_home.d \
./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_settings.d \
./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_stats.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl-master/demos/ebike/%.o Core/Src/lvgl-master/demos/ebike/%.su Core/Src/lvgl-master/demos/ebike/%.cyclo: ../Core/Src/lvgl-master/demos/ebike/%.c Core/Src/lvgl-master/demos/ebike/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F750xx -c -I../Core/Inc -I../Core/Src/lvgl-master/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2d-master-2f-demos-2f-ebike

clean-Core-2f-Src-2f-lvgl-2d-master-2f-demos-2f-ebike:
	-$(RM) ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike.cyclo ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike.d ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike.o ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike.su ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_home.cyclo ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_home.d ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_home.o ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_home.su ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_settings.cyclo ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_settings.d ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_settings.o ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_settings.su ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_stats.cyclo ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_stats.d ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_stats.o ./Core/Src/lvgl-master/demos/ebike/lv_demo_ebike_stats.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2d-master-2f-demos-2f-ebike

