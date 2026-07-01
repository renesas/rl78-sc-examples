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
/*  DATE        :2020/12/06                                            */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :R7F100GLG                                             */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/

/***********************************************************************/

/*******************************************************************************
Includes
********************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_IICA0.h"
#include "Config_TAU0_7.h"
#include "Config_TAU0_3.h"


/*******************************************************************************
Global variables and functions
********************************************************************************/

uint8_t const INC_DATA[16][16] =
{ 
    /* increment data patern1 :0x00-0x3F */
    {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F},
    {0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F},
    {0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F},
    {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F},

    /* increment data patern2 :0x40-0x7F */
    {0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F},
    {0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F},
    {0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F},
    {0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F},

    /* increment data patern3 :0x80-0xBF */
    {0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F},
    {0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F},
    {0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF},
    {0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0xBE,0xBF},

    /* increment data patern4 :0xC0-0xFF */
    {0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF},
    {0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xDB,0xDC,0xDD,0xDE,0xDF},
    {0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,0xEE,0xEF},
    {0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFE,0xFF}
};

uint8_t g_sl_addr_T[4] = {RAM1,RAM2,RAM3,RAM4};         /* slave address table     */
uint8_t g_Rx_buff[256];                                 /* buffer for received data*/
uint8_t g_Tx_buff[257] =                                /* buffer for transmit data*/
{
    0x00,                                               /* address register         */
    0xFF,0xFE,0xFD,0xFC,0xFB,0xFA,0xF9,0xF8,0xF7,0xF6,0xF5,0xF4,0xF3,0xF2,0xF1,0xF0,
    0xEF,0xEE,0xED,0xEC,0xEB,0xEA,0xE9,0xE8,0xE7,0xE6,0xE5,0xE4,0xE3,0xE2,0xE1,0xE0,
    0xDF,0xDE,0xDD,0xDC,0xDB,0xDA,0xD9,0xD8,0xD7,0xD6,0xD5,0xD4,0xD3,0xD2,0xD1,0xD0,
    0xCF,0xCE,0xCD,0xCC,0xCB,0xCA,0xC9,0xC8,0xC7,0xC6,0xC5,0xC4,0xC3,0xC2,0xC1,0xC0,
    0xBF,0xBE,0xBD,0xBC,0xBB,0xBA,0xB9,0xB8,0xB7,0xB6,0xB5,0xB4,0xB3,0xB2,0xB1,0xB0,
    0xAF,0xAE,0xAD,0xAC,0xAB,0xAA,0xA9,0xA8,0xA7,0xA6,0xA5,0xA4,0xA3,0xA2,0xA1,0xA0,
    0x9F,0x9E,0x9D,0x9C,0x9B,0x9A,0x99,0x98,0x97,0x96,0x95,0x94,0x93,0x92,0x91,0x90,
    0x8F,0x8E,0x8D,0x8C,0x8B,0x8A,0x89,0x88,0x87,0x86,0x85,0x84,0x83,0x82,0x81,0x80,
    0x7F,0x7E,0x7D,0x7C,0x7B,0x7A,0x79,0x78,0x77,0x76,0x75,0x74,0x73,0x72,0x71,0x70,
    0x6F,0x6E,0x6D,0x6C,0x6B,0x6A,0x69,0x68,0x67,0x66,0x65,0x64,0x63,0x62,0x61,0x60,
    0x5F,0x5E,0x5D,0x5C,0x5B,0x5A,0x59,0x58,0x57,0x56,0x55,0x54,0x53,0x52,0x51,0x50,
    0x4F,0x4E,0x4D,0x4C,0x4B,0x4A,0x49,0x48,0x47,0x46,0x45,0x44,0x43,0x42,0x41,0x40,
    0x3F,0x3E,0x3D,0x3C,0x3B,0x3A,0x39,0x38,0x37,0x36,0x35,0x34,0x33,0x32,0x31,0x30,
    0x2F,0x2E,0x2D,0x2C,0x2B,0x2A,0x29,0x28,0x27,0x26,0x25,0x24,0x23,0x22,0x21,0x20,
    0x1F,0x1E,0x1D,0x1C,0x1B,0x1A,0x19,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,
    0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00
};

extern volatile uint8_t g_SW_state;
void R_MAIN_UserInit(void);


void main(void);

