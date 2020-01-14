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
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
#if USART_BUFFER_STACK == ENABLE
circularBuffer_st * m_cb_rx_svptr;
#endif
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

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

#if USART_BUFFER_STACK == ENABLE

void
USART_BufferLink(circularBuffer_st * cirbuf_svptr)
{
  m_cb_rx_svptr = cirbuf_svptr;
}

void
USART_BufferEngin()
{
  uint8_t read_byte_u8 = REG_Read(UDR0);
  CIRCULAR_BUFFER_Write(m_cb_rx_svptr, read_byte_u8);
}

#endif