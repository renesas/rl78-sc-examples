/***********************************************************************************************************************
 * File Name    : i2c_sensor.c
 * Description  : Contains data structures and functions used in i2c_sensor.c.
 **********************************************************************************************************************/
/***********************************************************************************************************************
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
#include "common_utils.h"
#include "i2c_sensor.h"

/*******************************************************************************************************************//**
 * @addtogroup r_iic_master_ep
 * @{
 **********************************************************************************************************************/

/*
 * Global Variables
 */
/* Reading I2C call back event through i2c_Master callback */
static volatile iica_event_t i2c_event = IICA_MASTER_EVENT_ABORTED;

/*
 * private function declarations
 */
static fsp_err_t get_device_id(uint8_t *dev_id);
static fsp_err_t validate_i2c_event(void);

/*******************************************************************************************************************//**
 *  @brief       initialize IIC master module and set up ADXL sensor
 *  @param[IN]   None
 *  @retval      FSP_SUCCESS                  Upon successful open and start of timer
 *  @retval      Any Other Error code apart from FSP_SUCCESS is  Unsuccessful open or start
 **********************************************************************************************************************/
fsp_err_t init_sensor(void)
{
    uint8_t device_id = RESET_VALUE;
    fsp_err_t err     = FSP_SUCCESS;
    MD_STATUS err_cg = MD_OK;
    uint8_t measure_enable_payload[MEASURE_PAYLOAD_SIZE] = { POWER_CTL_REG, ENABLE_BIT };

    /* opening IIC master module */
    R_IICA0_Create();

    /* Get device ID as a start of communication */
    err =  get_device_id(&device_id);

    /* Verify I2C transaction is successful with ADXL and correct device ID is received */
    if ( (FSP_SUCCESS == err) && (DEVICE_SIGNATURE == device_id) )
    {
        err_cg = R_IICA0_Master_Send(SENSOR_SLAVE_ADDR,measure_enable_payload,TWO_BYTE,0xFF);

        if (MD_OK == err_cg)
        {
            err = validate_i2c_event();
        }
        /* handle error */
        else
        {
            /* minimal: return aborted on API error */
            err = FSP_ERR_ABORTED;
        }
    }
    /* handle error */
    else
    {
        /*Don't return success when ID mismatch or get_device_id failed */
        if (FSP_SUCCESS == err)
        {
            err = FSP_ERR_ABORTED;
        }
    }
    return err;
}


/*******************************************************************************************************************//**
 *  @brief       DeInitialize IIC master module
 *  @param[IN]   None
 *  @retval      None
 **********************************************************************************************************************/
void deinit_sensor(void)
{
    /* close open modules */
    R_IICA0_Stop();
}
/*******************************************************************************************************************//**
 *  @brief       Read The ACL Sensor data for X,Y and Z axis. And prints the raw data on the RTT console
 *  @param[IN]   Array pointer to get the sensor data
 *  @retval      FSP_SUCCESS                  Upon successful open and start of timer
 *  @retval      Any Other Error code apart from FSP_SUCCES  Unsuccessful open or start
 **********************************************************************************************************************/
