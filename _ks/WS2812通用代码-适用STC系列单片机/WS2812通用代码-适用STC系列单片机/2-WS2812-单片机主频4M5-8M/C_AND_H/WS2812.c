#include<all.h>
u8 WS2812_BUffer[WSCOUNT][3];
//u8 code light=30;
void WS2812_write_date()
{
		u8 j,k,a;
#if WSCASE>=9	
bit b0,b1,b2,b3,b4,b5,b6,b7;
#endif
 		for(k=0;k<WSCOUNT;k++)
		{
				for(j=0;j<3;j++)
				{
					/*	switch(j)
						{
							case 0:a=WS2812_BUffer[k][1];break;
							case 1:a=WS2812_BUffer[k][0];break;
							case 2:a=WS2812_BUffer[k][2];break;
						}*/
						a=WS2812_BUffer[k][j];
#if WSCASE>=9	
						b7=a&0x80;b6=a&0x40;b5=a&0x20;b4=a&0x10;
						b3=a&0x08;b2=a&0x04;b1=a&0x02;b0=a&0x01;	
#endif						
#if WSCASE==8
WS2812_DI=1;
WS2812_DI=a&0x80;_nop_();
WS2812_DI=0;_nop_();_nop_();

WS2812_DI=1;
WS2812_DI=a&0x40;_nop_();
WS2812_DI=0;_nop_();_nop_();

WS2812_DI=1;
WS2812_DI=a&0x20;_nop_();
WS2812_DI=0;_nop_();_nop_();

WS2812_DI=1;
WS2812_DI=a&0x10;_nop_();
WS2812_DI=0;_nop_();_nop_();

WS2812_DI=1;
WS2812_DI=a&0x08;_nop_();
WS2812_DI=0;_nop_();_nop_();

WS2812_DI=1;
WS2812_DI=a&0x04;_nop_();
WS2812_DI=0;_nop_();_nop_();

WS2812_DI=1;
WS2812_DI=a&0x02;_nop_();
WS2812_DI=0;_nop_();_nop_();

WS2812_DI=1;
WS2812_DI=a&0x01;_nop_();
WS2812_DI=0;_nop_();_nop_();

#elif WSCASE==9
WS2812_DI=1;
WS2812_DI=b7;_nop_();
WS2812_DI=0;_nop_();

WS2812_DI=1;
WS2812_DI=b6;_nop_();
WS2812_DI=0;_nop_();

WS2812_DI=1;
WS2812_DI=b5;_nop_();
WS2812_DI=0;_nop_();

WS2812_DI=1;
WS2812_DI=b4;_nop_();
WS2812_DI=0;_nop_();

WS2812_DI=1;
WS2812_DI=b3;_nop_();
WS2812_DI=0;_nop_();

WS2812_DI=1;
WS2812_DI=b2;_nop_();
WS2812_DI=0;_nop_();

WS2812_DI=1;
WS2812_DI=b1;_nop_();
WS2812_DI=0;_nop_();

WS2812_DI=1;
WS2812_DI=b0;_nop_();
WS2812_DI=0;_nop_();

#elif WSCASE==10

WS2812_DI=1;
WS2812_DI=b7;
WS2812_DI=0;_nop_();_nop_();

WS2812_DI=1;
WS2812_DI=b6;
WS2812_DI=0;_nop_();_nop_();

WS2812_DI=1;
WS2812_DI=b5;
WS2812_DI=0;_nop_();_nop_();

WS2812_DI=1;
WS2812_DI=b4;
WS2812_DI=0;_nop_();_nop_();

WS2812_DI=1;
WS2812_DI=b3;
WS2812_DI=0;_nop_();_nop_();

WS2812_DI=1;
WS2812_DI=b2;
WS2812_DI=0;_nop_();_nop_();

WS2812_DI=1;
WS2812_DI=b1;
WS2812_DI=0;_nop_();_nop_();

WS2812_DI=1;
WS2812_DI=b0;
WS2812_DI=0;_nop_();_nop_();
#endif
				}
		}
}
void WS2812_Ser()
{
		static u8 count=0;
		count++;
		switch(count)
		{
			case 1:WS2812_DI=0;break;
			case 50:EA=0;WS2812_write_date();EA=1;break;
			case 51:WS2812_DI=0;break;
		}
		count%=60;
}				