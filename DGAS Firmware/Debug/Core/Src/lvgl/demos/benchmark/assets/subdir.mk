################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/demos/benchmark/assets/img_benchmark_avatar.c \
../Core/Src/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_argb.c \
../Core/Src/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_rgb.c \
../Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.c \
../Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.c \
../Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.c 

C_DEPS += \
./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_avatar.d \
./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_argb.d \
./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_rgb.d \
./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.d \
./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.d \
./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.d 

OBJS += \
./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_avatar.o \
./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_argb.o \
./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_rgb.o \
./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.o \
./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.o \
./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/demos/benchmark/assets/%.o Core/Src/lvgl/demos/benchmark/assets/%.su Core/Src/lvgl/demos/benchmark/assets/%.cyclo: ../Core/Src/lvgl/demos/benchmark/assets/%.c Core/Src/lvgl/demos/benchmark/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/ui/ -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-demos-2f-benchmark-2f-assets

clean-Core-2f-Src-2f-lvgl-2f-demos-2f-benchmark-2f-assets:
	-$(RM) ./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_avatar.cyclo ./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_avatar.d ./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_avatar.o ./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_avatar.su ./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_argb.cyclo ./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_argb.d ./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_argb.o ./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_argb.su ./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_rgb.cyclo ./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_rgb.d ./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_rgb.o ./Core/Src/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_rgb.su ./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.cyclo ./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.d ./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.o ./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.su ./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.cyclo ./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.d ./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.o ./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.su ./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.cyclo ./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.d ./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.o ./Core/Src/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-demos-2f-benchmark-2f-assets

