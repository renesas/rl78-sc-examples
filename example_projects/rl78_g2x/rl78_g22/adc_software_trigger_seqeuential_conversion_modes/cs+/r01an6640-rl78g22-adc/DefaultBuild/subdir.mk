################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../main.c 

COMPILER_OBJS += \
main.obj 

C_DEPS += \
main.d 

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c Compiler.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo cDepSubCommand.tmp=
	@sed -e "s/^/ /" "cDepSubCommand.tmp"
	ccrl -subcommand="cDepSubCommand.tmp" -o "$(@:%.obj=%.d)"  -MT="$(@:%.obj=%.obj)"  -MT="$(@:%.obj=%.d)" -msg_lang=japanese "$<"
	@echo cSubCommand.tmp=
	@sed -e "s/^/ /" "cSubCommand.tmp"
	ccrl -subcommand="cSubCommand.tmp" -msg_lang=japanese -o "$(@:%.d=%.obj)" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

