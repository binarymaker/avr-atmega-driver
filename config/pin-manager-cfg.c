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
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
enum intSense_e
{
INT_SENSE_LOW     ,
INT_SENSE_CHANGE  ,
INT_SENSE_FALLING ,
INT_SENSE_RISING
};

/* Private macro -------------------------------------------------------------*/
#define _I_(pin)                                                            (0u)
#define _O_(pin)                                                      BIT((pin))

/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void
PIN_MANAGER_Config()
{
  /**
   * Port Direction -----------------------------------------------------------
   * _O_ - Output
   * _I_ - Input      
   */
  DDRB    =    _O_(7)| _O_(6)| _O_(5)| _O_(4)| _O_(3)| _O_(2)| _O_(1)| _O_(0) ;  
  DDRC    =    _O_(7)| _O_(6)| _O_(5)| _O_(4)| _O_(3)| _O_(2)| _O_(1)| _O_(0) ;    
  DDRD    =    _O_(7)| _O_(6)| _O_(5)| _O_(4)| _O_(3)| _O_(2)| _O_(1)| _O_(0) ;
  
  /**
   * Port value ---------------------------------------------------------------
   *       INPUT | OUTPUT
   * _L_ - Low     Open drain
   * _H_ - High    PullUp
   */
  PORTB   =    _L_(7)| _L_(6)| _L_(5)| _L_(4)| _L_(3)| _L_(2)| _L_(1)| _L_(0) ;
  PORTC   =    _L_(7)| _L_(6)| _H_(5)| _H_(4)| _L_(3)| _L_(2)| _L_(1)| _L_(0) ;
  PORTD   =    _L_(7)| _L_(6)| _L_(5)| _L_(4)| _L_(3)| _L_(2)| _L_(1)| _L_(0) ;

  /**
   * External interrupts ------------------------------------------------------
   * EIMSK
   *   _L_ - Disable
   *   _H_ - Enable
   * EICRC
   *   INT_SENSE_LOW_LEVEL
   *   INT_SENSE_ANY_EDGE
   *   INT_SENSE_FALLING_EDGE
   *   INT_SENSE_RISING_EDGE
   */
  /*                   INT1                 |         INT0                    */
  EIMSK   =            _L_(1)               |        _L_(0)                  ;
  EICRA   =    (INT_SENSE_RISING << 2)      |    INT_SENSE_RISING            ; 
  
  /**
   * Pin change interrupt -----------------------------------------------------
   * PCIRC
   *   _L_ - Disable
   *   _H_ - Enable
   */
  /*              PCIE2      |     PCIE1      |     PCIE0                   */
  PCICR   =       _L_(2)     |     _L_(1)     |     _L_(0)                    ;
  
  /**
   * Pin change interrupt channels
   * _L_ - Disable particular pin
   * _H_ - Enable particular pin
   */
  /**
   * PCINT0->|   7   |   6   |   5   |   4   |   3   |   2   |   1   |   0   |
   * PCINT1->|       |   14  |   13  |   12  |   11  |   10  |   9   |   8   |
   * PCINT2->|   23  |   22  |   21  |   20  |   19  |   18  |   17  |   16  |     
   */
  PCMSK0  =    _L_(7)| _L_(6)| _L_(5)| _L_(4)| _L_(3)| _L_(2)| _L_(1)| _L_(0) ;
  PCMSK1  =            _L_(6)| _L_(5)| _L_(4)| _L_(3)| _L_(2)| _L_(1)| _L_(0) ;
  PCMSK2  =    _L_(7)| _L_(6)| _L_(5)| _L_(4)| _L_(3)| _L_(2)| _L_(1)| _L_(0) ;
  
}