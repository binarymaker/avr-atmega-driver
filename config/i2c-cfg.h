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

#ifndef I2C_5fcbfdc6_febd_11e9_8eef_705a0f25cb51
#define I2C_5fcbfdc6_febd_11e9_8eef_705a0f25cb51

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "mcu.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define I2C_CLOCK_FREQ                                                (400000UL)

#define I2C_STATUS_RETURN                                               DISABLE


/*
 * Passible Prescale values - 1, 4, 16, 64
 * Note: Update respective register bits in I2C_Config() function
 */
#define I2C_PRESCALE                                                       (1UL)
/* Exported macro ------------------------------------------------------------*/
#define I2C_CLOCK_BITRATE_REG_CALC()                                           \
                          ( (F_CPU / (I2C_CLOCK_FREQ * I2C_PRESCALE) - 16 ) / 2)
/* Exported functions --------------------------------------------------------*/

STATIC_INLINE void
I2C_Config()
{
  /**
   * I2C Prescaler -----------------------------------------------------------
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

#ifdef __cplusplus
}
#endif

#endif /* I2C_5fcbfdc6_febd_11e9_8eef_705a0f25cb51 */

