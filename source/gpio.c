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
#include "gpio.h"
#include "mcu.h"
#include "complier-cfg.h"
#include "regctrl.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
#define WHICH_PORT(pinId)                          ((pinId) / GPIO_PIN_PER_PORT)
#define WHICH_PIN(pinId)                           ((pinId) % GPIO_PIN_PER_PORT)
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void
GPIO_PinDirection(pin_et pin, pinDirection_et dir)
{
  sfr_t *directionReg = NULL;
  switch(WHICH_PORT(pin))
  {
#if defined(DDRA)
    case 0:
      directionReg = (sfr_t*)&DDRA;
      break;
#endif

#if defined(DDRB)
    case 1:
      directionReg = (sfr_t*)&DDRB;
      break;
#endif
      
#if defined(DDRC)
    case 2:
      directionReg = (sfr_t*)&DDRC;
      break;
#endif
      
#if defined(DDRD)
    case 3:
      directionReg = (sfr_t*)&DDRD;
      break;
#endif
    default:
      break;
  }
  
  if (directionReg)
  {
    BIT_Write(*directionReg, WHICH_PIN(pin), dir);
  }
  
}

void
GPIO_PinWrite(pin_et pin, state_et state)
{
  sfr_t *dataOutReg = NULL;
  
  switch(WHICH_PORT(pin))
  {
#if defined(PORTA)
    case 0:
      dataOutReg = (sfr_t*)&PORTA;
      break;
#endif

#if defined(PORTB)
    case 1:
      dataOutReg = (sfr_t*)&PORTB;
      break;
#endif
      
#if defined(PORTC)
    case 2:
      dataOutReg = (sfr_t*)&PORTC;
      break;
#endif
      
#if defined(PORTD)
    case 3:
      dataOutReg = (sfr_t*)&PORTD;
      break;
#endif
    default:
      break;
  }
  
  if (dataOutReg)
  {
    BIT_Write(*dataOutReg, WHICH_PIN(pin), state);
  }
}

state_et
GPIO_PinRead(pin_et pin)
{
  sfr_t *dataInReg = NULL;
  state_et pinState;
  
  switch(WHICH_PORT(pin))
  {
#if defined(PINA)
    case 0:
      dataInReg = (sfr_t*)&PINA;
      break;
#endif

#if defined(PINB)
    case 1:
      dataInReg = (sfr_t*)&PINB;
      break;
#endif
      
#if defined(PINC)
    case 2:
      dataInReg = (sfr_t*)&PINC;
      break;
#endif
      
#if defined(PIND)
    case 3:
      dataInReg = (sfr_t*)&PIND;
      break;
#endif
    default:
      break;
  }
  
  if (dataInReg)
  {
    pinState = BIT_Read(*dataInReg, WHICH_PIN(pin));
  }
  
  return (pinState);
}

void
GPIO_PinToggle(pin_et pin)
{
  sfr_t *dataOutReg = NULL;
  
  switch(WHICH_PORT(pin))
  {
#if defined(PORTA)
    case 0:
      dataOutReg = (sfr_t*)&PORTA;
      break;
#endif

#if defined(PORTB)
    case 1:
      dataOutReg = (sfr_t*)&PORTB;
      break;
#endif
      
#if defined(PORTC)
    case 2:
      dataOutReg = (sfr_t*)&PORTC;
      break;
#endif
      
#if defined(PORTD)
    case 3:
      dataOutReg = (sfr_t*)&PORTD;
      break;
#endif
    default:
      break;
  }
  
  if (dataOutReg)
  {
    BIT_Toggle(*dataOutReg, WHICH_PIN(pin));
  }
}
