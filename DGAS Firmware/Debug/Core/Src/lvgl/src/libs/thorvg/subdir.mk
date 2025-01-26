################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/lvgl/src/libs/thorvg/tvgAccessor.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgAnimation.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgCanvas.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgCapi.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgCompressor.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgFill.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgGlCanvas.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgInitializer.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgLoader.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgLottieAnimation.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgLottieBuilder.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgLottieExpressions.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgLottieInterpolator.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgLottieLoader.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgLottieModel.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgLottieModifier.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgLottieParser.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgLottieParserHandler.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgMath.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgPaint.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgPicture.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgRawLoader.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgRender.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSaver.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgScene.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgShape.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgStr.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSvgCssStyle.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSvgLoader.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSvgPath.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSvgSceneBuilder.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSvgUtil.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSwCanvas.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSwFill.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSwImage.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSwMath.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSwMemPool.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSwPostEffect.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSwRaster.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSwRenderer.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSwRle.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSwShape.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgSwStroke.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgTaskScheduler.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgText.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgWgCanvas.cpp \
../Core/Src/lvgl/src/libs/thorvg/tvgXmlParser.cpp 

OBJS += \
./Core/Src/lvgl/src/libs/thorvg/tvgAccessor.o \
./Core/Src/lvgl/src/libs/thorvg/tvgAnimation.o \
./Core/Src/lvgl/src/libs/thorvg/tvgCanvas.o \
./Core/Src/lvgl/src/libs/thorvg/tvgCapi.o \
./Core/Src/lvgl/src/libs/thorvg/tvgCompressor.o \
./Core/Src/lvgl/src/libs/thorvg/tvgFill.o \
./Core/Src/lvgl/src/libs/thorvg/tvgGlCanvas.o \
./Core/Src/lvgl/src/libs/thorvg/tvgInitializer.o \
./Core/Src/lvgl/src/libs/thorvg/tvgLoader.o \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieAnimation.o \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieBuilder.o \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieExpressions.o \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieInterpolator.o \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieLoader.o \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieModel.o \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieModifier.o \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieParser.o \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieParserHandler.o \
./Core/Src/lvgl/src/libs/thorvg/tvgMath.o \
./Core/Src/lvgl/src/libs/thorvg/tvgPaint.o \
./Core/Src/lvgl/src/libs/thorvg/tvgPicture.o \
./Core/Src/lvgl/src/libs/thorvg/tvgRawLoader.o \
./Core/Src/lvgl/src/libs/thorvg/tvgRender.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSaver.o \
./Core/Src/lvgl/src/libs/thorvg/tvgScene.o \
./Core/Src/lvgl/src/libs/thorvg/tvgShape.o \
./Core/Src/lvgl/src/libs/thorvg/tvgStr.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSvgCssStyle.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSvgLoader.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSvgPath.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSvgSceneBuilder.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSvgUtil.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSwCanvas.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSwFill.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSwImage.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSwMath.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSwMemPool.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSwPostEffect.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSwRaster.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSwRenderer.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSwRle.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSwShape.o \
./Core/Src/lvgl/src/libs/thorvg/tvgSwStroke.o \
./Core/Src/lvgl/src/libs/thorvg/tvgTaskScheduler.o \
./Core/Src/lvgl/src/libs/thorvg/tvgText.o \
./Core/Src/lvgl/src/libs/thorvg/tvgWgCanvas.o \
./Core/Src/lvgl/src/libs/thorvg/tvgXmlParser.o 

