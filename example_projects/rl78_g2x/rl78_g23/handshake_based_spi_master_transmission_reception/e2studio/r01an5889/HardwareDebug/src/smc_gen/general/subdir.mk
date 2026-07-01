################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/general/r_cg_lvd_common.c \
../src/smc_gen/general/r_cg_lvd_common_user.c \
../src/smc_gen/general/r_cg_sau_common.c \
../src/smc_gen/general/r_cg_systeminit.c \
../src/smc_gen/general/r_cg_tau_common.c 

COMPILER_OBJS += \
src/smc_gen/general/r_cg_lvd_common.obj \
src/smc_gen/general/r_cg_lvd_common_user.obj \
src/smc_gen/general/r_cg_sau_common.obj \
src/smc_gen/general/r_cg_systeminit.obj \
src/smc_gen/general/r_cg_tau_common.obj 

C_DEPS += \
src/smc_gen/general/r_cg_lvd_common.d \
src/smc_gen/general/r_cg_lvd_common_user.d \
src/smc_gen/general/r_cg_sau_common.d \
src/smc_gen/general/r_cg_systeminit.d \
src/smc_gen/general/r_cg_tau_common.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/general/%.obj: ../src/smc_gen/general/%.c src/smc_gen/general/Compiler.sub
	@echo 'Scanning and building file: $<'
	ccrl -subcommand="src\smc_gen\general\cDepSubCommand.tmp" -o "$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -msg_lang=japanese "$<"
	ccrl -subcommand="src\smc_gen\general\cSubCommand.tmp" -msg_lang=japanese -o "$(@:%.d=%.obj)" "$<"


