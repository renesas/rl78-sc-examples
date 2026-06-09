################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/general/r_cg_ad_common.c \
C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/general/r_cg_lvd_common.c \
C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/general/r_cg_lvd_common_user.c \
C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/general/r_cg_systeminit.c 

COMPILER_OBJS += \
Smart\ Configurator/general/r_cg_ad_common.obj \
Smart\ Configurator/general/r_cg_lvd_common.obj \
Smart\ Configurator/general/r_cg_lvd_common_user.obj \
Smart\ Configurator/general/r_cg_systeminit.obj 

C_DEPS += \
Smart\ Configurator/general/r_cg_ad_common.d \
Smart\ Configurator/general/r_cg_lvd_common.d \
Smart\ Configurator/general/r_cg_lvd_common_user.d \
Smart\ Configurator/general/r_cg_systeminit.d 

# Each subdirectory must supply rules for building sources it contributes
Smart\ Configurator/general/r_cg_ad_common.obj: C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/general/r_cg_ad_common.c Smart\ Configurator/general/r_cg_ad_common.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo Smart Configurator\general\r_cg_ad_commoncDepSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\general\r_cg_ad_commoncDepSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\general\r_cg_ad_commoncDepSubCommand.tmp" -msg_lang=japanese "$<"
	@echo Smart Configurator\general\r_cg_ad_commoncSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\general\r_cg_ad_commoncSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\general\r_cg_ad_commoncSubCommand.tmp" -msg_lang=japanese "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

Smart\ Configurator/general/r_cg_lvd_common.obj: C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/general/r_cg_lvd_common.c Smart\ Configurator/general/r_cg_lvd_common.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo Smart Configurator\general\r_cg_lvd_commoncDepSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\general\r_cg_lvd_commoncDepSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\general\r_cg_lvd_commoncDepSubCommand.tmp" -msg_lang=japanese "$<"
	@echo Smart Configurator\general\r_cg_lvd_commoncSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\general\r_cg_lvd_commoncSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\general\r_cg_lvd_commoncSubCommand.tmp" -msg_lang=japanese "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

Smart\ Configurator/general/r_cg_lvd_common_user.obj: C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/general/r_cg_lvd_common_user.c Smart\ Configurator/general/r_cg_lvd_common_user.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo Smart Configurator\general\r_cg_lvd_common_usercDepSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\general\r_cg_lvd_common_usercDepSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\general\r_cg_lvd_common_usercDepSubCommand.tmp" -msg_lang=japanese "$<"
	@echo Smart Configurator\general\r_cg_lvd_common_usercSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\general\r_cg_lvd_common_usercSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\general\r_cg_lvd_common_usercSubCommand.tmp" -msg_lang=japanese "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

Smart\ Configurator/general/r_cg_systeminit.obj: C:/Users/a5111070/Documents/r01an6640-rl78g22-adc/src/smc_gen/general/r_cg_systeminit.c Smart\ Configurator/general/r_cg_systeminit.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo Smart Configurator\general\r_cg_systeminitcDepSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\general\r_cg_systeminitcDepSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\general\r_cg_systeminitcDepSubCommand.tmp" -msg_lang=japanese "$<"
	@echo Smart Configurator\general\r_cg_systeminitcSubCommand.tmp=
	@sed -e "s/^/ /" "Smart Configurator\general\r_cg_systeminitcSubCommand.tmp"
	ccrl -subcommand="Smart Configurator\general\r_cg_systeminitcSubCommand.tmp" -msg_lang=japanese "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

