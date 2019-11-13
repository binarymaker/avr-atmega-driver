/**\cond
  ******************************************************************************
  * ______  _                             ___  ___        _               
  * | ___ \(_)                            |  \/  |       | |              
  * | |_/ / _  _ __    __ _  _ __  _   _  | .  . |  __ _ | | __ ___  _ __ 
  * | ___ \| || '_ \  / _` || '__|| | | | | |\/| | / _` || |/ // _ \| '__|
  * | |_/ /| || | | || (_| || |   | |_| | | |  | || (_| ||   <|  __/| |   
  * \____/ |_||_| |_| \__,_||_|    \__, | \_|  |_/ \__,_||_|\_\\___||_|   
  *                                 __/ |                                 
  *                                |___/                                  
  *                                                                       
  * Copyright (C) 2019 Binary Maker - All Rights Reserved
  *
  * This program and the accompanying materials are made available
  * under the terms described in the LICENSE file which accompanies
  * this distribution.
  * Written by Binary Maker <https://github.com/binarymaker>
  ******************************************************************************
  \endcond*/

#ifndef I2C_5fc37576_febd_11e9_9ff1_705a0f25cb51
#define I2C_5fc37576_febd_11e9_9ff1_705a0f25cb51

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * \brief Source file version tag
 *        
 *        version info: [15:8] main [7:0] beta
 */
#define __I2C_VERSION      (0x0001u)

/* Includes ------------------------------------------------------------------*/
#include "mcu.h"
/* Exported types ------------------------------------------------------------*/
typedef enum
{
  I2C_FAILED = 0,
  I2C_SUCCESS,
  I2C_ARBT_FAILED,
  I2C_DEVICE_FAILED,
  I2C_DATA_WRITE_FAILED,
  I2C_DATA_READ_FAILED
}i2c_status_et;

typedef enum
{
  I2C_ACK = 0,
  I2C_NACK
}i2c_ack_et;
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#if (I2C_STATUS_RETURN == ENABLE)
i2c_status_et
#else
void
#endif
I2C_Start();


#if (I2C_STATUS_RETURN == ENABLE)
i2c_status_et
#else
void
#endif
I2C_Write(uint8_t data);

#if (I2C_STATUS_RETURN == ENABLE)
i2c_status_et
#else
void
#endif
I2C_Read(uint8_t* data, i2c_ack_et ack);

void
I2C_Stop();

void
I2C_Transmit(uint8_t slaveAddr, uint8_t memAddr, uint8_t *data, uint16_t size);

void
I2C_Receive(uint8_t slaveAddr, uint8_t memAddr, uint8_t *data, uint16_t size);

#ifdef __cplusplus
}
#endif

#endif /* I2C_5fc37576_febd_11e9_9ff1_705a0f25cb51 */

