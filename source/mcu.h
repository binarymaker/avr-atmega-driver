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

#ifndef MCU_a1c3b80c_fb96_11e9_887f_0c5b8f279a64
#define MCU_a1c3b80c_fb96_11e9_887f_0c5b8f279a64

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * \brief Source file version tag
 *        
 *        version info: [15:8] main [7:0] beta
 */
#define __MCU_VERSION      (0x0001u)

/* Includes ------------------------------------------------------------------*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "stdint.h"
#include "mcu-cfg.h"
#include "regctrl.h"
#include "common-def.h"
#include "complier-cfg.h"
#include "delay.h"

#if MCU_GPIO_DRIVER == ENABLE
#include "gpio.h"
#endif

#if MCU_UART_DRIVER == ENABLE
#include "usart.h"
#endif

#if MCU_ADC_DRIVER == ENABLE
#include "adc.h"
#endif

#if MCU_I2C_DRIVER == ENABLE
#include "i2c.h"
#endif

#if MCU_SPI_DRIVER == ENABLE
#endif 
   
#if MCU_TIMER0_DRIVER == ENABLE
#include "timer0.h"
#endif 

#include "systimer.h"
#if MCU_TIMER1_DRIVER == ENABLE
#endif 

#if MCU_TIMER2_DRIVER == ENABLE
#endif 

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define CLOCK_CYCLE_PER_MICROSECOND()                          (F_CPU / 1000000)
#define CLOCK_CYCLE_TO_MICROSECONDS(clk) ((clk) / CLOCK_CYCLE_PER_MICROSECOND())
#define MICROSECONDS_TO_CLOCK_CYCLE(us)   ((us) * CLOCK_CYCLE_PER_MICROSECOND())

#define _L_(pin)                                                            (0u)
#define _H_(pin)                                                      BIT((pin))
#define _I_(pin)                                                            (0u)
#define _O_(pin)                                                      BIT((pin))
/* Exported functions ------------------------------------------------------- */
void
MCU_Init();

#ifdef __cplusplus
}
#endif

#endif /* MCU_a1c3b80c_fb96_11e9_887f_0c5b8f279a64 */

