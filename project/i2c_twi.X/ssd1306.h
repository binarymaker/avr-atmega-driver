/* 
 * File:   ssd1306.h
 * Author: |H_e_c_t_o_r|
 *
 * Graphical display OLED 128x64.
 * Driver SSD1306.
 * Interface: I2C.
 * This library can only be used for educational and hobbyist purposes.
 * Website https://www.youtube.com/user/Hector8389/videos
 * 
 * Version 2.0 
 * 
 */

#ifndef SSD1306_H
#define	SSD1306_H

#include "mcu.h"
//==============================================================================
// Connection of module OLED.
//
// VCC         <<<>>> 3.3 V.
// GND         <<<>>> GND.
// OLED_SCL    <<<>>> Connect to SCL MCU.
// OLED_SDA    <<<>>> Connect to SDA MCU.

// OLED_SA0    <<<>>> Connect to 0 or 1. I2C-address
// OLED:RESET  <<<>>> This module hasn't got RESET pin.
//==============================================================================
//#define OLED_12C_ADDRESS    0x7A // If SA0 = 1
#define OLED_12C_ADDRESS    0x7A // If SA0 = 0
#define OLED_ResetPin(x)    GPIO_PinWrite(P_C0, (x))



//==============================================================================
// Those are pages and frames that you can use.
//==============================================================================
#define PAGE0         0
#define PAGE1         1
#define PAGE2         2
#define PAGE3         3
#define PAGE4         4
#define PAGE5         5
#define PAGE6         6
#define PAGE7         7
#define FRAME_2       7
#define FRAME_3       4
#define FRAME_4       5
#define FRAME_5       0
#define FRAME_25      6
#define FRAME_64      1
#define FRAME_128     2
#define FRAME_256     3
#define BLACK         1
#define WHITE         2
#define INVERSE       3


//==============================================================================
// New name for data types.
//==============================================================================
typedef char                     schar;
typedef unsigned char            uchar;
typedef const char               cschar;
typedef const unsigned char      cuchar;
typedef int                      sint;
typedef unsigned int             uint;


//==============================================================================
// Function Prototypes.
//==============================================================================
void Oled_Init(void);
void Oled_Delay(void);
void Oled_Reset(void);
void Oled_Command(uchar cmd);
void Oled_WriteRam(uchar dat);
void Oled_SetPointer(uchar seg, uchar pag);
void Oled_SetFont(cuchar *_font, uchar _width, uchar _height, uchar _min, uchar _max);
void Oled_WriteChar(uchar c, uchar seg, uchar pag);
void Oled_ConstText(cschar *buffer, uchar seg, uchar pag);
void Oled_Text(schar *buffer, uchar seg, uchar pag);
void Oled_ConstTextScroll(cschar *buffer);
void Oled_TextScroll(schar *buffer);
void Oled_ResetScroll(void);
void Oled_FillScreen(uchar pattern);
void Oled_Image(cuchar *buffer);
void Oled_InvertRam(uchar seg1, uchar pag1, uchar seg2, uchar pag2);
void Oled_Icon(cuchar *buffer, uchar seg, uchar pag, uchar _width, uchar _height);
void Oled_Pixel(sint x, sint y, uchar color);
void Oled_Line(uint x1, uint y1, uint x2, uint y2, uchar color);
void Oled_Rectangle(uint x1, uint y1, uint x2, uint y2, uchar color);
void Oled_Circle(uint x1, uint y1, uint radius, uchar color);
void Right_HorizontalScroll(uchar start_page, uchar end_page, uchar set_time);
void Left_HorizontalScroll(uchar start_page, uchar end_page, uchar set_time);
void VerticalRight_HorizontalScroll(uchar start_page, uchar end_page, uchar set_time);
void VerticalLeft_HorizontalScroll(uchar start_page, uchar end_page, uchar set_time);
void Deactivate_Scroll(void);
void Activate_Scroll(void);
#endif	/* SSD1306_H */

