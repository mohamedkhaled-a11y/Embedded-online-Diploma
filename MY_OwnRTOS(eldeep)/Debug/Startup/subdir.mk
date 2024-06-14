################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f103c8tx.s 

OBJS += \
./Startup/startup_stm32f103c8tx.o 

S_DEPS += \
./Startup/startup_stm32f103c8tx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f103c8tx.o: ../Startup/startup_stm32f103c8tx.s
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -c -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/HAL/includes" -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/CMSIS_V5" -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/Stm32_F103C6_Drivers/inc" -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/Eldeep_RTOS/inc" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f103c8tx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

