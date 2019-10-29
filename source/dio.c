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

static const DioConfig_st * _channelConfigList;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void
DIO_Init(const DioConfig_st * const config)
{
  uint8_t chn_u8;
  DioConfig_st cfg;
  
  _channelConfigList = config;
  
  for (chn_u8 = 0; chn_u8 < NUM_DIO_CHANNEL; chn_u8++)
  {
    memcpy_P(&cfg, &config[chn_u8], sizeof(cfg));
    DIO_ChannelConfig(&cfg);
  }
}

void
DIO_ChannelConfig(const DioConfig_st * const config)
{
  /* Mini map
   * !
   * +-- Direction == Input
   * |   +-- Resistor config 
   * +-- Direction == output
   *     +-- Pin state config
   */
  switch (config->direction)
  {
    /*----------------------------------------------------------- Input config*/
    case DIO_DIRECTION_INPUT:
      
      BIT_CLEAR(*PORT_DIRECTION[config->port], config->pin);
      /*------------------------------------------------------ Resistor config*/
        switch (config->resistor)
        {
          case DIO_RESISTOR_PULLUP:
            BIT_CLEAR(MCUCR, PUD);
            BIT_SET(*PORT_DATA_OUT[config->port], config->pin);
            break;
          case DIO_RESISTOR_DISABLE:
            BIT_CLEAR(*PORT_DATA_OUT[config->port], config->pin);
            break;
          default:
            break;
        }
        
      break;
      
    /*---------------------------------------------------------- Output config*/
    case DIO_DIRECTION_OUTPUT:
      /*--------------------------------------------- Initial pin state config*/
      BIT_SET(*PORT_DIRECTION[config->port], config->pin);
      
        switch (config->pinState)
        {
          case DIO_PINSTATE_LOW:
            BIT_CLEAR(*PORT_DATA_OUT[config->port], config->pin);
            break;
          case DIO_PINSTATE_HIGH:
            BIT_SET(*PORT_DATA_OUT[config->port], config->pin);
            break;
          default:
            break;
        }
      
      break;
      
    default:
      break;
  }   
}

void
DIO_ChannelWrite(DioChannel_et channel, DioPinState_et pinState)
{
  DioConfig_st config;
  
  memcpy_P(&config, &_channelConfigList[channel], sizeof(config));
  
  switch(pinState)
  {
    case DIO_PINSTATE_LOW:
      BIT_CLEAR(*PORT_DATA_OUT[config.port], config.pin);
      break;
    case DIO_PINSTATE_HIGH:
      BIT_SET(*PORT_DATA_OUT[config.port], config.pin);
      break;
    default:
      break;
  }
}

DioPinState_et
DIO_ChannelRead(DioChannel_et channel)
{
  DioConfig_st config;
  
  memcpy_P(&config, &_channelConfigList[channel], sizeof(config));
  
  if (BIT_IS_CLEAR(*PORT_DATA_IN[config.port], config.pin))
  {
    return (DIO_PINSTATE_LOW);
  }
  
  return (DIO_PINSTATE_HIGH);
  
}

DioPinState_et
Dio_ChannelToggle(DioChannel_et channel)
{
  DioConfig_st config;

  memcpy_P(&config, &_channelConfigList[channel], sizeof(config));
  BIT_TOGGLE(*PORT_DATA_OUT[config.port], config.pin);

  if (BIT_IS_CLEAR(*PORT_DATA_IN[config.port], config.pin))
  {
    return (DIO_PINSTATE_LOW);
  }
  
  return (DIO_PINSTATE_HIGH); 
}

/* Port - Access functions ###################################################*/
void
DIO_PortWrite(DioPort_et port, DioPortValue_t value)
{
  REG_WRITE(*PORT_DATA_OUT[port], value);
}

DioPortValue_t
DIO_PortRead(DioPort_et port)
{
  return (REG_READ(*PORT_DATA_IN[port]));
}

/* Pin - Access functions ####################################################*/

void
DIO_PinWrite(DioPort_et port, DioPin_et pin, DioPinState_et pinState)
{
  switch(pinState)
  {
    case DIO_PINSTATE_LOW:
      BIT_CLEAR(*PORT_DATA_OUT[port], pin);
      break;
    case DIO_PINSTATE_HIGH:
      BIT_SET(*PORT_DATA_OUT[port], pin);
      break;
    default:
      break;
  }
}

DioPinState_et
DIO_PinRead(DioPort_et port, DioPin_et pin)
{
  if (BIT_IS_CLEAR(*PORT_DATA_IN[port], pin))
  {
    return (DIO_PINSTATE_LOW);
  }
  return (DIO_PINSTATE_HIGH);
}

DioPinState_et
DIO_PinToggle(DioPort_et port, DioPin_et pin)
{
  BIT_TOGGLE(*PORT_DATA_OUT[port], pin);

  if (BIT_IS_CLEAR(*PORT_DATA_IN[port], pin))
  {
    return (DIO_PINSTATE_LOW);
  }
  
  return (DIO_PINSTATE_HIGH); 
}