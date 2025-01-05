################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/osal/lv_cmsis_rtos2.c \
../Core/Src/lvgl/src/osal/lv_freertos.c \
../Core/Src/lvgl/src/osal/lv_mqx.c \
../Core/Src/lvgl/src/osal/lv_os.c \
../Core/Src/lvgl/src/osal/lv_pthread.c \
../Core/Src/lvgl/src/osal/lv_rtthread.c \
../Core/Src/lvgl/src/osal/lv_sdl2.c \
../Core/Src/lvgl/src/osal/lv_windows.c 

OBJS += \
./Core/Src/lvgl/src/osal/lv_cmsis_rtos2.o \
./Core/Src/lvgl/src/osal/lv_freertos.o \
./Core/Src/lvgl/src/osal/lv_mqx.o \
./Core/Src/lvgl/src/osal/lv_os.o \
./Core/Src/lvgl/src/osal/lv_pthread.o \
./Core/Src/lvgl/src/osal/lv_rtthread.o \
./Core/Src/lvgl/src/osal/lv_sdl2.o \
./Core/Src/lvgl/src/osal/lv_windows.o 

C_DEPS += \
./Core/Src/lvgl/src/osal/lv_cmsis_rtos2.d \
./Core/Src/lvgl/src/osal/lv_freertos.d \
./Core/Src/lvgl/src/osal/lv_mqx.d \
./Core/Src/lvgl/src/osal/lv_os.d \
./Core/Src/lvgl/src/osal/lv_pthread.d \
./Core/Src/lvgl/src/osal/lv_rtthread.d \
./Core/Src/lvgl/src/osal/lv_sdl2.d \
./Core/Src/lvgl/src/osal/lv_windows.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/osal/%.o Core/Src/lvgl/src/osal/%.su Core/Src/lvgl/src/osal/%.cyclo: ../Core/Src/lvgl/src/osal/%.c Core/Src/lvgl/src/osal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F750xx -c -I../Core/Inc -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-osal

clean-Core-2f-Src-2f-lvgl-2f-src-2f-osal:
	-$(RM) ./Core/Src/lvgl/src/osal/lv_cmsis_rtos2.cyclo ./Core/Src/lvgl/src/osal/lv_cmsis_rtos2.d ./Core/Src/lvgl/src/osal/lv_cmsis_rtos2.o ./Core/Src/lvgl/src/osal/lv_cmsis_rtos2.su ./Core/Src/lvgl/src/osal/lv_freertos.cyclo ./Core/Src/lvgl/src/osal/lv_freertos.d ./Core/Src/lvgl/src/osal/lv_freertos.o ./Core/Src/lvgl/src/osal/lv_freertos.su ./Core/Src/lvgl/src/osal/lv_mqx.cyclo ./Core/Src/lvgl/src/osal/lv_mqx.d ./Core/Src/lvgl/src/osal/lv_mqx.o ./Core/Src/lvgl/src/osal/lv_mqx.su ./Core/Src/lvgl/src/osal/lv_os.cyclo ./Core/Src/lvgl/src/osal/lv_os.d ./Core/Src/lvgl/src/osal/lv_os.o ./Core/Src/lvgl/src/osal/lv_os.su ./Core/Src/lvgl/src/osal/lv_pthread.cyclo ./Core/Src/lvgl/src/osal/lv_pthread.d ./Core/Src/lvgl/src/osal/lv_pthread.o ./Core/Src/lvgl/src/osal/lv_pthread.su ./Core/Src/lvgl/src/osal/lv_rtthread.cyclo ./Core/Src/lvgl/src/osal/lv_rtthread.d ./Core/Src/lvgl/src/osal/lv_rtthread.o ./Core/Src/lvgl/src/osal/lv_rtthread.su ./Core/Src/lvgl/src/osal/lv_sdl2.cyclo ./Core/Src/lvgl/src/osal/lv_sdl2.d ./Core/Src/lvgl/src/osal/lv_sdl2.o ./Core/Src/lvgl/src/osal/lv_sdl2.su ./Core/Src/lvgl/src/osal/lv_windows.cyclo ./Core/Src/lvgl/src/osal/lv_windows.d ./Core/Src/lvgl/src/osal/lv_windows.o ./Core/Src/lvgl/src/osal/lv_windows.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-osal

