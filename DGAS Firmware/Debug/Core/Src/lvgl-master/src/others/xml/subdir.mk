################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl-master/src/others/xml/lv_xml.c \
../Core/Src/lvgl-master/src/others/xml/lv_xml_base_types.c \
../Core/Src/lvgl-master/src/others/xml/lv_xml_component.c \
../Core/Src/lvgl-master/src/others/xml/lv_xml_parser.c \
../Core/Src/lvgl-master/src/others/xml/lv_xml_style.c \
../Core/Src/lvgl-master/src/others/xml/lv_xml_utils.c \
../Core/Src/lvgl-master/src/others/xml/lv_xml_widget.c 

OBJS += \
./Core/Src/lvgl-master/src/others/xml/lv_xml.o \
./Core/Src/lvgl-master/src/others/xml/lv_xml_base_types.o \
./Core/Src/lvgl-master/src/others/xml/lv_xml_component.o \
./Core/Src/lvgl-master/src/others/xml/lv_xml_parser.o \
./Core/Src/lvgl-master/src/others/xml/lv_xml_style.o \
./Core/Src/lvgl-master/src/others/xml/lv_xml_utils.o \
./Core/Src/lvgl-master/src/others/xml/lv_xml_widget.o 

C_DEPS += \
./Core/Src/lvgl-master/src/others/xml/lv_xml.d \
./Core/Src/lvgl-master/src/others/xml/lv_xml_base_types.d \
./Core/Src/lvgl-master/src/others/xml/lv_xml_component.d \
./Core/Src/lvgl-master/src/others/xml/lv_xml_parser.d \
./Core/Src/lvgl-master/src/others/xml/lv_xml_style.d \
./Core/Src/lvgl-master/src/others/xml/lv_xml_utils.d \
./Core/Src/lvgl-master/src/others/xml/lv_xml_widget.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl-master/src/others/xml/%.o Core/Src/lvgl-master/src/others/xml/%.su Core/Src/lvgl-master/src/others/xml/%.cyclo: ../Core/Src/lvgl-master/src/others/xml/%.c Core/Src/lvgl-master/src/others/xml/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F750xx -c -I../Core/Inc -I../Core/Src/lvgl-master/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2d-master-2f-src-2f-others-2f-xml

clean-Core-2f-Src-2f-lvgl-2d-master-2f-src-2f-others-2f-xml:
	-$(RM) ./Core/Src/lvgl-master/src/others/xml/lv_xml.cyclo ./Core/Src/lvgl-master/src/others/xml/lv_xml.d ./Core/Src/lvgl-master/src/others/xml/lv_xml.o ./Core/Src/lvgl-master/src/others/xml/lv_xml.su ./Core/Src/lvgl-master/src/others/xml/lv_xml_base_types.cyclo ./Core/Src/lvgl-master/src/others/xml/lv_xml_base_types.d ./Core/Src/lvgl-master/src/others/xml/lv_xml_base_types.o ./Core/Src/lvgl-master/src/others/xml/lv_xml_base_types.su ./Core/Src/lvgl-master/src/others/xml/lv_xml_component.cyclo ./Core/Src/lvgl-master/src/others/xml/lv_xml_component.d ./Core/Src/lvgl-master/src/others/xml/lv_xml_component.o ./Core/Src/lvgl-master/src/others/xml/lv_xml_component.su ./Core/Src/lvgl-master/src/others/xml/lv_xml_parser.cyclo ./Core/Src/lvgl-master/src/others/xml/lv_xml_parser.d ./Core/Src/lvgl-master/src/others/xml/lv_xml_parser.o ./Core/Src/lvgl-master/src/others/xml/lv_xml_parser.su ./Core/Src/lvgl-master/src/others/xml/lv_xml_style.cyclo ./Core/Src/lvgl-master/src/others/xml/lv_xml_style.d ./Core/Src/lvgl-master/src/others/xml/lv_xml_style.o ./Core/Src/lvgl-master/src/others/xml/lv_xml_style.su ./Core/Src/lvgl-master/src/others/xml/lv_xml_utils.cyclo ./Core/Src/lvgl-master/src/others/xml/lv_xml_utils.d ./Core/Src/lvgl-master/src/others/xml/lv_xml_utils.o ./Core/Src/lvgl-master/src/others/xml/lv_xml_utils.su ./Core/Src/lvgl-master/src/others/xml/lv_xml_widget.cyclo ./Core/Src/lvgl-master/src/others/xml/lv_xml_widget.d ./Core/Src/lvgl-master/src/others/xml/lv_xml_widget.o ./Core/Src/lvgl-master/src/others/xml/lv_xml_widget.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2d-master-2f-src-2f-others-2f-xml

