#include "config.h"
  
/* 微秒延时函数，us-延时时间 */
void delay_us(u16 us)
{
	while (us--)
	{
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
	}
}
/* 毫秒延时函数，ms-延时时间 */
void delay_ms(u16 ms)
{
    while (ms--)
    {
        delay_us(998);
    }
}




