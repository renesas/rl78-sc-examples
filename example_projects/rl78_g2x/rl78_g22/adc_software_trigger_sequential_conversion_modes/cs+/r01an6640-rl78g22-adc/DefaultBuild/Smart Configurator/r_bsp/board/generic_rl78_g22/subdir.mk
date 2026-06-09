################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/r_bsp/board/generic_rl78_g22/hdwinit.c \
C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/r_bsp/board/generic_rl78_g22/r_bsp_init.c 

ASM_SRCS += \
C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/r_bsp/board/generic_rl78_g22/stkinit.asm 

ASSEMBLER_OBJS += \
Smart\ Configurator/r_bsp/board/generic_rl78_g22/stkinit.obj 

ASM_DEPS += \
Smart\ Configurator/r_bsp/board/generic_rl78_g22/stkinit.d 

COMPILER_OBJS += \
Smart\ Configurator/r_bsp/board/generic_rl78_g22/hdwinit.obj \
Smart\ Configurator/r_bsp/board/generic_rl78_g22/r_bsp_init.obj 

C_DEPS += \
Smart\ Configurator/r_bsp/board/generic_rl78_g22/hdwinit.d \
Smart\ Configurator/r_bsp/board/generic_rl78_g22/r_bsp_init.d 

# Each subdirectory must supply rules for building sources it contributes
Smart\ Configurator/r_bsp/board/generic_rl78_g22/hdwinit.obj: C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/r_bsp/board/generic_rl78_g22/hdwinit.c Smart\ Configurator/r_bsp/board/generic_rl78_g22/hdwinit.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo Smart Configurator\r_bsp\board\generic_rl78_g22\hdwinitcDepSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\r_bsp\board\generic_rl78_g22\hdwinitcDepSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\r_bsp\board\generic_rl78_g22\hdwinitcDepSubCommand.tmp" -msg_lang=japanese "$<"
	@echo Smart Configurator\r_bsp\board\generic_rl78_g22\hdwinitcSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\r_bsp\board\generic_rl78_g22\hdwinitcSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\r_bsp\board\generic_rl78_g22\hdwinitcSubCommand.tmp" -msg_lang=japanese "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

Smart\ Configurator/r_bsp/board/generic_rl78_g22/r_bsp_init.obj: C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/r_bsp/board/generic_rl78_g22/r_bsp_init.c Smart\ Configurator/r_bsp/board/generic_rl78_g22/r_bsp_init.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo Smart Configurator\r_bsp\board\generic_rl78_g22\r_bsp_initcDepSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\r_bsp\board\generic_rl78_g22\r_bsp_initcDepSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\r_bsp\board\generic_rl78_g22\r_bsp_initcDepSubCommand.tmp" -msg_lang=japanese "$<"
	@echo Smart Configurator\r_bsp\board\generic_rl78_g22\r_bsp_initcSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\r_bsp\board\generic_rl78_g22\r_bsp_initcSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\r_bsp\board\generic_rl78_g22\r_bsp_initcSubCommand.tmp" -msg_lang=japanese "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

Smart\ Configurator/r_bsp/board/generic_rl78_g22/stkinit.obj: C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/r_bsp/board/generic_rl78_g22/stkinit.asm Smart\ Configurator/r_bsp/board/generic_rl78_g22/stkinit.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Assembler'
	@echo Smart Configurator\r_bsp\board\generic_rl78_g22\stkinitasmDepSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\r_bsp\board\generic_rl78_g22\stkinitasmDepSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\r_bsp\board\generic_rl78_g22\stkinitasmDepSubCommand.tmp" -msg_lang=japanese "$<"
	@echo Smart Configurator\r_bsp\board\generic_rl78_g22\stkinitasmSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\r_bsp\board\generic_rl78_g22\stkinitasmSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\r_bsp\board\generic_rl78_g22\stkinitasmSubCommand.tmp" -msg_lang=japanese "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

