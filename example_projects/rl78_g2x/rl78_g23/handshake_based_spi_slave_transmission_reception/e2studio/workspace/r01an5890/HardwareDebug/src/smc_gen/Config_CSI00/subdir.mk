################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/Config_CSI00/Config_CSI00.c \
../src/smc_gen/Config_CSI00/Config_CSI00_user.c 

COMPILER_OBJS += \
src/smc_gen/Config_CSI00/Config_CSI00.obj \
src/smc_gen/Config_CSI00/Config_CSI00_user.obj 

C_DEPS += \
src/smc_gen/Config_CSI00/Config_CSI00.d \
src/smc_gen/Config_CSI00/Config_CSI00_user.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/Config_CSI00/%.obj: ../src/smc_gen/Config_CSI00/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo src\smc_gen\Config_CSI00\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\Config_CSI00\cDepSubCommand.tmp"
	ccrl -subcommand="src\smc_gen\Config_CSI00\cDepSubCommand.tmp" -o "$(@:%.obj=%.d)"  -MT="$(@:%.obj=%.obj)"  -MT="$(@:%.obj=%.d)" -msg_lang=japanese "$<"
	@echo src\smc_gen\Config_CSI00\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\Config_CSI00\cSubCommand.tmp"
	ccrl -subcommand="src\smc_gen\Config_CSI00\cSubCommand.tmp" -msg_lang=japanese -o "$(@:%.d=%.obj)" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

