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

#ifndef UART_68cebc5c_fa05_11e9_9f4d_0c5b8f279a64
#define UART_68cebc5c_fa05_11e9_9f4d_0c5b8f279a64

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * \brief Source file version tag
 *        
 *        version info: [15:8] main [7:0] beta
 */
#define __UART_VERSION      (0x0001u)

/* Includes ------------------------------------------------------------------*/
#include "uart-cfg.h"
#include "common-def.h"
#include "stdint.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void
UART_Init(const UartConfig_st * const config);

void
UART_ChannelConfig(const UartConfig_st * const config);

void
UART_Write(UartChannel_et uart, uint8_t data);

status_et
UART_Read(UartChannel_et uart, uint8_t *data, time_t timeout);

void
UART_Transfer(UartChannel_et uart, uint8_t *data, uint32_t size);

status_et
UART_Receive(UartChannel_et uart, uint8_t *data, uint32_t size, time_t timeout);

void
UART_Interrupt(UartChannel_et uart, UartIntrpt_et intrpt, bool_et enable);

bool_et
UART_InterruptGet(UartChannel_et uart, UartIntrpt_et intrpt);

void
UART_InterruptClear(UartChannel_et uart, UartIntrpt_et intrpt);

#ifdef __cplusplus
}
#endif

#endif /* UART_68cebc5c_fa05_11e9_9f4d_0c5b8f279a64 */