/*******************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
********************************************************************************/
void main(void)
{

    uint8_t status;
    uint8_t sladr;                      /* address of selected slave    */
    uint8_t * txbuf;                    /* data pointer for transmit    */
    uint8_t ram_valid = 0;              /* RAM data is valid flag       */
    uint16_t i;                         /* loop counter for subloop     */
    uint16_t j;                         /* loop counter for subloop     */

    R_MAIN_UserInit();                  /* start TM07 & enable interrupt*/

/*------------------------------------------------------
    wait for SW is pushed
------------------------------------------------------*/

    while ( 0x02 != ( g_SW_state & 0x03 ) )
    {   /* wait for g_SW_state = 0bxxxxxx10 */
        NOP();
    }


/*======================================================
    main function (I2C bus communication)
======================================================*/

    while (1)
    {

/*------------------------------------------------------
    selecte slave address to test 
------------------------------------------------------*/

        for ( j = 0 ; j < 4 ; ++j )     /* for each slave handling      */
        {
            sladr = g_sl_addr_T[j];     /* set slave address(7bit)      */

/*------------------------------------------------------
    read 256 byte (decremental) data from selected slave
------------------------------------------------------*/

            status = R_IICA0_Rx(sladr, 0x00, g_Rx_buff, 256);   /* read */

            while ( SUCCESS != status ) /* check receive error or not   */ 
            {
                LED2_pin = LED_ON;      /* turn on erorr LED            */
                HALT();
            }   /* end of receive error  */

            if ( 0x00 != ram_valid )
            {                           /* check received data          */
/*------------------------------------------------------
    check received data
------------------------------------------------------*/

                for ( i = 0 ; i <256 ; ++i )
                {
                    while ( g_Rx_buff[i] != g_Tx_buff[(i+1)] )
                    {
                        LED2_pin = LED_ON; /* turn on erorr LED         */
                    }
                }   /* end of data check loop   */
            }   /* end of data check    */
/*------------------------------------------------------
    transmit incremental data by 16 byte unit
------------------------------------------------------*/

            for ( i = 0 ; i <16 ; ++i )
            {   /* transmit 16 bytes data to slave  */
                txbuf = (uint8_t *)&INC_DATA[i][0];
                status = R_IICA0_Tx(sladr, i*16, (uint8_t *)txbuf, 16);

                while ( SUCCESS != status )
                {
                    LED2_pin = LED_ON;  /* turn on erorr LED        */
                }
            }   /* end of for loop to transmit  */

/*======================================================

    receive data by 16 byte unit

======================================================*/

/*------------------------------------------------------
    transmit address register data
------------------------------------------------------*/

            status = R_IICA0_Master_Send((sladr << 1 ), g_Tx_buff, 1 );

            if ( SUCCESS == status )    /* success to start transmit    */
            {
                status = R_IICA0_wait_comend(0); /* wait for transmit end*/
            }

            while ( SUCCESS != status ) /* check communication result   */
            {
                LED2_pin = LED_ON;      /* turn on erorr LED            */
            }

/*------------------------------------------------------
    receive (incremental) data by 16 bytes unit
------------------------------------------------------*/

            for ( i = 0 ; i <16 ; ++i )
            {
                status = R_IICA0_Master_Receive((sladr << 1 ), &g_Rx_buff[(i*16)], 16 );

                if ( SUCCESS == status )  /* success to start receive   */
                {
                    status = R_IICA0_wait_comend(0); /* wait for receive end*/
                }

                while ( SUCCESS != status )
                {
                    LED2_pin = LED_ON;  /* turn on erorr LED            */
                }
            }   /* end of receive 16 bytes loop */


            if ( 0x00 != ram_valid )
            {                           /* check received data          */
/*------------------------------------------------------
    check received data
------------------------------------------------------*/

                for ( i = 0 ; i <256 ; ++i )
                {
                    while ( g_Rx_buff[i] != i )
                    {
                        LED2_pin = LED_ON;  /* turn on erorr LED        */
                    }
                }   /* end of data check for-loop   */

            }

/*------------------------------------------------------
    transmit  (decremental) data by 256bytes
------------------------------------------------------*/

            status =  R_IICA0_Master_Send((sladr << 1 ), g_Tx_buff, 257 );
            if ( SUCCESS == status )
            {
                status = R_IICA0_wait_comend(0); /* wait for transmit end*/
            }
            
            while ( SUCCESS != status )
            {
                LED2_pin = LED_ON;      /* erorr LED on                 */
            }

/*------------------------------------------------------
    end of communication for each slave
------------------------------------------------------*/

            R_IICA0_StopCondition();    /* issue stop condition         */

        }   /* end of each slave  handling for loop  */

        ram_valid = 0x01;               /* set data compare flag        */
        LED1_pin ^= 1;                  /* invert operation LED         */
        TMIF03 = 0;                     /* clear 500ms interval flag    */
        while ( 0 == TMIF03 )           /* wait for 500ms               */
        {
            NOP();
        }
    }   /* end of while(1) loop */
}   /* end of main function */



/*******************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
********************************************************************************/
void R_MAIN_UserInit(void)
{

    TMIF03 = 0;                         /* clear INTTM03 flag           */
    TMMK03 = 1;                         /* disable INTTM03              */
    TS0 = 0x0008;                       /* start TM03                   */
    R_Config_TAU0_7_Start();            /* start SW check timer         */
    EI();

}
