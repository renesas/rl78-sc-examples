################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/Config_ADC/Config_ADC.c \
C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/Config_ADC/Config_ADC_user.c 

COMPILER_OBJS += \
Smart\ Configurator/Config_ADC/Config_ADC.obj \
Smart\ Configurator/Config_ADC/Config_ADC_user.obj 

C_DEPS += \
Smart\ Configurator/Config_ADC/Config_ADC.d \
Smart\ Configurator/Config_ADC/Config_ADC_user.d 

# Each subdirectory must supply rules for building sources it contributes
Smart\ Configurator/Config_ADC/Config_ADC.obj: C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/Config_ADC/Config_ADC.c Smart\ Configurator/Config_ADC/Config_ADC.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo Smart Configurator\Config_ADC\Config_ADCcDepSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\Config_ADC\Config_ADCcDepSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\Config_ADC\Config_ADCcDepSubCommand.tmp" -msg_lang=japanese "$<"
	@echo Smart Configurator\Config_ADC\Config_ADCcSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\Config_ADC\Config_ADCcSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\Config_ADC\Config_ADCcSubCommand.tmp" -msg_lang=japanese "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

Smart\ Configurator/Config_ADC/Config_ADC_user.obj: C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/Config_ADC/Config_ADC_user.c Smart\ Configurator/Config_ADC/Config_ADC_user.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo Smart Configurator\Config_ADC\Config_ADC_usercDepSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\Config_ADC\Config_ADC_usercDepSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\Config_ADC\Config_ADC_usercDepSubCommand.tmp" -msg_lang=japanese "$<"
	@echo Smart Configurator\Config_ADC\Config_ADC_usercSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\Config_ADC\Config_ADC_usercSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\Config_ADC\Config_ADC_usercSubCommand.tmp" -msg_lang=japanese "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

