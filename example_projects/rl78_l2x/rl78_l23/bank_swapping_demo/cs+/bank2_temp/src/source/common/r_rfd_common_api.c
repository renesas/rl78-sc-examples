/**********************************************************************************************************************
    Program Name    : Renesas Flash Driver (RFD RL78 Type11)
    
    File Name       : r_rfd_common_api.c
    Program Version : V1.00
    Device(s)       : RL78/L23 microcontroller
    Description     : Common Flash Control program
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
#include "r_rfd_common_api.h"
#include "r_rfd_common_userown.h"

#if (COMPILER_IAR == COMPILER)
    #include "intrinsics.h"
#endif

/**********************************************************************************************************************
 Exported global variables
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_DATA
#include "r_rfd_memmap.h"
    /* Flag whether the interrupt vector is changed */
    uint8_t g_u08_change_interrupt_vector_flag = R_RFD_VALUE_U08_INIT_FLAG;
#define  R_RFD_END_SECTION_RFD_DATA
#include "r_rfd_memmap.h"

#define  R_RFD_START_SECTION_RFD_DATA
#include "r_rfd_memmap.h"
    /* CPU Frequency configuration for r_rfd_*_wait_count */
    uint8_t g_u08_cpu_frequency                = R_RFD_VALUE_U08_INIT_VARIABLE;
#define  R_RFD_END_SECTION_RFD_DATA
#include "r_rfd_memmap.h"

/**********************************************************************************************************************
 * Function name : R_RFD_Init
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Initialize the RFD.
 *  
 *  @param[in]      i_u08_cpu_frequency : 
 *                    CPU operating frequency
 *  @return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :        Successful completion
 *                  - R_RFD_ENUM_RET_ERR_PARAMETER : Out of parameter range
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_Init(uint8_t i_u08_cpu_frequency)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    
    /* Local variables initialization */
    l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    
    /* Global variables initialization */
    g_u08_change_interrupt_vector_flag = R_RFD_VALUE_U08_SET_FWEDIS_FLAG_OFF;
    
    if ((R_RFD_VALUE_U08_FREQUENCY_LOWER_LIMIT <= i_u08_cpu_frequency) 
        && (R_RFD_VALUE_U08_FREQUENCY_UPPER_LIMIT >= i_u08_cpu_frequency))
    {
        /* Adjust the CPU frequency variable */
        g_u08_cpu_frequency = i_u08_cpu_frequency - R_RFD_VALUE_U08_FREQUENCY_ADJUST;
    }
    else
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_ERR_PARAMETER;
    }
    
    return (l_e_ret_value);
}

#define  R_RFD_END_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_SetDataFlashAccessMode
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Enable or disable to access the data flash.
 *  
 *  @param[in]      i_e_df_access : 
 *                    Data flash access enable or disable
 *  @return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void R_RFD_SetDataFlashAccessMode(e_rfd_df_access_t i_e_df_access)
{
    /* Local variable definitions */
    
    /* Parameter is Data Flash Access Enable Request */
    if (R_RFD_ENUM_DF_ACCESS_ENABLE == i_e_df_access)
    {
        /* Set the value for DFLCTL register DFLEN bit */
        R_RFD_REG_U01_DFLCTL_DFLEN = R_RFD_VALUE_U01_DFLEN_DATA_FLASH_ACCESS_ENABLE;
        
        /* Wait for the setup time of DFLCTL register */
        R_RFD_NO_OPERATION();
        R_RFD_NO_OPERATION();
    }
    /* Parameter is Data Flash Access Disable Request */
    else
    {
        /* Set the value for DFLCTL register DFLEN bit */
        R_RFD_REG_U01_DFLCTL_DFLEN = R_RFD_VALUE_U01_DFLEN_DATA_FLASH_ACCESS_DISABLE;
    }
}

