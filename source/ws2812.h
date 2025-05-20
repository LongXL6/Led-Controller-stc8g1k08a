#ifndef __WS2812_H
#define __WS2812_H

#include"config.h"

#define LedNum  50  //36¸öLEDµÆ 

void LedRefresh(void);
void WS2812_Init(void);
void SetLedColor(u8 ledx,u8 r,u8 g,u8 b);
void SetLedHSVColor(u8 ledx,u16 h,u8 s,u8 v);
void HSVtoRGB(u8 *r, u8 *g, u8 *b, u16 h, u8 s, u8 v);


#endif
