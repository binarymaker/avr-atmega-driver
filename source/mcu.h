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

#ifndef MCU_6f1bc99a_fa32_11e9_8b64_0c5b8f279a64
#define MCU_6f1bc99a_fa32_11e9_8b64_0c5b8f279a64

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
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* MCU Code frequency */
#define F_CPU                                                           8000000
/* Exported macro ------------------------------------------------------------*/
#define GLOBAL_INTERRUPT_ENABLE()                                         sei()
#define GLOBAL_INTERRUPT_DISABLE()                                        cli()
/* Exported functions ------------------------------------------------------- */


#ifdef __cplusplus
}
#endif

#endif /* MCU_6f1bc99a_fa32_11e9_8b64_0c5b8f279a64 */

