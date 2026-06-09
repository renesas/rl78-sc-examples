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
 * Copyright (C) 2024 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_UART0.h"
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/***********************************************************************************************************************
Exported global variables and functions (to be accessed by other files)
***********************************************************************************************************************/
uint8_t g_Uart0RxBuf;              /* UART0 receive buffer */
uint8_t g_Uart0RxErr;              /* UART0 receive error status */
MD_STATUS g_Uart0TxEnd;            /* UART0 transmission end */

/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/
static uint8_t messageOK[4] = {"OK\r\n"};	/* Message for "T" */
static uint8_t messageok[4] = {"ok\r\n"};	/* Message for "t" */
static uint8_t messageUC[4] = {"UC\r\n"};	/* Message for other */
static uint8_t messageFE[4] = {"FE\r\n"};	/* Framing error message */
static uint8_t messagePE[4] = {"PE\r\n"};	/* Parity error message */
static uint8_t messageOE[4] = {"OE\r\n"};	/* Overrun error message */

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    EI();
    R_Config_UART0_Receive(&g_Uart0RxBuf, 1);
    R_Config_UART0_Start();
    
    while (1U)
    {
        HALT();                    /* Wait for UART Rx interrupt */

        /* Finish Reception and check result */

        SRMK0 = 1U;                /* Disable Reception Interrupt */
        SREMK0 = 1U;               /* Disable Reception error Interrupt */
        
        if (g_Uart0RxErr)          /* Check reception error */
        {   /* Reception error */
            if(g_Uart0RxErr & 0x04)               /* Framing error */
            {   /* Transmit "Framing error" */
                g_Uart0TxEnd = R_Config_UART0_Send(messageFE, 4);
                while(g_Uart0TxEnd == 0)          /* Wait for final transmit */
		{
		    NOP();
		}
            }

            if(g_Uart0RxErr & 0x02)               /* Parity error */
            {   /* Transmit "Parity error" */
                g_Uart0TxEnd = R_Config_UART0_Send(messagePE, 4);
                while(g_Uart0TxEnd == 0)          /* Wait for final transmit */
		{
		    NOP();
		}
            }

            if(g_Uart0RxErr & 0x01)               /* Overrun error */
            {   /* Transmit "Overrun error" */
                g_Uart0TxEnd = R_Config_UART0_Send(messageOE, 4);
                while(g_Uart0TxEnd == 0)          /* Wait for final transmit */
		{
		    NOP();
		}
            }

        }
        else    /* Normal reception */
        {
            switch(g_Uart0RxBuf)   /* Check Reception data */
            {
                case    'T':       /* Reception data is 'T' */
                    g_Uart0TxEnd = R_Config_UART0_Send(messageOK, 4);    /* Transmit "OK" */
                    break;

                case    't':       /* Reception data is 't' */
                    g_Uart0TxEnd = R_Config_UART0_Send(messageok, 4);    /* Transmit "ok" */
                    break;

                default:           /* Received another character */
                    g_Uart0TxEnd = R_Config_UART0_Send(messageUC, 4);    /* Transmit "UC" */
                    break;
            }
            while(g_Uart0TxEnd == 0)          /* Wait for final transmit */
	    {
	        NOP();
	    }
        }

        /* For next reception */

        /* Set reception buffer pointer */
        R_Config_UART0_Receive(&g_Uart0RxBuf, 1);

        SRMK0 = 0U;                /* Enable Reception Interrupt */
        SREMK0 = 0U;               /* Enable Reception error Interrupt */
    }
}
