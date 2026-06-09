################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/r_bsp/board/generic_rl78_g22/hdwinit.c \
../src/smc_gen/r_bsp/board/generic_rl78_g22/r_bsp_init.c 

ASM_SRCS += \
../src/smc_gen/r_bsp/board/generic_rl78_g22/stkinit.asm 

ASSEMBLER_OBJS += \
src/smc_gen/r_bsp/board/generic_rl78_g22/stkinit.obj 

ASM_DEPS += \
src/smc_gen/r_bsp/board/generic_rl78_g22/stkinit.d 

COMPILER_OBJS += \
src/smc_gen/r_bsp/board/generic_rl78_g22/hdwinit.obj \
src/smc_gen/r_bsp/board/generic_rl78_g22/r_bsp_init.obj 

C_DEPS += \
src/smc_gen/r_bsp/board/generic_rl78_g22/hdwinit.d \
src/smc_gen/r_bsp/board/generic_rl78_g22/r_bsp_init.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/r_bsp/board/generic_rl78_g22/%.obj: ../src/smc_gen/r_bsp/board/generic_rl78_g22/%.c src/smc_gen/r_bsp/board/generic_rl78_g22/Compiler.sub
	@echo 'Scanning and building file: $<'
	ccrl -subcommand="src\smc_gen\r_bsp\board\generic_rl78_g22\cDepSubCommand.tmp" -o "$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -msg_lang=japanese "$<"
	ccrl -subcommand="src\smc_gen\r_bsp\board\generic_rl78_g22\cSubCommand.tmp" -msg_lang=japanese -o "$(@:%.d=%.obj)" "$<"


src/smc_gen/r_bsp/board/generic_rl78_g22/%.obj: ../src/smc_gen/r_bsp/board/generic_rl78_g22/%.asm src/smc_gen/r_bsp/board/generic_rl78_g22/Assembler.sub
	@echo 'Scanning and building file: $<'
	ccrl -subcommand="src\smc_gen\r_bsp\board\generic_rl78_g22\asmDepSubCommand.tmp" -asmopt=-MF="$(@:%.obj=%.d)" -asmopt=-MT="$(@:%.obj=%.obj)" -asmopt=-MT="$(@:%.obj=%.d)" -msg_lang=japanese "$<"
	ccrl -subcommand="src\smc_gen\r_bsp\board\generic_rl78_g22\asmSubCommand.tmp" -msg_lang=japanese -o "$(@:%.d=%.obj)" "$<"


