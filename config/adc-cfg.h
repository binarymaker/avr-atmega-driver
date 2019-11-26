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

#ifndef ADC_e082068a_fca2_11e9_ae20_705a0f25cb51
#define ADC_e082068a_fca2_11e9_ae20_705a0f25cb51

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

STATIC_INLINE void
ADC_Config()
{
  /**
   * ADC module activate ------------------------------------------------------
   *            
   *            ADEN 
   * Enable  -  _H_
   * Disable -  _L_
   */
  ADCSRA    =    _H_(ADEN)                                                     ;
  
  /**
   * ADC prescaler selection --------------------------------------------------
   *  clk
   * Divider       ADPS2   |   ADPS1  |   ADPS0
   *   2     -      _L_    |   _L_    |    _L_
   *   2     -      _L_    |   _L_    |    _H_
   *   4     -      _L_    |   _H_    |    _L_
   *   8     -      _L_    |   _H_    |    _H_
   *  16     -      _H_    |   _L_    |    _L_
   *  32     -      _H_    |   _L_    |    _H_
   *  64     -      _H_    |   _H_    |    _L_
   * 128     -      _H_    |   _H_    |    _H_
   */
  ADCSRA   |=    _L_(ADPS2) |   _L_(ADPS1)   |   _L_(ADPS0)                    ;
  
  
  /**
   * ADC result data justify --------------------------------------------------
   *          
   *          ADLAR                  ADCH    ADCL
   * Right  -  _L_             ex: 000000DD DDDDDDDD
   * Left   -  _H_             ex: DDDDDDDD DD000000
   */
  ADMUX     =    _L_(ADLAR)                                                    ;
  
  /**
   * ADC Trigger mode ---------------------------------------------------------
   * 
   *           ADATE 
   * Enable  -  _H_
   * Disable -  _L_
   */
  ADCSRA   |=    _L_(ADATE)                                                    ;
  
  /**
   * ADC Trigger source selection
   *                      ADTS2   |   ADTS1  |   ADTS0
   * Free run       -      _L_    |   _L_    |    _L_
   * Analog cmpr    -      _L_    |   _L_    |    _H_
   * Ext Intrpt 0   -      _L_    |   _H_    |    _L_
   * Tim0 cmpr A    -      _L_    |   _H_    |    _H_
   * Tim0 overflow  -      _H_    |   _L_    |    _L_
   * Tim1 cmpr B    -      _H_    |   _L_    |    _H_
   * Tim1 overflow  -      _H_    |   _H_    |    _L_
   * Tim1 capture   -      _H_    |   _H_    |    _H_
   */
  ADCSRB   |=    _L_(ADTS2)  |   _L_(ADTS1)   |   _L_(ADTS0)                   ;
  
  /**
   * ADC Channel enable / Digital pin disable
   *              
   * Analog pin   -   _H_
   * Digital pin  -   _L_ 
   */
  DIDR0     =   _L_(5) | _L_(4) | _L_(3) | _L_(2) | _L_(1) | _H_(0)            ;
  /**
   * ADC Interrupt activate ---------------------------------------------------
   * 
   *            ADIE 
   * Enable  -  _H_
   * Disable -  _L_
   */
  ADCSRA   |=    _L_(ADIE)                                                     ;

}

#ifdef __cplusplus
}
#endif

#endif /* ADC_e082068a_fca2_11e9_ae20_705a0f25cb51 */

