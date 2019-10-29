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

#define F_CPU 8000000

/* Includes ------------------------------------------------------------------*/
#include <avr/io.h>
#include <util/delay.h>
#include "dio.h"
#include "dio-cfg.h"
#include "uart.h"
#include "uart-cfg.h"
#include "regctrl.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

int
main()
{
  uint8_t ctrlBit;
  uint8_t lastCtrlBit = 0;
  
  DIO_Init(dioConfig);
  UART_Init(uartConfig);
  UART_Transfer(UART_CH_0, (uint8_t*)"UART Program \n\r", 15);
  UART_Transfer(UART_CH_0, (uint8_t*)"Press key '1' for ON '0' for OFF \n\r", 35);
  while(1)
  {
    UART_Read(UART_CH_0, &ctrlBit, 1000);
    
    if (lastCtrlBit != ctrlBit)
    {
      lastCtrlBit = ctrlBit;
      UART_Transfer(UART_CH_0, (uint8_t*)"Pressed key is ", 15);
      UART_Write(UART_CH_0, ctrlBit);
      UART_Transfer(UART_CH_0, (uint8_t*)"\n\r", 2);
      if ('1' == ctrlBit){
        DIO_ChannelWrite(CH0, DIO_PINSTATE_HIGH);
      }else{
        DIO_ChannelWrite(CH0, DIO_PINSTATE_LOW);
      }
    }
  }
  return 0;
}
