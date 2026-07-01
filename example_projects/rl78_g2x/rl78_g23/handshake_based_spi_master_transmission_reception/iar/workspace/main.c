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
uint8_t     g_tx_data;                              /* Send data buffer */
uint8_t     g_rx_data;                              /* Receive data buffer */
volatile uint8_t     g_slave_select_flag;           /* slave select flag */
volatile uint8_t     g_status_confirmation_flag;    /* status confirmation flag */
volatile uint8_t     g_timeout_flag;                /* timeout flag */

uint8_t  g_num;                                     /* Number of data that can be sent by the slave */

volatile uint8_t g_rx_data_stored[63] ;             /* Receive data storage */

const uint8_t TX_NUM = 32;                          /* Send data number */
const uint8_t RX_NUM = 32;                          /* Receive data number */
const uint8_t TX_RX_NUM = 32;                       /* Send & Receive data number */
const uint16_t data_length = 1;                     /* Data length */

const uint8_t MODE[] =                              /* operation mode command code */
{
    0B00000000,                                     /* status check command  */
    0B01000000,                                     /* master receive command  */
    0B10000000,                                     /* master Send command */
    0B11000000,                                     /* master Send & Receive command */
    0B11111111,                                     /* DUMMY */
};

const uint8_t TX_DATA[]=
{
	0x20,				/*   */
	0x21,				/* ! */	
	0x22,				/* " */
	0x23,				/* # */
	0x24,				/* $ */
	0x25,				/* % */
	0x26,				/* & */
	0x27,				/* ' */
	0x28,				/* ( */
	0x29,				/* ) */
	0x2A,				/* * */
	0x2B,				/* + */
	0x2C,				/* , */
	0x2D,				/* - */
	0x2E,				/* . */
	0x2F,				/* / */
	0x30,				/* 0 */
	0x31,				/* 1 */
	0x32,				/* 2 */
	0x33,				/* 3 */
	0x34,				/* 4 */
	0x35,				/* 5 */
	0x36,				/* 6 */
	0x37,				/* 7 */
	0x38,				/* 8 */
	0x39,				/* 9 */
	0x3A,				/* : */
	0x3B,				/* ; */
	0x3C,				/* < */
	0x3D,				/* = */
	0x3E,				/* > */
	0x3F,				/* ? */
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
};

/*------------------------------------------------------
    prototype of function
------------------------------------------------------*/
uint8_t wait(void);                     /* timeout or /BUSY check   */
void CSI00_Status_check(void);           /* slave status check function */
void CSI00_Send_Receive(void);          /* send and receive data function */
void CSI00_Send(void);                  /* send data to slave funvtion  */
void CSI00_Receive(void);               /* receive data from slave function */
void main(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{       

    R_Config_TAU0_3_Higher8bits_Start();    /* 1ms interval timer start */
    R_Config_CSI00_Start();                 /* Enable CSI00 module */
    
    while (1U)
    {

/*------------------------------------------------------
   Wait for 1 ms  
------------------------------------------------------*/

        g_timeout_flag = 0;             /* clear g_timeout_flag */
        DI();                           /* Disable interrupt functions */
        while (TMIF03H == 0U)
        {
            HALT();                     /*  Wait until INTTM03H interrupt  */
        }
        TMIF03H = 0U;                   /* clear INTTM03 interrupt flag */

/*------------------------------------------------------
   Issue Chip Select signal
------------------------------------------------------*/

        if(g_slave_select_flag == 0U)
        {                               /* CS1 select timing    */
            CS2_pin =1;              /* set CS2 inactive     */
            CS1_pin =0;              /* set CS1 active       */
        }
        else
        {                               /* CS2 select timing    */
            CS1_pin =1;              /* set CS1 inactive     */
            CS2_pin =0;              /* set CS2 active       */
        }

/*==========================================================
    Start Command sequence
==========================================================*/

        if(g_status_confirmation_flag ==0)/* check g_status_confirmation_flag*/
        {

/*------------------------------------------------------
    Start Status check command
------------------------------------------------------*/

            CSI00_Status_check();                    /*call Status_check function*/
            if(g_timeout_flag == 1)
            {
                g_slave_select_flag ^= 1U;          /*change slave number*/
                g_status_confirmation_flag = 0;     /* clear g_status_confirmation_flag */
            }
        }else
        {

/*------------------------------------------------------
    Send Receive command
------------------------------------------------------*/

            CSI00_Send_Receive();                   /*call Send Receive function*/
            /*CSI00_Send();*/
            /*CSI00_Receive();*/
            g_slave_select_flag ^= 1U;              /*change slave number*/
            g_status_confirmation_flag = 0;         /* clear g_status_confirmation_flag */

        }   /* end of else  */
	CS2_pin =1;		/*set CS2 inactive*/
	CS1_pin =1;		/*set CS1 inactive*/
    }   /* end of while(1)  */

}   /* end of main function */

/***********************************************************************************************************************
* Function Name: CSI00_Status_check
* Description  : This function implements Status check function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void CSI00_Status_check(void)
{
    uint8_t  cnt = 0;

    for ( cnt = 0; cnt <= 2; cnt++)
    {
        if (wait()== 0)
        {
            EI();                       /* Enable interrupt functions */
            if( cnt == 0 )
            {                           /* send command timing */
                g_tx_data = MODE[0];    /* set status check command  */
            }
            else
            {                           /* data receive timing */
                g_tx_data = MODE[4];    /* set DUMMY data */
            }

            R_Config_CSI00_Send_Receive(&g_tx_data, data_length, &g_rx_data);

            HALT();                     /*  Wait until INTCSI00 interrupt  */

            if ( cnt > 0)
            {
                g_rx_data_stored[cnt -1] = g_rx_data;       /*Number of data that can be sent or received by the slave*/
                if ( cnt == 2)
                {
                    if((0x80 > g_rx_data_stored[0])&&(g_rx_data_stored[0] >= 0x40) && (0x40 > g_rx_data_stored[1])&&(0x40 > g_rx_data_stored[1]))
                    {
                        g_status_confirmation_flag = 1;/* set g_status_confirmation_flag */
                    }
                }

            }   /* end of status check   */
        }
        else 
        {
            g_timeout_flag = 1; /* set g_timeout_flag */
            break;
        }

    }   /* end of for loop  */
}   /* end of CSI00_Status_check function    */

