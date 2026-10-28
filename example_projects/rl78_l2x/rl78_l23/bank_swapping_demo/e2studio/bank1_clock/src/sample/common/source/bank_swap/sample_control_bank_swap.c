/**********************************************************************************************************************
    Program Name    : Sample program for Renesas Flash Driver (RFD RL78 Type11) (Bank Swap)
    
    File Name       : sample_control_bank_swap.c
    Program Version : V1.00.00
    Device(s)       : RL78/L23 microcontroller
    Description     : Sample program for bank swap control
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
#include "sample_control_bank_swap.h"
#include "sample_defines.h"
#include "sample_config.h"

#include "r_rfd_common_get_api.h"
#include "r_rfd_extra_area_control_api.h"
#include "r_rfd_extra_area_api.h"

#if (!defined SMP_BP_SWAP_IMMEDIATELY)
#include "r_rfd_common_control_api.h"
#else
#include "r_rfd_extra_extension_api.h"
#endif

/**********************************************************************************************************************
 * Function name : Sample_BankSwapControl
 *********************************************************************************************************************/
#define  SAMPLE_START_SECTION_SMP_EX
#include "sample_memmap.h"
/*********************************************************************************************************************/
/**
 *  Sample function for bank swap control.
 *  Check bank flag ->  Change bank flag -> Reset the CPU or swap bank immediately
 *  
 *  @param[in]      -
 *  @return         Execution result status  Need Update
 *                  - SAMPLE_ENUM_RET_STS_OK                 : Successful completion
 *                  - SAMPLE_ENUM_RET_ERR_MODE_MISMATCHED    : Mode mismatched error
 *                  - SAMPLE_ENUM_RET_ERR_CMD_SET_EXTRA_AREA : Set extra area command (boot flag) error
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_sample_ret_t Sample_BankSwapControl(void)
{
    /* Local variable definition */
    e_rfd_ret_t             l_e_rfd_ret_status;
    e_sample_ret_t          l_e_sam_ret_value;
    e_sample_ret_t          l_e_sam_ret_status;
    e_rfd_boot_cluster_t    l_e_boot_cluster;
    bool                    l_e_sam_error_flag;
    uint16_t                l_u16_security_and_boot_flags;
    
    /* Set local variables */
    l_e_sam_ret_value   = SAMPLE_ENUM_RET_STS_OK;
    l_e_sam_error_flag  = false;
    
    /******************************************************************************************************************
     * Check current boot flag condition
     *****************************************************************************************************************/
    /* This command should execute in non-programmable mode */
    R_RFD_GetSecurityAndBootFlags(&l_u16_security_and_boot_flags);
    
    if (0x0000u != (l_u16_security_and_boot_flags & SAMPLE_VALUE_U16_MASK1_FLSEC_BTFLG))
    {
        /* Current boot flag is the boot cluster 0, then the boot cluster 1 will be swapped boot cluster */
        l_e_boot_cluster = R_RFD_ENUM_BOOT_CLUSTER_1;
    }
    else
    {
        /* Current boot flag is the boot cluster 1, then the boot cluster 0 will be swapped boot cluster */
        l_e_boot_cluster = R_RFD_ENUM_BOOT_CLUSTER_0;
    }
    
    /******************************************************************************************************************
     * Set the code flash (extra area) programming mode
     *****************************************************************************************************************/
    l_e_rfd_ret_status = R_RFD_SetExtraProgrammingMode();
    
    if (l_e_rfd_ret_status != R_RFD_ENUM_RET_STS_OK)
    {
        l_e_sam_error_flag = true;
        l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_MODE_MISMATCHED;
    }
    else
    {
        /* No operation */
    }
    
    /******************************************************************************************************************
     * Set boot flag
     *****************************************************************************************************************/
    if (false == l_e_sam_error_flag)
    {
        R_RFD_SetExtraBootAreaReq(l_e_boot_cluster);
        l_e_sam_ret_status =  Sample_CheckExtraSeqEnd();
        
        if (SAMPLE_ENUM_RET_STS_OK != l_e_sam_ret_status)
        {
            l_e_sam_error_flag = true;
            l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_CMD_SET_EXTRA_AREA;
        }
        else
        {
            /* No operation */
        }
    }
    else /* true == l_e_sam_error_flag */
    {
        /* No operation */
    }
    
    /******************************************************************************************************************
     * Set non-programmable mode
     *****************************************************************************************************************/
    l_e_rfd_ret_status = R_RFD_SetExtraNonProgrammableMode();
    
    if (R_RFD_ENUM_RET_STS_OK != l_e_rfd_ret_status)
    {
        l_e_sam_error_flag = true;
        l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_MODE_MISMATCHED;
    }
    else
    {
        /* No operation */
    }
    
    if (false == l_e_sam_error_flag)
    {
#if (!defined SMP_BP_SWAP_IMMEDIATELY)
        /******************************************************************************************************************
         * Reset the CPU
         *****************************************************************************************************************/
        R_RFD_ForceReset();
#else
        /******************************************************************************************************************
         * Set the code flash (extra area) programming mode
         *****************************************************************************************************************/
        l_e_rfd_ret_status = R_RFD_SetExtraProgrammingMode();
        
        if (l_e_rfd_ret_status != R_RFD_ENUM_RET_STS_OK)
        {
            l_e_sam_error_flag = true;
            l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_MODE_MISMATCHED;
        }
        else
        {
            /* No operation */
        }
        
        /******************************************************************************************************************
         * Swap bank immediately without CPU reset
         *****************************************************************************************************************/
        if (false == l_e_sam_error_flag)
        {
            R_RFD_SetBootAreaImmediately(l_e_boot_cluster);
        }
        else /* true == l_e_sam_error_flag */
        {
            /* No operation */
        }
        
        /******************************************************************************************************************
         * Set non-programmable mode
         *****************************************************************************************************************/
        l_e_rfd_ret_status = R_RFD_SetExtraNonProgrammableMode();
        
        if (R_RFD_ENUM_RET_STS_OK != l_e_rfd_ret_status)
        {
            l_e_sam_error_flag = true;
            l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_MODE_MISMATCHED;
        }
        else
        {
            /* No operation */
        }
        
        /******************************************************************************************************************
         * Call the function swapped and placed at RESET_VECTOR_SWAPPED_BANK
         *****************************************************************************************************************/
        if (false == l_e_sam_error_flag)
        {
            ((void (R_RFD_FAR_FUNC *)(void))(uint32_t)RESET_VECTOR_SWAPPED_BANK)();
        }
        else /* true == l_e_sam_error_flag */
        {
            /* No operation */
        }
#endif
    }
    else /* true == l_e_sam_error_flag */
    {
        /* No operation */
    }
    
    return (l_e_sam_ret_value);
}

