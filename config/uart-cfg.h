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

#ifndef UART_68f839f0_fa05_11e9_a26e_0c5b8f279a64
#define UART_68f839f0_fa05_11e9_a26e_0c5b8f279a64

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include <avr/pgmspace.h>
/* Exported types ------------------------------------------------------------*/
typedef enum
{
  UART_CH_0,
  NUM_UART_CHANNEL
}UartChannel_et;

typedef enum
{
  UART0,
  NUM_UART_PORTS
}UartPort_et;

typedef enum
{
  UART_BAUDRATE_110,
  UART_BAUDRATE_300,
  UART_BAUDRATE_600,
  UART_BAUDRATE_1200,
  UART_BAUDRATE_2400,
  UART_BAUDRATE_4800,
  UART_BAUDRATE_9600,
  UART_BAUDRATE_14400,
  UART_BAUDRATE_19200,
  UART_BAUDRATE_38400,
  UART_BAUDRATE_57600,
  UART_BAUDRATE_115200,
  UART_BAUDRATE_128000,
  UART_BAUDRATE_256000,
  NUM_UART_BAUDRATE
}UartBaudRate_et;

typedef enum
{
  UART_DATABITS_5,
  UART_DATABITS_6,
  UART_DATABITS_7,
  UART_DATABITS_8,
  UART_DATABITS_9,
  NUM_UART_DATABITS
}UartDataBits_et;

typedef enum
{
  UART_STOPBITS_1,
  UART_STOPBITS_2,
  NUM_UART_STOPBITS
}UartStopBits_et;

typedef enum
{
  UART_PARITY_DISABLE,
  UART_PARITY_EVEN,
  UART_PARITY_ODD,
  NUM_UART_PARITY
}UartParity_et;

typedef enum
{
  UART_COM_MODE_TRANSMIT_ONLY,
  UART_COM_MODE_RECEIVE_ONLY,
  UART_COM_MODE_TRANSMIT_RECEIVE,
  NUM_UART_MODE
}UartComMode_et;

typedef struct 
{
  UartPort_et     port     ;
  uint32_t        baudRate ;
  UartDataBits_et dataBits ;
  UartStopBits_et stopBits ;
  UartParity_et   parity   ;
  UartComMode_et  comMode  ;
}UartConfig_st;

/* Exported constants --------------------------------------------------------*/
extern const UartConfig_st uartConfig[NUM_UART_CHANNEL] PROGMEM;
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */


#ifdef __cplusplus
}
#endif

#endif /* UART_68f839f0_fa05_11e9_a26e_0c5b8f279a64 */

