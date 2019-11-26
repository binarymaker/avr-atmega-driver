/* 
 * File:   ssd1306.c
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mcu.h"
#include "ssd1306.h"
#include "delay.h"


//==============================================================================
// Declaration of global variables.
//==============================================================================
cuchar *font, *font2;
uchar width, height, min, max;
uchar Oled_RAM[1024];
uchar cnt_width = 0;
uint cnt_character = 0;


//==============================================================================
// Initializes the OLED module.
//==============================================================================
void Oled_Init(void){
//OLED_ResetPin(0);
Oled_Delay();
//Oled_Reset();
Oled_Command(0xAE);                     // Set Display OFF
Oled_Command(0x81); Oled_Command(0xCF); // Set Contrast Control
Oled_Command(0xA4);                     // Entire Display ON
Oled_Command(0xA6);                     // Set Normal

Oled_Command(0x20); Oled_Command(0x02); // Set Memory Addressing Mode
Oled_Command(0x00);                     // Set Lower Column
Oled_Command(0x10);                     // Set Higher Column
Oled_Command(0xB0);                     // Set Page Start

Oled_Command(0x40);                     // Set Display Start Line
Oled_Command(0xA1);                     // Set Segment Re-map
Oled_Command(0xA8); Oled_Command(0x3F); // Set Multiplex Ratio
Oled_Command(0xC8);                     // Set COM Output
Oled_Command(0xD3); Oled_Command(0x00); // Set Display Offset
Oled_Command(0xDA); Oled_Command(0x12); // Set COM Pins Hardware Configuration

Oled_Command(0xD5); Oled_Command(0x80); // Set Display Clock
Oled_Command(0xD9); Oled_Command(0xF1); // Set Pre-charge Period
Oled_Command(0xDB); Oled_Command(0x40); // Set VCOMH Deselect Level
Oled_Command(0x8D); Oled_Command(0x14); // Charge Pump Setting

Oled_Command(0xAF);                     // Set Display ON
Oled_FillScreen(0x00);                  // Clear screen
}


//==============================================================================
// Delay of 500 ms.
//==============================================================================
void Oled_Delay(void){
uint i;
for(i = 0; i < 500; i++){
  DELAY_ms(1);
}
}


//==============================================================================
// Resets the OLED module.
//==============================================================================
void Oled_Reset(void){
OLED_ResetPin(0);
Oled_Delay(); Oled_Delay();
OLED_ResetPin(1);
Oled_Delay();
}


//==============================================================================
// Writes a command.
//==============================================================================
void Oled_Command(uchar cmd){
I2C_Start();
I2C_Write(OLED_12C_ADDRESS);
I2C_Write(0x00);  // Co = 0, D/C = 0
I2C_Write(cmd);
I2C_Stop();
}


//==============================================================================
// Writes a byte at RAM memory.
//==============================================================================
void Oled_WriteRam(uchar dat){
I2C_Start();
I2C_Write(OLED_12C_ADDRESS);
I2C_Write(0x40);  // Co = 0, D/C = 1
I2C_Write(dat);
I2C_Stop();
}


//==============================================================================
// Sets the pointer in frame memory where MCU can access.
// seg: sets the segment.
// pag: sets the  page.
//==============================================================================
void Oled_SetPointer(uchar seg, uchar pag){
uchar low_column, hig_column;
low_column = (seg & 0b00001111);
hig_column = (seg & 0b11110000)>>4;
hig_column = hig_column | 0b00010000;
pag = (pag & 0b00000111);
pag = (pag | 0b10110000);
Oled_Command(low_column); // Set Lower Column
Oled_Command(hig_column); // Set Higher Column
Oled_Command(pag);        // Set Page Start
}


//==============================================================================
// Sets font that will be used.
// _font: desired font.
// _width: sets the width in units of pixels.
// _height: sets the height in units of pixels. 
// _min: sets the range minimum.
// _max: sets the range maximum.
//
// Note: this library supports only  fonts with multiples of 8 pixels in height.
//==============================================================================
void Oled_SetFont(cuchar *_font, uchar _width, uchar _height, uchar _min, uchar _max){
font2  = _font;
width  = _width;
height = _height / 8;
min    = _min;
max    = _max;
}


//==============================================================================
// Writes a char on the OLED.
// c: char to be written.
// seg: sets the segment. Valid values: 0..127
// pag: sets the page. Valid values: 0..7
//==============================================================================
void Oled_WriteChar(uchar c, uchar seg, uchar pag){
uint i, j;
uint x_seg, y_pag;
x_seg = seg;
y_pag = pag;
font = font2;
j = c - min;
j = j * (width * height);
for(i = 0; i < j; i++){font++;}
for(i = 0; i < width; i++)
   {
    y_pag = pag;
    for(j = 0; j < height; j++)
       {
        if(x_seg < 128)
          {
           Oled_SetPointer(x_seg, y_pag);
           Oled_WriteRam(*font);
           Oled_RAM[x_seg + (y_pag * 128)] = *font;
          }
        y_pag++;
        font++;
       }
    x_seg++;
   }
}


//==============================================================================
// Prints text constant on OLED.
// buffer: text to be written.
// seg: sets the segment. Valid values: 0..127
// pag: sets the page. Valid values: 0..7
//==============================================================================
void Oled_ConstText(cschar *buffer, uchar seg, uchar pag){
uchar x_seg = seg;
while(*buffer)
     {
      Oled_WriteChar(*buffer, x_seg, pag);
      x_seg = x_seg + width;
      buffer++;
     }
}


//==============================================================================
// Prints text variable on OLED.
// buffer: text to be written.
// seg: sets the segment. Valid values: 0..127
// pag: sets the page. Valid values: 0..7
//==============================================================================
void Oled_Text(schar *buffer, uchar seg, uchar pag){
uchar x_seg = seg;
while(*buffer)
     {
      Oled_WriteChar(*buffer, x_seg, pag);
      x_seg = x_seg + width;
      buffer++;
     }
}


//==============================================================================
// Prints text constant on OLED with scroll.
// buffer: text to be written.
//==============================================================================
void Oled_ConstTextScroll(cschar *buffer){
uint i;
cnt_width++;
if(cnt_character == strlen(buffer))
   {
    cnt_character = 0;
   }
if(cnt_width == width)
  {
   for(i = 0; i < cnt_character; i++)
      {
       buffer++;
      }  
   Oled_WriteChar(*buffer, 127 - width, 0);   
   cnt_character++;
   cnt_width = 0; 
  }
Oled_SetPointer(0, 0);
for(i = 0; i < 127; i++)
   {
    Oled_RAM[i] = Oled_RAM[i+1];
    Oled_WriteRam(Oled_RAM[i]);
   } 
Oled_SetPointer(0, 1);
for(i = 128; i < 255; i++)
   {
    Oled_RAM[i] = Oled_RAM[i+1];
    Oled_WriteRam(Oled_RAM[i]);
   }
}


//==============================================================================
// Prints text variable on OLED with scroll.
// buffer: text to be written.
//==============================================================================
void Oled_TextScroll(schar *buffer){
uint i;
cnt_width++;
if(cnt_character == strlen(buffer))
   {
    cnt_character = 0;
   }
if(cnt_width == width)
  {
   for(i = 0; i < cnt_character; i++)
      {
       buffer++;
      }  
   Oled_WriteChar(*buffer, 127 - width, 0);   
   cnt_character++;
   cnt_width = 0; 
  }
Oled_SetPointer(0, 0);
for(i = 0; i < 127; i++)
   {
    Oled_RAM[i] = Oled_RAM[i+1];
    Oled_WriteRam(Oled_RAM[i]);
   } 
Oled_SetPointer(0, 1);
for(i = 128; i < 255; i++)
   {
    Oled_RAM[i] = Oled_RAM[i+1];
    Oled_WriteRam(Oled_RAM[i]);
   }
}


//==============================================================================
// Resets the scroll.
// This function must be called before of a new scroll function.
//==============================================================================
void Oled_ResetScroll(void){
cnt_width = 0;
cnt_character = 0;
}


//==============================================================================
// Fills OLED memory.
// pattern: byte to fill OLED memory.
//==============================================================================
void Oled_FillScreen(uchar pattern){
uchar i, j;
uint k = 0;
for(i = 0; i < 8; i++)
   {
    Oled_SetPointer(0, i);
    for(j = 0; j < 128; j++)
       {
        Oled_WriteRam(pattern);
        Oled_RAM[k] = pattern;
        k++;
       }
   }
}


//==============================================================================
// Displays bitmap on OLED.
// buffer: image to be displayed.
//==============================================================================
void Oled_Image(cuchar *buffer){
uchar i, j;
uint k = 0;
for(i = 0; i < 8; i++)
   {
    Oled_SetPointer(0, i);
    for(j = 0; j < 128; j++)
       {
        Oled_WriteRam(*buffer);
        Oled_RAM[k] = *buffer;
        buffer++;
        k++;
       }
   }
}


//==============================================================================
// Displays an image on a desired location.
// buffer: image to be displayed.
// seg: sets the segment. Valid values: 0..127
// pag: sets the page. Valid values: 0..7
// _width sets the width of the image.
// _height sets the height of the image.
//==============================================================================
void Oled_Icon(cuchar *buffer, uchar seg, uchar pag, uchar _width, uchar _height){
uchar i, j;
uint x_seg, y_pag;
y_pag = pag;
for(i = 0; i < _height / 8; i++)
   {
    x_seg = seg;
    for(j = 0; j < _width; j++)
       {
        if(x_seg < 128)
          {
           Oled_SetPointer(x_seg, y_pag);
           Oled_WriteRam(*buffer);
           Oled_RAM[x_seg + (y_pag * 128)] = *buffer;
          }
        buffer++;
        x_seg++;
       }
    y_pag++;
   }          
}


//==============================================================================
// Inverts the RAM memory.
// seg1 sets the start segment. Valid values: 0..127
// pag1 sets the start page. Valid values: 0..7
// seg2 sets the end segment. Valid values: 0..127
// pag2 sets the end page. Valid values: 0..7
//==============================================================================
void Oled_InvertRam(uchar seg1, uchar pag1, uchar seg2, uchar pag2){
uint i, j, k;
for(i = pag1; i <= pag2; i++)
   {
    for(j = seg1; j <= seg2; j++)
       {
        k = j + (i * 128);
        Oled_RAM[k] = ~Oled_RAM[k];
        Oled_SetPointer(j, i);
        Oled_WriteRam(Oled_RAM[k]);
       }
   }
}


//==============================================================================
// Draws a Pixel on OLED.
// x: x position. Valid values: 0..127 
// y: y position. Valid values: 0..63 
// color: color parameter. Valid values: 1,2,3 
//==============================================================================
void Oled_Pixel(sint x, sint y, uchar color){
if((x < 0) || (x > 127) || (y < 0) || (y > 63)){return;}  
Oled_SetPointer(x, y/8);    
switch(color)
      {
       case 1: Oled_WriteRam(Oled_RAM[x+((y/8)*128)] |=  (1<<(y%8))); break;
       case 2: Oled_WriteRam(Oled_RAM[x+((y/8)*128)] &= ~(1<<(y%8))); break;
       case 3: Oled_WriteRam(Oled_RAM[x+((y/8)*128)] ^=  (1<<(y%8))); break;
      }
}


//==============================================================================
// Draws a Line on OLED.
//
// Bresenham algorithm.
// 
// x1: x coordinate of the line start. Valid values: 0..127
// y1: y coordinate of the line start. Valid values: 0..63 
// x2: x coordinate of the line end. Valid values: 0..127 
// y2: y coordinate of the line end. Valid values: 0..63 
// color: color parameter. Valid values: 1,2,3 
//==============================================================================
void Oled_Line(uint x1, uint y1, uint x2, uint y2, uchar color){
sint i;
sint longest, shortest; 
sint numerator;
sint w = x2 - x1;
sint h = y2 - y1;
sint dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;

if(w < 0) dx1 = -1; else if(w > 0) dx1 = 1;
if(h < 0) dy1 = -1; else if(h > 0) dy1 = 1;
if(w < 0) dx2 = -1; else if(w > 0) dx2 = 1;
if(w < 0) w *= -1;
if(h < 0) h *= -1;
longest = w; 
shortest = h;
if(!(longest > shortest)) 
  {//if(w < 0) w *= -1; //if(h < 0) h *= -1; 
   longest = h; 
   shortest = w;
   if(h < 0) dy2 = -1; else if(h > 0) dy2 = 1;
   dx2 = 0;         
  }
numerator = longest >> 1;
for (i = 0; i <= longest; i++)
    {
     Oled_Pixel(x1, y1, color);
     numerator += shortest;
     if(!(numerator < longest)) 
       {
        numerator -= longest;
        x1 += dx1;
        y1 += dy1;
       }else
       {
        x1 += dx2;
        y1 += dy2;
       }
    }
}


//==============================================================================
// Draws a rectangle on Display.
// x1: x coordinate of the upper left rectangle corner. Valid values: 0..127  
// y1: y coordinate of the upper left rectangle corner. Valid values: 0..63 
// x2: x coordinate of the lower right rectangle corner. Valid values: 0..127 
// y2: y coordinate of the lower right rectangle corner. Valid values: 0..63 
// color: color parameter. Valid values: 1,2,3 
//==============================================================================
void Oled_Rectangle(uint x1, uint y1, uint x2, uint y2, uchar color){
Oled_Line(x1, y1, x2, y1, color);
Oled_Line(x1, y2, x2, y2, color);
Oled_Line(x1, y1, x1, y2, color);
Oled_Line(x2, y1, x2, y2, color);
}


//==============================================================================
// Draws a circle on Display.
//
// Midpoint circle algorithm.
//
// x1: x coordinate of the circle center. Valid values: 0..127
// y1: y coordinate of the circle center. Valid values: 0..63
// radius: radius size
// color: color parameter. Valid values: 1,2,3 
//==============================================================================
void Oled_Circle(uint x1, uint y1, uint radius, uchar color){
sint x = radius, y = 0;
sint radiusError = 1 - x;

while(x >= y)
     {
      Oled_Pixel(x + x1, y + y1, color);
      Oled_Pixel(y + x1, x + y1, color);
      Oled_Pixel(-x + x1, y + y1, color);
      Oled_Pixel(-y + x1, x + y1, color);
      Oled_Pixel(-x + x1, -y + y1, color);
      Oled_Pixel(-y + x1, -x + y1, color);
      Oled_Pixel(x + x1, -y + y1, color);
      Oled_Pixel(y + x1, -x + y1, color);
      y++;
      if(radiusError<0)
        {
         radiusError += 2 * y + 1;
        }else
        {
         x--;
         radiusError += 2 * (y - x + 1);
        }
     }
}


//==============================================================================
// Sets the scroll. 
// start_page: Sets the start page. Valid values: 0..7
// end_page: Sets the end page. Valid values: 0..7
// set_time: sets time. Valid values: 0..7
//==============================================================================
void Right_HorizontalScroll(uchar start_page, uchar end_page, uchar set_time){
Deactivate_Scroll();
Oled_Command(0x26);
Oled_Command(0x00);
Oled_Command(start_page);
Oled_Command(set_time);
Oled_Command(end_page);
Oled_Command(0x00);
Oled_Command(0xFF);
Activate_Scroll();
}

void Left_HorizontalScroll(uchar start_page, uchar end_page, uchar set_time){
Deactivate_Scroll();
Oled_Command(0x27);
Oled_Command(0x00);
Oled_Command(start_page);
Oled_Command(set_time);
Oled_Command(end_page);
Oled_Command(0x00);
Oled_Command(0xFF);
Activate_Scroll();
}

void VerticalRight_HorizontalScroll(uchar start_page, uchar end_page, uchar set_time){
Deactivate_Scroll();
Oled_Command(0x29);
Oled_Command(0x00);
Oled_Command(start_page);
Oled_Command(set_time);
Oled_Command(end_page);
Oled_Command(0x01); //scrolling_offset
Activate_Scroll();
}

void VerticalLeft_HorizontalScroll(uchar start_page, uchar end_page, uchar set_time){
Deactivate_Scroll();
Oled_Command(0x2A);
Oled_Command(0x00);
Oled_Command(start_page);
Oled_Command(set_time);
Oled_Command(end_page);
Oled_Command(0x01); //scrolling_offset
Activate_Scroll();
}

void Deactivate_Scroll(void){
Oled_Command(0x2E);
}

void Activate_Scroll(void){
Oled_Command(0x2F);
}