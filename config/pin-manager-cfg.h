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

#ifndef PIN_MANAGER_262a4022_fb96_11e9_9a66_0c5b8f279a64
#define PIN_MANAGER_262a4022_fb96_11e9_9a66_0c5b8f279a64

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "mcu.h"
/* Exported types ------------------------------------------------------------*/
typedef enum
{
  P_A0, P_A1, P_A2, P_A3, P_A4, P_A5, P_A6, P_A7,
  P_B0, P_B1, P_B2, P_B3, P_B4, P_B5, P_B6, P_B7,
  P_C0, P_C1, P_C2, P_C3, P_C4, P_C5, P_C6, P_C7,
  P_D0, P_D1, P_D2, P_D3, P_D4, P_D5, P_D6, P_D7,
  P_NC = 0xff
}pin_et;

enum intSense_e
{
INT_SENSE_LOW     ,
INT_SENSE_CHANGE  ,
INT_SENSE_FALLING ,
INT_SENSE_RISING
};
/* Exported constants --------------------------------------------------------*/
#define NUM_PIN_PER_PORT                                                      8
/* Exported macro ------------------------------------------------------------*/
#define _I_(pin)                                                            (0u)
#define _O_(pin)                                                      BIT((pin))
/* Exported functions ------------------------------------------------------- */

STATIC_INLINE void
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
  PORTC   =    _L_(7)| _L_(6)| _L_(5)| _L_(4)| _L_(3)| _L_(2)| _L_(1)| _L_(0) ;
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

#ifdef __cplusplus
}
#endif

#endif /* PIN_MANAGER_262a4022_fb96_11e9_9a66_0c5b8f279a64 */

