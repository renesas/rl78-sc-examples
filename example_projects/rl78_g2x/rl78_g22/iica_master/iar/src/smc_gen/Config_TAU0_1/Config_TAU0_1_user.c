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
* File Name        : Config_TAU0_1_user.c
* Component Version: 1.4.0
* Device(s)        : R7F102GGExFB
* Description      : This file implements device driver for Config_TAU0_1.
***********************************************************************************************************************/
/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_TAU0_1.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
volatile    uint16_t    g_us_rest_time;         /* remainig time (us)       */

void set_delay_us(uint16_t);                    /* set wait time for us     */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TAU0_1_Create_UserInit
* Description  : This function adds user code after initializing the TAU0 channel 1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAU0_1_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_TAU0_1_interrupt
* Description  : This function is INTTM01 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma vector = INTTM01_vect
__interrupt static void r_Config_TAU0_1_interrupt(void)
{
    /* Start user code for r_Config_TAU0_1_interrupt. Do not edit comment generated here */
    if ( g_us_rest_time == 0 )
    {
/*--------------------------------------*/
/*  specified time is up                */
/*--------------------------------------*/
        TMMK01 = 1;                             /* disable INTTM01              */
        TT0L = 0x02;                            /* stop TM01 operation          */

    }
    else
    {       
/*--------------------------------------*/
/*  remaining time > 0us                */
/*--------------------------------------*/
        if ( g_us_rest_time <= 2000 )
        {
/*--------------------------------------*/
/*  remaining time <= 4000us            */
/* remaining data is already set to TCR */
/*--------------------------------------*/
            g_us_rest_time = 0x0000;            /* and next remaining time is 0 */
        }
        else
        {
/*--------------------------------------*/
/*  remaining time > 2000us             */
/*--------------------------------------*/
            g_us_rest_time -= 2000;             /* change remaining wait time   */
            if ( g_us_rest_time < 2000 )
            {
/*--------------------------------------*/
/*  remaing time < 2000us               */
/*   next cycle < 2000 and TDR < 64000  */
/*--------------------------------------*/
                TDR01 = (( g_us_rest_time * 32 ) - 1 );
            }
            else
            {
                /* do nothing, because next TDR is same as current data(63999)  */
            }
        }

    }
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/*********************************************************************************
* Function Name: delay_us
* Description  : This function wait for micro second upto 65ms
* Arguments    : wait time
* Return Value : None
*********************************************************************************/
void delay_us(uint16_t us)
{
    if ( us > 0 )
    {                                           /* wait more than 1us       */
        set_delay_us(us);                       /* set wait time            */

/* wait for specified time is up                */
        while ( (TE0L & 0x02) )                 /* wait for TM01 is stop    */
        {
            NOP();                              /* wait for time up         */
        }
    }

}
/*********************************************************************************
* Function Name: set_delay_us
* Description  : This function set wait time to TM02
* Arguments    : wait time(us)
* Return Value : 
* Remark       : TM02(interval timer) works as pipeline operation.
                 TCR has current count data(1st data) and TDR hold next(2nd data) 
                 and at INTTM002 timing TDR data is move to TCR without delay. 
*********************************************************************************/
void set_delay_us(uint16_t us)
{

    TMMK01 = 1;                                 /* disable INTTM01 interrupt    */
    TMIF01 = 0;                                 /* clear interrupt flag         */
    g_us_rest_time = 0x0000;                    /* clear remaining time         */

    if ( us > 2000U )
    {       /* wait time is over 2000us     */
        g_us_rest_time = ( us - 2000U );        /* set remaining time           */
        TDR01 = (( 1999U * 32U ) - 1U );        /* set count data of TDR01      */
        TS0L = 0x02;                            /* start TM01 counting          */

            /* set next count data          */
        if ( g_us_rest_time > 2000 )
        {   /* remaining time more than 2000us  */
            TDR01 = (( 2000U * 32U ) - 1U );    /* set 2000us count data        */
        }
        else
        {   /* remaining time less than 2000us  */
            TDR01 = (( g_us_rest_time * 32U ) - 1U ); /* set next count data */
        }
            TMMK01 = 0;                         /* enable INTTM01               */
    }
    else
    {       /* wait time <= 2000us              */
        if ( us <= 1 )
        {   /* count time is 1 or 0 us      */
            TT0L = 0x02;                        /* stop TM01 operation          */
        
        }
        else
        {   /* specified time is more than 2us  : now g_us_rest_time is 0x0000  */
            TDR01 = ((( us - 1U ) * 32U ) - 1U ); /* set TDR01 count data       */
            TS0L = 0x02;                        /* start TM01 counting          */
            TMMK01 = 0;                         /* enable INTTM01               */
        }

    }

}
/* End user code. Do not edit comment generated here */