CPP_DEPS += \
./Core/Src/lvgl/src/libs/thorvg/tvgAccessor.d \
./Core/Src/lvgl/src/libs/thorvg/tvgAnimation.d \
./Core/Src/lvgl/src/libs/thorvg/tvgCanvas.d \
./Core/Src/lvgl/src/libs/thorvg/tvgCapi.d \
./Core/Src/lvgl/src/libs/thorvg/tvgCompressor.d \
./Core/Src/lvgl/src/libs/thorvg/tvgFill.d \
./Core/Src/lvgl/src/libs/thorvg/tvgGlCanvas.d \
./Core/Src/lvgl/src/libs/thorvg/tvgInitializer.d \
./Core/Src/lvgl/src/libs/thorvg/tvgLoader.d \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieAnimation.d \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieBuilder.d \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieExpressions.d \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieInterpolator.d \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieLoader.d \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieModel.d \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieModifier.d \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieParser.d \
./Core/Src/lvgl/src/libs/thorvg/tvgLottieParserHandler.d \
./Core/Src/lvgl/src/libs/thorvg/tvgMath.d \
./Core/Src/lvgl/src/libs/thorvg/tvgPaint.d \
./Core/Src/lvgl/src/libs/thorvg/tvgPicture.d \
./Core/Src/lvgl/src/libs/thorvg/tvgRawLoader.d \
./Core/Src/lvgl/src/libs/thorvg/tvgRender.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSaver.d \
./Core/Src/lvgl/src/libs/thorvg/tvgScene.d \
./Core/Src/lvgl/src/libs/thorvg/tvgShape.d \
./Core/Src/lvgl/src/libs/thorvg/tvgStr.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSvgCssStyle.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSvgLoader.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSvgPath.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSvgSceneBuilder.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSvgUtil.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSwCanvas.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSwFill.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSwImage.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSwMath.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSwMemPool.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSwPostEffect.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSwRaster.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSwRenderer.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSwRle.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSwShape.d \
./Core/Src/lvgl/src/libs/thorvg/tvgSwStroke.d \
./Core/Src/lvgl/src/libs/thorvg/tvgTaskScheduler.d \
./Core/Src/lvgl/src/libs/thorvg/tvgText.d \
./Core/Src/lvgl/src/libs/thorvg/tvgWgCanvas.d \
./Core/Src/lvgl/src/libs/thorvg/tvgXmlParser.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/libs/thorvg/%.o Core/Src/lvgl/src/libs/thorvg/%.su Core/Src/lvgl/src/libs/thorvg/%.cyclo: ../Core/Src/lvgl/src/libs/thorvg/%.cpp Core/Src/lvgl/src/libs/thorvg/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DLV_CONF_INCLUDE_SIMPLE -DDEBUG -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Core/Src/ui/ -I../Core/Src/lvgl/ -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-libs-2f-thorvg

