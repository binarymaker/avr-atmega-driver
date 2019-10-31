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

#ifndef ISR_d43376ec_fa3e_11e9_bab6_0c5b8f279a64
#define ISR_d43376ec_fa3e_11e9_bab6_0c5b8f279a64

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * \brief Source file version tag
 *        
 *        version info: [15:8] main [7:0] beta
 */
#define __ISR_VERSION      (0x0001u)

/* Includes ------------------------------------------------------------------*/
#include <avr/interrupt.h>
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

ISR(USART_RX_vect);

#ifdef __cplusplus
}
#endif

#endif /* ISR_d43376ec_fa3e_11e9_bab6_0c5b8f279a64 */

