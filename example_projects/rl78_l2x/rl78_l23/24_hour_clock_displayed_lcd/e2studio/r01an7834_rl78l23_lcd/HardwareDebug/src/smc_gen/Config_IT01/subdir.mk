################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/Config_IT01/Config_IT01.c \
../src/smc_gen/Config_IT01/Config_IT01_user.c 

COMPILER_OBJS += \
src/smc_gen/Config_IT01/Config_IT01.obj \
src/smc_gen/Config_IT01/Config_IT01_user.obj 

C_DEPS += \
src/smc_gen/Config_IT01/Config_IT01.d \
src/smc_gen/Config_IT01/Config_IT01_user.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/Config_IT01/%.obj: ../src/smc_gen/Config_IT01/%.c 
	@echo 'Scanning and building file: $<'
	ccrl -subcommand="src\smc_gen\Config_IT01\cDepSubCommand.tmp" -o "$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -msg_lang=english "$<"
	ccrl -subcommand="src\smc_gen\Config_IT01\cSubCommand.tmp" -msg_lang=english -o "$(@:%.d=%.obj)" "$<"


