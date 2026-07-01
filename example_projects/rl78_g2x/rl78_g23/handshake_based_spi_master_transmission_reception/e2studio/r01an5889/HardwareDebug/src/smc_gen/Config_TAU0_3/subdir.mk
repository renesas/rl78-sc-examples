################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/Config_TAU0_3/Config_TAU0_3.c \
../src/smc_gen/Config_TAU0_3/Config_TAU0_3_user.c 

COMPILER_OBJS += \
src/smc_gen/Config_TAU0_3/Config_TAU0_3.obj \
src/smc_gen/Config_TAU0_3/Config_TAU0_3_user.obj 

C_DEPS += \
src/smc_gen/Config_TAU0_3/Config_TAU0_3.d \
src/smc_gen/Config_TAU0_3/Config_TAU0_3_user.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/Config_TAU0_3/%.obj: ../src/smc_gen/Config_TAU0_3/%.c src/smc_gen/Config_TAU0_3/Compiler.sub
	@echo 'Scanning and building file: $<'
	ccrl -subcommand="src\smc_gen\Config_TAU0_3\cDepSubCommand.tmp" -o "$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -msg_lang=japanese "$<"
	ccrl -subcommand="src\smc_gen\Config_TAU0_3\cSubCommand.tmp" -msg_lang=japanese -o "$(@:%.d=%.obj)" "$<"


