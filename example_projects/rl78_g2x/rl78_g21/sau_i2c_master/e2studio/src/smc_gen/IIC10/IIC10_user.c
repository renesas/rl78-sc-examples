/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : IIC10_user.c
* Component Version: 1.12.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for IIC10.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "IIC10.h"
/* Start user code for include. Do not edit comment generated here */
#include "i2c_sensor.h"
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_IIC10_interrupt(vect=INTIIC10)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t g_iic10_master_status_flag;      /* iic10 start flag for send address check */
extern volatile uint8_t * gp_iic10_tx_address;           /* iic10 send data pointer by master mode */
extern volatile uint16_t g_iic10_tx_count;               /* iic10 send data size by master mode */
extern volatile uint8_t * gp_iic10_rx_address;           /* iic10 receive data pointer by master mode */
extern volatile uint16_t g_iic10_rx_count;               /* iic10 receive data size by master mode */
extern uint16_t g_iic10_rx_length;                       /* iic10 receive data length by master mode */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_IIC10_Create_UserInit
* Description  : This function adds user code after initializing IIC10.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IIC10_Create_UserInit(void)
{
/* Start user code for user init. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_IIC10_callback_master_sendend
* Description  : This function is a callback function when IIC10 finishes master transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_IIC10_callback_master_sendend(void)
{
/* Start user code for r_IIC10_callback_master_sendend. Do not edit comment generated here */
    i2c_master_callback(IIC10_MASTER_EVENT_SENDEND);
/* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_IIC10_callback_master_receiveend
* Description  : This function is a callback function when IIC10 finishes master reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_IIC10_callback_master_receiveend(void)
{
/* Start user code for r_IIC10_callback_master_receiveend. Do not edit comment generated here */
    i2c_master_callback(IIC10_MASTER_EVENT_RECEIVEEND);
/* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_IIC10_callback_master_error
* Description  : This function is a callback function when IIC10 master error occurs.
* Arguments    : flag -
*                    status flag
* Return Value : None
***********************************************************************************************************************/
static void r_IIC10_callback_master_error(MD_STATUS flag)
{
    /* Start user code for r_IIC10_callback_master_error. Do not edit comment generated here */
    i2c_master_callback(IIC10_MASTER_EVENT_ABORTED);
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_IIC10_interrupt
* Description  : This function is INTIIC10 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_IIC10_interrupt(void)
{
    volatile uint16_t w_count;
    uint16_t temp = SCR02;

    /* Set delay to secure a hold time after SDA, SDL output. The delay time depend on slave device.
       Here set 20us as default base on current clock */
    for (w_count = 0U; w_count <= IIC10_WAITTIME_2; w_count++ )
    {
        NOP();
    }

    if ((0x0002U == (SSR02 & _0002_SAU_PARITY_ERROR)) && (0U != g_iic10_tx_count))
    {
        SIR02L |= _02_SAU_SIRMN_PECTMN;    /* clear ACK error detection flag */
        R_IIC10_StopCondition();
        r_IIC10_callback_master_error(MD_NACK);
    }
    else if ((0x0001U == (SSR02 & _0001_SAU_OVERRUN_ERROR)) && (0U != g_iic10_tx_count))
    {
        SIR02L |= _01_SAU_SIRMN_OVCTMN;    /* clear overrun error detection flag */
        R_IIC10_StopCondition();
        r_IIC10_callback_master_error(MD_OVERRUN);
    }
    else
    {
        /* Control for master send */
        if (1U == (g_iic10_master_status_flag & _01_SAU_IIC_SEND_FLAG))
        {
            if (g_iic10_tx_count > 0U)
            {
                SIO10 = *gp_iic10_tx_address;
                gp_iic10_tx_address++;
                g_iic10_tx_count--;
            }
            else
            {
                /* IIC master transmission finishes and a callback function can be called here. */
                r_IIC10_callback_master_sendend();
            }
        }
        /* Control for master receive */
        else
        {
            if (0U == (g_iic10_master_status_flag & _04_SAU_IIC_SENDED_ADDRESS_FLAG))
            {
                ST0L_bit.no2 = 1U;    /* disable IIC10 */
                temp &= (uint16_t)~_C000_SAU_RECEPTION_TRANSMISSION;
                temp |= _4000_SAU_RECEPTION;
                SCR02 = temp;
                SS0L_bit.no2 = 1U;    /* enable IIC10 */
                g_iic10_master_status_flag |= _04_SAU_IIC_SENDED_ADDRESS_FLAG;

                if (1U == g_iic10_rx_length)
                {
                    SOE0L_bit.no2 = 0U;    /* disable IIC10 out */
                }

                SIO10 = 0xFFU;
            }
            else
            {
                if (g_iic10_rx_count < g_iic10_rx_length)
                {
                    *gp_iic10_rx_address = SIO10;
                    gp_iic10_rx_address++;
                    g_iic10_rx_count++;

                    if ((g_iic10_rx_length - 1U) == g_iic10_rx_count)
                    {
                        SOE0L_bit.no2 = 0U;    /* disable IIC10 out */
                        SIO10 = 0xFFU;
                    }
                    else if (g_iic10_rx_count == g_iic10_rx_length)
                    {
                        /* IIC master reception finishes and a callback function can be called here. */
                        r_IIC10_callback_master_receiveend();
                    }
                    else
                    {
                        SIO10 = 0xFFU;
                    }
                }
            }
        }
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

