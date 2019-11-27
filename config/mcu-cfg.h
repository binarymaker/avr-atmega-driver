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

#define F_CPU                                                         8000000UL
   
#define MCU_GPIO_DRIVER                                                 ENABLE   
#define MCU_ADC_DRIVER                                                  DISABLE
#define MCU_UART_DRIVER                                                 DISABLE
#define MCU_I2C_DRIVER                                                  DISABLE
#define MCU_SPI_DRIVER                                                  DISABLE
#define MCU_TIMER0_DRIVER                                               DISABLE
#define MCU_TIMER1_DRIVER                                               DISABLE
#define MCU_TIMER2_DRIVER                                               DISABLE

/* SYSTIMER Driver ############################################################*/
#define MICROSECONDS_PER_SYSTIMER_OVERFLOW                               (2000U)

/* GPIO Driver settings ######################################################*/
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

#define NUM_PIN_PER_PORT                                                      8

void
PIN_MANAGER_Config();

/* ADC Driver #################################################################*/
void
ADC_Config();

/* USART Driver ###############################################################*/
#define USART_BAUDRATE                                                   9600UL
#define USART_PRINTF_REDIRECT
#define USART_BAUD_REG_CALC(baud)        (uint16_t)((F_CPU / (16 * (baud))) - 1)
#define USART_BAUD_REG_2X_CALC(baud)      (uint16_t)((F_CPU / (8 * (baud))) - 1)
void
USART_Config();
/* I2C Driver ################################################################*/
#define I2C_CLOCK_FREQ                                                (400000UL)
#define I2C_STATUS_RETURN                                               DISABLE
/*
 * Passible Prescale values - 1, 4, 16, 64
 * Note: Update respective register bits in I2C_Config() function
 */
#define I2C_PRESCALE                                                       (1UL)
#define I2C_CLOCK_BITRATE_REG_CALC()                                           \
                          ( (F_CPU / (I2C_CLOCK_FREQ * I2C_PRESCALE) - 16 ) / 2)
void
I2C_Config();
/* TIMER0 Driver ###############################################################*/
void
TIMER0_Config();

#ifdef __cplusplus
}
#endif

#endif /* MCU_a1c651d2_fb96_11e9_9e08_0c5b8f279a64 */

