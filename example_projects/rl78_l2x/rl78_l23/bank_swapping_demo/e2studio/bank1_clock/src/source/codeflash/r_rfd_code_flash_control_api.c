/**********************************************************************************************************************
    Program Name    : Renesas Flash Driver (RFD RL78 Type11)
    
    File Name       : r_rfd_code_flash_control_api.c
    Program Version : V1.00
    Device(s)       : RL78/L23 microcontroller
    Description     : Code Flash Control program
**********************************************************************************************************************/

/**********************************************************************************************************************
    DISCLAIMER
    This software is supplied by Renesas Electronics Corporation and is only intended for use with
    Renesas products. No other uses are authorized. This software is owned by Renesas Electronics
    Corporation and is protected under all applicable laws, including copyright laws.
    THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE,
    WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
    TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR
    ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR
    CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
    BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
    Renesas reserves the right, without notice, to make changes to this software and to discontinue the
    availability of this software. By using this software, you agree to the additional terms and conditions
    found by accessing the following link:
    http://www.renesas.com/disclaimer
    
    Copyright (C) 2024,2025 Renesas Electronics Corporation. All rights reserved.
**********************************************************************************************************************/

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "r_rfd_code_flash_control_api.h"
#include "r_rfd_code_flash_userown.h"

#if (COMPILER_IAR == COMPILER)
    #include "intrinsics.h"
#endif

/**********************************************************************************************************************
 * Function name : R_RFD_SetCFProgrammingMode
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Set the flash memory mode to the code flash programming mode and set the flash operating frequency.
 *  
 *  @param[in]      -
 *  @return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :              Successful completion
 *                  - R_RFD_ENUM_RET_ERR_MODE_MISMATCHED : Failed to change flash memory mode
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_SetCFProgrammingMode(void)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    uint8_t     l_u08_fsset_value;
    uint8_t     l_u08_set_flpmc_value;
    uint8_t     l_u08_pfs_value;
    
    /* Local variables initialization */
    l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    
    /* Set code flash programming mode */
    l_u08_set_flpmc_value = R_RFD_VALUE_U08_FLPMC_MODE_CODE_FLASH_PROGRAMMING;
    
    R_RFD_HOOK_EnterCFCriticalSection();
    
    /* Start specific sequence for writing */
    R_RFD_REG_U08_PFCMD = R_RFD_VALUE_U08_PFCMD_SPECIFIC_SEQUENCE_WRITE;
    
    /* Set mode */
    R_RFD_REG_U08_FLPMC = l_u08_set_flpmc_value;
    R_RFD_REG_U08_FLPMC = ~l_u08_set_flpmc_value;
    R_RFD_REG_U08_FLPMC = l_u08_set_flpmc_value;
    
    /* Read PFS register */
    l_u08_pfs_value = R_RFD_REG_U08_PFS;
    
    R_RFD_HOOK_ExitCFCriticalSection();
    
    /* Check specific sequence writing error */
    if (0u != (l_u08_pfs_value & R_RFD_VALUE_U08_MASK1_PFS_FPRERR))
    {
        l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
    }
    else
    {
        /* Check mode */
        l_e_ret_value = R_RFD_CheckCFProgrammingMode();
        
        if (R_RFD_ENUM_RET_STS_OK == l_e_ret_value)
        {
            /* Read from FSSET register */
            l_u08_fsset_value = R_RFD_REG_U08_FSSET;
            
            /* Set frequency */
            R_RFD_REG_U08_FSSET = (l_u08_fsset_value & R_RFD_VALUE_U08_MASK1_FSSET_TMSPMD_AND_TMBTSEL) 
                                  | g_u08_cpu_frequency;
        }
        else
        {
            l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
        }
    }
    
    return (l_e_ret_value);
}

#define  R_RFD_END_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_SetCFProgrammingMode
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_SetCFNonProgrammableMode
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Set the flash memory mode to the non-programmable mode.
 *  
 *  @param[in]      -
 *  @return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :              Successful completion
 *                  - R_RFD_ENUM_RET_ERR_MODE_MISMATCHED : Failed to change flash memory mode
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_SetCFNonProgrammableMode(void)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    uint8_t     l_u08_set_flpmc_value;
    uint8_t     l_u08_pfs_value;
    
    /* Local variables initialization */
    l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    
    /* Set non-programmable mode */
    /* When using R_RFD_ChangeInterruptVector() */
    if (R_RFD_VALUE_U08_SET_FWEDIS_FLAG_ON == g_u08_change_interrupt_vector_flag)
    {
        /* Non-programmable mode (FWEDIS enable) */
        l_u08_set_flpmc_value = R_RFD_VALUE_U08_FLPMC_MODE_NONPROGRAMMABLE_FWEDIS_ENABLE;
    }
    /* When not using R_RFD_ChangeInterruptVector() */
    else
    {
        /* Non-programmable mode (FWEDIS disable) */
        l_u08_set_flpmc_value = R_RFD_VALUE_U08_FLPMC_MODE_NONPROGRAMMABLE_FWEDIS_DISABLE;
    }
    
    R_RFD_HOOK_EnterCFCriticalSection();
    
    /* Start specific sequence for writing */
    R_RFD_REG_U08_PFCMD = R_RFD_VALUE_U08_PFCMD_SPECIFIC_SEQUENCE_WRITE;
    
    /* Set mode */
    R_RFD_REG_U08_FLPMC = l_u08_set_flpmc_value;
    R_RFD_REG_U08_FLPMC = ~l_u08_set_flpmc_value;
    R_RFD_REG_U08_FLPMC = l_u08_set_flpmc_value;
    
    /* Read PFS register */
    l_u08_pfs_value = R_RFD_REG_U08_PFS;
    
    R_RFD_HOOK_ExitCFCriticalSection();
    
    r_rfd_cf_wait_count(10u);
    
    /* Check specific sequence writing error */
    if (0u != (l_u08_pfs_value & R_RFD_VALUE_U08_MASK1_PFS_FPRERR))
    {
        l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
    }
    else
    {
        /* Check mode */
        l_e_ret_value = R_RFD_CheckCFNonProgrammableMode();
        
        if (R_RFD_ENUM_RET_STS_OK == l_e_ret_value)
        {
            /* No operation */
        }
        else
        {
            l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
        }
    }
    
    return (l_e_ret_value);
}

