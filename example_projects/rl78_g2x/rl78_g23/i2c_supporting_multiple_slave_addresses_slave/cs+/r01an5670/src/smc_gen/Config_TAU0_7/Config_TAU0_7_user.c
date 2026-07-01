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
* Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Config_TAU0_7_user.c
* Version      : 1.0.0
* Device(s)    : R7F100GLGxFB
* Description  : This file implements device driver for Config_TAU0_7.
* Creation Date: 2021-05-21
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_TAU0_7.h"
/* Start user code for include. Do not edit comment generated here */
#include "Config_IICA0.h"
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_Config_TAU0_7_interrupt(vect=INTTM07)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
#define   D0_pin  ( P0_bit.no3 )
#define   D1_pin  ( P0_bit.no2 )
#define   D2_pin  ( P4_bit.no3 )
#define   D3_pin  ( P4_bit.no2 )
#define   SEL_L   ( P7_bit.no7 )
#define   SEL_U   ( P4_bit.no1 )
#define   SW_IN   ( P13_bit.no7 )

#define   LED_ON  ( 0 )                 /* LED ON data                          */
#define   LED_OFF ( 1 )                 /* LED OFF data                         */

volatile uint8_t static g_disp_data;    /* display data buffer area             */

volatile uint8_t static g_5ms;          /* base timer counter(5ms interrval)    */

uint8_t r_sl_addr_get(void);		/* get slave address			*/

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TAU0_7_Create_UserInit
* Description  : This function adds user code after initializing the TAU0 channel 7.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAU0_7_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_TAU0_7_interrupt
* Description  : This function is INTTM07 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_Config_TAU0_7_interrupt(void)
{
    /* Start user code for r_Config_TAU0_7_interrupt. Do not edit comment generated here */

/*------------------------------------------
    change LED display data
--------------------------------------------*/

    SEL_L = LED_OFF;                        /* turn off display         */
    SEL_U = LED_OFF;


    D0_pin = ( g_disp_data & 0x01 );        /* set LED1 or LED5 data    */
    g_disp_data = g_disp_data >> 1;         /* get next bit data        */
    
    D1_pin = ( g_disp_data & 0x01 );        /* set LED2 or LED6 data    */
    g_disp_data = g_disp_data >> 1;         /* get next bit data        */

    D2_pin = ( g_disp_data & 0x01 );        /* set LED3 or LED7 data    */
    g_disp_data = g_disp_data >> 1;         /* get next bit data        */

    D3_pin = ( g_disp_data & 0x01 );        /* set LED4 or LED8 data    */
    g_disp_data = g_disp_data >> 1;                      /* get next time data       */

/*------------------------------------------
    display new nibble data
--------------------------------------------*/

    if ( 0 == ( g_5ms & 0x01 ) )            /* check low or high nibble */
    {                                       /* low nibble timing        */
        SEL_L = LED_ON;                     /* enable low nibble        */
    }
    else
    {                                       /* high nibble timing       */
        SEL_U = LED_ON;                     /* enable high nibble       */

/*------------------------------------------
    get next display data
--------------------------------------------*/

        g_disp_data = r_sl_addr_get();      /* get slave address        */

    }

    g_5ms++;                                /* count up 5ms counter     */


    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/***********************************************************************
* Function Name: R_LED_Init
* Description  : This function initialize LED.
* Arguments    : None
* Return Value : None
************************************************************************/
void R_LED_Init(void)
{

/*------------------------------------------
    initialize variable
--------------------------------------------*/

    g_disp_data = 0;                    /* clear display data           */
    g_5ms = 0;                          /* clear 5milli sec counter     */

/*------------------------------------------
    start TM07
--------------------------------------------*/

    TMIF07 = 0;                         /* clear INTTM07 request flag   */
    TMMK07 = 0;                         /* enable INTTM07 interrupt     */

    TS0L = 0x80;                        /* start TM07                   */


} /* end of R_LED_Init() */

/* End user code. Do not edit comment generated here */
