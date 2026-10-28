/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : SAU_SPI.c
* Component Version: 1.9.0
* Device(s)        : R7F103GLJxFB
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
uint16_t g_csi10_send_length;              /* csi10 send data length */
volatile uint8_t * gp_csi10_tx_address;    /* csi10 send buffer address */
volatile uint16_t g_csi10_tx_count;        /* csi10 send data count */
volatile uint8_t * gp_csi10_rx_address;    /* csi10 receive buffer address */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_SAU_SPI_Create
* Description  : This function initializes the CSI10 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU_SPI_Create(void)
{
    uint8_t temp = SPS0L;

    temp &= _F0_SAU_CK00_CLEAR;
    temp |= _02_SAU_CK00_FCLK_2;
    SPS0L = temp;
    ST0L_bit.no2 = 1U;    /* stop CSI10 */
    /* Mask channel 2 interrupt */
    CSIMK10 = 1U;    /* disable INTCSI10 interrupt */
    CSIIF10 = 0U;    /* clear INTCSI10 interrupt flag */
    /* Set INTCSI10 low priority */
    CSIPR110 = 1U;
    CSIPR010 = 1U;
    SIR02L = _02_SAU_SIRMN_PECTMN | _01_SAU_SIRMN_OVCTMN;    /* clear error flag */
    SMR02 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0000_SAU_CLOCK_MODE_CKS | 
            _0000_SAU_TRIGGER_SOFTWARE | _0000_SAU_MODE_CSI | _0001_SAU_BUFFER_EMPTY;
    SCR02 = _0004_SAU_SCRMN_INITIALVALUE | _C000_SAU_RECEPTION_TRANSMISSION | _0000_SAU_TIMING_1 | _0000_SAU_MSB | 
            _0003_SAU_LENGTH_8;
    SDR02 = _0E00_SAU0_CH2_BAUDRATE_DIVISOR;
    SO0 |= _0400_SAU_CH2_CLOCK_OUTPUT_1;    /* CSI10 clock initial level */
    SO0 &= (uint16_t)~_0004_SAU_CH2_DATA_OUTPUT_1;    /* CSI10 SO initial level */
    SOE0L_bit.no2 = 1U;    /* enable CSI10 output */
    /* Set SI10 pin */
    PMCA0 &= 0xF7U;
    PM0 |= 0x08U;
    /* Set SO10 pin */
    PMCA0 &= 0xFBU;
    P0 |= 0x04U;
    PM0 &= 0xFBU;
    /* Set SCK10 pin */
    P0 |= 0x10U;
    PM0 &= 0xEFU;

    R_SAU_SPI_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_SAU_SPI_Start
* Description  : This function starts the CSI10 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU_SPI_Start(void)
{
    SO0 |= _0400_SAU_CH2_CLOCK_OUTPUT_1;    /* CSI10 clock initial level */
    SO0 &= (uint16_t)~_0004_SAU_CH2_DATA_OUTPUT_1;    /* CSI10 SO initial level */
    SOE0L_bit.no2 = 1U;    /* enable CSI10 output */
    SS0L_bit.no2 = 1U;    /* enable CSI10 */
    CSIIF10 = 0U;    /* clear INTCSI10 interrupt flag */
    CSIMK10 = 0U;    /* enable INTCSI10 interrupt */
}

/***********************************************************************************************************************
* Function Name: R_SAU_SPI_Stop
* Description  : This function stops the CSI10 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU_SPI_Stop(void)
{
    CSIMK10 = 1U;    /* disable INTCSI10 interrupt */
    ST0L_bit.no2 = 1U;    /* stop CSI10 */
    SOE0L_bit.no2 = 0U;    /* disable CSI10 output */
    CSIIF10 = 0U;    /* clear INTCSI10 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_SAU_SPI_Send_Receive
* Description  : This function sends and receives CSI10 data.
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
        g_csi10_send_length = tx_num;     /* send data length */
        g_csi10_tx_count = tx_num;    /* send data count */
        gp_csi10_tx_address = tx_buf;    /* send buffer pointer */
        gp_csi10_rx_address = rx_buf;    /* receive buffer pointer */

        if (1U == tx_num)
        {
            SMR02 &= (uint16_t)~_0001_SAU_BUFFER_EMPTY;
        }
        else
        {
            SMR02 |= _0001_SAU_BUFFER_EMPTY;
        }
        CSIMK10 = 1U;    /* disable INTCSI10 interrupt */

        if (0U != gp_csi10_tx_address)
        {
            SIO10 = *gp_csi10_tx_address;    /* started by writing data to SDR02[7:0] */
            gp_csi10_tx_address++;
        }
        else
        {
            SIO10 = 0xFFU;
        }

        g_csi10_tx_count--;
        CSIMK10 = 0U;    /* enable INTCSI10 interrupt */
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
