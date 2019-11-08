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

#ifndef MCU_a1c651d2_fb96_11e9_9e08_0c5b8f279a64
#define MCU_a1c651d2_fb96_11e9_9e08_0c5b8f279a64

#ifdef __cplusplus
 extern "C" {
#endif

/* Exported constants --------------------------------------------------------*/
#define F_CPU                                                         8000000UL
   
#define MCU_GPIO_DRIVER                                                 ENABLE   
#define MCU_ADC_DRIVER                                                  ENABLE
#define MCU_UART_DRIVER                                                 ENABLE
#define MCU_I2C_DRIVER                                                  ENABLE
#define MCU_SPI_DRIVER                                                  ENABLE
#define MCU_TIMER0_DRIVER                                               ENABLE
#define MCU_TIMER1_DRIVER                                               ENABLE
#define MCU_TIMER2_DRIVER                                               ENABLE

/* Includes ------------------------------------------------------------------*/
#include "mcu.h"
   
#include "pin-manager-cfg.h"
#include "delay-cfg.h"
#include "gpio-cfg.h"
#include "adc-cfg.h"
#include "usart-cfg.h"
#include "i2c-cfg.h"
#include "systimer-cfg.h"
#include "timer0-cfg.h"
/* Exported types ------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */


#ifdef __cplusplus
}
#endif

#endif /* MCU_a1c651d2_fb96_11e9_9e08_0c5b8f279a64 */

