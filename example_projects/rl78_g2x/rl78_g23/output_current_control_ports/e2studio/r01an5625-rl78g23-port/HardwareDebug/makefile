################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include makefile.init

RM := rm -rf *.sni *.dbg *.lst *.lis *.lpp *.map *.x *.lbp *.h *.bls *.libelf *.rel *.lbk *.abs *.prn *.mi *.fsy *.ud *.udm 1st/*.abs 1st/*.fsy

# All of the sources participating in the build are defined here
-include sources.mk
-include src/smc_gen/r_bsp/board/generic_rl78_g23/subdir.mk
-include src/subdir.mk
-include src/smc_gen/r_bsp/mcu/rl78_g23/subdir.mk
-include src/smc_gen/general/subdir.mk
-include src/smc_gen/r_bsp/mcu/all/subdir.mk
-include src/smc_gen/Config_INTC/subdir.mk
-include src/smc_gen/Config_PORT/subdir.mk

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
r01an5625_rl78g23_port.abs

OBJS := \
$(COMPILER_OBJS) \
$(INDIVIDUAL_COMPILER_OBJS) \
$(ASSEMBLER_OBJS) \
$(CUSTOM_OBJS)

$(COMPILER_OBJS): $(SMS_ASSEMBLER_H)

# All Target
all: $(LINKER_OUTPUT_OUTPUTS) r01an5625_rl78g23_port.x r01an5625_rl78g23_port.udm

	@echo 'Build complete.'

r01an5625_rl78g23_port.abs: $(OBJS)  $(ALL_ASMS)
	@echo 'Invoking: Linker'
	@echo 'Building target:'
	@echo Linkerr01an5625_rl78g23_port.tmp=
	@sed -e "s/^/    /" "Linkerr01an5625_rl78g23_port.tmp"
	rlink -subcommand="Linkerr01an5625_rl78g23_port.tmp"
	@echo 'Finished building target:'
	@echo ''


r01an5625_rl78g23_port.x: r01an5625_rl78g23_port.abs
		-C:\Users\a5090549\.eclipse\com.renesas.platform_1435879475\Utilities\\ccrl\renesas_cc_converter r01an5625_rl78g23_port.abs r01an5625_rl78g23_port.x

r01an5625_rl78g23_port.udm: $(LINKER_OUTPUT_OUTPUTS)
	udcollector -subcommand=udSubcommand.tmp -output=r01an5625_rl78g23_port.udm

# Other Targets
clean:
	-$(RM) $(LINKER_OUTPUT_OUTPUTS)
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
	-rm -rf src/smc_gen/r_bsp/board/generic_rl78_g23/*.asm src/smc_gen/r_bsp/board/generic_rl78_g23/*.p src/smc_gen/r_bsp/board/generic_rl78_g23/*.pp src/smc_gen/r_bsp/board/generic_rl78_g23/*.src src/smc_gen/r_bsp/board/generic_rl78_g23/*.jmp src/smc_gen/r_bsp/board/generic_rl78_g23/*.lst src/smc_gen/r_bsp/board/generic_rl78_g23/*.prn src/smc_gen/r_bsp/board/generic_rl78_g23/*.i src/smc_gen/r_bsp/board/generic_rl78_g23/*.ud 
	-rm -rf src/*.asm src/*.p src/*.pp src/*.src src/*.jmp src/*.lst src/*.prn src/*.i src/*.ud 
	-rm -rf src/smc_gen/r_bsp/mcu/rl78_g23/*.asm src/smc_gen/r_bsp/mcu/rl78_g23/*.p src/smc_gen/r_bsp/mcu/rl78_g23/*.pp src/smc_gen/r_bsp/mcu/rl78_g23/*.src src/smc_gen/r_bsp/mcu/rl78_g23/*.jmp src/smc_gen/r_bsp/mcu/rl78_g23/*.lst src/smc_gen/r_bsp/mcu/rl78_g23/*.prn src/smc_gen/r_bsp/mcu/rl78_g23/*.i src/smc_gen/r_bsp/mcu/rl78_g23/*.ud 
	-rm -rf src/smc_gen/general/*.asm src/smc_gen/general/*.p src/smc_gen/general/*.pp src/smc_gen/general/*.src src/smc_gen/general/*.jmp src/smc_gen/general/*.lst src/smc_gen/general/*.prn src/smc_gen/general/*.i src/smc_gen/general/*.ud 
	-rm -rf src/smc_gen/r_bsp/mcu/all/*.asm src/smc_gen/r_bsp/mcu/all/*.p src/smc_gen/r_bsp/mcu/all/*.pp src/smc_gen/r_bsp/mcu/all/*.src src/smc_gen/r_bsp/mcu/all/*.jmp src/smc_gen/r_bsp/mcu/all/*.lst src/smc_gen/r_bsp/mcu/all/*.prn src/smc_gen/r_bsp/mcu/all/*.i src/smc_gen/r_bsp/mcu/all/*.ud 
	-rm -rf src/smc_gen/Config_INTC/*.asm src/smc_gen/Config_INTC/*.p src/smc_gen/Config_INTC/*.pp src/smc_gen/Config_INTC/*.src src/smc_gen/Config_INTC/*.jmp src/smc_gen/Config_INTC/*.lst src/smc_gen/Config_INTC/*.prn src/smc_gen/Config_INTC/*.i src/smc_gen/Config_INTC/*.ud 
	-rm -rf src/smc_gen/Config_PORT/*.asm src/smc_gen/Config_PORT/*.p src/smc_gen/Config_PORT/*.pp src/smc_gen/Config_PORT/*.src src/smc_gen/Config_PORT/*.jmp src/smc_gen/Config_PORT/*.lst src/smc_gen/Config_PORT/*.prn src/smc_gen/Config_PORT/*.i src/smc_gen/Config_PORT/*.ud 
	@echo ''
	@echo 'Clean complete.'

.PHONY: all clean 
-include ../makefile.targets
.NOTPARALLEL: $(SMS_ASSEMBLER_H)
.SECONDARY: $(SMS_ASSEMBLER_H)