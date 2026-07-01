/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2021, 2024 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : r_cg_elc.h
* Version          : 1.0.20
* Device(s)        : R7F102GGExFB
* Description      : General header file for ELC peripheral.
***********************************************************************************************************************/

#ifndef ELC_H
#define ELC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Event Output Destination Select Register n (ELSELRn) (n = 00 to 08, 10 to 19)
*/
/* Selection of event link (ELSELRn3 - ELSELRn0) */
#define _00_ELC_EVENT_LINK_DISABLE      (0x00U)    /* event link disabled */
#define _01_ELC_EVENT_LINK_AD           (0x01U)    /* event link destination AD converter */
#define _02_ELC_EVENT_LINK_TAU00        (0x02U)    /* event link destination TAU00 */
#define _03_ELC_EVENT_LINK_TAU01        (0x03U)    /* event link destination TAU01 */
#define _04_ELC_EVENT_LINK_SMS          (0x04U)    /* event link destination SNOOZE mode sequencer */
#define _05_ELC_EVENT_LINK_DTC          (0x05U)    /* event link destination DTC */
#define _06_ELC_EVENT_LINK_CTSU         (0x06U)    /* event link destination Capacitive sensing unit */
#define _07_ELC_EVENT_LINK_TML32        (0x07U)    /* event link destination 32-bit interval timer */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
