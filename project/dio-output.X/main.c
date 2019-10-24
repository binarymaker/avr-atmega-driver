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

#define F_CPU 8000000

/* Includes ------------------------------------------------------------------*/
#include <avr/io.h>
#include <util/delay.h>
#include "dio.h"
#include "dio-cfg.h"
#include "regctrl.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void
GPIO_Init();
/* Private functions ---------------------------------------------------------*/
/* STM32 HAL style */
static void GPIO_Init()
{
  DioConfig_st cfg;
  
  cfg.port = DIO_PORTB;
  cfg.pin = DIO_PIN_2;
  cfg.direction = DIO_DIRECTION_OUTPUT;
  cfg.pinState = DIO_PINSTATE_LOW;
  DIO_ChannelConfig(&cfg);
  
  cfg.port = DIO_PORTB;
  cfg.pin = DIO_PIN_3;
  DIO_ChannelConfig(&cfg);
}
int
main()
{
  DIO_Init(dioConfig);
  GPIO_Init();
  while(1)
  {
    DioPinState_et state = DIO_ChannelRead(CH2);
    DIO_PinToggle(DIO_PORTB, DIO_PIN_2);
    DIO_PinToggle(DIO_PORTB, DIO_PIN_3);
    if (DIO_PINSTATE_LOW == state)
    {/*
      DIO_ChannelWrite(CH0, DIO_PINSTATE_LOW);
      _delay_ms(100);
      DIO_ChannelWrite(CH0, DIO_PINSTATE_HIGH);
      _delay_ms(100);
      */
      Dio_ChannelToggle(CH1);
      _delay_ms(1000);
    }
  
  }
  return 0;
}
