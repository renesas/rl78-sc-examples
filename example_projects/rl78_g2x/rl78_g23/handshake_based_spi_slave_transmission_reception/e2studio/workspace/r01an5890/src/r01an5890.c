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
/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c                                                */
/*  DATE        :                                                      */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/

/*******************************************************************************
Includes
********************************************************************************/
#include "r_smc_entry.h"
/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
uint8_t     g_tx_data;              /* Transmit data buffer */
uint8_t     g_rx_data;              /* Receive data buffer */

volatile uint8_t 	g_mode_check;            /* mode check flag */

uint8_t  g_num;				 /* Number of data that can be sent by the slave */

volatile uint8_t g_rx_data_stored[63] ;	/* Receive data storage */

const uint8_t TX_NUM = 32;		/* Transmit data number */
const uint8_t RX_NUM = 32;		/* Receive data number */
const uint16_t data_length = 1;		/* Data length */
const uint8_t TX_DATA[63]=
{
	0x40,				/* @ */
	0x41,				/* A */
	0x42,				/* B */
	0x43,				/* C */
	0x44,				/* D */
	0x45,				/* E */
	0x46,				/* F */
	0x47,				/* G */
	0x48,				/* H */
	0x49,				/* I */
	0x4A,				/* J */
	0x4B,				/* K */
	0x4C,				/* L */
	0x4D,				/* M */
	0x4E,				/* N */
	0x4F,				/* O */
	0x50,				/* P */
	0x51,				/* Q */
	0x52,				/* R */
	0x53,				/* S */
	0x54,				/* T */
	0x55,				/* U */
	0x56,				/* V */
	0x57,				/* W */
	0x58,				/* X */
	0x59,				/* Y */
	0x5A,				/* Z */
	0x5B,				/* [ */
	0x5C,				/* \ */
	0x5D,				/* ] */
	0x5E,				/* ^ */
	0x5F,				/* _ */
	0x60,				/* ' */
	0x61,				/* a */
	0x62,				/* b */
	0x63,				/* c */
	0x64,				/* d */
	0x65,				/* e */
	0x66,				/* f */
	0x67,				/* g */
	0x68,				/* h */
	0x69,				/* i */
	0x6A,				/* j */
	0x6B,				/* k */
	0x6C,				/* l */
	0x6D,				/* m */
	0x6E,				/* n */
	0x6F,				/* o */
	0x70,				/* p */
	0x71,				/* q */
	0x72,				/* r */
	0x73,				/* s */
	0x74,				/* t */
	0x75,				/* u */
	0x76,				/* v */
	0x77,				/* w */
	0x78,				/* x */
	0x79,				/* y */
	0x7A,				/* z */
	0x7B,				/* { */
	0x7C,				/* | */
	0x7D,				/* } */
	0x7E,				/* ~ */
};

