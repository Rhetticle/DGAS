################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/demos/music/lv_demo_music.c \
../Core/Src/lvgl/demos/music/lv_demo_music_list.c \
../Core/Src/lvgl/demos/music/lv_demo_music_main.c 

C_DEPS += \
./Core/Src/lvgl/demos/music/lv_demo_music.d \
./Core/Src/lvgl/demos/music/lv_demo_music_list.d \
./Core/Src/lvgl/demos/music/lv_demo_music_main.d 

OBJS += \
./Core/Src/lvgl/demos/music/lv_demo_music.o \
./Core/Src/lvgl/demos/music/lv_demo_music_list.o \
./Core/Src/lvgl/demos/music/lv_demo_music_main.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/demos/music/%.o Core/Src/lvgl/demos/music/%.su Core/Src/lvgl/demos/music/%.cyclo: ../Core/Src/lvgl/demos/music/%.c Core/Src/lvgl/demos/music/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/ui/ -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-demos-2f-music

clean-Core-2f-Src-2f-lvgl-2f-demos-2f-music:
	-$(RM) ./Core/Src/lvgl/demos/music/lv_demo_music.cyclo ./Core/Src/lvgl/demos/music/lv_demo_music.d ./Core/Src/lvgl/demos/music/lv_demo_music.o ./Core/Src/lvgl/demos/music/lv_demo_music.su ./Core/Src/lvgl/demos/music/lv_demo_music_list.cyclo ./Core/Src/lvgl/demos/music/lv_demo_music_list.d ./Core/Src/lvgl/demos/music/lv_demo_music_list.o ./Core/Src/lvgl/demos/music/lv_demo_music_list.su ./Core/Src/lvgl/demos/music/lv_demo_music_main.cyclo ./Core/Src/lvgl/demos/music/lv_demo_music_main.d ./Core/Src/lvgl/demos/music/lv_demo_music_main.o ./Core/Src/lvgl/demos/music/lv_demo_music_main.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-demos-2f-music

