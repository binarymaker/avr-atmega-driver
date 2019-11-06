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

#ifndef GPIO_1ee7051c_fb96_11e9_b0d7_0c5b8f279a64
#define GPIO_1ee7051c_fb96_11e9_b0d7_0c5b8f279a64

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * \brief Source file version tag
 *        
 *        version info: [15:8] main [7:0] beta
 */
#define __GPIO_VERSION      (0x0001u)

/* Includes ------------------------------------------------------------------*/
#include "common-def.h"
#include "pin-manager-cfg.h"
/* Exported types ------------------------------------------------------------*/
typedef enum
{
  GPIO_PIN_INPUT = 0,
  GPIO_PIN_OUTPUT
}pinDirection_et;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void
GPIO_PinDirection(pin_et pin, pinDirection_et dir);

void
GPIO_PinWrite(pin_et pin, state_et state);

state_et
GPIO_PinRead(pin_et pin);

void
GPIO_PinToggle(pin_et pin);

#ifdef __cplusplus
}
#endif

#endif /* GPIO_1ee7051c_fb96_11e9_b0d7_0c5b8f279a64 */

