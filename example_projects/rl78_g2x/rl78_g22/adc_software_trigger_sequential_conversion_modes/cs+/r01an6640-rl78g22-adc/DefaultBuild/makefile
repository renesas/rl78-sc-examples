################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include makefile.init

RM := rm -rf *.sni *.dbg *.lst *.lis *.lpp *.map *.x *.lbp *.h *.bls *.libelf *.rel *.lbk *.abs *.prn *.mi *.fsy *.ud *.udm 1st/*.abs 1st/*.fsy

# All of the sources participating in the build are defined here
-include sources.mk
-include Smart\ Configurator/r_bsp/mcu/rl78_g22/subdir.mk
-include Smart\ Configurator/r_bsp/mcu/all/subdir.mk
-include subdir.mk
-include Smart\ Configurator/Config_ADC/subdir.mk
-include Smart\ Configurator/general/subdir.mk
-include Smart\ Configurator/r_bsp/board/generic_rl78_g22/subdir.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif 
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif 
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif 
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif 
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif 
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif 
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif 
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif 
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif 
ifneq ($(strip $(JMP_DEPS)),)
-include $(JMP_DEPS)
endif 
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif 
ifneq ($(strip $(PP_DEPS)),)
-include $(PP_DEPS)
endif 
ifneq ($(strip $(P_DEPS)),)
-include $(P_DEPS)
endif 
ifneq ($(strip $(FSY_DEPS)),)
-include $(FSY_DEPS)
endif 
endif

ifneq ($(strip $(SRC_UPPER_SRCS)),)
ALL_ASMS += $(SRC_UPPER_SRCS) 
endif
ifneq ($(strip $(SRC_SRCS)),)
ALL_ASMS += $(SRC_SRCS) 
endif
ifneq ($(strip $(S_UPPER_SRCS)),)
ALL_ASMS += $(S_UPPER_SRCS) 
endif
ifneq ($(strip $(S_SRCS)),)
ALL_ASMS += $(S_SRCS) 
endif


-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables
LINKER_OUTPUT_OUTPUTS += \
r01an6640-rl78g22-adc.abs

CONVERTOR_OUTPUT_OUTPUTS += \
r01an6640-rl78g22-adc.mot

OBJS := \
$(COMPILER_OBJS) \
$(INDIVIDUAL_COMPILER_OBJS) \
$(ASSEMBLER_OBJS) \
$(CUSTOM_OBJS)

$(COMPILER_OBJS): $(SMS_ASSEMBLER_H)

# All Target
all: $(CONVERTOR_OUTPUT_OUTPUTS) r01an6640-rl78g22-adc.x r01an6640-rl78g22-adc.udm

	@echo 'Build complete.'

r01an6640-rl78g22-adc.mot: $(LINKER_OUTPUT_OUTPUTS) 
	@echo 'Invoking: Converter'
	@echo 'Building target:'
	@echo Converterr01an6640-rl78g22-adc.tmp=
	@sed -e "s/^/    /" "Converterr01an6640-rl78g22-adc.tmp"
	rlink "r01an6640-rl78g22-adc.abs" -subcommand="Converterr01an6640-rl78g22-adc.tmp"
	@echo 'Finished building target:'
	@echo ''


r01an6640-rl78g22-adc.abs: $(OBJS)  $(ALL_ASMS)
	@echo 'Invoking: Linker'
	@echo Linkerr01an6640-rl78g22-adc.tmp=
	@sed -e "s/^/    /" "Linkerr01an6640-rl78g22-adc.tmp"
	rlink -subcommand="Linkerr01an6640-rl78g22-adc.tmp"
	@echo 'Finished building:'
	@echo ''


r01an6640-rl78g22-adc.x: r01an6640-rl78g22-adc.abs
		-C:\Users\MyPC\.eclipse\com.renesas.platform_1435879475\Utilities\\ccrl\renesas_cc_converter r01an6640-rl78g22-adc.abs r01an6640-rl78g22-adc.x

r01an6640-rl78g22-adc.udm: $(LINKER_OUTPUT_OUTPUTS) $(CONVERTOR_OUTPUT_OUTPUTS)
	udcollector -subcommand=udSubcommand.tmp -output=r01an6640-rl78g22-adc.udm

# Other Targets
clean:
	-$(RM) $(LINKER_OUTPUT_OUTPUTS) $(CONVERTOR_OUTPUT_OUTPUTS)
	-rm -rf $(SMS_ASSEMBLER_H)
ifneq ($(strip $(OBJS)),)
	-$(file > clean_OBJS.tmp, $(OBJS))
	-@xargs -s 4000 -t -a clean_OBJS.tmp rm -rf
	-@rm -rf clean_OBJS.tmp
endif
ifneq ($(strip $(C_DEPS)),)
	-$(file > clean_C_DEPS.tmp, $(C_DEPS))
	-@xargs -s 4000 -t -a clean_C_DEPS.tmp rm -rf
	-@rm -rf clean_C_DEPS.tmp
endif
ifneq ($(strip $(CPP_DEPS)),)
	-$(file > clean_CPP_DEPS.tmp, $(CPP_DEPS))
	-@xargs -s 4000 -t -a clean_CPP_DEPS.tmp rm -rf
	-@rm -rf clean_CPP_DEPS.tmp
endif
ifneq ($(strip $(ASM_DEPS)),)
	-$(file > clean_ASM_DEPS.tmp, $(ASM_DEPS))
	-@xargs -s 4000 -t -a clean_ASM_DEPS.tmp rm -rf
	-@rm -rf clean_ASM_DEPS.tmp
endif
ifneq ($(strip $(DSP_DEPS)),)
	-$(file > clean_DSP_DEPS.tmp, $(DSP_DEPS))
	-@xargs -s 4000 -t -a clean_DSP_DEPS.tmp rm -rf
	-@rm -rf clean_DSP_DEPS.tmp
endif
	-rm -rf Smart?Configurator/r_bsp/mcu/rl78_g22/*.asm Smart?Configurator/r_bsp/mcu/rl78_g22/*.p Smart?Configurator/r_bsp/mcu/rl78_g22/*.pp Smart?Configurator/r_bsp/mcu/rl78_g22/*.src Smart?Configurator/r_bsp/mcu/rl78_g22/*.jmp Smart?Configurator/r_bsp/mcu/rl78_g22/*.lst Smart?Configurator/r_bsp/mcu/rl78_g22/*.prn Smart?Configurator/r_bsp/mcu/rl78_g22/*.i Smart?Configurator/r_bsp/mcu/rl78_g22/*.ud 
	-rm -rf Smart?Configurator/r_bsp/mcu/all/*.asm Smart?Configurator/r_bsp/mcu/all/*.p Smart?Configurator/r_bsp/mcu/all/*.pp Smart?Configurator/r_bsp/mcu/all/*.src Smart?Configurator/r_bsp/mcu/all/*.jmp Smart?Configurator/r_bsp/mcu/all/*.lst Smart?Configurator/r_bsp/mcu/all/*.prn Smart?Configurator/r_bsp/mcu/all/*.i Smart?Configurator/r_bsp/mcu/all/*.ud 
	-rm -rf /*.asm /*.p /*.pp /*.src /*.jmp /*.lst /*.prn /*.i /*.ud 
	-rm -rf Smart?Configurator/Config_ADC/*.asm Smart?Configurator/Config_ADC/*.p Smart?Configurator/Config_ADC/*.pp Smart?Configurator/Config_ADC/*.src Smart?Configurator/Config_ADC/*.jmp Smart?Configurator/Config_ADC/*.lst Smart?Configurator/Config_ADC/*.prn Smart?Configurator/Config_ADC/*.i Smart?Configurator/Config_ADC/*.ud 
	-rm -rf Smart?Configurator/general/*.asm Smart?Configurator/general/*.p Smart?Configurator/general/*.pp Smart?Configurator/general/*.src Smart?Configurator/general/*.jmp Smart?Configurator/general/*.lst Smart?Configurator/general/*.prn Smart?Configurator/general/*.i Smart?Configurator/general/*.ud 
	-rm -rf Smart?Configurator/r_bsp/board/generic_rl78_g22/*.asm Smart?Configurator/r_bsp/board/generic_rl78_g22/*.p Smart?Configurator/r_bsp/board/generic_rl78_g22/*.pp Smart?Configurator/r_bsp/board/generic_rl78_g22/*.src Smart?Configurator/r_bsp/board/generic_rl78_g22/*.jmp Smart?Configurator/r_bsp/board/generic_rl78_g22/*.lst Smart?Configurator/r_bsp/board/generic_rl78_g22/*.prn Smart?Configurator/r_bsp/board/generic_rl78_g22/*.i Smart?Configurator/r_bsp/board/generic_rl78_g22/*.ud 
	@echo ''
	@echo 'Clean complete.'

.PHONY: all clean $(CONVERTOR_OUTPUT_OUTPUTS)  $(LINKER_OUTPUT_OUTPUTS)  
-include ../makefile.targets
.NOTPARALLEL: $(SMS_ASSEMBLER_H)
.SECONDARY: $(SMS_ASSEMBLER_H)