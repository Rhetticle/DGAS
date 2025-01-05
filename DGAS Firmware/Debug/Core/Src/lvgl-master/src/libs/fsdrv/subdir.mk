################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_cbfs.c \
../Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_fatfs.c \
../Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_littlefs.c \
../Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_memfs.c \
../Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_posix.c \
../Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_stdio.c \
../Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_win32.c 

OBJS += \
./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_cbfs.o \
./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_fatfs.o \
./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_littlefs.o \
./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_memfs.o \
./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_posix.o \
./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_stdio.o \
./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_win32.o 

C_DEPS += \
./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_cbfs.d \
./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_fatfs.d \
./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_littlefs.d \
./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_memfs.d \
./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_posix.d \
./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_stdio.d \
./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_win32.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl-master/src/libs/fsdrv/%.o Core/Src/lvgl-master/src/libs/fsdrv/%.su Core/Src/lvgl-master/src/libs/fsdrv/%.cyclo: ../Core/Src/lvgl-master/src/libs/fsdrv/%.c Core/Src/lvgl-master/src/libs/fsdrv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F750xx -c -I../Core/Inc -I../Core/Src/lvgl-master/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2d-master-2f-src-2f-libs-2f-fsdrv

clean-Core-2f-Src-2f-lvgl-2d-master-2f-src-2f-libs-2f-fsdrv:
	-$(RM) ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_cbfs.cyclo ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_cbfs.d ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_cbfs.o ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_cbfs.su ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_fatfs.cyclo ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_fatfs.d ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_fatfs.o ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_fatfs.su ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_littlefs.cyclo ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_littlefs.d ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_littlefs.o ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_littlefs.su ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_memfs.cyclo ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_memfs.d ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_memfs.o ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_memfs.su ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_posix.cyclo ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_posix.d ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_posix.o ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_posix.su ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_stdio.cyclo ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_stdio.d ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_stdio.o ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_stdio.su ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_win32.cyclo ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_win32.d ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_win32.o ./Core/Src/lvgl-master/src/libs/fsdrv/lv_fs_win32.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2d-master-2f-src-2f-libs-2f-fsdrv

