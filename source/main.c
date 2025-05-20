#include "config.h"
#include "ws2812.h"
#include "key.h"



#define BRIGHT 10   

const uint8_t rgb_7c_tab[7][3]={
	{255*BRIGHT/100,0,0},
	{0,255*BRIGHT/100,0},
	{0,0,255*BRIGHT/100},
	{255*BRIGHT/100,0,255*BRIGHT/100},
	{255*BRIGHT/100,255*BRIGHT/100,0},
	{0,255*BRIGHT/100,255*BRIGHT/100},
	{255*BRIGHT/100,255*BRIGHT/100,255*BRIGHT/100},
};

void KeyAction(uint8_t keycode)
{
	u8 i;
	static uint8_t cnt = 0;
	if(++cnt > 7)
	{
		cnt = 0;
	}
	
	for(i=0;i<LedNum;i++)
	{
		SetLedColor(i,rgb_7c_tab[cnt][0],rgb_7c_tab[cnt][1],rgb_7c_tab[cnt][2]);
	}
	LedRefresh(); 

}

void main()
{	 
	u8 i;

	KeyInit();
	WS2812_Init();

	for(i=0;i<LedNum;i++)
	{
		SetLedColor(i,rgb_7c_tab[0][0],rgb_7c_tab[0][1],rgb_7c_tab[0][2]);
	}
	LedRefresh();              				//刷新灯带数据
	while(1)
	{
		KeyDriver();
		delay_ms(5);
	}
}
