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
* File Name        : r_cg_userdefine.h
* Version          : 1.0.30
* Device(s)        : R7F100GLGxFA
* Description      : User header file for code generation.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

#ifndef USER_DEF_H
#define USER_DEF_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/* Start user code for register. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Start user code for macro define. Do not edit comment generated here */
#define R_RTC_INIT_SEC            (0x55U)   /* An initial current time(second) */
#define R_RTC_INIT_MIN            (0x59U)   /* An initial current time(minute) */
#define R_RTC_INIT_HOUR           (0x15U)   /* An initial current time(hour) */
#define R_RTC_INIT_WEEK           (0x05U)   /* An initial current time(week) */
#define R_RTC_INIT_DAY            (0x01U)   /* An initial current time(day) */
#define R_RTC_INIT_MONTH          (0x01U)   /* An initial current time(month) */
#define R_RTC_INIT_YEAR           (0x21U)   /* An initial current time(year) */

#define R_RTC_ALARM_MIN           (0x00U)   /* An alarm time(minute) */
#define R_RTC_ALARM_HOUR          (0x16U)   /* An alarm time(hour) */
#define R_RTC_ALARM_WEEK          (0x7FU) /* An alarm time(week) */

#define R_INTERRUPT_OFF           (0U)
#define R_INTERRUPT_ON            (1U)
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
/* Start user code for type define. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