clean-Core-2f-Src-2f-lvgl-2f-src-2f-libs-2f-thorvg:
	-$(RM) ./Core/Src/lvgl/src/libs/thorvg/tvgAccessor.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgAccessor.d ./Core/Src/lvgl/src/libs/thorvg/tvgAccessor.o ./Core/Src/lvgl/src/libs/thorvg/tvgAccessor.su ./Core/Src/lvgl/src/libs/thorvg/tvgAnimation.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgAnimation.d ./Core/Src/lvgl/src/libs/thorvg/tvgAnimation.o ./Core/Src/lvgl/src/libs/thorvg/tvgAnimation.su ./Core/Src/lvgl/src/libs/thorvg/tvgCanvas.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgCanvas.d ./Core/Src/lvgl/src/libs/thorvg/tvgCanvas.o ./Core/Src/lvgl/src/libs/thorvg/tvgCanvas.su ./Core/Src/lvgl/src/libs/thorvg/tvgCapi.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgCapi.d ./Core/Src/lvgl/src/libs/thorvg/tvgCapi.o ./Core/Src/lvgl/src/libs/thorvg/tvgCapi.su ./Core/Src/lvgl/src/libs/thorvg/tvgCompressor.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgCompressor.d ./Core/Src/lvgl/src/libs/thorvg/tvgCompressor.o ./Core/Src/lvgl/src/libs/thorvg/tvgCompressor.su ./Core/Src/lvgl/src/libs/thorvg/tvgFill.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgFill.d ./Core/Src/lvgl/src/libs/thorvg/tvgFill.o ./Core/Src/lvgl/src/libs/thorvg/tvgFill.su ./Core/Src/lvgl/src/libs/thorvg/tvgGlCanvas.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgGlCanvas.d ./Core/Src/lvgl/src/libs/thorvg/tvgGlCanvas.o ./Core/Src/lvgl/src/libs/thorvg/tvgGlCanvas.su ./Core/Src/lvgl/src/libs/thorvg/tvgInitializer.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgInitializer.d ./Core/Src/lvgl/src/libs/thorvg/tvgInitializer.o ./Core/Src/lvgl/src/libs/thorvg/tvgInitializer.su ./Core/Src/lvgl/src/libs/thorvg/tvgLoader.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgLoader.d ./Core/Src/lvgl/src/libs/thorvg/tvgLoader.o ./Core/Src/lvgl/src/libs/thorvg/tvgLoader.su ./Core/Src/lvgl/src/libs/thorvg/tvgLottieAnimation.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgLottieAnimation.d ./Core/Src/lvgl/src/libs/thorvg/tvgLottieAnimation.o ./Core/Src/lvgl/src/libs/thorvg/tvgLottieAnimation.su ./Core/Src/lvgl/src/libs/thorvg/tvgLottieBuilder.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgLottieBuilder.d ./Core/Src/lvgl/src/libs/thorvg/tvgLottieBuilder.o ./Core/Src/lvgl/src/libs/thorvg/tvgLottieBuilder.su ./Core/Src/lvgl/src/libs/thorvg/tvgLottieExpressions.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgLottieExpressions.d ./Core/Src/lvgl/src/libs/thorvg/tvgLottieExpressions.o ./Core/Src/lvgl/src/libs/thorvg/tvgLottieExpressions.su ./Core/Src/lvgl/src/libs/thorvg/tvgLottieInterpolator.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgLottieInterpolator.d ./Core/Src/lvgl/src/libs/thorvg/tvgLottieInterpolator.o ./Core/Src/lvgl/src/libs/thorvg/tvgLottieInterpolator.su ./Core/Src/lvgl/src/libs/thorvg/tvgLottieLoader.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgLottieLoader.d ./Core/Src/lvgl/src/libs/thorvg/tvgLottieLoader.o ./Core/Src/lvgl/src/libs/thorvg/tvgLottieLoader.su ./Core/Src/lvgl/src/libs/thorvg/tvgLottieModel.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgLottieModel.d ./Core/Src/lvgl/src/libs/thorvg/tvgLottieModel.o ./Core/Src/lvgl/src/libs/thorvg/tvgLottieModel.su ./Core/Src/lvgl/src/libs/thorvg/tvgLottieModifier.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgLottieModifier.d ./Core/Src/lvgl/src/libs/thorvg/tvgLottieModifier.o ./Core/Src/lvgl/src/libs/thorvg/tvgLottieModifier.su ./Core/Src/lvgl/src/libs/thorvg/tvgLottieParser.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgLottieParser.d ./Core/Src/lvgl/src/libs/thorvg/tvgLottieParser.o ./Core/Src/lvgl/src/libs/thorvg/tvgLottieParser.su ./Core/Src/lvgl/src/libs/thorvg/tvgLottieParserHandler.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgLottieParserHandler.d ./Core/Src/lvgl/src/libs/thorvg/tvgLottieParserHandler.o ./Core/Src/lvgl/src/libs/thorvg/tvgLottieParserHandler.su ./Core/Src/lvgl/src/libs/thorvg/tvgMath.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgMath.d ./Core/Src/lvgl/src/libs/thorvg/tvgMath.o ./Core/Src/lvgl/src/libs/thorvg/tvgMath.su ./Core/Src/lvgl/src/libs/thorvg/tvgPaint.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgPaint.d ./Core/Src/lvgl/src/libs/thorvg/tvgPaint.o ./Core/Src/lvgl/src/libs/thorvg/tvgPaint.su ./Core/Src/lvgl/src/libs/thorvg/tvgPicture.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgPicture.d ./Core/Src/lvgl/src/libs/thorvg/tvgPicture.o ./Core/Src/lvgl/src/libs/thorvg/tvgPicture.su ./Core/Src/lvgl/src/libs/thorvg/tvgRawLoader.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgRawLoader.d ./Core/Src/lvgl/src/libs/thorvg/tvgRawLoader.o ./Core/Src/lvgl/src/libs/thorvg/tvgRawLoader.su ./Core/Src/lvgl/src/libs/thorvg/tvgRender.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgRender.d ./Core/Src/lvgl/src/libs/thorvg/tvgRender.o ./Core/Src/lvgl/src/libs/thorvg/tvgRender.su ./Core/Src/lvgl/src/libs/thorvg/tvgSaver.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSaver.d ./Core/Src/lvgl/src/libs/thorvg/tvgSaver.o ./Core/Src/lvgl/src/libs/thorvg/tvgSaver.su ./Core/Src/lvgl/src/libs/thorvg/tvgScene.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgScene.d ./Core/Src/lvgl/src/libs/thorvg/tvgScene.o ./Core/Src/lvgl/src/libs/thorvg/tvgScene.su ./Core/Src/lvgl/src/libs/thorvg/tvgShape.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgShape.d ./Core/Src/lvgl/src/libs/thorvg/tvgShape.o ./Core/Src/lvgl/src/libs/thorvg/tvgShape.su ./Core/Src/lvgl/src/libs/thorvg/tvgStr.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgStr.d ./Core/Src/lvgl/src/libs/thorvg/tvgStr.o ./Core/Src/lvgl/src/libs/thorvg/tvgStr.su ./Core/Src/lvgl/src/libs/thorvg/tvgSvgCssStyle.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSvgCssStyle.d ./Core/Src/lvgl/src/libs/thorvg/tvgSvgCssStyle.o ./Core/Src/lvgl/src/libs/thorvg/tvgSvgCssStyle.su ./Core/Src/lvgl/src/libs/thorvg/tvgSvgLoader.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSvgLoader.d ./Core/Src/lvgl/src/libs/thorvg/tvgSvgLoader.o ./Core/Src/lvgl/src/libs/thorvg/tvgSvgLoader.su ./Core/Src/lvgl/src/libs/thorvg/tvgSvgPath.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSvgPath.d ./Core/Src/lvgl/src/libs/thorvg/tvgSvgPath.o ./Core/Src/lvgl/src/libs/thorvg/tvgSvgPath.su ./Core/Src/lvgl/src/libs/thorvg/tvgSvgSceneBuilder.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSvgSceneBuilder.d ./Core/Src/lvgl/src/libs/thorvg/tvgSvgSceneBuilder.o
	-$(RM) ./Core/Src/lvgl/src/libs/thorvg/tvgSvgSceneBuilder.su ./Core/Src/lvgl/src/libs/thorvg/tvgSvgUtil.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSvgUtil.d ./Core/Src/lvgl/src/libs/thorvg/tvgSvgUtil.o ./Core/Src/lvgl/src/libs/thorvg/tvgSvgUtil.su ./Core/Src/lvgl/src/libs/thorvg/tvgSwCanvas.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSwCanvas.d ./Core/Src/lvgl/src/libs/thorvg/tvgSwCanvas.o ./Core/Src/lvgl/src/libs/thorvg/tvgSwCanvas.su ./Core/Src/lvgl/src/libs/thorvg/tvgSwFill.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSwFill.d ./Core/Src/lvgl/src/libs/thorvg/tvgSwFill.o ./Core/Src/lvgl/src/libs/thorvg/tvgSwFill.su ./Core/Src/lvgl/src/libs/thorvg/tvgSwImage.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSwImage.d ./Core/Src/lvgl/src/libs/thorvg/tvgSwImage.o ./Core/Src/lvgl/src/libs/thorvg/tvgSwImage.su ./Core/Src/lvgl/src/libs/thorvg/tvgSwMath.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSwMath.d ./Core/Src/lvgl/src/libs/thorvg/tvgSwMath.o ./Core/Src/lvgl/src/libs/thorvg/tvgSwMath.su ./Core/Src/lvgl/src/libs/thorvg/tvgSwMemPool.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSwMemPool.d ./Core/Src/lvgl/src/libs/thorvg/tvgSwMemPool.o ./Core/Src/lvgl/src/libs/thorvg/tvgSwMemPool.su ./Core/Src/lvgl/src/libs/thorvg/tvgSwPostEffect.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSwPostEffect.d ./Core/Src/lvgl/src/libs/thorvg/tvgSwPostEffect.o ./Core/Src/lvgl/src/libs/thorvg/tvgSwPostEffect.su ./Core/Src/lvgl/src/libs/thorvg/tvgSwRaster.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSwRaster.d ./Core/Src/lvgl/src/libs/thorvg/tvgSwRaster.o ./Core/Src/lvgl/src/libs/thorvg/tvgSwRaster.su ./Core/Src/lvgl/src/libs/thorvg/tvgSwRenderer.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSwRenderer.d ./Core/Src/lvgl/src/libs/thorvg/tvgSwRenderer.o ./Core/Src/lvgl/src/libs/thorvg/tvgSwRenderer.su ./Core/Src/lvgl/src/libs/thorvg/tvgSwRle.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSwRle.d ./Core/Src/lvgl/src/libs/thorvg/tvgSwRle.o ./Core/Src/lvgl/src/libs/thorvg/tvgSwRle.su ./Core/Src/lvgl/src/libs/thorvg/tvgSwShape.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSwShape.d ./Core/Src/lvgl/src/libs/thorvg/tvgSwShape.o ./Core/Src/lvgl/src/libs/thorvg/tvgSwShape.su ./Core/Src/lvgl/src/libs/thorvg/tvgSwStroke.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgSwStroke.d ./Core/Src/lvgl/src/libs/thorvg/tvgSwStroke.o ./Core/Src/lvgl/src/libs/thorvg/tvgSwStroke.su ./Core/Src/lvgl/src/libs/thorvg/tvgTaskScheduler.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgTaskScheduler.d ./Core/Src/lvgl/src/libs/thorvg/tvgTaskScheduler.o ./Core/Src/lvgl/src/libs/thorvg/tvgTaskScheduler.su ./Core/Src/lvgl/src/libs/thorvg/tvgText.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgText.d ./Core/Src/lvgl/src/libs/thorvg/tvgText.o ./Core/Src/lvgl/src/libs/thorvg/tvgText.su ./Core/Src/lvgl/src/libs/thorvg/tvgWgCanvas.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgWgCanvas.d ./Core/Src/lvgl/src/libs/thorvg/tvgWgCanvas.o ./Core/Src/lvgl/src/libs/thorvg/tvgWgCanvas.su ./Core/Src/lvgl/src/libs/thorvg/tvgXmlParser.cyclo ./Core/Src/lvgl/src/libs/thorvg/tvgXmlParser.d ./Core/Src/lvgl/src/libs/thorvg/tvgXmlParser.o ./Core/Src/lvgl/src/libs/thorvg/tvgXmlParser.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-libs-2f-thorvg

