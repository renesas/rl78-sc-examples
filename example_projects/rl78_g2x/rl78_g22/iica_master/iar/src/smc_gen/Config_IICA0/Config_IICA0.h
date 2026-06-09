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
* File Name        : Config_IICA0.h
* Component Version: 1.5.1
* Device(s)        : R7F102GGExFB
* Description      : This file implements device driver for Config_IICA0.
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

#define _32_IICA0_MASTERADDRESS                (0x32U)    /* IICA0 address */
#define _15_IICA0_IICWL_VALUE                  (0x15U)
#define _14_IICA0_IICWH_VALUE                  (0x14U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_IICA0_Create (void);
void R_Config_IICA0_Stop (void);
void R_Config_IICA0_StopCondition (void);
MD_STATUS R_Config_IICA0_Master_Send (uint8_t adr, uint8_t * const tx_buf, uint16_t tx_num, uint8_t wait);
MD_STATUS R_Config_IICA0_Master_Receive (uint8_t adr, uint8_t * const rx_buf, uint16_t rx_num, uint8_t wait);
void R_Config_IICA0_Create_UserInit (void);
/* Start user code for function. Do not edit comment generated here */
/*******************************************************************************
Global definition
********************************************************************************/

#define     STS_MASK        ( 0x03 )    /* mask data for get status     */
#define     IIC_USING       ( 0x01 )    /* IIC bus is using             */
#define     IIC_SUCCESS     ( 0x00 )    /* communication is success     */
#define     NO_ACK          ( 0x84 )    /* no ACK from slave for data   */
#define     NO_SLAVE        ( 0x88 )    /* no ACK for slave address     */
#define     BUS_BUSY        ( 0x8C )    /* I2C bus Busy                 */

#define     WAITTIME        ( 1000 )    /* limit of start condition     */
#define     ON_COMMU        ( 0x01 )    /* on communication (transmit)  */
#define     DUMMY_DATA      ( 0xFF )    /* dummy data for receive       */


/*******************************************************************************
Global function
********************************************************************************/
uint8_t R_IICA0_Master_Send(uint8_t adr, uint8_t * const tx_buf, uint16_t tx_num);
                                        /* transmit data to slave       */
uint8_t R_IICA0_Master_Receive(uint8_t adr, uint8_t * const rx_buf, uint16_t rx_num);
                                        /* recieve data from slave      */
uint8_t R_IICA0_check_comstate(void);     /* check transfer status        */
uint8_t R_IICA0_wait_comend(void);        /* wait for transfer end        */
/*  00 : operation end witout error
    01 : transmit data operation mode
    82 : I2C bus is busy
    84 : no ACK from slave for data
    85 : no ACK for slave address
*/
uint8_t R_IICA0_StopCondition(void);      /* issue STOP condition         */

uint8_t r_IICA0_put_data( uint8_t s_addr, uint8_t r_addr, uint8_t __far * const buffer, uint8_t tx_num );
uint8_t r_IICA0_get_data( uint8_t s_addr, uint8_t r_addr, uint8_t * const buffer, uint8_t rx_num );
/* End user code. Do not edit comment generated here */
#endif


