/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : IIC10.c
* Component Version: 1.12.0
* Device(s)        : R7F100GSNxFB
* Description      : This file implements device driver for IIC10.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "IIC10.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint8_t   g_iic10_master_status_flag;    /* iic10 start flag for send address check */
volatile uint8_t * gp_iic10_tx_address;           /* iic10 send data pointer by master mode */
volatile uint16_t  g_iic10_tx_count;              /* iic10 send data size by master mode */
volatile uint8_t * gp_iic10_rx_address;           /* iic10 receive data pointer by master mode */
volatile uint16_t  g_iic10_rx_count;              /* iic10 receive data size by master mode */
uint16_t  g_iic10_rx_length;                      /* iic10 receive data length by master mode */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_IIC10_Create
* Description  : This function initializes the IIC10 master module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IIC10_Create(void)
{
    uint8_t temp = SPS0L;

    temp &= _F0_SAU_CK00_CLEAR;
    temp |= _01_SAU_CK00_FCLK_1;
    SPS0L = temp;
    ST0L_bit.no2 = 1U;    /* disable IIC10 */
    IICMK10 = 1U;    /* disable INTIIC10 interrupt */
    IICIF10 = 0U;    /* clear INTIIC10 interrupt flag */
    /* Set INTIIC10 low priority */
    IICPR110 = 1U;
    IICPR010 = 1U;
    SIR02L = _02_SAU_SIRMN_PECTMN | _01_SAU_SIRMN_OVCTMN;    /* clear error flag */
    SMR02 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0000_SAU_CLOCK_MODE_CKS | 
            _0000_SAU_TRIGGER_SOFTWARE | _0000_SAU_EDGE_FALL | _0004_SAU_MODE_IIC | _0000_SAU_TRANSFER_END;
    SCR02 = _0004_SAU_SCRMN_INITIALVALUE | _0000_SAU_TIMING_1 | _0000_SAU_INTSRE_MASK | _0000_SAU_PARITY_NONE | 
            _0000_SAU_MSB | _0010_SAU_STOP_1 | _0003_SAU_LENGTH_8;
    SDR02 = _9E00_IIC10_DIVISOR;
    SO0 |= (_0400_SAU_CH2_CLOCK_OUTPUT_1 | _0004_SAU_CH2_DATA_OUTPUT_1);
    /* Set SCL10, SDA10 pin */
    POM0 |= 0x08U;
    PMCA0 &= 0xF7U;
    PMCT0 &= 0xF7U;
    P0 |= 0x18U;
    PM0 &= 0xE7U;

    R_IIC10_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_IIC10_Stop
* Description  : This function stops the IIC10 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IIC10_Stop(void)
{
    IICMK10 = 1U;    /* disable INTIIC10 interrupt */
    ST0L_bit.no2 = 1U;    /* disable IIC10 */
    IICIF10 = 0U;    /* clear INTIIC10 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_IIC10_StartCondition
* Description  : This function starts the IIC10 condition.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IIC10_StartCondition(void)
{
    volatile uint8_t w_count;

    SO0 &= (uint16_t)~_0004_SAU_CH2_DATA_OUTPUT_1;    /* clear IIC10 SDA */

    /* Set delay to secure a hold time after SDA output low. The delay time depend on slave device.
       Here set 5us as default base on current clock */
    for (w_count = 0U; w_count <= IIC10_WAITTIME; w_count++)
    {
        NOP();
    }

    SO0 &= (uint16_t)~_0400_SAU_CH2_CLOCK_OUTPUT_1;    /* clear IIC10 SCL */
    SOE0L_bit.no2 = 1U;    /* enable IIC10 output */
    SS0L_bit.no2 = 1U;    /* enable IIC10 */

    /* Set delay to secure a hold time after SCL output low. The delay time depend on slave device.
       Here set 5us as default base on current clock */
    for (w_count = 0U; w_count <= IIC10_WAITTIME; w_count++)
    {
        NOP();
    }
}

/***********************************************************************************************************************
* Function Name: R_IIC10_StopCondition
* Description  : This function stops the IIC10 condition.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IIC10_StopCondition(void)
{
    volatile uint8_t w_count;

    ST0L_bit.no2 = 1U;    /* disable IIC10 */
    SOE0L_bit.no2 = 0U;    /* disable IIC10 output */
    SO0 &= (uint16_t)~_0004_SAU_CH2_DATA_OUTPUT_1;    /* clear IIC10 SDA */

    /* Set delay to secure a hold time after SDA output low. The delay time depend on slave device.
       Here set 5us as default base on current clock */
    for (w_count = 0U; w_count <= IIC10_WAITTIME; w_count++)
    {
        NOP();
    }

    SO0 |= _0400_SAU_CH2_CLOCK_OUTPUT_1;    /* set IIC10 SCL */

    /* Set delay to secure a hold time after SCL output low. The delay time depend on slave device.
       Here set 5us as default base on current clock */
    for (w_count = 0U; w_count <= IIC10_WAITTIME; w_count++)
    {
        NOP();
    }

    SO0 |= _0004_SAU_CH2_DATA_OUTPUT_1;    /* set IIC10 SDA */

    /* Set delay to secure a hold time after SDA output low. The delay time depend on slave device.
       Here set 5us as default base on current clock */
    for (w_count = 0U; w_count <= IIC10_WAITTIME; w_count++)
    {
        NOP();
    }
}

