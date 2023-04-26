################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/stm32l562e_discovery.c \
../Drivers/BSP/stm32l562e_discovery_bus.c \
../Drivers/BSP/stm32l562e_discovery_lcd.c 

C_DEPS += \
./Drivers/BSP/stm32l562e_discovery.d \
./Drivers/BSP/stm32l562e_discovery_bus.d \
./Drivers/BSP/stm32l562e_discovery_lcd.d 

OBJS += \
./Drivers/BSP/stm32l562e_discovery.o \
./Drivers/BSP/stm32l562e_discovery_bus.o \
./Drivers/BSP/stm32l562e_discovery_lcd.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/%.o Drivers/BSP/%.su Drivers/BSP/%.cyclo: ../Drivers/BSP/%.c Drivers/BSP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L562xx -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I../DISPLAY/Target -I../Drivers/BSP/Components/st7789h2 -I../Drivers/BSP/Components/Common -I../Drivers/BSP -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP

clean-Drivers-2f-BSP:
	-$(RM) ./Drivers/BSP/stm32l562e_discovery.cyclo ./Drivers/BSP/stm32l562e_discovery.d ./Drivers/BSP/stm32l562e_discovery.o ./Drivers/BSP/stm32l562e_discovery.su ./Drivers/BSP/stm32l562e_discovery_bus.cyclo ./Drivers/BSP/stm32l562e_discovery_bus.d ./Drivers/BSP/stm32l562e_discovery_bus.o ./Drivers/BSP/stm32l562e_discovery_bus.su ./Drivers/BSP/stm32l562e_discovery_lcd.cyclo ./Drivers/BSP/stm32l562e_discovery_lcd.d ./Drivers/BSP/stm32l562e_discovery_lcd.o ./Drivers/BSP/stm32l562e_discovery_lcd.su

.PHONY: clean-Drivers-2f-BSP

