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
#include "usart.h"
#include "mcu.h"
#include "complier-cfg.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
#define USART_BAUDRATE                                                   9600UL

#define USART_BAUD_REG_CALC(baud)        (uint16_t)((F_CPU / (16 * (baud))) - 1)
#define USART_BAUD_REG_2X_CALC(baud)      (uint16_t)((F_CPU / (8 * (baud))) - 1)
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void
USART_Init()
{
  /**
   * USART transmit and receive activation
   * 
   *          Receive | Transmit
   *           RXEN0  |  TXEN0
   * Enable  -  _H_   |   _H_
   * Disable -  _L_   |   _L_
   */
  UCSR0B    =     _L_(RXEN0)    |     _H_(TXEN0)                              ;
  UCSR0B   |=     _L_(RXCIE0)   |     _L_(TXCIE0)     |   _L_(UDRIE0)         ;
  
  /**
   * Frame Character size -----------------------------------------------------
   * 
   *         UCSZ02 |  UCSZ01 |  UCSZ00
   * 5 bit -   _L_  |   _L_   |   _L_
   * 6 bit -   _L_  |   _L_   |   _H_
   * 7 bit -   _L_  |   _H_   |   _L_
   * 8 bit -   _L_  |   _H_   |   _H_
   * 9 bit -   _H_  |   _H_   |   _H_
   */
  UCSR0C    =     _H_(UCSZ01)   |     _H_(UCSZ00)                             ;
  UCSR0B   |=     _L_(UCSZ02)                                                 ;                
  
  /**
   * Frame Stop bit size ------------------------------------------------------
   * 
   *         USBS0
   * 1 bit -  _L_
   * 2 nit -  _H_
   */
  UCSR0C   |=     _L_(USBS0)                                                  ;
  
  /**
   * Frame Parity bit setting -------------------------------------------------
   * 
   *            UMP01  |  UMP00
   * Disable -   _L_   |   _L_
   * Even    -   _H_   |   _L_
   * Odd     -   _H_   |   _H_
   */
  
  UCSR0C   |=     _L_(UMP01)    |    _L_(UMP01)                               ;
  
  /**
   * Baud rate register value calculation -------------------------------------
   */
  UBRR0     =    USART_BAUD_REG_CALC(USART_BAUDRATE)                          ;
}

void
USART_Write(uint8_t ch)
{
  while ( BIT_IsClear(UCSR0A, UDRE0) );
  REG_Write(UDR0, ch);
}

uint8_t
USART_Read()
{
  while ( BIT_IsClear(UCSR0A, RXC0) );
  return (REG_Read(UDR0));
}
