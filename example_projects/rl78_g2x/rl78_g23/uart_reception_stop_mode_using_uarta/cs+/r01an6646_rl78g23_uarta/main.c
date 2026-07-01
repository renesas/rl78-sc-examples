/**********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO
 * THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
 /***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_UARTA0.h"
#include "Config_KR.h"
#include "Config_TAU0_0.h"
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/***********************************************************************************************************************
Exported global variables and functions (to be accessed by other files)
***********************************************************************************************************************/
uint8_t g_uarta0rxbuf;              /* UARTA0 receive buffer */
uint8_t g_uarta0rxerr;              /* UARTA0 receive error status */
MD_STATUS g_uarta0txend;            /* UARTA0 transmission end */
uint8_t g_status_flag;              /* status flag */

/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/
static uint8_t s_messageOK[4] = {"OK\r\n"};    /* Message for "T" */
static uint8_t s_messageok[4] = {"ok\r\n"};    /* Message for "t" */
static uint8_t s_messageUC[4] = {"UC\r\n"};    /* Message for other */
static uint8_t s_messageFE[4] = {"FE\r\n"};    /* Framing error message */
static uint8_t s_messagePE[4] = {"PE\r\n"};    /* Parity error message */
static uint8_t s_messageOE[4] = {"OE\r\n"};    /* Overrun error message */

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    EI();
    WKUPMD = 0x01;                 /* Starting of the high-speed on-chip oscillator is at high speed */
    R_Config_UARTA0_Start();
    R_Config_UARTA0_Receive(&g_uarta0rxbuf, 1);
    R_Config_KR_Start();

    while (1U)
    {
        g_status_flag = 0x00U;
        STOP();                        /* Wait for Key interrupt */
        
    while (0x00 == g_status_flag)
    {
            HALT();                    /* Wait for UARTA0 and timer interrupt */
    }
        R_Config_TAU0_0_Stop();
        
        if (0x01 == g_status_flag)     /* Finish Reception and check result */
        {
            URMK0  = 1U;               /* Disable Reception Interrupt */
            UREMK0 = 1U;               /* Disable Reception error Interrupt */
            
            if (g_uarta0rxerr)          /* Check reception error */
            {   /* Reception error */
                if (g_uarta0rxerr & 0x02)               /* Framing error */
                {   /* Transmit "Framing error" */
                    g_uarta0txend = R_Config_UARTA0_Send(s_messageFE, 4);
                    while (0 == g_uarta0txend)          /* Wait for final transmit */
                    {
                        NOP();
                    }
                }

                if (g_uarta0rxerr & 0x04)               /* Parity error */
                {   /* Transmit "Parity error" */
                    g_uarta0txend = R_Config_UARTA0_Send(s_messagePE, 4);
                    while (0 == g_uarta0txend)          /* Wait for final transmit */
                    {
                        NOP();
                    }
                }

                if (g_uarta0rxerr & 0x01)               /* Overrun error */
                {   /* Transmit "Overrun error" */
                    g_uarta0txend = R_Config_UARTA0_Send(s_messageOE, 4);
                    while (0 == g_uarta0txend)          /* Wait for final transmit */
                    {
                        NOP();
                    }
                }

            }
            else    /* Normal reception */
            {
                switch (g_uarta0rxbuf)   /* Check Reception data */
                {
                    case    'T':       /* Reception data is 'T' */
                        g_uarta0txend = R_Config_UARTA0_Send(s_messageOK, 4);    /* Transmit "OK" */
                        break;

                    case    't':       /* Reception data is 't' */
                        g_uarta0txend = R_Config_UARTA0_Send(s_messageok, 4);    /* Transmit "ok" */
                        break;

                    default:           /* Received another character */
                        g_uarta0txend = R_Config_UARTA0_Send(s_messageUC, 4);    /* Transmit "UC" */
                        break;
                }
                while (0 == g_uarta0txend)          /* Wait for final transmit */
                {
                    NOP();
                }
            }

            R_Config_UARTA0_Receive(&g_uarta0rxbuf, 1);     /* Set reception buffer pointer */

            URMK0  = 0U;               /* Enable Reception Interrupt */
            UREMK0 = 0U;               /* Enable Reception error Interrupt */
        }
        else
        {
            NOP();
        }
    }
}
/***********************************************************************************************************************
* End of function main
***********************************************************************************************************************/
