################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl-master/src/libs/expat/xmlparse.c \
../Core/Src/lvgl-master/src/libs/expat/xmlrole.c \
../Core/Src/lvgl-master/src/libs/expat/xmltok.c \
../Core/Src/lvgl-master/src/libs/expat/xmltok_impl.c \
../Core/Src/lvgl-master/src/libs/expat/xmltok_ns.c 

OBJS += \
./Core/Src/lvgl-master/src/libs/expat/xmlparse.o \
./Core/Src/lvgl-master/src/libs/expat/xmlrole.o \
./Core/Src/lvgl-master/src/libs/expat/xmltok.o \
./Core/Src/lvgl-master/src/libs/expat/xmltok_impl.o \
./Core/Src/lvgl-master/src/libs/expat/xmltok_ns.o 

C_DEPS += \
./Core/Src/lvgl-master/src/libs/expat/xmlparse.d \
./Core/Src/lvgl-master/src/libs/expat/xmlrole.d \
./Core/Src/lvgl-master/src/libs/expat/xmltok.d \
./Core/Src/lvgl-master/src/libs/expat/xmltok_impl.d \
./Core/Src/lvgl-master/src/libs/expat/xmltok_ns.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl-master/src/libs/expat/%.o Core/Src/lvgl-master/src/libs/expat/%.su Core/Src/lvgl-master/src/libs/expat/%.cyclo: ../Core/Src/lvgl-master/src/libs/expat/%.c Core/Src/lvgl-master/src/libs/expat/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F750xx -c -I../Core/Inc -I../Core/Src/lvgl-master/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2d-master-2f-src-2f-libs-2f-expat

clean-Core-2f-Src-2f-lvgl-2d-master-2f-src-2f-libs-2f-expat:
	-$(RM) ./Core/Src/lvgl-master/src/libs/expat/xmlparse.cyclo ./Core/Src/lvgl-master/src/libs/expat/xmlparse.d ./Core/Src/lvgl-master/src/libs/expat/xmlparse.o ./Core/Src/lvgl-master/src/libs/expat/xmlparse.su ./Core/Src/lvgl-master/src/libs/expat/xmlrole.cyclo ./Core/Src/lvgl-master/src/libs/expat/xmlrole.d ./Core/Src/lvgl-master/src/libs/expat/xmlrole.o ./Core/Src/lvgl-master/src/libs/expat/xmlrole.su ./Core/Src/lvgl-master/src/libs/expat/xmltok.cyclo ./Core/Src/lvgl-master/src/libs/expat/xmltok.d ./Core/Src/lvgl-master/src/libs/expat/xmltok.o ./Core/Src/lvgl-master/src/libs/expat/xmltok.su ./Core/Src/lvgl-master/src/libs/expat/xmltok_impl.cyclo ./Core/Src/lvgl-master/src/libs/expat/xmltok_impl.d ./Core/Src/lvgl-master/src/libs/expat/xmltok_impl.o ./Core/Src/lvgl-master/src/libs/expat/xmltok_impl.su ./Core/Src/lvgl-master/src/libs/expat/xmltok_ns.cyclo ./Core/Src/lvgl-master/src/libs/expat/xmltok_ns.d ./Core/Src/lvgl-master/src/libs/expat/xmltok_ns.o ./Core/Src/lvgl-master/src/libs/expat/xmltok_ns.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2d-master-2f-src-2f-libs-2f-expat

