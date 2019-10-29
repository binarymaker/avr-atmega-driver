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
#include "dio-cfg.h"
#include <avr/pgmspace.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

const DioConfig_st dioConfig[NUM_DIO_CHANNEL] PROGMEM =
{
  /* ------------------------------------------ Channel ID-0 : Name-CH0 ------*/
  { 
    .port      = DIO_PORTC, 
    .pin       = DIO_PIN_0,
    .direction = DIO_DIRECTION_OUTPUT,    
    .resistor  = DIO_RESISTOR_DISABLE, 
    .function  = DIO_MODE_GPIO,
    .pinState  = DIO_PINSTATE_LOW
  },
  /* ------------------------------------------ Channel ID-1 : Name-RX ------*/
  { 
    .port      = DIO_PORTD,
    .pin       = DIO_PIN_0,
    .direction = DIO_DIRECTION_INPUT,
    .resistor  = DIO_RESISTOR_PULLUP,
    .function  = DIO_MODE_UART,
    .pinState  = DIO_PINSTATE_HIGH
  },
  /* ------------------------------------------ Channel ID-2 : Name-TX ------*/
  { 
    .port      = DIO_PORTD,
    .pin       = DIO_PIN_1,
    .direction = DIO_DIRECTION_OUTPUT,
    .resistor  = DIO_RESISTOR_DISABLE,
    .function  = DIO_MODE_UART,
    .pinState  = DIO_PINSTATE_HIGH
  }
};
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

