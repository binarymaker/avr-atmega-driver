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
#include "mcu.h"
#include "timer0-cfg.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void
TIMER0_Config()
{
  /**
   * Timer clock selection
   * 
   * clk div           CS02    |   CS01    |   CS00
   * timer off       -  _L_    |    _L_    |    _L_
   * 1               -  _L_    |    _L_    |    _H_
   * 8               -  _L_    |    _H_    |    _L_
   * 64              -  _L_    |    _H_    |    _H_
   * 256             -  _H_    |    _L_    |    _L_
   * 1024            -  _H_    |    _L_    |    _H_
   * Ext T0 falling  -  _H_    |    _H_    |    _L_
   * Ext T0 rising   -  _H_    |    _H_    |    _H_     
   */
  TCCR0B    =     _L_(CS02)    |    _L_(CS01)    |    _L_(CS00)                ;
  
  /**
   * Timer0 count value
   */
  TCNT0     =   0x00                                                           ;
  
  /**
   * Timer0 Output compare register
   */
  OCR0A     =   0xff                                                           ;
  OCR0B     =   0xff                                                           ;
  
 /**
   * Waveform generation mode 
   * Common for OC0A and OC0B
   * 
   * Mode | TimerMode  | TOP       WGM02   |   WGM01   |   WGM00
   *  0   | Normal     | 0xFF    -  _L_    |    _L_    |    _L_
   *  1   | Phase PWM  | 0xFF    -  _L_    |    _L_    |    _H_
   *  2   | CTC(1)     | OCRA    -  _L_    |    _H_    |    _L_
   *  3   | Fast PWM   | 0xFF    -  _L_    |    _H_    |    _H_
   *  4   | Reserved   |         -  _H_    |    _L_    |    _L_
   *  5   | Phase PWM  | OCRA    -  _H_    |    _L_    |    _H_
   *  6   | Reserved   |         -  _H_    |    _H_    |    _L_
   *  7   | Fast PWM   | OCRA    -  _H_    |    _H_    |    _H_
   * 
   * (1) Clear timer on match
   */
  TCCR0A    =     _L_(WGM01)     |    _L_(WGM00)                               ;
  TCCR0B   |=     _L_(WGM02)                                                   ;
  
  /**
   * OC0A - Compare match output mode
   *                               Phase
   * non-PWM    |   Fast-PWM   | Correct-PWM    COM0A1   |   COM0A0
   * Disconnect |  Disconnect  |  Disconnect  -   _L_    |    _L_
   * Toggle     |  Toggle(1)   |  Toggle(1)   -   _L_    |    _H_
   * Clear      |  Normal PWM  |  Invert PWM  -   _H_    |    _L_
   * Set        |  Invert PWM  |  Normal PWM  -   _H_    |    _H_  
   * 
   * (1) Toggle function in WGM02 = 1, Disconnect in WGM02 = 0 
   */
  TCCR0A   |=     _L_(COM0A1)    |    _L_(COM0A0)                              ;
  
  /**
   * OC0B - Compare match output mode
   *                              Phase
   * non-PWM    |   Fast-PWM   | Correct-PWM    COM0B1   |   COM0B0
   * Disconnect |  Disconnect  |  Disconnect  -   _L_    |    _L_
   * Toggle     |  Reserved    |  Reserved    -   _L_    |    _H_
   * Clear      |  Normal PWM  |  Invert PWM  -   _H_    |    _L_
   * Set        |  Invert PWM  |  Normal PWM  -   _H_    |    _H_  
   */
  TCCR0A   |=     _L_(COM0B1)    |    _L_(COM0B0)                              ;
    
  /**
   * Timer0 interrupt activation
   *           
   *             overflow  |  match A  |  match B
   *              TOIE0    |  OCIE0A   |  OCIE0B
   * Enable    -   _H_     |   _H_     |   _H_
   * Disable   -   _L_     |   _L_     |   _L_
   */
   TIMSK0    =     _H_(TOIE0)     |     _L_(OCIE0A)     |     _L_(OCIE0B)      ;
}

