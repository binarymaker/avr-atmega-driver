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

/* Includes ------------------------------------------------------------------*/
#include "i2c.h"
#include "mcu.h"
#include "util/twi.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

#if (I2C_STATUS_RETURN == ENABLE)
i2c_status_et
#else
void
#endif
I2C_Start()
{
  TWCR = BIT(TWINT) | BIT(TWSTA) | BIT(TWEN);
  while ( BIT_IsClear(TWCR, TWINT) );

#if (I2C_STATUS_RETURN == ENABLE)
  switch (TW_STATUS)
  {
    case TW_START:
      return I2C_SUCCESS;
      break;
    default:
      return I2C_FAILED;
      break;
  }
#endif
}


#if (I2C_STATUS_RETURN == ENABLE)
i2c_status_et
#else
void
#endif
I2C_Write(uint8_t data)
{
  TWDR = data;
  TWCR = BIT(TWINT) |  BIT(TWEN);
  while ( BIT_IsClear(TWCR, TWINT) );

#if (I2C_STATUS_RETURN == ENABLE)
  switch (TW_STATUS)
  {
    case TW_MT_SLA_ACK:
      return I2C_SUCCESS;
      break;
    case TW_MT_DATA_ACK:
      return I2C_SUCCESS;
      break;
    case TW_MT_SLA_NACK:
      return I2C_DEVICE_FAILED;
      break;
    case TW_MT_DATA_NACK:
      return I2C_DATA_WRITE_FAILED;
      break;
    case TW_MT_ARB_LOST:
      return I2C_ARBT_FAILED;
      break;
    default:
      return I2C_FAILED;
      break;
  }
#endif
}

#if (I2C_STATUS_RETURN == ENABLE)
i2c_status_et
#else
void
#endif
I2C_Read(uint8_t* data, i2c_ack_et ack)
{
  if (I2C_ACK == ack)
  {
    TWCR = BIT(TWINT) |  BIT(TWEN) | BIT(TWEA);
  }
  else
  {
    TWCR = BIT(TWINT) |  BIT(TWEN);
  }

  while ( BIT_IsClear(TWCR, TWINT) );
  
  *data = TWDR;
  
#if (I2C_STATUS_RETURN == ENABLE)
  switch (TW_STATUS)
  {
    case TW_MR_DATA_ACK:
      *data = TWDR;
      return I2C_SUCCESS;
      break;
    case TW_MR_DATA_NACK:
      return I2C_DEVICE_FAILED;
      break;
    default:
      return I2C_FAILED;
      break;
  }
#endif
}

void
I2C_Stop()
{
  TWCR = BIT(TWINT) |  BIT(TWEN)  |  BIT(TWSTO);
}

void
I2C_Transmit(uint8_t slaveAddr, uint8_t memAddr, uint8_t *data, uint16_t size)
{
  uint16_t i_u16;

  I2C_Start();
  I2C_Write(slaveAddr << 1);
  I2C_Write(memAddr);

  for (i_u16 = 0; i_u16 < size; i_u16++)
  {
    I2C_Write(data[i_u16]);
  }
  
  I2C_Stop();
}

void
I2C_Receive(uint8_t slaveAddr, uint8_t memAddr, uint8_t *data, uint16_t size)
{
  uint16_t i_u16;

  I2C_Start();
  I2C_Write(slaveAddr << 1);
  I2C_Write(memAddr);

  I2C_Start();
  I2C_Write((slaveAddr << 1) | 0x01);

  for (i_u16 = 0; i_u16 < size - 1; i_u16++)
  {
    I2C_Read(&data[i_u16], I2C_ACK );
  }
  I2C_Read(&data[size - 1], I2C_NACK );
  I2C_Stop();
}