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
#include "mcu.h"
#include "delay.h"
#include "gpio.h"
#include "usart.h"
#include "print.h"
#include "adc.h"
#include "i2c.h"
#include "ssd1306.h"
#include "font.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
int i;
int
main()
{
  uint8_t data[5] = {1, 2, 3, 4, 5};
  
  PIN_MANAGER_Config();
  I2C_Config();

  DELAY_ms(100);
  
  
  I2C_Transmit(0x01, 0x40, data, 5);
  I2C_Receive(0x01, 0x40, data, 5);
 /* for (i = 0; i < 128; i++)
  {
    I2C_Start();
    I2C_Write(i);
    I2C_Stop();
    DELAY_ms(100);
  }*/
 
  Oled_Init();
  Oled_SetFont(Font_6x8, 6, 8, 32,127);
  Oled_ConstText("library for", 0, 0);
  Oled_ConstText("Graphic", 0, 2);
  Oled_ConstText("OLED 128x64", 0, 4);
  Oled_ConstText("SSD1306", 0, 6);
  while(1);

  return 0;
}
