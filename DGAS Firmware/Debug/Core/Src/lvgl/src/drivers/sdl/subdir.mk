################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/drivers/sdl/lv_sdl_keyboard.c \
../Core/Src/lvgl/src/drivers/sdl/lv_sdl_mouse.c \
../Core/Src/lvgl/src/drivers/sdl/lv_sdl_mousewheel.c \
../Core/Src/lvgl/src/drivers/sdl/lv_sdl_window.c 

C_DEPS += \
./Core/Src/lvgl/src/drivers/sdl/lv_sdl_keyboard.d \
./Core/Src/lvgl/src/drivers/sdl/lv_sdl_mouse.d \
./Core/Src/lvgl/src/drivers/sdl/lv_sdl_mousewheel.d \
./Core/Src/lvgl/src/drivers/sdl/lv_sdl_window.d 

OBJS += \
./Core/Src/lvgl/src/drivers/sdl/lv_sdl_keyboard.o \
./Core/Src/lvgl/src/drivers/sdl/lv_sdl_mouse.o \
./Core/Src/lvgl/src/drivers/sdl/lv_sdl_mousewheel.o \
./Core/Src/lvgl/src/drivers/sdl/lv_sdl_window.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/drivers/sdl/%.o Core/Src/lvgl/src/drivers/sdl/%.su Core/Src/lvgl/src/drivers/sdl/%.cyclo: ../Core/Src/lvgl/src/drivers/sdl/%.c Core/Src/lvgl/src/drivers/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/ui/ -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-drivers-2f-sdl

clean-Core-2f-Src-2f-lvgl-2f-src-2f-drivers-2f-sdl:
	-$(RM) ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_keyboard.cyclo ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_keyboard.d ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_keyboard.o ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_keyboard.su ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_mouse.cyclo ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_mouse.d ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_mouse.o ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_mouse.su ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_mousewheel.cyclo ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_mousewheel.d ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_mousewheel.o ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_mousewheel.su ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_window.cyclo ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_window.d ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_window.o ./Core/Src/lvgl/src/drivers/sdl/lv_sdl_window.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-drivers-2f-sdl

