################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/libs/freetype/lv_freetype.c \
../Core/Src/lvgl/src/libs/freetype/lv_freetype_glyph.c \
../Core/Src/lvgl/src/libs/freetype/lv_freetype_image.c \
../Core/Src/lvgl/src/libs/freetype/lv_freetype_outline.c \
../Core/Src/lvgl/src/libs/freetype/lv_ftsystem.c 

C_DEPS += \
./Core/Src/lvgl/src/libs/freetype/lv_freetype.d \
./Core/Src/lvgl/src/libs/freetype/lv_freetype_glyph.d \
./Core/Src/lvgl/src/libs/freetype/lv_freetype_image.d \
./Core/Src/lvgl/src/libs/freetype/lv_freetype_outline.d \
./Core/Src/lvgl/src/libs/freetype/lv_ftsystem.d 

OBJS += \
./Core/Src/lvgl/src/libs/freetype/lv_freetype.o \
./Core/Src/lvgl/src/libs/freetype/lv_freetype_glyph.o \
./Core/Src/lvgl/src/libs/freetype/lv_freetype_image.o \
./Core/Src/lvgl/src/libs/freetype/lv_freetype_outline.o \
./Core/Src/lvgl/src/libs/freetype/lv_ftsystem.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/libs/freetype/%.o Core/Src/lvgl/src/libs/freetype/%.su Core/Src/lvgl/src/libs/freetype/%.cyclo: ../Core/Src/lvgl/src/libs/freetype/%.c Core/Src/lvgl/src/libs/freetype/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/ui/ -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-libs-2f-freetype

clean-Core-2f-Src-2f-lvgl-2f-src-2f-libs-2f-freetype:
	-$(RM) ./Core/Src/lvgl/src/libs/freetype/lv_freetype.cyclo ./Core/Src/lvgl/src/libs/freetype/lv_freetype.d ./Core/Src/lvgl/src/libs/freetype/lv_freetype.o ./Core/Src/lvgl/src/libs/freetype/lv_freetype.su ./Core/Src/lvgl/src/libs/freetype/lv_freetype_glyph.cyclo ./Core/Src/lvgl/src/libs/freetype/lv_freetype_glyph.d ./Core/Src/lvgl/src/libs/freetype/lv_freetype_glyph.o ./Core/Src/lvgl/src/libs/freetype/lv_freetype_glyph.su ./Core/Src/lvgl/src/libs/freetype/lv_freetype_image.cyclo ./Core/Src/lvgl/src/libs/freetype/lv_freetype_image.d ./Core/Src/lvgl/src/libs/freetype/lv_freetype_image.o ./Core/Src/lvgl/src/libs/freetype/lv_freetype_image.su ./Core/Src/lvgl/src/libs/freetype/lv_freetype_outline.cyclo ./Core/Src/lvgl/src/libs/freetype/lv_freetype_outline.d ./Core/Src/lvgl/src/libs/freetype/lv_freetype_outline.o ./Core/Src/lvgl/src/libs/freetype/lv_freetype_outline.su ./Core/Src/lvgl/src/libs/freetype/lv_ftsystem.cyclo ./Core/Src/lvgl/src/libs/freetype/lv_ftsystem.d ./Core/Src/lvgl/src/libs/freetype/lv_ftsystem.o ./Core/Src/lvgl/src/libs/freetype/lv_ftsystem.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-libs-2f-freetype

