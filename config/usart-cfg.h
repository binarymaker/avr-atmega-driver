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

#ifndef USART_b5b7f24a_fb96_11e9_9a9d_0c5b8f279a64
#define USART_b5b7f24a_fb96_11e9_9a9d_0c5b8f279a64

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "mcu.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define USART_BAUDRATE                                                   9600UL
   
#define USART_PRINTF_REDIRECT
/* Exported macro ------------------------------------------------------------*/
#define USART_BAUD_REG_CALC(baud)        (uint16_t)((F_CPU / (16 * (baud))) - 1)
#define USART_BAUD_REG_2X_CALC(baud)      (uint16_t)((F_CPU / (8 * (baud))) - 1)
/* Exported functions ------------------------------------------------------- */

STATIC_INLINE void
USART_Config()
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

#ifdef __cplusplus
}
#endif

#endif /* USART_b5b7f24a_fb96_11e9_9a9d_0c5b8f279a64 */

