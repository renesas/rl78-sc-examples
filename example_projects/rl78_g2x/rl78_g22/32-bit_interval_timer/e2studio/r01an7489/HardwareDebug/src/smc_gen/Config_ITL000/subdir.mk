################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/Config_ITL000/Config_ITL000.c \
../src/smc_gen/Config_ITL000/Config_ITL000_user.c 

COMPILER_OBJS += \
src/smc_gen/Config_ITL000/Config_ITL000.obj \
src/smc_gen/Config_ITL000/Config_ITL000_user.obj 

C_DEPS += \
src/smc_gen/Config_ITL000/Config_ITL000.d \
src/smc_gen/Config_ITL000/Config_ITL000_user.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/Config_ITL000/%.obj: ../src/smc_gen/Config_ITL000/%.c 
	@echo 'Scanning and building file: $<'
	ccrl -subcommand="src\smc_gen\Config_ITL000\cDepSubCommand.tmp" -o "$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -msg_lang=japanese "$<"
	ccrl -subcommand="src\smc_gen\Config_ITL000\cSubCommand.tmp" -msg_lang=japanese -o "$(@:%.d=%.obj)" "$<"