#define  SAMPLE_END_SECTION_SMP_EX
#include "sample_memmap.h"
/**********************************************************************************************************************
 End of function Sample_BankSwapControl
 *********************************************************************************************************************/
 
 
/**********************************************************************************************************************
 * Function name : Sample_CheckExtraSeqEnd
 *********************************************************************************************************************/
#define  SAMPLE_START_SECTION_SMP_EX
#include "sample_memmap.h"
/*********************************************************************************************************************/
/**
 *  Check the state of the extra area sequencer and result.
 *  
 *  @param[in]      -
 *  @return         Execution result status
 *                  - SAMPLE_ENUM_RET_STS_OK              : Successful completion
 *                  - SAMPLE_ENUM_RET_ERR_EXTRA_SEQUENCER : Extra area sequencer error
 *                  - SAMPLE_ENUM_RET_ERR_ACT_ERASE       : Erase action error
 *                  - SAMPLE_ENUM_RET_ERR_ACT_WRITE       : Write action error
 *                  - SAMPLE_ENUM_RET_ERR_ACT_BLANKCHECK  : Blankcheck action error
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_sample_ret_t Sample_CheckExtraSeqEnd(void)
{
    /* Local variable definition */
    e_sample_ret_t l_e_sam_ret_value;
    uint8_t        l_u08_status_flag;
    
    /* Set local variables */
    l_e_sam_ret_value = SAMPLE_ENUM_RET_STS_OK;
    
    /* Sequencer busy loop step1 */
    while (R_RFD_ENUM_RET_STS_BUSY == R_RFD_CheckExtraSeqEndStep1())
    {
        /* No operation */
        /* It is possible to write the program for detecting timeout here as necessity requires */
    }
    
    /* Sequencer busy loop step2 */
    while (R_RFD_ENUM_RET_STS_BUSY == R_RFD_CheckExtraSeqEndStep2())
    {
        /* No operation */
        /* It is possible to write the program for detecting timeout here as necessity requires */
    }
    
    /* Action error check */
    R_RFD_GetExtraSeqErrorStatus(&l_u08_status_flag);
    
    /* Check error status */
    if (SAMPLE_VALUE_U08_MASK0_8BIT != (l_u08_status_flag & SAMPLE_VALUE_U08_MASK1_FSQ_STATUS_ERR_EXTRA_SEQUENCER))
    {
        /* Set return value */
        l_e_sam_ret_value = SAMPLE_ENUM_RET_ERR_EXTRA_SEQUENCER;
    }
    else if (SAMPLE_VALUE_U08_MASK0_8BIT != (l_u08_status_flag & SAMPLE_VALUE_U08_MASK1_FSQ_STATUS_ERR_ERASE))
    {
        /* Set return value */
        l_e_sam_ret_value = SAMPLE_ENUM_RET_ERR_ACT_ERASE;
    }
    else if (SAMPLE_VALUE_U08_MASK0_8BIT != (l_u08_status_flag & SAMPLE_VALUE_U08_MASK1_FSQ_STATUS_ERR_WRITE))
    {
        /* Set return value */
        l_e_sam_ret_value = SAMPLE_ENUM_RET_ERR_ACT_WRITE;
    }
    else if (SAMPLE_VALUE_U08_MASK0_8BIT != (l_u08_status_flag & SAMPLE_VALUE_U08_MASK1_FSQ_STATUS_ERR_BLANKCHECK))
    {
        /* Set return value */
        l_e_sam_ret_value = SAMPLE_ENUM_RET_ERR_ACT_BLANKCHECK;
    }
    else
    {
        /* Set return value */
        l_e_sam_ret_value = SAMPLE_ENUM_RET_STS_OK;
    }
    
    /* Clear sequencer registers */
    R_RFD_ClearExtraSeqRegister();
    
    return (l_e_sam_ret_value);
}

#define  SAMPLE_END_SECTION_SMP_EX
#include "sample_memmap.h"
/**********************************************************************************************************************
 End of function Sample_CheckExtraSeqEnd
 *********************************************************************************************************************/
