################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/r_bsp/mcu/rl78_g22/mcu_clocks.c 

COMPILER_OBJS += \
Smart\ Configurator/r_bsp/mcu/rl78_g22/mcu_clocks.obj 

C_DEPS += \
Smart\ Configurator/r_bsp/mcu/rl78_g22/mcu_clocks.d 

# Each subdirectory must supply rules for building sources it contributes
Smart\ Configurator/r_bsp/mcu/rl78_g22/mcu_clocks.obj: C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/r_bsp/mcu/rl78_g22/mcu_clocks.c Smart\ Configurator/r_bsp/mcu/rl78_g22/mcu_clocks.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo Smart Configurator\r_bsp\mcu\rl78_g22\mcu_clockscDepSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\r_bsp\mcu\rl78_g22\mcu_clockscDepSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\r_bsp\mcu\rl78_g22\mcu_clockscDepSubCommand.tmp" -msg_lang=japanese "$<"
	@echo Smart Configurator\r_bsp\mcu\rl78_g22\mcu_clockscSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\r_bsp\mcu\rl78_g22\mcu_clockscSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\r_bsp\mcu\rl78_g22\mcu_clockscSubCommand.tmp" -msg_lang=japanese "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

