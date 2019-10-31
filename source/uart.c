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
#include "uart.h"
#include "complier-cfg.h"
#include "regctrl.h"
#include "stdint.h"
#include <avr/io.h>
#include <avr/pgmspace.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define F_CPU 8000000
/* Private macro -------------------------------------------------------------*/
#define BAUD_REG_NORMAL_CALC(baud)                 ((F_CPU / (16 * (baud))) - 1)
#define BAUD_REG_2X_CALC(baud)                      ((F_CPU / (8 * (baud))) - 1)
/* Private variables ---------------------------------------------------------*/
static SFR volatile * const DATA_REGISTOR[NUM_UART_PORTS] = 
{
  (SFR*)&UDR0
};

static SFR volatile * const CONTROL_STATUS_A_REG[NUM_UART_PORTS] = 
{
  (SFR*)&UCSR0A
};

static SFR volatile * const CONTROL_STATUS_B_REG[NUM_UART_PORTS] = 
{
  (SFR*)&UCSR0B
};

static SFR volatile * const CONTROL_STATUS_C_REG[NUM_UART_PORTS] = 
{
  (SFR*)&UCSR0C
};

static SFR volatile * const BAUDRATE_L_REG[NUM_UART_PORTS] = 
{
  (SFR*)&UBRR0L
};

static SFR volatile * const BAUDRATE_H_REG[NUM_UART_PORTS] = 
{
  (SFR*)&UBRR0H
};

static const UartConfig_st * _channelConfigList;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void
UART_Init(const UartConfig_st * const config)
{
  uint8_t chn_u8;
  UartConfig_st cfg;

  _channelConfigList = config;
  
  for (chn_u8 = 0; chn_u8 < NUM_UART_CHANNEL; chn_u8++)
  {
    memcpy_P(&cfg, &config[chn_u8], sizeof(cfg));
    UART_ChannelConfig(&cfg);
  }
}

void
UART_ChannelConfig(const UartConfig_st * const config)
{
  UartPort_et port;
  uint32_t baudRegValue;
  
  port = config->port;
  
  /* Asynchronous mode */
  BIT_CLEAR(*CONTROL_STATUS_C_REG[port], UMSEL00);
  BIT_CLEAR(*CONTROL_STATUS_C_REG[port], UMSEL01);
  
  /* Communication mode (transmit and receive) selection*/
  switch (config->comMode)
  {
    case (UART_COM_MODE_TRANSMIT_ONLY):
      REG_WRITE(*CONTROL_STATUS_B_REG[port], BIT_MASK(TXEN0));
      break;
    case (UART_COM_MODE_RECEIVE_ONLY):
      REG_WRITE(*CONTROL_STATUS_B_REG[port], BIT_MASK(RXEN0));
      break;
    case (UART_COM_MODE_TRANSMIT_RECEIVE):
      REG_WRITE(*CONTROL_STATUS_B_REG[port], BIT_MASK(TXEN0) | BIT_MASK(RXEN0));
      break;
    default:
      break;
  }
  
  /* Frame data length selection */
  switch (config->dataBits)
  {
    case (UART_DATABITS_5):
      BIT_CLEAR(*CONTROL_STATUS_C_REG[port], UCSZ00);
      BIT_CLEAR(*CONTROL_STATUS_C_REG[port], UCSZ01);
      BIT_CLEAR(*CONTROL_STATUS_B_REG[port], UCSZ02);
      break;
    case (UART_DATABITS_6):
      BIT_SET  (*CONTROL_STATUS_C_REG[port], UCSZ00);
      BIT_CLEAR(*CONTROL_STATUS_C_REG[port], UCSZ01);
      BIT_CLEAR(*CONTROL_STATUS_B_REG[port], UCSZ02);
      break;
    case (UART_DATABITS_7):
      BIT_CLEAR(*CONTROL_STATUS_C_REG[port], UCSZ00);
      BIT_SET  (*CONTROL_STATUS_C_REG[port], UCSZ01);
      BIT_CLEAR(*CONTROL_STATUS_B_REG[port], UCSZ02);
      break;
    case (UART_DATABITS_8):
      BIT_SET  (*CONTROL_STATUS_C_REG[port], UCSZ00);
      BIT_SET  (*CONTROL_STATUS_C_REG[port], UCSZ01);
      BIT_CLEAR(*CONTROL_STATUS_B_REG[port], UCSZ02);
      break;
    case (UART_DATABITS_9):
      BIT_SET  (*CONTROL_STATUS_C_REG[port], UCSZ00);
      BIT_SET  (*CONTROL_STATUS_C_REG[port], UCSZ01);
      BIT_SET  (*CONTROL_STATUS_B_REG[port], UCSZ02);
      break;
    default:
      break;
  }
  
  /* Num of stop bit selection */
  switch (config->stopBits)
  {
    case (UART_STOPBITS_1): 
      BIT_CLEAR(*CONTROL_STATUS_C_REG[port], USBS0);
      break;
    case (UART_STOPBITS_2):
      BIT_SET(*CONTROL_STATUS_C_REG[port], USBS0);
      break;
    default:
      break;
  }
  
  /* Parity bit selection */
  switch (config->parity)
  {
    case (UART_PARITY_DISABLE):
      BIT_CLEAR(*CONTROL_STATUS_C_REG[port], UPM00);
      BIT_CLEAR(*CONTROL_STATUS_C_REG[port], UPM01);
      break;
    case (UART_PARITY_EVEN):
      BIT_CLEAR(*CONTROL_STATUS_C_REG[port], UPM00);
      BIT_SET  (*CONTROL_STATUS_C_REG[port], UPM01);
      break;
    case (UART_PARITY_ODD):
      BIT_SET(*CONTROL_STATUS_C_REG[port], UPM00);
      BIT_SET(*CONTROL_STATUS_C_REG[port], UPM01);
      break;
    default:
      break;
  }
  
  /* Baud rate calculation */
  baudRegValue = BAUD_REG_NORMAL_CALC(config->baudRate);
  
  REG_WRITE(*BAUDRATE_L_REG[port], baudRegValue);
  REG_WRITE(*BAUDRATE_H_REG[port], baudRegValue >> 8);
}