#define  R_RFD_END_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_SetDataFlashAccessMode
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_ChangeInterruptVector
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Change all interrupt vector addresses to specified address in RAM.
 *  
 *  @param[in]      i_u32_interrupt_vector_addr : 
 *                    Interruption destination address
 *  @return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :              Successful completion
 *                  - R_RFD_ENUM_RET_ERR_MODE_MISMATCHED : Failed to change interrupt vector addresses
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_ChangeInterruptVector(uint32_t i_u32_interrupt_vector_addr)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    uint8_t     l_u08_set_flpmc_value;
    uint8_t     l_u08_pfs_value;
    
    /* Set local variables */
    l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    l_u08_set_flpmc_value = R_RFD_VALUE_U08_FLPMC_MODE_NONPROGRAMMABLE_FWEDIS_ENABLE;
    
    R_RFD_HOOK_EnterCriticalSection();
    
    /* FLPMC register FWEDIS bit disable */
    /* Start specific sequence for writing */
    R_RFD_REG_U08_PFCMD = R_RFD_VALUE_U08_PFCMD_SPECIFIC_SEQUENCE_WRITE;
    
    /* Set non-programmable mode (FWEDIS enable) */
    R_RFD_REG_U08_FLPMC = l_u08_set_flpmc_value;
    R_RFD_REG_U08_FLPMC = ~l_u08_set_flpmc_value;
    R_RFD_REG_U08_FLPMC = l_u08_set_flpmc_value;
    
    /* Read PFS register */
    l_u08_pfs_value = R_RFD_REG_U08_PFS;
    
    /* Check specific sequence writing error */
    if (0u != (l_u08_pfs_value & R_RFD_VALUE_U08_MASK1_PFS_FPRERR))
    {
        l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
    }
    else
    {
        /* Change interrupt table */
        R_RFD_REG_U16_FLSIVC0 = (uint16_t)(i_u32_interrupt_vector_addr & R_RFD_VALUE_U16_MASK1_16BIT);
        R_RFD_REG_U16_FLSIVC1 = (uint16_t)(i_u32_interrupt_vector_addr >> R_RFD_VALUE_U08_SHIFT_16BIT);
        
        /* Switch to changed interrupt vector */
        R_RFD_REG_U08_VECTCTRL = R_RFD_VALUE_U08_VECTCTRL_ON;
        
        /* Flag setting */
        g_u08_change_interrupt_vector_flag = R_RFD_VALUE_U08_SET_FWEDIS_FLAG_ON;
    }
    
    R_RFD_HOOK_ExitCriticalSection();
    
    return (l_e_ret_value);
}

#define  R_RFD_END_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_ChangeInterruptVector
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_RestoreInterruptVector
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Restore all interrupt vector addresses to initial interrupt vector addresses.
 *  
 *  @param[in]      -
 *  @return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :              Successful completion
 *                  - R_RFD_ENUM_RET_ERR_MODE_MISMATCHED : Failed to restore interrupt vector addresses
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_RestoreInterruptVector(void)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    uint8_t     l_u08_set_flpmc_value;
    uint8_t     l_u08_pfs_value;
    
    /* Set local variables */
    l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    l_u08_set_flpmc_value = R_RFD_VALUE_U08_FLPMC_MODE_NONPROGRAMMABLE_FWEDIS_DISABLE;
    
    R_RFD_HOOK_EnterCriticalSection();
    
    /* FLPMC register FWEDIS bit disable */
    /* Start specific sequence for writing */
    R_RFD_REG_U08_PFCMD = R_RFD_VALUE_U08_PFCMD_SPECIFIC_SEQUENCE_WRITE;
    
    /* Set non-programmable mode (FWEDIS disable) */
    R_RFD_REG_U08_FLPMC = l_u08_set_flpmc_value;
    R_RFD_REG_U08_FLPMC = ~l_u08_set_flpmc_value;
    R_RFD_REG_U08_FLPMC = l_u08_set_flpmc_value;
    
    /* Read PFS register */
    l_u08_pfs_value = R_RFD_REG_U08_PFS;
    
    /* Check specific sequence writing error */
    if (0u != (l_u08_pfs_value & R_RFD_VALUE_U08_MASK1_PFS_FPRERR))
    {
        l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
    }
    else
    {
        /* Restore to initial interrupt vector */
        R_RFD_REG_U08_VECTCTRL = R_RFD_VALUE_U08_VECTCTRL_OFF;
        
        /* Flag setting */
        g_u08_change_interrupt_vector_flag = R_RFD_VALUE_U08_SET_FWEDIS_FLAG_OFF;
    }
    
    R_RFD_HOOK_ExitCriticalSection();
    
    return (l_e_ret_value);
}

#define  R_RFD_END_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_RestoreInterruptVector
 *********************************************************************************************************************/
