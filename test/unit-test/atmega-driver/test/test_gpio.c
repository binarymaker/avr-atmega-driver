/**
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
  */

#include "unity.h"
#include "mcu.h"

#include "mcu-cfg.h"
#include "gpio.h"

void
setUp()
{
  PORTB = 0x00;
}

void
tearDown()
{

}

void
test_PORTB_pin0_write_high()
{
  GPIO_PinWrite(P_B0, HIGH);
  TEST_ASSERT_EQUAL_UINT8(1, PORTB);
}

void
test_PORTB_pin2_write_high()
{
  GPIO_PinWrite(P_B2, HIGH);
  TEST_ASSERT_EQUAL_UINT8(BIT(2), PORTB);
}


