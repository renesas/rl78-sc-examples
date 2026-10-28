/***********************************************************************************************************************
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
#include "common_utils.h"
#include "i2c_sensor.h"

int main (void);

volatile bool g_data_get_flag = false;

/* Stop processing after fatal error */
static void error_stop(void)
{
    deinit_sensor();
    while(true)
    {
        /* Do nothing */
    }
}

/*******************************************************************************************************************//**
 * @addtogroup r_iic_master_ep
 * @{
 **********************************************************************************************************************/
int main(void)
{
    EI();

    fsp_err_t err = FSP_SUCCESS;
    uint8_t xyz_axis[6]      = {RESET_VALUE};
    char flt_str[64]        = {RESET_VALUE};
    float x_axis            = 0.0f;
    float y_axis            = 0.0f;
    float z_axis            = 0.0f;

    /* Opening IIC master module and Initializing ADXL sensor */
    err = init_sensor();

    if(FSP_SUCCESS != err)
    {
        error_stop();
    }

    R_INTC_INTP0_Start();

    /* Stay in forever loop and read the sensor data every 3 Seconds
     * If the Sensor data reading returns error, cleanup and break with TRAP.
     * Note: For Demonstration Purpose the failure ends up with TRAP.
     * Note: This can be handled in many ways as per the Application needs
     */

    while(true)
    {
        while(g_data_get_flag)
        {
            /* Read ADXL sensor data */
            err =  read_sensor_data(xyz_axis);

            if(FSP_SUCCESS != err)
            {
                error_stop();
            }
            else
            {
                 /*
                  * X,Y,Z - axis data has to be evaluated so accessing particular array value,
                  * shifting it by 8 bits obtains data value to float variable
                  */

                x_axis = (float) (xyz_axis[0] | (xyz_axis[1] << BIT_SHIFT_8));   // X-axis value
                y_axis = (float) (xyz_axis[2] | (xyz_axis[3] << BIT_SHIFT_8));   // Y-axis value
                z_axis = (float) (xyz_axis[4] | (xyz_axis[5] << BIT_SHIFT_8));   // Z-axis value

                snprintf(flt_str,SIZE_64,"X-axis = %.02f, Y-axis = %.02f, Z-axis = %.02f",x_axis,y_axis,z_axis);

                g_data_get_flag = false;

                /* 3 Seconds Wait time between successive readings */
                R_BSP_SoftwareDelay(SENSOR_READ_DELAY, BSP_DELAY_SECS);
            }
        }
    }
}

/*******************************************************************************************************************//**
 * @} (end addtogroup r_iic_master_ep)
 **********************************************************************************************************************/