/***********************************************************************************************************************
* Function Name: CSI00_Send_Receive
* Description  : This function implements Send Receive function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void CSI00_Send_Receive(void)
{
/*------------------------------------------------------
  Check the number of send & receive characters
------------------------------------------------------*/
	uint8_t  cnt = 0;
	g_num = g_rx_data_stored[0] & 0x3F  ;	
	if(g_num >= TX_RX_NUM)
	{
		if(g_rx_data_stored[1] >= TX_RX_NUM)
		{
/*------------------------------------------------------
 Send & Receive operation
------------------------------------------------------*/
			EI();
			for ( cnt = 0; cnt <= TX_RX_NUM+1; cnt++)
			{
				if (wait()== 0)
				{
					if(cnt == 0)
					{
						g_tx_data = MODE[3] + TX_RX_NUM;/* master Send & Receive command + Send & Receive characters */
					}
					else
					{
						g_tx_data = TX_DATA[cnt -1];
					}
					R_Config_CSI00_Send_Receive(&g_tx_data, data_length, &g_rx_data);
					HALT();			/*  Wait until INTCSI00 interrupt  */
					if (cnt != 0)
					{
						g_rx_data_stored[cnt - 1] = g_rx_data;
					}
				}
				else
				{
				g_timeout_flag = 1; /* set g_timeout_flag */
            			break;
				}
			}
		}
	}
}

/***********************************************************************************************************************
* Function Name: CSI00_Send
* Description  : This function implements Send function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void CSI00_Send(void)
{
/*------------------------------------------------------
  Check the number of send characters
------------------------------------------------------*/
	uint8_t  cnt = 0;
	if(g_rx_data_stored[1] >= TX_NUM)
	{
/*------------------------------------------------------
 Send  operation
------------------------------------------------------*/
		EI();
		for ( cnt = 0; cnt <= TX_NUM + 1; cnt++)
		{
			if (wait()== 0)
			{
				if(cnt == 0)
				{
					g_tx_data = MODE[2] + TX_NUM;/* master Send command + Send characters */
				}
				else
				{
					g_tx_data = TX_DATA[cnt -1];
				}
				R_Config_CSI00_Send_Receive(&g_tx_data, data_length, &g_rx_data);
				HALT();			/*  Wait until INTCSI00 interrupt  */
			}
			else
			{
			g_timeout_flag = 1; /* set g_timeout_flag */
           		break;
			}
		}
	}
}

/***********************************************************************************************************************
* Function Name: CSI00_Receive
* Description  : This function implements Receive function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void CSI00_Receive(void)
{	
/*------------------------------------------------------
  Check the number of Receive characters
------------------------------------------------------*/
	uint8_t  cnt = 0;
	g_num = g_rx_data_stored[0] & 0x3F  ;	
	if(g_num >= RX_NUM)
	{
/*------------------------------------------------------
 Receive operation
------------------------------------------------------*/
		EI();
		for ( cnt = 0; cnt <= RX_NUM+1; cnt++)
		{
			if (wait()== 0)
			{
				if(cnt == 0)
				{
					g_tx_data = MODE[1] + RX_NUM;/* master Receivend command + Receive characters */
				}
				else
				{
					g_tx_data = MODE[4];
				}
				R_Config_CSI00_Send_Receive(&g_tx_data, data_length, &g_rx_data);
				HALT();			/*  Wait until INTCSI00 interrupt  */
				if (cnt != 0)
				{
					g_rx_data_stored[cnt - 1] = g_rx_data;
				}
			}
			else
			{
			g_timeout_flag = 1; /* set g_timeout_flag */
           			break;
			}
		}
	}
}

/***********************************************************************************************************************
* Function Name: wait
* Description  : This function implements wait function.
* Arguments    : None
* Return Value : 1 timeout occured, 0 ready signal received 
***********************************************************************************************************************/
uint8_t wait(void)
{
	/*wait Confirmation*/
	TS0 = _0008_TAU_CH3_START_TRG_ON;
    	while (TMIF03 == 0U)
	{
		if(BUSYIN == 0)
		{
			TT0 = _0008_TAU_CH3_STOP_TRG_ON;
			TMIF03 = 0U;    /* clear INTTM03 interrupt flag */
			return 0;	/* Ready signal received */
		} 					
	}
    	TT0 = _0008_TAU_CH3_STOP_TRG_ON;
	TMIF03 = 0U;    /* clear INTTM03 interrupt flag */
	return 1;	/* Timeout */
}