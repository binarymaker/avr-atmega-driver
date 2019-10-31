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
#define WHICH_PORT(pinId)                           ((pinId) / NUM_PIN_PER_PORT)
#define WHICH_PIN(pinId)                            ((pinId) % NUM_PIN_PER_PORT)
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void
GPIO_PinDirection(pin_et pin, pinDirection_et dir)
{
  SFR *directionReg = NULL;
  switch(WHICH_PORT(pin))
  {
#if defined(DDRA)
    case 0:
      directionReg = (SFR*)&DDRA;
      break;
#endif

#if defined(DDRB)
    case 1:
      directionReg = (SFR*)&DDRB;
      break;
#endif
      
#if defined(DDRC)
    case 2:
      directionReg = (SFR*)&DDRC;
      break;
#endif
      
#if defined(DDRD)
    case 3:
      directionReg = (SFR*)&DDRD;
      break;
#endif
    default:
      break;
  }
  
  BIT_Write(*directionReg, WHICH_PIN(pin), dir);
  
}

void
GPIO_PinWrite(pin_et pin, state_et state)
{
  SFR *dataOutReg = NULL;
  
  switch(WHICH_PORT(pin))
  {
#if defined(PORTA)
    case 0:
      dataOutReg = (SFR*)&PORTA;
      break;
#endif

#if defined(PORTB)
    case 1:
      dataOutReg = (SFR*)&PORTB;
      break;
#endif
      
#if defined(PORTC)
    case 2:
      dataOutReg = (SFR*)&PORTC;
      break;
#endif
      
#if defined(PORTD)
    case 3:
      dataOutReg = (SFR*)&PORTD;
      break;
#endif
    default:
      break;
  }
  
  BIT_Write(*dataOutReg, WHICH_PIN(pin), state);
}

state_et
GPIO_PinRead(pin_et pin)
{
  SFR *dataInReg = NULL;
  state_et pinState;
  
  switch(WHICH_PORT(pin))
  {
#if defined(PINA)
    case 0:
      dataInReg = (SFR*)&PINA;
      break;
#endif

#if defined(PINB)
    case 1:
      dataInReg = (SFR*)&PINB;
      break;
#endif
      
#if defined(PINC)
    case 2:
      dataInReg = (SFR*)&PINC;
      break;
#endif
      
#if defined(PIND)
    case 3:
      dataInReg = (SFR*)&PIND;
      break;
#endif
    default:
      break;
  }
  
  pinState = BIT_Read(*dataInReg, WHICH_PIN(pin));
  
  return (pinState);
}

void
GPIO_PinToggle(pin_et pin)
{
  SFR *dataOutReg = NULL;
  
  switch(WHICH_PORT(pin))
  {
#if defined(PORTA)
    case 0:
      dataOutReg = (SFR*)&PORTA;
      break;
#endif

#if defined(PORTB)
    case 1:
      dataOutReg = (SFR*)&PORTB;
      break;
#endif
      
#if defined(PORTC)
    case 2:
      dataOutReg = (SFR*)&PORTC;
      break;
#endif
      
#if defined(PORTD)
    case 3:
      dataOutReg = (SFR*)&PORTD;
      break;
#endif
    default:
      break;
  }
  
  BIT_Toggle(*dataOutReg, WHICH_PIN(pin));
  
}