#define  R_RFD_END_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_SetCFNonProgrammableMode
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_CheckCFProgrammingMode
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Check whether the current flash memory mode is the code flash programming mode or not.
 *  
 *  @param[in]      -
 *  @return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :              Successful completion
 *                  - R_RFD_ENUM_RET_ERR_MODE_MISMATCHED : Mode mismatch error (Not code flash programming mode)
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckCFProgrammingMode(void)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    uint8_t     l_u08_flpmc_value;
    
    /* Local variables initialization */
    l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    
    /* Acquire the value of FLPMC register */
    l_u08_flpmc_value = R_RFD_REG_U08_FLPMC;
    
    if (R_RFD_VALUE_U08_FLPMC_MODE_CODE_FLASH_PROGRAMMING == l_u08_flpmc_value)
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    }
    else
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
    }
    
    return (l_e_ret_value);
}

#define  R_RFD_END_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_CheckCFProgrammingMode
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_CheckCFNonProgrammableMode
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Check whether the current flash memory mode is the non-programmable mode or not.
 *  
 *  @param[in]      -
 *  @return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :              Successful completion
 *                  - R_RFD_ENUM_RET_ERR_MODE_MISMATCHED : Mode mismatch error (Not non-programmable mode)
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckCFNonProgrammableMode(void)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    uint8_t     l_u08_flpmc_value;
    
    /* Local variables initialization */
    l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    
    /* Acquire the value of FLPMC register and exclude FWEDIS */
    l_u08_flpmc_value = R_RFD_REG_U08_FLPMC & R_RFD_VALUE_U08_MASK0_FLPMC_FWEDIS;
    
    if (R_RFD_VALUE_U08_FLPMC_MODE_NONPROGRAMMABLE_FWEDIS_ENABLE == l_u08_flpmc_value)
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    }
    else
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
    }
    
    return (l_e_ret_value);
}

#define  R_RFD_END_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_CheckCFNonProgrammableMode
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_CheckCFSeqEndStep1
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Check whether the operation of the activated code/data flash memory sequencer has been completed.
 *  If completed, then clear the control register for the code/data flash memory sequencer.
 *  
 *  @param[in]      -
 *  @return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :   The operation of the code/data flash memory sequencer is completed
 *                  - R_RFD_ENUM_RET_STS_BUSY : The code/data flash memory sequencer is still being processed
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckCFSeqEndStep1(void)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    uint8_t     l_u08_fsasth_value;
    
    /* Set local variables */
    l_e_ret_value      = R_RFD_ENUM_RET_STS_OK;
    l_u08_fsasth_value = R_RFD_REG_U08_FSASTH;
    
    /* SQEND bit is valid */
    if (0u != (l_u08_fsasth_value & R_RFD_VALUE_U08_MASK1_FSASTH_SQEND))
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
        
        /* Set the value for FSSQ register */
        R_RFD_REG_U08_FSSQ = R_RFD_VALUE_U08_FSSQ_CLEAR;
    }
    /* SQEND bit is invalid */
    else
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_STS_BUSY;
    }
    
    return (l_e_ret_value);
}

#define  R_RFD_END_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_CheckCFSeqEndStep1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_CheckCFSeqEndStep2
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Check whether the code/data flash memory sequencer command has been completed 
 *  by clearing the control register for the code/data flash memory sequencer.
 *  
 *  @param[in]      -
 *  @return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :   The command of code/data flash memory sequencer is completed
 *                  - R_RFD_ENUM_RET_STS_BUSY : The command is still being processed
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckCFSeqEndStep2(void)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    uint8_t     l_u08_fsasth_value;
    
    /* Set local variables */
    l_e_ret_value      = R_RFD_ENUM_RET_STS_OK;
    l_u08_fsasth_value = R_RFD_REG_U08_FSASTH;
    
    /* SQEND bit is invalid */
    if (0u == (l_u08_fsasth_value & R_RFD_VALUE_U08_MASK1_FSASTH_SQEND))
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    }
    /* SQEND bit is valid */
    else
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_STS_BUSY;
    }
    
    return (l_e_ret_value);
}

