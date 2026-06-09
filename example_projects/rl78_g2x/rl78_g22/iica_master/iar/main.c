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
/*  DATE        :2024/xx/xx                                            */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :R7F102GGE2DFB                                         */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/

/*******************************************************************************
Includes
********************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_IICA0.h"
#include "Config_TAU0_0.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint8_t    g_read_ram[8][16];          /* receive RAM data buffer      */

static uint8_t const __far  RAM_COMMAND[4] =
{
    0b11000000,                                 /* operation enable             */
    0b11000011,                                 /* initialize RAM               */
    0b11000100,                                 /* warite protected             */
    0b10000000                                  /* operation disable            */
};
/* command format of serial RAM
    bit7 : 1:command is valid/0:no operation
    bit6 : 1:oparetion enable/0:operation disable
    bit5 : reserved(0)
    bit4 : reserved(0)
    bit3 : reserved(0)
    bit2 : 1:write protected/0:write enable
    bit1 : 1:initialize/0:do nothing
    bit0 : 1:increment data/0:zero data
*/
    
static uint8_t const __far  RAM_DATA[4][64] =
{                                       /* serial RAM test data         */
    /* increment data patern1 :0x00-0x3F */
    {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
     0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
     0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
     0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
     0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,
     0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
     0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,
     0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F},

    /* increment data patern2 :0x40-0x7F */
    {0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,
     0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
     0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,
     0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,
     0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,
     0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,
     0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,
     0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F},

    /* decrement data patern1 :0xFF-0xC0 */
    {0xFF,0xFE,0xFD,0xFC,0xFB,0xFA,0xF9,0xF8,
     0xF7,0xF6,0xF5,0xF4,0xF3,0xF2,0xF1,0xF0,
     0xEF,0xEE,0xED,0xEC,0xEB,0xEA,0xE9,0xE8,
     0xE7,0xE6,0xE5,0xE4,0xE3,0xE2,0xE1,0xE0,
     0xDF,0xDE,0xDD,0xDC,0xDB,0xDA,0xD9,0xD8,
     0xD7,0xD6,0xD5,0xD4,0xD3,0xD2,0xD1,0xD0,
     0xCF,0xCE,0xCD,0xCC,0xCB,0xCA,0xC9,0xC8,
     0xC7,0xC6,0xC5,0xC4,0xC3,0xC2,0xC1,0xC0},

    /* decrement data patern2 :0xBF-0x80 */
    {0xBF,0xBE,0xBD,0xBC,0xBB,0xBA,0xB9,0xB8,
     0xB7,0xB6,0xB5,0xB4,0xB3,0xB2,0xB1,0xB0,
     0xAF,0xAE,0xAD,0xAC,0xAB,0xAA,0xA9,0xA8,
     0xA7,0xA6,0xA5,0xA4,0xA3,0xA2,0xA1,0xA0,
     0x9F,0x9E,0x9D,0x9C,0x9B,0x9A,0x99,0x98,
     0x97,0x96,0x95,0x94,0x93,0x92,0x91,0x90,
     0x8F,0x8E,0x8D,0x8C,0x8B,0x8A,0x89,0x88,
     0x87,0x86,0x85,0x84,0x83,0x82,0x81,0x80}

};

void r_wait_SW(void);                           /* wait for SW is pushed        */
void R_MAIN_UserInit(void);


