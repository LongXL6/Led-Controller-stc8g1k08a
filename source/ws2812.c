#include "ws2812.h"
	
sbit WS2812_IO = P3^3;			 //WS2812���ݿ�
u8 xdata LED_BYTE_Buffer[LedNum][3];  

/*HSVתRGB���� *r *g *b:rgb������ַָ�룻hɫ��0~359 s���Ͷ�0~100, v����0~100*/
void HSVtoRGB(u8 *r, u8 *g, u8 *b, u16 h, u8 s, u8 v)
{
	u8  i;
	u16  difs;
	float RGB_min,RGB_max,RGB_Adj;

	RGB_max = v*2.55f;
	RGB_min = RGB_max*(100 - s) / 100.0f;

	i = h / 60;
	difs = h % 60; 	 
	RGB_Adj = (RGB_max - RGB_min)*difs / 60.0f; 

	switch (i) {
	case 0:
		*r = RGB_max;
		*g = RGB_min + RGB_Adj;
		*b = RGB_min;
		break;
	case 1:
		*r = RGB_max - RGB_Adj;
		*g = RGB_max;
		*b = RGB_min;
		break;
	case 2:
		*r = RGB_min;
		*g = RGB_max;
		*b = RGB_min + RGB_Adj;
		break;
	case 3:
		*r = RGB_min;
		*g = RGB_max - RGB_Adj;
		*b = RGB_max;
		break;
	case 4:
		*r = RGB_min + RGB_Adj;
		*g = RGB_min;
		*b = RGB_max;
		break;
	default:		
		*r = RGB_max;
		*g = RGB_min;
		*b = RGB_max - RGB_Adj;
		break;
	}
}
/*����LED����ɫ������ledx������λ��0~N r:��ɫ����0~255 g:��ɫ����0~255 b:��ɫ����0~255*/
void SetLedColor(u8 ledx,u8 r,u8 g,u8 b)
{
	LED_BYTE_Buffer[ledx][0] = g;
	LED_BYTE_Buffer[ledx][1] = r;
	LED_BYTE_Buffer[ledx][2] = b;
}
/*HSVģ������LED����ɫ������ledx������λ��0~N h:ɫ��0~359 s:���Ͷ�0~100 v:����0~100*/
void SetLedHSVColor(u8 ledx,u16 h,u8 s,u8 v)
{  
	//����HSVתRGB�����������rgbֵ ������������
   HSVtoRGB(&LED_BYTE_Buffer[ledx][1], &LED_BYTE_Buffer[ledx][0], &LED_BYTE_Buffer[ledx][2], h, s,v);  	
}
/*ˢ��LED�����ݺ���*/
void LedRefresh(void)
{
	u8 i,j,k,dat;
	EA = 0;		  						//���жϣ���ֹ�жϸ��ŵ���ʱ�����
	for(k = 0; k < LedNum; k++)     	//�������е�������
	{
		for(j = 0; j < 3; j++)  		//����RGB�����ֽ�
		{
			dat = LED_BYTE_Buffer[k][j];
			for(i = 0; i < 8; i++)       //����8��λ
			{
				WS2812_IO = 1;
				_nop_();_nop_();_nop_();_nop_();_nop_();
				_nop_();_nop_();_nop_();_nop_();
				WS2812_IO = (dat & 0x80);	
				_nop_();_nop_();_nop_();_nop_();_nop_();
				_nop_();_nop_();_nop_();_nop_();_nop_();
				_nop_();_nop_();
				dat <<= 1;
				WS2812_IO = 0;
				_nop_();_nop_();_nop_();_nop_();
				_nop_();
			}
		}
	}
	EA = 1;
}	
/*WS2812��ʼ������*/
void WS2812_Init(void)
{
	u8 i;

	WS2812_IO = 0;			  
	P3M0 &=0xF7;		     //P3.3ǿ�������
	P3M1 &=0xF7;
 
	for(i=0;i<LedNum;i++)	 //��ʼ��Ϊ0��Ϩ������LED
	{
		 SetLedColor(i,0,0,0);
	}
	 LedRefresh();
}