#define  R_RFD_END_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_CheckCFSeqEndStep2
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_GetCFSeqErrorStatus
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Get the error information occurred by the code/data flash memory sequencer command.
 *  
 *  @param[out]     onp_u08_error_status : 
 *                    Pointer to the variable that stores error information
 *  @return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void R_RFD_GetCFSeqErrorStatus(uint8_t __near * onp_u08_error_status)
{
    /* Local variable definitions */
    uint8_t l_u08_fsastl_value;
    
    /* Set local variables */
    l_u08_fsastl_value = R_RFD_REG_U08_FSASTL;
    
    /* Write to parameter */
    * onp_u08_error_status = l_u08_fsastl_value & R_RFD_VALUE_U08_MASK1_FSASTL_ERROR_FLAG;
}

#define  R_RFD_END_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_GetCFSeqErrorStatus
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_ClearCFSeqRegister
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Clear the registers that control the code/data flash memory sequencer.
 *  
 *  @param[in]      -
 *  @return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void R_RFD_ClearCFSeqRegister(void)
{
    /* Local variable definitions */
    
    /* Set the value for FLRST register */
    R_RFD_REG_U08_FLRST = R_RFD_VALUE_U08_FLRST_ON;
    
    /* Wait one clock */
    R_RFD_NO_OPERATION();
    
    /* Set the value for FLRST register */
    R_RFD_REG_U08_FLRST = R_RFD_VALUE_U08_FLRST_OFF;
}

#define  R_RFD_END_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_ClearCFSeqRegister
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_ForceStopCFSeq
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Stop the code/data flash memory sequencer operation forcibly.
 *  
 *  @param[in]      -
 *  @return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void R_RFD_ForceStopCFSeq(void)
{
    /* Local variable definitions */
    
    /* Set the value for FSSQ register FSSTP bit */
    R_RFD_REG_U01_FSSQ_FSSTP = R_RFD_VALUE_U01_FSSQ_FSSTP_ON;
}

#define  R_RFD_END_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_ForceStopCFSeq
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Internal functions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function name : r_rfd_cf_wait_count
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CF
#include "r_rfd_memmap.h"

#if (COMPILER_CC == COMPILER)
    #pragma inline_asm r_rfd_cf_wait_count
#endif
/*********************************************************************************************************************/
/**
 *  Wait until the target count value (microsecond) is reached in the code flash programming mode.
 *  
 *  @param[in]      i_u08_count : 
 *                    Target count value (us)
 *  @return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void r_rfd_cf_wait_count(uint8_t i_u08_count)
{
    #if (COMPILER_CC == COMPILER)
    /* CC-RL compiler uses the register A as this function argument */
    PUSH  AX
    
    /* Calculate the counter of the waiting loop */
    MOV   X, !_g_u08_cpu_frequency
    INC   X
    MULU  X
    SHRW  AX, 3
    INCW  AX
    
    /* Start the waiting loop that has 8 clocks (1+1+1+1+4) */
    .LOCAL _WAIT_LOOP
    _WAIT_LOOP:
    NOP
    NOP
    DECW  AX
    CMPW  AX, #0
    BNZ   $_WAIT_LOOP
    POP   AX
    
    #elif (COMPILER_IAR == COMPILER)
    /* IAR compiler uses the register A as this function argument */
    __asm("PUSH  AX");
    
    /* Calculate the counter of the waiting loop */
    __asm("MOV   X, N:_g_u08_cpu_frequency");
    __asm("INC   X");
    __asm("MULU  X");
    __asm("SHRW  AX, 3");
    __asm("INCW  AX");
    
    /* Start the waiting loop that has 8 clocks (1+1+1+1+4) */
    __asm("NOP");
    __asm("NOP");
    __asm("DECW  AX");
    __asm("CMPW  AX, #0");
    __asm("BNZ   $-0x06");
    __asm("POP   AX");
    
    #elif (COMPILER_LLVM == COMPILER)
    /* LLVM compiler uses the register A as this function argument */
    __asm("push ax");
    
    /* Calculate the counter of the waiting loop */
    __asm("mov  x, !_g_u08_cpu_frequency");
    __asm("inc  x");
    __asm("mulu x");
    __asm("shrw ax, 3");
    __asm("incw ax");
    
    /* Start the waiting loop that has 8 clocks (1+1+1+1+4) */
    __asm("nop");
    __asm("nop");
    __asm("decw  ax");
    __asm("cmpw  ax, #0");
    __asm("bnz   $.-0x06");
    __asm("pop   ax");
    #endif
}

#define  R_RFD_END_SECTION_RFD_CF
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function r_rfd_cf_wait_count
 *********************************************************************************************************************/

/**********************************************************************************************************************
 End of internal functions
 *********************************************************************************************************************/
