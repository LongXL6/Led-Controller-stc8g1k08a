#include "config.h"
  
/* ΢����ʱ������us-��ʱʱ�� */
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
/* ������ʱ������ms-��ʱʱ�� */
void delay_ms(u16 ms)
{
    while (ms--)
    {
        delay_us(998);
    }
}