void CSI00_Status_check(void);
void CSI00_Send_Receive(void);
void CSI00_Send(void);
void CSI00_Receive(void);
void main(void);
/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
	g_tx_data = 0xff;	/* DUMMY */
	g_rx_data = 0xff;	/* DUMMY */

	PM_SO00 = 1U;/* SO00 signal set to input port */
	PM_BUSY = 1U;/* BUSY signal set to input port */
	R_Config_INTC_INTP0_Start();	/* Ready INTP0*/

	while (1U)
	{
/*------------------------------------------------------
   Wait for INTP0 interrupt
------------------------------------------------------*/
		DI();
		while ( PIF0 == 0U)
		{
			HALT();			/*  Wait until INTP0 interrupt  */
		}
		PIF0 = 0U;
/*------------------------------------------------------
   Chip select
------------------------------------------------------*/
		if (CS_pin == 0U)		/*  Chip select ON  */
		{
			PM_SO00 = 0U;/* SO00 signal set to output port */
			PM_BUSY = 0U;/* BUSY signal set to output port */
			SO0 = (uint16_t)~_0001_SAU_CH0_DATA_OUTPUT_1;    /* CSI00 SO initial level */
    			SS0 = _0001_SAU_CH0_START_TRG_ON;    /* enable CSI00 */
  			CSIIF00 = 0U;    /* clear INTCSI00 interrupt flag */
   			CSIMK00 = 0U;    /* enable INTCSI00 interrupt */
			EI();
			R_Config_CSI00_Send_Receive(&g_tx_data, data_length, &g_rx_data);
			BUSYOUT = 0U;	/*  Ready signal  */
			HALT();			/*  Wait until INTCSI00 interrupt  */
			g_rx_data_stored[0] = g_rx_data;

			g_num = g_rx_data_stored[0]&0x3F; /* Confirmation of send and received characters */
			g_mode_check = g_rx_data_stored[0]&0xc0; /* Command Confirmation */

			switch(g_mode_check)
			{
				case 0x00:
					CSI00_Status_check();	/*�@Status Confirmation Command */
					break;
				case 0x40:			/*�@master  Receive command */
					CSI00_Send();
					break;
				case 0x80:			/* master Transmit command */
					CSI00_Receive();
					break;
				case 0xc0:			/* master Transmit & Receive command */
					CSI00_Send_Receive();
					break;
				default:			/* other */
					break;
			}
		}
		else
		{
		CSIMK00 = 1U;    /* disable INTCSI00 interrupt */
		ST0 = _0001_SAU_CH0_STOP_TRG_ON;    /* disable CSI00 */
  		CSIIF00 = 0U;    /* clear INTCSI00 interrupt flag */
		PM_SO00 = 1U;/* SO00 signal set to input port */
		PM_BUSY = 1U;/* BUSY signal set to input port */
		g_tx_data = 0xff;/* DUMMY */
		}
	}

}

/***********************************************************************************************************************
* Function Name: CSI00_Status_check
* Description  : This function implements Status Confirmation Command function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void CSI00_Status_check(void)
{
	uint8_t  cnt = 0;
	for ( cnt = 0; cnt <= 1; cnt++)
	{
		if(cnt == 0)
		{
			g_tx_data = TX_NUM + 0x40;
		}
		else
		{
			g_tx_data = RX_NUM;
		}
		R_Config_CSI00_Send_Receive(&g_tx_data, data_length, &g_rx_data);
		BUSYOUT = 0U;	/*  Ready signal  */
		HALT();			/*  Wait until INTCSI00 interrupt  */
	}
}
/***********************************************************************************************************************
* Function Name: CSI00_Send_Receive
* Description  : This function implements CSI00 Send Receive function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void CSI00_Send_Receive(void)
{
	uint8_t  cnt = 0;
	for ( cnt = 0; cnt <= g_num; cnt++)
	{
		g_tx_data = TX_DATA[cnt];
		R_Config_CSI00_Send_Receive(&g_tx_data, data_length, &g_rx_data);
		BUSYOUT = 0U;	/*  Ready signal  */
		HALT();			/*  Wait until INTCSI00 interrupt  */
		g_rx_data_stored[cnt] = g_rx_data;
	}
}
/***********************************************************************************************************************
* Function Name: CSI00_Send
* Description  : This function implements CSI00 Send function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void CSI00_Send(void)
{
	uint8_t  cnt = 0;
	for ( cnt = 0; cnt <= g_num; cnt++)
	{
		g_tx_data = TX_DATA[cnt];
		R_Config_CSI00_Send_Receive(&g_tx_data, data_length, &g_rx_data);
		BUSYOUT = 0U;	/*  Ready signal  */
		HALT();			/*  Wait until INTCSI00 interrupt  */
	}
}
/***********************************************************************************************************************
* Function Name: CSI00_Receive
* Description  : This function implements CSI00 Receive function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void CSI00_Receive(void)
{
	uint8_t  cnt = 0;
	g_tx_data = 0xff;
	for ( cnt = 0; cnt <= g_num; cnt++)
	{
		R_Config_CSI00_Send_Receive(&g_tx_data, data_length, &g_rx_data);
		BUSYOUT = 0U;	/*  Ready signal  */
		HALT();			/*  Wait until INTCSI00 interrupt  */
		g_rx_data_stored[cnt] = g_rx_data;
	}
}