void main(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{

    uint8_t status;
    uint8_t main_loopc;                         /* loop counter for main loop   */
    uint8_t i;                                  /* loop counter for subloop     */
    uint8_t j;                                  /* loop counter for subloop     */
    uint8_t k;                                  /* loop counter for subloop     */
    uint8_t __far const *pt_txdata;             /* write data to slave pointer  */
    uint8_t *pt_ram;                            /* read RAM data pointer        */
    uint8_t reg_addr;                           /* register address in slave    */
    uint8_t temp_pt;                            /* work pointer for read data   */
    uint8_t temp_data;                          /* work area for read data      */
    
    R_MAIN_UserInit();                          /* start IT & enable interrupt  */

    main_loopc = 0x00;                          /* write data buffer number     */
    
    r_wait_SW();                                /* wait for SW is pushed        */
    
    reg_addr = 0x00;                            /* set command register address */

/*--------------------------------------------------------------*/
/*      enable serial RAM operation                             */
/*--------------------------------------------------------------*/

    status = r_IICA0_put_data( SLAVE_ADDR,      /* select serial RAM            */
                             reg_addr,          /* index command register       */
                             (uint8_t __far *)&RAM_COMMAND[0],  /* command      */
                             1 );               /* data number(command only)    */

    while ( status )
    {
        P6_bit.no3 = LED_ON;                    /* turn on LED when NACK        */
        HALT();                                 /* program halt                 */
    }

/*--------------------------------------------------------------*/
/*      initialize serial RAM data                              */
/*--------------------------------------------------------------*/

    status = r_IICA0_put_data( SLAVE_ADDR,      /* select serial RAM            */
                             reg_addr,          /* index command register       */
                             (uint8_t __far *)&RAM_COMMAND[1],  /* command      */
                             1 );               /* data number(command only)    */

    while ( status )
    {
        P6_bit.no3 = LED_ON;                    /* turn on LED when NACK        */
        HALT();                                 /* program halt                 */
    }


/*==============================================================*/
/*      RAM check main operation loop                           */
/*==============================================================*/

    while (1U)
    {

/*--------------------------------------------------------------*/
/*      Data read from serial RAM by 16 bytes unit              */
/*--------------------------------------------------------------*/
        for ( j = 0x00 ; j < 0x08 ; j++ )
        {
            pt_ram = (uint8_t *)&g_read_ram[j][0];  /* set pointer for read data  */
            reg_addr = RAM_TOP + j*0x10;        /* set address register data      */
            status = r_IICA0_get_data( SLAVE_ADDR,/* select serial RAM            */
                                    reg_addr,   /* index serial RAM srea          */
                                    pt_ram,     /* read data buffer address       */
                                    0x10 );     /* read data number               */

            if ( status )
            {                                   /* read error ( not slave)        */
                P6_bit.no3 = LED_ON;            /* turn on LED when NACK          */
            }
            else
            {
                /* do nothing */
            }
        }

/*--------------------------------------------------------------*/
/*      check read data from serial RAM                         */
/*--------------------------------------------------------------*/

        for ( i = 0 ; i < 8 ; i++ )             /* check read 1st 64 bytes data */
        {
            for ( j = 0 ; j < 16 ; j++ )
            {
                k = ( i >> 2 );                 /* for offset of 64 bytes unit  */
                temp_pt = (( i & 0b00000011 ) * 16 ) + j; /* get offset for 64  */
                temp_data = RAM_DATA[(main_loopc+k)][temp_pt]; /* get data      */

                while ( temp_data != g_read_ram[i][j] )
                {
                    P6_bit.no3 ^= 1;            /* blink LED when NACK          */
                    wait_ms(250);               /* wait 250ms                   */
                }

            }

        }

/*--------------------------------------------------------------*/
/*      write data to serial RAM by 64 bytes unit               */
/*--------------------------------------------------------------*/

        main_loopc ^= 2;                              /* change 0  <--> 2             */

        for ( k = 0x00 ; k < 0x02 ; k++ )
        {
            pt_txdata = &RAM_DATA[main_loopc+k][0];   /* set write data pointer       */
            reg_addr = (RAM_TOP + k*0x40);            /* set access RAM address       */
            status = r_IICA0_put_data( SLAVE_ADDR,    /* select serial RAM            */
                                    reg_addr,         /* index serial RAM srea        */
                                    (uint8_t __far *)pt_txdata,   /* write dara TOP   */
                                     MAX_DATA );      /* write data number(64 bytes)  */

            if ( status )
            {
                P6_bit.no3 = LED_ON;                  /* turn on LED when NACK        */
            }
            else
            {
                /* do nothing */
            }
            
        }

        P6_bit.no2 ^= 1;                              /* turn on/off LED1 of TB       */
        wait_ms(10);
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
/* start IT                       */
    TMMK00 = INT_ENABLE;                /* enable TAU00 interrupt	    */
    EI();
    wait_ms(250);                       /* wait for 250ms	    */
}

/*******************************************************************************
* Function Name: r_wait_SW
* Description  : This function wait for SW is pushed
* Arguments    : None
* Return Value : None
********************************************************************************/
void r_wait_SW(void)
{
    while ( FALSE == P13_bit.no7 )
    {
        NOP();
    }
    wait_ms(50);
    while ( TRUTH == P13_bit.no7 )
    {
        NOP();
    }
    wait_ms(50);
}
