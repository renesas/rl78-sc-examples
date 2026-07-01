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
* File Name    : Config_IICA0.h
* Version      : 1.0.0
* Device(s)    : R7F100GLGxFB
* Description  : This file implements device driver for Config_IICA0.
* Creation Date: 2021-05-11
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_iica.h"

#ifndef CFG_Config_IICA0_H
#define CFG_Config_IICA0_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

#define _10_IICA0_MASTERADDRESS                (0x10U)    /* IICA0 address */
#define _15_IICA0_IICWL_VALUE                  (0x15U)
#define _14_IICA0_IICWH_VALUE                  (0x14U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_IICA0_Create(void);
void R_Config_IICA0_Stop(void);
void R_Config_IICA0_StopCondition(void);
MD_STATUS R_Config_IICA0_Master_Send(uint8_t adr, uint8_t * const tx_buf, uint16_t tx_num, uint8_t wait);
MD_STATUS R_Config_IICA0_Master_Receive(uint8_t adr, uint8_t * const rx_buf, uint16_t rx_num, uint8_t wait);
void R_Config_IICA0_Create_UserInit(void);
/* Start user code for function. Do not edit comment generated here */

/*******************************************************************************
Global definition
********************************************************************************/

#define     WAITTIME    ( 1000 )        /* limit of start condition     */
#define     DUMMY_DATA  ( 0xFF )        /* dummy data for receive       */

#define     BUS_BUSY    ( 0x0F )        /* I2C bus is busy              */
#define     BUS_FREE    ( 0x00 )        /* I2C bus is free              */
#define     BUS_HOLD    ( 0x20 )        /* hold I2C bus (same as above) */

#define     TX_SADDR    ( 0x18 )        /* TX slave address             */
#define     TX_ADDR_REG ( 0x16 )        /* TX address register          */
#define     RX_MODE     ( 0x14 )        /* receive operation mode       */
#define     TX_MODE     ( 0x12 )        /* transmit operation mode      */
#define     OP_END      ( 0x20 )        /* operation complete           */
#define     RX_END      ( 0x24 )        /* receive operation end        */
#define     TX_END      ( 0x22 )        /* transmit operation end       */

#define     ON_COMMU    ( 0x01 )        /* on communication             */
#define     BUS_ERROR   ( 0x8F )        /* bus or IICA0 is busy error   */
#define     NO_SLAVE    ( 0x80 )        /* NACK for slave address       */
#define     NO_ACK      ( 0xC0 )        /* NACK for transmit data       */
#define     SUCCESS     ( 0x00 )        /* operation complete           */
#define     COM_ERROR   ( 0xFF )        /* other error of communication */


/*******************************************************************************
Global function
********************************************************************************/

/* start procedure of master transmit mode  */
uint8_t R_IICA0_Master_Send(uint8_t sladr8, uint8_t * const tx_buf, uint16_t tx_num);
/*
    sladr8  : 8bit slave address(LSB is 0)
    tx_num  : 0 is permitted

    0x00(SUCCESS)  : get IIC bus and transmit slave address
    0x8F(BUS_ERROR): I2C bus or IICA0 is busy
*/


/* start procedure of master receive mode   */
uint8_t R_IICA0_Master_Receive(uint8_t sladr8, uint8_t * const rx_buf, uint16_t rx_num);
/*
    sladr8  : 8bit slave address(LSB is 0)
    rx_num  : must be more than 1(0 is prohibited)

    0x00(SUCCESS)  : get IIC bus and transmit slave address
    0x8F(BUS_ERROR): I2C bus or IICA0 is busy
    0xFF(COM_ERROR): command parameter error(receive null data)
*/


/* wait for communication end   */
uint8_t R_IICA0_wait_comend(uint8_t stop);
/*
    stop    : 0:

    0x00(SUCCESS)   : success(operation complete)

    0x8F(BUS_ERROR) : bus or IICA0 is busy error
    0x80(NO_SLAVE)  : NACK for slave address
    0xC0(NO_ACK)    : NACK for transmit data
*/


/* check communication end or not   */
uint8_t R_IICA0_poll(void);
/*
    0x00(SUCCESS)   : success(operation complete)
    0x01(ON_COMMU)  : on communication( not complete )

    0x8F(BUS_ERROR) : bus or IICA0 is busy error
    0x80(NO_SLAVE)  : NACK for slave address
    0xC0(NO_ACK)    : NACK for transmit data
*/


/* check transfer status        */
uint8_t R_IICA0_check_(void);
/*
    0x00(BUS_FREE)  : I2C bus is free
    0x18(TX_SADDR)  : transmit slave address
    0x16(TX_ADDR_REG): transmit address register
    0x14(RX_MODE)   : receive operation mode
    0x12(TX_MODE)   : transmit operation mode
    0x20(OP_END)    : operation end and hold I2C bus
    0x22(TX_END)    : transmit end and hold I2C bus
    0x24(RX_END)    : receive and and hold I2C bus
    0x8F(BUS_ERROR) : bus or IICA0 is busy error
    0x80(NO_SLAVE)  : NACK for slave address
    0xC0(NO_ACK)    : NACK for transmit data
*/

/* data transfer to specified slave and specified address   */
uint8_t R_IICA0_Tx(uint8_t sladr7, uint8_t adr, uint8_t * const tx_buf, uint16_t tx_num);
/*
    sladr7  : 7bit slave address(MSB is 0)
    adr     : address register data

    0x00(SUCCESS)  : get IIC bus and transmit slave address
    0x8F(BUS_ERROR): I2C bus or IICA0 is busy
*/


/* data receive from specified slave and specified address   */
uint8_t R_IICA0_Rx(uint8_t sladr7, uint8_t adr, uint8_t * const rx_buf, uint16_t rx_num);
/*
    sladr7  : 7bit slave address(MSB is 0)
    adr     : address register data
    rx_num  : must be more than 1(0 is prohibited)

    0x00(SUCCESS)  : get IIC bus and transmit slave address
    0x8F(BUS_ERROR): I2C bus or IICA0 is busy
    0xFF(COM_ERROR): command parameter error(receive null data)
*/


/* issue stopcondition  */
uint8_t R_IICA0_StopCondition(void);
/*
    0x00(SUCCESS)   : success
    0x8F(BUS_ERROR) : error
*/


/* End user code. Do not edit comment generated here */
#endif

