################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/Config_RTC/Config_RTC.c \
../src/smc_gen/Config_RTC/Config_RTC_user.c 

COMPILER_OBJS += \
src/smc_gen/Config_RTC/Config_RTC.obj \
src/smc_gen/Config_RTC/Config_RTC_user.obj 

C_DEPS += \
src/smc_gen/Config_RTC/Config_RTC.d \
src/smc_gen/Config_RTC/Config_RTC_user.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/Config_RTC/%.obj: ../src/smc_gen/Config_RTC/%.c 
	@echo 'Scanning and building file: $<'
	ccrl -subcommand="src\smc_gen\Config_RTC\cDepSubCommand.tmp" -o "$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -msg_lang=english "$<"
	ccrl -subcommand="src\smc_gen\Config_RTC\cSubCommand.tmp" -msg_lang=english -o "$(@:%.d=%.obj)" "$<"


