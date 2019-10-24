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
    DIO_PORTC, 
    DIO_PIN_0,
    DIO_DIRECTION_OUTPUT,    
    DIO_RESISTOR_DISABLE, 
    DIO_MODE_GPIO,
    DIO_PINSTATE_LOW
  },
  /* ------------------------------------------ Channel ID-1 : Name-CH1 ------*/
  { 
    DIO_PORTC, 
    DIO_PIN_1,
    DIO_DIRECTION_OUTPUT,
    DIO_RESISTOR_DISABLE, 
    DIO_MODE_GPIO,
    DIO_PINSTATE_LOW 
  },
  /* ------------------------------------------ Channel ID-2 : Name-CH2 ------*/
  { 
    DIO_PORTC,
    DIO_PIN_3,
    DIO_DIRECTION_INPUT,
    DIO_RESISTOR_PULLUP, 
    DIO_MODE_GPIO,
    DIO_PINSTATE_HIGH 
  }
};
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