void
UART_Write(UartChannel_et uart, uint8_t data)
{
  UartConfig_st cfg;
  
  memcpy_P(&cfg, &_channelConfigList[uart], sizeof(cfg));
  while ( BIT_IS_CLEAR(*CONTROL_STATUS_A_REG[cfg.port], UDRE0) );
  REG_WRITE(*DATA_REGISTOR[cfg.port], data);
}

status_et
UART_Read(UartChannel_et uart, uint8_t *data, time_t timeout)
{
  UartConfig_st cfg;
  
  memcpy_P(&cfg, &_channelConfigList[uart], sizeof(cfg));
  while ( BIT_IS_CLEAR(*CONTROL_STATUS_A_REG[cfg.port], RXC0) );
  *data = (uint8_t)*DATA_REGISTOR[cfg.port];
  return 0;
}

void
UART_Transfer(UartChannel_et uart, uint8_t *data, uint32_t size)
{
  int32_t i_i32;
  UartConfig_st cfg;
  
  memcpy_P(&cfg, &_channelConfigList[uart], sizeof(cfg));
  
  for (i_i32 = 0; i_i32 < size; i_i32++)
  {
    while ( BIT_IS_CLEAR(*CONTROL_STATUS_A_REG[cfg.port], UDRE0) );
    REG_WRITE(*DATA_REGISTOR[cfg.port], data[i_i32]);
  }
}

status_et
UART_Receive(UartChannel_et uart, uint8_t *data, uint32_t size, time_t timeout)
{
  int32_t i_i32;
  UartConfig_st cfg;
  
  memcpy_P(&cfg, &_channelConfigList[uart], sizeof(cfg));
  for (i_i32 = 0; i_i32 < size; i_i32++)
  {
    while ( BIT_IS_CLEAR(*CONTROL_STATUS_A_REG[cfg.port], RXC0) );
    data[i_i32] = (uint8_t)*DATA_REGISTOR[cfg.port];
  }
  return 0;
}


void
UART_Interrupt(UartChannel_et uart, UartIntrpt_et intrpt, bool_et enable)
{
  UartConfig_st cfg;
  
  memcpy_P(&cfg, &_channelConfigList[uart], sizeof(cfg));
 
  switch (intrpt)
  {
    case UART_IRQ_RX:
      BIT_WRITE(*CONTROL_STATUS_B_REG[cfg.port], RXCIE0, enable);
      break;
    case UART_IRQ_TX:
      BIT_WRITE(*CONTROL_STATUS_B_REG[cfg.port], TXCIE0, enable);
      break;
    case UART_IRQ_TX_BUF_EMPTY:
      BIT_WRITE(*CONTROL_STATUS_B_REG[cfg.port], UDRIE0, enable);
      break;
    default:
      break;
  }
}

bool_et
UART_InterruptGet(UartChannel_et uart, UartIntrpt_et intrpt)
{
  UartConfig_st cfg;
  
  memcpy_P(&cfg, &_channelConfigList[uart], sizeof(cfg));
 
  switch (intrpt)
  {
    case UART_IRQ_RX:
      return BIT_IS_SET(*CONTROL_STATUS_A_REG[cfg.port], RXC0);
      break;
    case UART_IRQ_TX:
      return BIT_IS_SET(*CONTROL_STATUS_A_REG[cfg.port], TXC0);
      break;
    case UART_IRQ_TX_BUF_EMPTY:
      return BIT_IS_SET(*CONTROL_STATUS_A_REG[cfg.port], UDR0);
      break;
    default:
      break;
  }
  return FALSE;
}

void
UART_InterruptClear(UartChannel_et uart, UartIntrpt_et intrpt)
{
  UartConfig_st cfg;
  
  memcpy_P(&cfg, &_channelConfigList[uart], sizeof(cfg));
 
  switch (intrpt)
  {
    case UART_IRQ_RX:
      BIT_CLEAR(*CONTROL_STATUS_A_REG[cfg.port], RXC0);
      break;
    case UART_IRQ_TX:
      BIT_CLEAR(*CONTROL_STATUS_A_REG[cfg.port], TXC0);
      break;
    case UART_IRQ_TX_BUF_EMPTY:
      BIT_CLEAR(*CONTROL_STATUS_A_REG[cfg.port], UDR0);
      break;
    default:
      break;
  }
}