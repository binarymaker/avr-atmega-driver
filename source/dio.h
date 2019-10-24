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

#ifndef DIO_7131a280_f4a5_11e9_a451_705a0f25cb51
#define DIO_7131a280_f4a5_11e9_a451_705a0f25cb51

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * \brief Source file version tag
 *        
 *        version info: [15:8] main [7:0] beta
 */
#define __DIO_VERSION      (0x0001u)

/* Includes ------------------------------------------------------------------*/
#include "dio-cfg.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Configuration Settings ####################################################*/
void
DIO_Init(const DioConfig_st * const config);

void
DIO_ChannelConfig(const DioConfig_st * const config);


/* Access functions ##########################################################*/
void
DIO_ChannelWrite(DioChannel_et channel, DioPinState_et pinState);

DioPinState_et
DIO_ChannelRead(DioChannel_et chennal);

void
Dio_ChannelToggle(DioChannel_et channel);

#ifdef __cplusplus
}
#endif

#endif /* DIO_7131a280_f4a5_11e9_a451_705a0f25cb51 */

