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

#ifndef PIN_MANAGER_262a4022_fb96_11e9_9a66_0c5b8f279a64
#define PIN_MANAGER_262a4022_fb96_11e9_9a66_0c5b8f279a64

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
typedef enum
{
  P_A0, P_A1, P_A2, P_A3, P_A4, P_A5, P_A6, P_A7,
  P_B0, P_B1, P_B2, P_B3, P_B4, P_B5, P_B6, P_B7,
  P_C0, P_C1, P_C2, P_C3, P_C4, P_C5, P_C6, P_C7,
  P_D0, P_D1, P_D2, P_D3, P_D4, P_D5, P_D6, P_D7,
  P_NC = 0xff
}pin_et;
/* Exported constants --------------------------------------------------------*/
#define NUM_PIN_PER_PORT                                                      8
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void
PIN_MANAGER_Config();

#ifdef __cplusplus
}
#endif

#endif /* PIN_MANAGER_262a4022_fb96_11e9_9a66_0c5b8f279a64 */