fsp_err_t read_sensor_data(uint8_t *xyz_data)
{
    fsp_err_t err           = FSP_SUCCESS;
    MD_STATUS err_cg = MD_OK;
    uint8_t adxl_data[7]    = { RESET_VALUE };
    uint8_t internal_reg    = AXIS_DATA;


    if(NULL == xyz_data)
    {
        err = FSP_ERR_INVALID_POINTER;

        return err;
    }

    /* Write Accelerometer Data register   */
    err_cg = R_IICA0_Master_Send(SENSOR_SLAVE_ADDR, &internal_reg, ONE_BYTE, 0xFF);

    /* handle error */
    if (MD_OK != err_cg)
    {
        return (fsp_err_t)err_cg;
    }
    else
    {
        err = validate_i2c_event();

        /* Performs read operation only when write event is successful, failure part is handled at next stage*/
        if (FSP_SUCCESS == err)
        {
            /* Check return value of Receive API */
            err_cg = R_IICA0_Master_Receive(SENSOR_SLAVE_ADDR, &adxl_data[0], DATA_REGISTERS, 0xFF);

            /* handle error */
            if (MD_OK != err_cg)
            {
                return (fsp_err_t)err_cg;
            }
            else
            {
                err = validate_i2c_event();
                if (FSP_SUCCESS != err)
                {
                    return err;
                }
            }
        }
        else
        {
            return err;
        }

        /*  Read is successful update the x,y,z values and return success */
        for (uint8_t itr = RESET_VALUE; itr < SENSOR_DATA_SIZE; itr++)
        {
            *(xyz_data+itr) = adxl_data[itr];
        }
    }
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 *  @brief     Read Device signature/ID from sensor
 *
 *  @param[in] dev_id                       retrieve ADXL device ID
 *
 *  @retval    FSP_SUCCESS                  on successful I2C transaction
 *             FSP_ERR_INVALID_POINTER      if invalid parameters passed
 *             err                          whichever occurs on either API or on I2C event failure
 **********************************************************************************************************************/
static fsp_err_t get_device_id(uint8_t *dev_id)
{
    fsp_err_t err         = FSP_SUCCESS;
    uint8_t reg_address   = DEVICE_ID_REG;

    /* Parameter checking */
    if (NULL == dev_id)
    {
        err = FSP_ERR_INVALID_POINTER;
        return err;
    }
    err = (fsp_err_t)R_IICA0_Master_Send(SENSOR_SLAVE_ADDR, &reg_address, ONE_BYTE, 0xFF);

    /* handle error */
    if (FSP_SUCCESS != err)
    {
        // Do nothing.
    }
    else
    {
        err = validate_i2c_event();
        /* handle error */
        if(FSP_ERR_ABORTED == err)
        {
            // Do nothing.
        }
        else
        {
            err = (fsp_err_t)R_IICA0_Master_Receive(SENSOR_SLAVE_ADDR, dev_id, ONE_BYTE, 0xFF);

            /* handle error */
            if (FSP_SUCCESS != err)
            {
                //  Do nothing, the error is returned in the end
            }
            else
            {
                err = validate_i2c_event(); // ABORTED occurred
            }
        }
    }
    /* On successful I2C transaction with ADXL return from here */
    return err;
}

/*******************************************************************************************************************//**
 *  @brief      User callback function
 *  @param[in]  p_args
 *  @retval None
 **********************************************************************************************************************/
void i2c_master_callback(iica_event_t args)
{
        /* capture callback event for validating the i2c transfer event*/
        i2c_event = args;
}

/*******************************************************************************************************************//**
 *  @brief       Validate i2c receive/transmit  based on required write read operation
 *
 *  @param[in]   None
 *
 *  @retval      FSP_SUCCESS                       successful event receiving returns FSP_SUCCESS
 *               FSP_ERR_TRANSFER_ABORTED          Either on timeout elapsed or received callback event is
 *                                                 I2C_MASTER_EVENT_ABORTED
 **********************************************************************************************************************/
static fsp_err_t validate_i2c_event(void)
{
    uint16_t local_time_out = UINT16_MAX;

    /* resetting call back event capture variable */
    i2c_event = (iica_event_t)RESET_VALUE;

    do
    {
        /* This is to avoid infinite loop */
        --local_time_out;

        if(RESET_VALUE == local_time_out)
        {
            return FSP_ERR_ABORTED;
        }

    }while(RESET_VALUE == i2c_event);

    if(IICA_MASTER_EVENT_ABORTED != i2c_event)
    {
        i2c_event = (iica_event_t)RESET_VALUE;  // Make sure this is always Reset before return
        return FSP_SUCCESS;
    }

    i2c_event = (iica_event_t)RESET_VALUE; // Make sure this is always Reset before return
    return FSP_ERR_ABORTED;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup r_iic_master_ep)
 **********************************************************************************************************************/
