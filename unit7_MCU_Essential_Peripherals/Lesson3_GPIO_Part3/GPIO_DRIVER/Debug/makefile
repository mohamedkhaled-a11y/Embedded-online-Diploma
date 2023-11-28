################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STM32F103C6_Drivers/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
GPIO_DRIVERs.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
GPIO_DRIVERs.list \

OBJCOPY_HEX += \
GPIO_DRIVERs.hex \

OBJCOPY_BIN += \
GPIO_DRIVERs.bin \


# All Target
all: GPIO_DRIVERs.elf secondary-outputs

# Tool invocations
GPIO_DRIVERs.elf: $(OBJS) $(USER_OBJS) D:\embedded\ diploma\unit7\ARM\GPIO_DRIVER2\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "GPIO_DRIVERs.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\embedded diploma\unit7\ARM\GPIO_DRIVER2\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="GPIO_DRIVERs.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

GPIO_DRIVERs.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "GPIO_DRIVERs.list"
	@echo 'Finished building: $@'
	@echo ' '

GPIO_DRIVERs.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "GPIO_DRIVERs.hex"
	@echo 'Finished building: $@'
	@echo ' '

GPIO_DRIVERs.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "GPIO_DRIVERs.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
