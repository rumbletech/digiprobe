################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/DP_Src/Ct_RCC.cpp \
../Drivers/DP_Src/DP_RCC.cpp \
../Drivers/DP_Src/DP_SYSTICK.cpp \
../Drivers/DP_Src/DP_USB.cpp 

OBJS += \
./Drivers/DP_Src/Ct_RCC.o \
./Drivers/DP_Src/DP_RCC.o \
./Drivers/DP_Src/DP_SYSTICK.o \
./Drivers/DP_Src/DP_USB.o 

CPP_DEPS += \
./Drivers/DP_Src/Ct_RCC.d \
./Drivers/DP_Src/DP_RCC.d \
./Drivers/DP_Src/DP_SYSTICK.d \
./Drivers/DP_Src/DP_USB.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/DP_Src/Ct_RCC.o: ../Drivers/DP_Src/Ct_RCC.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32F103xB -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I"C:/Users/Garmoosh/STM32CubeIDE/workspace_1.3.0/DigiProbe/Drivers/DP_Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Drivers/DP_Src/Ct_RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/DP_Src/DP_RCC.o: ../Drivers/DP_Src/DP_RCC.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32F103xB -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I"C:/Users/Garmoosh/STM32CubeIDE/workspace_1.3.0/DigiProbe/Drivers/DP_Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Drivers/DP_Src/DP_RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/DP_Src/DP_SYSTICK.o: ../Drivers/DP_Src/DP_SYSTICK.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32F103xB -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I"C:/Users/Garmoosh/STM32CubeIDE/workspace_1.3.0/DigiProbe/Drivers/DP_Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Drivers/DP_Src/DP_SYSTICK.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/DP_Src/DP_USB.o: ../Drivers/DP_Src/DP_USB.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32F103xB -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I"C:/Users/Garmoosh/STM32CubeIDE/workspace_1.3.0/DigiProbe/Drivers/DP_Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Drivers/DP_Src/DP_USB.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

