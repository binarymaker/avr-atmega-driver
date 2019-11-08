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

#ifndef TIMER0_52630038_011d_11ea_a9d0_74dfbf0d835a
#define TIMER0_52630038_011d_11ea_a9d0_74dfbf0d835a

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * \brief Source file version tag
 *        
 *        version info: [15:8] main [7:0] beta
 */
#define __TIMER0_VERSION      (0x0001u)

/* Includes ------------------------------------------------------------------*/
#include "mcu.h"
#include "mcu-cfg.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void
TIMER0_Start();

void
TIMER0_Stop();

void
TIMER0_Write(uint8_t cnt);

uint8_t
TIMER0_Read();

void
TIMER0_Reload();

#ifdef __cplusplus
}
#endif

#endif /* TIMER0_52630038_011d_11ea_a9d0_74dfbf0d835a */

