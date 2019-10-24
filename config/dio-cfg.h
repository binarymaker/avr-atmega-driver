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

#ifndef DIO_715e6b5c_f4a5_11e9_b4bc_705a0f25cb51
#define DIO_715e6b5c_f4a5_11e9_b4bc_705a0f25cb51

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <avr/pgmspace.h>
/* Exported types ------------------------------------------------------------*/
typedef enum
{
  CH0,
  CH1,
  CH2,
  NUM_DIO_CHANNEL
}DioChannel_et;

typedef enum
{
  DIO_PORTB,
  DIO_PORTC,
  DIO_PORTD,
  NUM_DIO_PORTS
}DioPort_et;

typedef enum
{
  DIO_PIN_0,
  DIO_PIN_1,
  DIO_PIN_2,
  DIO_PIN_3,
  DIO_PIN_4,
  DIO_PIN_5,
  DIO_PIN_6,
  DIO_PIN_7,
  NUM_DIO_CHANNEL_PER_PORT
}DioPin_et;

typedef enum
{
  DIO_DIRECTION_INPUT,
  DIO_DIRECTION_OUTPUT,
  NUM_DIO_DIRECTION
}DioDirection_et;

typedef enum
{
  DIO_RESISTOR_PULLUP,
  DIO_RESISTOR_DISABLE,
  NUM_DIO_RESISTOR
}DioResistor_et;

typedef enum
{
  DIO_MODE_GPIO,
  DIO_MODE_ANALOG,
  DIO_MODE_UART,
  DIO_MODE_I2C,
  DIO_MODE_SPI,
  DIO_MODE_PWM,
  NUM_DIO_MODE
}DioMode_et;

typedef enum
{
  DIO_PINSTATE_LOW,
  DIO_PINSTATE_HIGH,
  NUM_DIO_PIN_STATE
}DioPinState_et;

typedef uint8_t DioPortValue_t;

typedef struct
{
  DioPort_et      port      ;
  DioPin_et       pin       ;
  DioDirection_et direction ;
  DioResistor_et  resistor  ;
  DioMode_et      function  ;
  DioPinState_et  pinState  ;
} DioConfig_st;

/* Exported constants --------------------------------------------------------*/
extern const DioConfig_st dioConfig[NUM_DIO_CHANNEL] PROGMEM;
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */


#ifdef __cplusplus
}
#endif

#endif /* DIO_715e6b5c_f4a5_11e9_b4bc_705a0f25cb51 */

