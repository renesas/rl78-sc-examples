################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
ASM_SRCS += \
C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/r_bsp/mcu/all/cstart.asm \
C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/r_bsp/mcu/all/r_bsp_common_ccrl.asm 

C_SRCS += \
C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/r_bsp/mcu/all/r_bsp_common.c 

ASSEMBLER_OBJS += \
Smart\ Configurator/r_bsp/mcu/all/cstart.obj \
Smart\ Configurator/r_bsp/mcu/all/r_bsp_common_ccrl.obj 

ASM_DEPS += \
Smart\ Configurator/r_bsp/mcu/all/cstart.d \
Smart\ Configurator/r_bsp/mcu/all/r_bsp_common_ccrl.d 

COMPILER_OBJS += \
Smart\ Configurator/r_bsp/mcu/all/r_bsp_common.obj 

C_DEPS += \
Smart\ Configurator/r_bsp/mcu/all/r_bsp_common.d 

# Each subdirectory must supply rules for building sources it contributes
Smart\ Configurator/r_bsp/mcu/all/cstart.obj: C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/r_bsp/mcu/all/cstart.asm Smart\ Configurator/r_bsp/mcu/all/cstart.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Assembler'
	@echo Smart Configurator\r_bsp\mcu\all\cstartasmDepSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\r_bsp\mcu\all\cstartasmDepSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\r_bsp\mcu\all\cstartasmDepSubCommand.tmp" -msg_lang=japanese "$<"
	@echo Smart Configurator\r_bsp\mcu\all\cstartasmSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\r_bsp\mcu\all\cstartasmSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\r_bsp\mcu\all\cstartasmSubCommand.tmp" -msg_lang=japanese "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

Smart\ Configurator/r_bsp/mcu/all/r_bsp_common.obj: C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/r_bsp/mcu/all/r_bsp_common.c Smart\ Configurator/r_bsp/mcu/all/r_bsp_common.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo Smart Configurator\r_bsp\mcu\all\r_bsp_commoncDepSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\r_bsp\mcu\all\r_bsp_commoncDepSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\r_bsp\mcu\all\r_bsp_commoncDepSubCommand.tmp" -msg_lang=japanese "$<"
	@echo Smart Configurator\r_bsp\mcu\all\r_bsp_commoncSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\r_bsp\mcu\all\r_bsp_commoncSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\r_bsp\mcu\all\r_bsp_commoncSubCommand.tmp" -msg_lang=japanese "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

Smart\ Configurator/r_bsp/mcu/all/r_bsp_common_ccrl.obj: C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/r_bsp/mcu/all/r_bsp_common_ccrl.asm Smart\ Configurator/r_bsp/mcu/all/r_bsp_common_ccrl.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Assembler'
	@echo Smart Configurator\r_bsp\mcu\all\r_bsp_common_ccrlasmDepSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\r_bsp\mcu\all\r_bsp_common_ccrlasmDepSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\r_bsp\mcu\all\r_bsp_common_ccrlasmDepSubCommand.tmp" -msg_lang=japanese "$<"
	@echo Smart Configurator\r_bsp\mcu\all\r_bsp_common_ccrlasmSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\r_bsp\mcu\all\r_bsp_common_ccrlasmSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\r_bsp\mcu\all\r_bsp_common_ccrlasmSubCommand.tmp" -msg_lang=japanese "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

