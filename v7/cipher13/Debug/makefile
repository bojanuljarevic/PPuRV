################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: cipher13

# Tool invocations
cipher13: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc  -o "cipher13" $(OBJS) $(USER_OBJS) $(LIBS)-L"/home/rtrk/workspace/caesar12/Debug" -L"/home/rtrk/workspace/rot12/Debug" -ldl
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) cipher13
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
