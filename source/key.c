#include "key.h"
#include "config.h"

sbit KEY1 = P3^2;


typedef struct
{
	uint8_t btn_st:1;
	uint8_t last_st:1;
	uint8_t count:6;

} button_ctl_t;

button_ctl_t button_ctl[1] = {0};

extern void KeyAction(uint8_t keycode);
/* 按键驱动函数，检测按键动作，调度相应动作函数，需在主循环中调用 */
void KeyDriver()
{
	uint8_t i;
	bit io_sta;
	for (i = 0; i < 1; i++)
	{
		switch(i)
		{
			case 0:io_sta = KEY1;break;
//			case 1:io_sta = KEY2;break;
//			case 2:io_sta = KEY3;break;
			default:break;
		}
		if(io_sta != button_ctl[i].btn_st)
		{
			button_ctl[i].count = 0;
			button_ctl[i].btn_st = io_sta;
		}
		else if(button_ctl[i].count < 20)
		{
			button_ctl[i].count++;
		}
		else
		{
			if(button_ctl[i].btn_st != button_ctl[i].last_st)
			{
				button_ctl[i].last_st = button_ctl[i].btn_st;
				if (button_ctl[i].btn_st == 0)
				{
					KeyAction(i); //调用按键动作函数
				}
				
			}
		}
	}

}

void  KeyInit()
{
	P3M0 &= ~0x04;	
	P3M1 &= ~0x04;
}