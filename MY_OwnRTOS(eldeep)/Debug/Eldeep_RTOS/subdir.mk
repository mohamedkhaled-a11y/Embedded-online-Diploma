################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Eldeep_RTOS/CortexMx_Porting.c \
../Eldeep_RTOS/MYRTOS_FIFO.c \
../Eldeep_RTOS/schedular.c 

OBJS += \
./Eldeep_RTOS/CortexMx_Porting.o \
./Eldeep_RTOS/MYRTOS_FIFO.o \
./Eldeep_RTOS/schedular.o 

C_DEPS += \
./Eldeep_RTOS/CortexMx_Porting.d \
./Eldeep_RTOS/MYRTOS_FIFO.d \
./Eldeep_RTOS/schedular.d 


# Each subdirectory must supply rules for building sources it contributes
Eldeep_RTOS/CortexMx_Porting.o: ../Eldeep_RTOS/CortexMx_Porting.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/Eldeep_RTOS/inc" -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/HAL/includes" -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/Stm32_F103C6_Drivers/inc" -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/CMSIS_V5" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Eldeep_RTOS/CortexMx_Porting.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Eldeep_RTOS/MYRTOS_FIFO.o: ../Eldeep_RTOS/MYRTOS_FIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/Eldeep_RTOS/inc" -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/HAL/includes" -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/Stm32_F103C6_Drivers/inc" -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/CMSIS_V5" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Eldeep_RTOS/MYRTOS_FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Eldeep_RTOS/schedular.o: ../Eldeep_RTOS/schedular.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/Eldeep_RTOS/inc" -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/HAL/includes" -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/Stm32_F103C6_Drivers/inc" -I"F:/embedded_diploma/Arm Architecture/MY_RTOS/MY_RTOS/rtos/CMSIS_V5" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Eldeep_RTOS/schedular.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

