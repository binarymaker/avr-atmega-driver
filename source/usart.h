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

#ifndef USART_b5b53152_fb96_11e9_ba51_0c5b8f279a64
#define USART_b5b53152_fb96_11e9_ba51_0c5b8f279a64

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * \brief Source file version tag
 *        
 *        version info: [15:8] main [7:0] beta
 */
#define __USART_VERSION      (0x0001u)

/* Includes ------------------------------------------------------------------*/
#include "mcu.h"

#if defined(USART_PRINTF_REDIRECT)
#include "print.h"
#endif

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#if defined(USART_PRINTF_REDIRECT)
#define USART_Printf(_F, ...)  {                                           \
                                PRINT_ChannelSelect(PRINT_CHANNEL_USART);  \
                                PRINT_Printf((_F), __VA_ARGS__);           \
                               }
#else
#define USART_Printf(_F, ...)
#warning (Printf not implimeted)            
#endif
/* Exported functions ------------------------------------------------------- */

void
USART_Write(uint8_t ch);

uint8_t
USART_Read();


#ifdef __cplusplus
}
#endif

#endif /* USART_b5b53152_fb96_11e9_ba51_0c5b8f279a64 */

