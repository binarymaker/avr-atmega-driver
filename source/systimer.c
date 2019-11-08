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
#include "systimer.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MILLIS_INC                   (MICROSECONDS_PER_SYSTIMER_OVERFLOW / 1000)
#define FRACT_INC              ((MICROSECONDS_PER_SYSTIMER_OVERFLOW % 1000) / 8)
#define FRACT_MAX                                                     (1000 / 8)
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static volatile time_t sysTimerMillis;

#if (FRACT_INC != 0)
static uint8_t sysTimerCalib;
#endif
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void
SYSTIMER_Engin()
{
  time_t millis = sysTimerMillis;

  millis += MILLIS_INC;
  
#if (FRACT_INC != 0)
	sysTimerCalib += FRACT_INC;
	if (sysTimerCalib >= FRACT_MAX) {
		sysTimerCalib -= FRACT_MAX;
		millis += 1;
	}
#endif
  
	sysTimerMillis = millis;
}

time_t
SYSTIMER_Millis()
{
	time_t millis;
	uint8_t oldSREG = SREG; //TODO

	cli(); // TODO
	millis = sysTimerMillis;
	SREG = oldSREG;

	return (millis);
}

void
SYSTIMER_Delay(time_t ms)
{
  time_t start = SYSTIMER_Millis();
  
  while ((SYSTIMER_Millis() - start) < ms );
}