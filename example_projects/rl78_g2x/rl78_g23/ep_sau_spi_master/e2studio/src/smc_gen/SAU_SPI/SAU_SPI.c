/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : SAU_SPI.c
* Component Version: 1.9.0
* Device(s)        : R7F100GSNxFB
* Description      : This file implements device driver for SAU_SPI.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "SAU_SPI.h"
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
uint16_t g_csi30_send_length;              /* csi30 send data length */
volatile uint8_t * gp_csi30_tx_address;    /* csi30 send buffer address */
volatile uint16_t g_csi30_tx_count;        /* csi30 send data count */
volatile uint8_t * gp_csi30_rx_address;    /* csi30 receive buffer address */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_SAU_SPI_Create
* Description  : This function initializes the CSI30 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU_SPI_Create(void)
{
    uint8_t temp = SPS1L;

    temp &= _F0_SAU_CK00_CLEAR;
    temp |= _02_SAU_CK00_FCLK_2;
    SPS1L = temp;
    ST1L_bit.no2 = 1U;    /* stop CSI30 */
    /* Mask channel 2 interrupt */
    CSIMK30 = 1U;    /* disable INTCSI30 interrupt */
    CSIIF30 = 0U;    /* clear INTCSI30 interrupt flag */
    /* Set INTCSI30 low priority */
    CSIPR130 = 1U;
    CSIPR030 = 1U;
    SIR12L = _02_SAU_SIRMN_PECTMN | _01_SAU_SIRMN_OVCTMN;    /* clear error flag */
    SMR12 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0000_SAU_CLOCK_MODE_CKS | 
            _0000_SAU_TRIGGER_SOFTWARE | _0000_SAU_MODE_CSI | _0001_SAU_BUFFER_EMPTY;
    SCR12 = _0004_SAU_SCRMN_INITIALVALUE | _C000_SAU_RECEPTION_TRANSMISSION | _0000_SAU_TIMING_1 | _0000_SAU_MSB | 
            _0003_SAU_LENGTH_8;
    SDR12 = _0E00_SAU1_CH2_BAUDRATE_DIVISOR;
    SO1 |= _0400_SAU_CH2_CLOCK_OUTPUT_1;    /* CSI30 clock initial level */
    SO1 &= (uint16_t)~_0004_SAU_CH2_DATA_OUTPUT_1;    /* CSI30 SO initial level */
    SOE1L_bit.no2 = 1U;    /* enable CSI30 output */
    /* Set SI30 pin */
    PM14 |= 0x08U;
    /* Set SO30 pin */
    P14 |= 0x10U;
    PM14 &= 0xEFU;
    /* Set SCK30 pin */
    P14 |= 0x04U;
    PM14 &= 0xFBU;
    
    R_SAU_SPI_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_SAU_SPI_Start
* Description  : This function starts the CSI30 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU_SPI_Start(void)
{
    SO1 |= _0400_SAU_CH2_CLOCK_OUTPUT_1;    /* CSI30 clock initial level */
    SO1 &= (uint16_t)~_0004_SAU_CH2_DATA_OUTPUT_1;    /* CSI30 SO initial level */
    SOE1L_bit.no2 = 1U;    /* enable CSI30 output */
    SS1L_bit.no2 = 1U;    /* enable CSI30 */
    CSIIF30 = 0U;    /* clear INTCSI30 interrupt flag */
    CSIMK30 = 0U;    /* enable INTCSI30 interrupt */
}

/***********************************************************************************************************************
* Function Name: R_SAU_SPI_Stop
* Description  : This function stops the CSI30 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU_SPI_Stop(void)
{
    CSIMK30 = 1U;    /* disable INTCSI30 interrupt */
    ST1L_bit.no2 = 1U;    /* stop CSI30 */
    SOE1L_bit.no2 = 0U;    /* disable CSI30 output */
    CSIIF30 = 0U;    /* clear INTCSI30 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_SAU_SPI_Send_Receive
* Description  : This function sends and receives CSI30 data.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
*                rx_buf -
*                    receive buffer pointer
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_SAU_SPI_Send_Receive(uint8_t * const tx_buf, uint16_t tx_num, uint8_t * const rx_buf)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        g_csi30_send_length = tx_num;     /* send data length */
        g_csi30_tx_count = tx_num;    /* send data count */
        gp_csi30_tx_address = tx_buf;    /* send buffer pointer */
        gp_csi30_rx_address = rx_buf;    /* receive buffer pointer */

        if (1U == tx_num)
        {
            SMR12 &= (uint16_t)~_0001_SAU_BUFFER_EMPTY;
        }
        else
        {
            SMR12 |= _0001_SAU_BUFFER_EMPTY;
        }
        CSIMK30 = 1U;    /* disable INTCSI30 interrupt */

        if (0U != gp_csi30_tx_address)
        {
            SIO30 = *gp_csi30_tx_address;    /* started by writing data to SDR12[7:0] */
            gp_csi30_tx_address++;
        }
        else
        {
            SIO30 = 0xFFU;
        }

        g_csi30_tx_count--;
        CSIMK30 = 0U;    /* enable INTCSI30 interrupt */
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
