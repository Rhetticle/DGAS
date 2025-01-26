################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/demos/high_res/lv_demo_high_res.c \
../Core/Src/lvgl/demos/high_res/lv_demo_high_res_api_example.c \
../Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_about.c \
../Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.c \
../Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_smart_home.c \
../Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.c \
../Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_thermostat.c \
../Core/Src/lvgl/demos/high_res/lv_demo_high_res_home.c \
../Core/Src/lvgl/demos/high_res/lv_demo_high_res_top_margin.c \
../Core/Src/lvgl/demos/high_res/lv_demo_high_res_util.c 

C_DEPS += \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res.d \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_api_example.d \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_about.d \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.d \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_smart_home.d \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.d \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_thermostat.d \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_home.d \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_top_margin.d \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_util.d 

OBJS += \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res.o \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_api_example.o \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_about.o \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.o \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_smart_home.o \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.o \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_thermostat.o \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_home.o \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_top_margin.o \
./Core/Src/lvgl/demos/high_res/lv_demo_high_res_util.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/demos/high_res/%.o Core/Src/lvgl/demos/high_res/%.su Core/Src/lvgl/demos/high_res/%.cyclo: ../Core/Src/lvgl/demos/high_res/%.c Core/Src/lvgl/demos/high_res/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/ui/ -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-demos-2f-high_res

clean-Core-2f-Src-2f-lvgl-2f-demos-2f-high_res:
	-$(RM) ./Core/Src/lvgl/demos/high_res/lv_demo_high_res.cyclo ./Core/Src/lvgl/demos/high_res/lv_demo_high_res.d ./Core/Src/lvgl/demos/high_res/lv_demo_high_res.o ./Core/Src/lvgl/demos/high_res/lv_demo_high_res.su ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_api_example.cyclo ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_api_example.d ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_api_example.o ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_api_example.su ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_about.cyclo ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_about.d ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_about.o ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_about.su ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.cyclo ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.d ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.o ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.su ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_smart_home.cyclo ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_smart_home.d ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_smart_home.o ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_smart_home.su ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.cyclo ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.d ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.o ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.su ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_thermostat.cyclo ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_thermostat.d ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_thermostat.o ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_app_thermostat.su ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_home.cyclo ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_home.d ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_home.o ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_home.su ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_top_margin.cyclo ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_top_margin.d ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_top_margin.o ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_top_margin.su ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_util.cyclo ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_util.d ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_util.o ./Core/Src/lvgl/demos/high_res/lv_demo_high_res_util.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-demos-2f-high_res

