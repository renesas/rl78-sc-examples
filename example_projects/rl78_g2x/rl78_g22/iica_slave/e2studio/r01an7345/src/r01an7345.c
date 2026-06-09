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
/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c or Main.cpp                                    */
/*  DATE        :                                                      */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_IICA0.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t     g_iica0_slave_status_flag;    /* iica0 slave flag
    0x00 : ON_COMM  : initial value
    0x01 : DET_STOP : detected stop condition
    0x02 : TX_END   : detected NACK (End of transmission)
    0x04 : TD_REQ   : received a request for transmission
    0x08 : RX_END   : received data for the specified number of times
    0x10 : DR_REQ   : received data exceeding the specified number of times
    0x20 : AR_END   : updated the register address
    0x40 : -
    0x80 : NOT_SEL  : not selected after restart condition or extension code reception
    */
extern volatile uint16_t    g_reg_addr;     /* address register                 */

static uint8_t g_rx_data[DATA_LENGTH];    /* Rx data buffer. */
static uint8_t g_serial_RAM[128];         /* serial memory area                   */
static uint8_t g_com_stat;                /* command and status of RAM
    bit7 : 1:command is valid/0:no operation
    bit6 : 1:oparetion enable/0:operation disable
    bit5 : reserved(0)
    bit4 : reserved(0)
    bit3 : reserved(0)
    bit2 : 1:write protected/0:write enable
    bit1 : 1:initialize/0:do nothing
    bit0 : 1:increment data/0:zero data
    */

void R_Increment_Address(void);         /* serial RAM address increment */
void R_Command(void);                   /* command handling             */
void R_MAIN_UserInit(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();

    while (1U)
    {
        R_Config_IICA0_Slave_Receive(g_rx_data,1); /* Request register address.*/

/*--------------------------------------------------------------*/
/* Enter  STOP mode (IICA0 wakeup mode) until a communication.  */
/*--------------------------------------------------------------*/

        WUP0 =  1U;                 /* Enables wakeup function.     */
        NOP();
        NOP();
        NOP();
        STOP();                     /* wait for communications.     */

/*==============================================================*/
/* Wake up by beginning of communication from master.           */
/*==============================================================*/

        while (1U)
        {
            while (g_iica0_slave_status_flag == 0U)
            {
                HALT();         /* Communication completion waiting. */
            }

/*--------------------------------------------------------------*/
/* one operation end and check communication status             */
/*--------------------------------------------------------------*/

            if ( ( g_iica0_slave_status_flag & 0b10000011 ) != 0x00 )
            {       /* check if ( NOT_SEL | TX_END | DET_STOP ) */
/*--------------------------------------------------------------*/
/* stop condition detect or NACK or not selected                */
/*--------------------------------------------------------------*/

                break;          /* exit from communication          */

            }

/*--------------------------------------------------------------*/
/* one data communication end and check address and com_stat    */
/*--------------------------------------------------------------*/

            if ((( g_reg_addr > 0x00 ) &&       /* not command register */
                ( g_reg_addr < 0x80 )) ||       /* not serial RAM       */
                (( g_reg_addr > 0x80 ) &&       /* serial RAM area is   */
                (( g_com_stat & 0x40 ) == 0x00 ))) /* disable             */
            {

/*--------------------------------------------------------------*/
/* received register address is not permitted then NACK response*/
/*--------------------------------------------------------------*/

                break;          /* exit from communication          */
            }

            if ((( g_reg_addr > 0x80 ) &&
                 (( g_com_stat & 0x04 ) != 0x00 ) &&
                 (( g_iica0_slave_status_flag & 0x28 ) == 0x08 )))
            {
/*--------------------------------------------------------------*/
/*  when write to protected RAM, exit with NACK                 */
/*--------------------------------------------------------------*/

                break;
            }

/*==============================================================*/
/*  normal communication and check operation mode               */
/*==============================================================*/

            switch ( g_iica0_slave_status_flag )
            {
                case TD_REQ:        /* request transmit data        */

/*--------------------------------------------------------------*/
/* master request data, then prepare next data from serial RAM  */
/*--------------------------------------------------------------*/
                    if ( g_reg_addr >= 0x80 )
                    {   /* transmit serial RAM data */
                        IICA0 = g_serial_RAM[( g_reg_addr & 0x7F )];
                        R_Increment_Address();  /* move RAM pointer */
                    }
                    else
                    {   /* send command register data   */
                        IICA0 = g_com_stat;
                    }

                    break;

                case AR_END:        /* get address register         */
                case (AR_END | RX_END): /* address register complete*/
                case RX_END:        /* data receive complete        */

/*--------------------------------------------------------------*/
/* specified number of receive data is completed                */
/*--------------------------------------------------------------*/

                    WREL0 = 1U;     /* release I2C bus wait         */
                    break;

                case DR_REQ:        /* request to read received data*/
                default:

/*==============================================================*/
/* master send a data when slave does not request to receive    */
/*==============================================================*/

                    if ( g_reg_addr == 0x00 )   /* check command or data*/
                    {

/*--------------------------------------------------------------*/
/* receive new command from master                              */
/*--------------------------------------------------------------*/

                        R_Command();            /* command processing   */
                    }
                    else
                    {

/*--------------------------------------------------------------*/
/* receive new data to store serial RAM area                    */
/*--------------------------------------------------------------*/
                        g_serial_RAM[( g_reg_addr & 0x7F )] = IICA0;
                        R_Increment_Address(); /* move RAM pointer  */
                    }

                    WREL0 = 1U;             /* release I2C bus wait */
                    break;

            }

            g_iica0_slave_status_flag = 0U;         /* clear flag*/

        }

        LREL0 = 1U;                     /* Exit from communications.*/

    }
}

/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    EI();
}

/******************************************************************************
* Function Name: R_Increment_Address
* Description : Increment serial RAM address.
* Arguments : none
* Return Value : none
******************************************************************************/
void R_Increment_Address(void)
{
    if ( g_reg_addr >= 0x80 )           /* check serial RAM area or not     */
    {   /* serial RAM address is indexed    */
        g_reg_addr++;                   /* move pointer to next data address*/
        g_reg_addr |= 0x80;             /* convert to 0x80-0xFF area        */
        g_reg_addr &= 0xFF;             /* mask none used bit               */
    }
}

/******************************************************************************
End of function R_Increment_Address
******************************************************************************/

/******************************************************************************
* Function Name: R_Command
* Description : command processing.
* Arguments : none
* Return Value : none
******************************************************************************/
void R_Command(void)
{
    uint8_t work;
    uint8_t addr_pt;
    uint8_t data = 0;

    work = IICA0;                       /* read received command            */

    if (( work & 0x80 ))                /* check if command is valid        */
    {
        if (( work & 0x40 ))            /* check operation enable           */
        {
            g_com_stat = ( work & 0xC4 ); /* set command status               */

            if (( work & 0x02 ))        /* check initialize bit             */
            {
                work &= 0x01;
                for ( addr_pt = 0 ; addr_pt < 0x80 ; addr_pt++ )
                {
                    g_serial_RAM[addr_pt] = data;     /* initialize memory    */
                    data += work;       /* make next initialize data        */
                }
            }
        }
        else
        {
            g_com_stat = 0x00;
        }

    }
}
/******************************************************************************
End of function R_Command
******************************************************************************/