/***********************************************************************************************************************
* Function Name: R_IIC10_Master_Send
* Description  : This function starts transferring data for IIC10 in master mode.
* Arguments    : adr -
*                    set address for select slave
*                tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
* Return Value : None
***********************************************************************************************************************/
void R_IIC10_Master_Send(uint8_t adr, uint8_t * const tx_buf, uint16_t tx_num)
{
    uint16_t temp = SCR02;

    g_iic10_master_status_flag = _00_SAU_IIC_MASTER_FLAG_CLEAR;    /* clear IIC10 master status flag */
    adr &= 0xFEU;    /* send mode */
    g_iic10_master_status_flag = _01_SAU_IIC_SEND_FLAG;    /* set master status flag */
    temp &= (uint16_t)~_C000_SAU_RECEPTION_TRANSMISSION;
    temp |= _8000_SAU_TRANSMISSION;
    SCR02 = temp;
    /* Set paramater */
    g_iic10_tx_count = tx_num;
    gp_iic10_tx_address = tx_buf;
    /* Start condition */
    R_IIC10_StartCondition();
    IICIF10 = 0U;    /* clear INTIIC10 interrupt flag */
    IICMK10 = 0U;    /* enable INTIIC10 */
    SIO10 = adr;
}

/***********************************************************************************************************************
* Function Name: R_IIC10_Master_Receive
* Description  : This function starts receiving data for IIC10 in master mode.
* Arguments    : adr -
*                    set address for select slave
*                rx_buf -
*                    receive buffer pointer
*                rx_num -
*                    buffer size
* Return Value : None
***********************************************************************************************************************/
void R_IIC10_Master_Receive(uint8_t adr, uint8_t * const rx_buf, uint16_t rx_num)
{
    uint16_t temp = SCR02;

    g_iic10_master_status_flag = _00_SAU_IIC_MASTER_FLAG_CLEAR;    /* clear master status flag */
    adr |= 0x01U;    /* receive mode */
    g_iic10_master_status_flag = _02_SAU_IIC_RECEIVE_FLAG;    /* set master status flag */
    temp &= (uint16_t)~_C000_SAU_RECEPTION_TRANSMISSION;
    temp |= _8000_SAU_TRANSMISSION;
    SCR02 = temp;
    /* Set parameter */
    g_iic10_rx_length = rx_num;
    g_iic10_rx_count = 0U;
    gp_iic10_rx_address = rx_buf;
    /* Start condition */
    R_IIC10_StartCondition();
    IICIF10 = 0U;    /* clear INTIIC10 interrupt flag */
    IICMK10 = 0U;    /* enable INTIIC10 */
    SIO10 = adr;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
