/**********************************************************************************************************************
    Program Name    : Renesas Flash Driver (RFD RL78 Type11)
    
    File Name       : r_rfd_data_flash_control_api.h
    Program Version : V1.00
    Device(s)       : RL78/L23 microcontroller
    Description     : API definition of Data Flash Control
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

#ifndef R_RFD_DATA_FLASH_CONTROL_API_H
#define R_RFD_DATA_FLASH_CONTROL_API_H

#include "r_rfd.h"
#include "r_rfd_common_api.h"

/**********************************************************************************************************************
 For Data Flash Control Component
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Prototype declaration
 *********************************************************************************************************************/

extern R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_SetDFProgrammingMode(void);
extern R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_SetDFNonProgrammableMode(void);
extern R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckDFProgrammingMode(void);
extern R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckDFNonProgrammableMode(void);
extern R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckDFSeqEndStep1(void);
extern R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckDFSeqEndStep2(void);
extern R_RFD_FAR_FUNC void        R_RFD_GetDFSeqErrorStatus(uint8_t __near * onp_u08_error_status);
extern R_RFD_FAR_FUNC void        R_RFD_ClearDFSeqRegister(void);
extern R_RFD_FAR_FUNC void        R_RFD_ForceStopDFSeq(void);
extern R_RFD_FAR_FUNC void        r_rfd_df_wait_count(uint8_t i_u08_count);

#endif /* end of R_RFD_DATA_FLASH_CONTROL_API_H */
