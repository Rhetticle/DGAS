################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/others/xml/parsers/lv_xml_button_parser.c \
../Core/Src/lvgl/src/others/xml/parsers/lv_xml_chart_parser.c \
../Core/Src/lvgl/src/others/xml/parsers/lv_xml_image_parser.c \
../Core/Src/lvgl/src/others/xml/parsers/lv_xml_label_parser.c \
../Core/Src/lvgl/src/others/xml/parsers/lv_xml_obj_parser.c \
../Core/Src/lvgl/src/others/xml/parsers/lv_xml_slider_parser.c \
../Core/Src/lvgl/src/others/xml/parsers/lv_xml_tabview_parser.c 

OBJS += \
./Core/Src/lvgl/src/others/xml/parsers/lv_xml_button_parser.o \
./Core/Src/lvgl/src/others/xml/parsers/lv_xml_chart_parser.o \
./Core/Src/lvgl/src/others/xml/parsers/lv_xml_image_parser.o \
./Core/Src/lvgl/src/others/xml/parsers/lv_xml_label_parser.o \
./Core/Src/lvgl/src/others/xml/parsers/lv_xml_obj_parser.o \
./Core/Src/lvgl/src/others/xml/parsers/lv_xml_slider_parser.o \
./Core/Src/lvgl/src/others/xml/parsers/lv_xml_tabview_parser.o 

C_DEPS += \
./Core/Src/lvgl/src/others/xml/parsers/lv_xml_button_parser.d \
./Core/Src/lvgl/src/others/xml/parsers/lv_xml_chart_parser.d \
./Core/Src/lvgl/src/others/xml/parsers/lv_xml_image_parser.d \
./Core/Src/lvgl/src/others/xml/parsers/lv_xml_label_parser.d \
./Core/Src/lvgl/src/others/xml/parsers/lv_xml_obj_parser.d \
./Core/Src/lvgl/src/others/xml/parsers/lv_xml_slider_parser.d \
./Core/Src/lvgl/src/others/xml/parsers/lv_xml_tabview_parser.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/others/xml/parsers/%.o Core/Src/lvgl/src/others/xml/parsers/%.su Core/Src/lvgl/src/others/xml/parsers/%.cyclo: ../Core/Src/lvgl/src/others/xml/parsers/%.c Core/Src/lvgl/src/others/xml/parsers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F750xx -c -I../Core/Inc -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-others-2f-xml-2f-parsers

clean-Core-2f-Src-2f-lvgl-2f-src-2f-others-2f-xml-2f-parsers:
	-$(RM) ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_button_parser.cyclo ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_button_parser.d ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_button_parser.o ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_button_parser.su ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_chart_parser.cyclo ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_chart_parser.d ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_chart_parser.o ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_chart_parser.su ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_image_parser.cyclo ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_image_parser.d ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_image_parser.o ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_image_parser.su ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_label_parser.cyclo ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_label_parser.d ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_label_parser.o ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_label_parser.su ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_obj_parser.cyclo ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_obj_parser.d ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_obj_parser.o ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_obj_parser.su ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_slider_parser.cyclo ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_slider_parser.d ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_slider_parser.o ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_slider_parser.su ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_tabview_parser.cyclo ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_tabview_parser.d ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_tabview_parser.o ./Core/Src/lvgl/src/others/xml/parsers/lv_xml_tabview_parser.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-others-2f-xml-2f-parsers

