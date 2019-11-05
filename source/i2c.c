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
#define I2C_CLOCK_FREQ                                                 (50000UL)
/*
 * Passible Prescale values - 1, 4, 16, 64
 * Note: Update respective register bits in I2C_Init() function
 */
#define I2C_PRESCALE                                                       (1UL)
#define I2C_STATUS_MASK                                                   (0xf8)
/* Private macro -------------------------------------------------------------*/
#define I2C_CLOCK_BITRATE_REG_CALC()                                           \
                          ( (F_CPU / (I2C_CLOCK_FREQ * I2C_PRESCALE) - 16 ) / 2)
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void
I2C_Init()
{
  /* I2C Prescaler -------------------------------------------------------------
   * 
   * Prescale    PWPS1   |  PWPS0
   *    1     -   _L_    |   _L_
   *    4     -   _L_    |   _H_
   *   16     -   _H_    |   _L_
   *   64     -   _H_    |   _H_
   */
  TWSR     =    _L_(TWPS1)    |    _L_(TWPS0)                                  ;
  
  TWBR     =    I2C_CLOCK_BITRATE_REG_CALC()                                   ;
  
}

void
I2C_Start()
{
  TWCR = BIT(TWINT) | BIT(TWSTA) | BIT(TWEN);
  while ( BIT_IsClear(TWCR, TWINT) ); 
}

void
I2C_Write(uint8_t data)
{
  TWDR = data;
  TWCR = BIT(TWINT) |  BIT(TWEN);
  while ( BIT_IsClear(TWCR, TWINT) );
}

uint8_t
I2C_Read()
{
  TWCR = BIT(TWINT) |  BIT(TWEN) | BIT(TWEA);
  while ( BIT_IsClear(TWCR, TWINT) );
  return (TWDR);
}

void
I2C_Stop()
{
  TWCR = BIT(TWINT) |  BIT(TWEN)  |  BIT(TWSTO);
}

void
I2C_Transmit(uint8_t slaveAddr, uint8_t *data, uint16_t size)
{
  uint16_t i_u16;
  I2C_Start();
  I2C_Write(slaveAddr << 1);
  
  for (i_u16 = 0; i_u16 < size; i_u16++)
  {
    I2C_Write(data[i_u16]);
  }
  
  I2C_Stop();
}

void
I2C_Receive(uint8_t slaveAddr, uint8_t *data, uint16_t size)
{
  uint16_t i_u16;
  
  I2C_Start();
  I2C_Write((slaveAddr << 1) | 0x01);
  for (i_u16 = 0; i_u16 < size; i_u16++)
  {
    data[i_u16+1] = I2C_Read();
  }
  I2C_Stop();
}