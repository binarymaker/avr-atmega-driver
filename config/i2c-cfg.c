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
#include "i2c-cfg.h"
#include "mcu.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

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
I2C_Config()
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
