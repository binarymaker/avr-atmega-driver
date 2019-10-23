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
#include "dio.h"
#include "complier-cfg.h"
#include "regctrl.h"
#include "stdint.h"
#include <avr/io.h>
#include <avr/pgmspace.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static SFR volatile * const PORT_DATA_OUT[NUM_DIO_PORTS] = 
{
  (SFR*)&PORTB, 
  (SFR*)&PORTC,
  (SFR*)&PORTD
};

static SFR volatile * const PORT_DATA_IN[NUM_DIO_PORTS] = 
{
  (SFR*)&PINB, 
  (SFR*)&PINC,
  (SFR*)&PIND
};

static SFR volatile * const PORT_DIRECTION[NUM_DIO_PORTS] =
{
  (SFR*)&DDRB, 
  (SFR*)&DDRC,
  (SFR*)&DDRD
};
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void
DIO_Init(const DioConfig_st * const config)
{
  uint8_t chn;
  DioConfig_st cfg;
  
  for (chn = 0; chn < NUM_DIO_CHANNEL; chn++)
  {
    memcpy_P(&cfg, &config[chn], sizeof(cfg));
    switch (cfg.direction)
    {
      case DIO_DIRECTION_OUTPUT:
        BIT_SET(
                *PORT_DIRECTION[cfg.port],
                cfg.pin
                );
        break;
      case DIO_DIRECTION_INPUT:
        BIT_CLEAR(
                  *PORT_DIRECTION[cfg.port],
                   cfg.pin
                  );
        break;
      default:
        break;
    }
  }
}

void
DIO_ChannelWrite(DioChannel_et channel, DioPinState pinState);