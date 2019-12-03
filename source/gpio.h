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
#include "mcu.h"
/* Exported types ------------------------------------------------------------*/
typedef enum
{
  GPIO_PIN_INPUT = 0,
  GPIO_PIN_OUTPUT
}pinDirection_et;

typedef enum
{
#ifdef PORTA
  P_A0 =  0U, P_A1, P_A2, P_A3, P_A4, P_A5, P_A6, P_A7,
#endif
#ifdef PORTB
  P_B0 =  8U, P_B1, P_B2, P_B3, P_B4, P_B5, P_B6, P_B7,
#endif
#ifdef PORTC
  P_C0 = 16U, P_C1, P_C2, P_C3, P_C4, P_C5, P_C6, P_C7,
#endif
#ifdef PORTD
  P_D0 = 24U, P_D1, P_D2, P_D3, P_D4, P_D5, P_D6, P_D7,
#endif
  P_NC = 0xff
}pin_et;

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

