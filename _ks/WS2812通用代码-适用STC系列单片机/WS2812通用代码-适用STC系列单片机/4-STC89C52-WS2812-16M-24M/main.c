#include<REG52.H>
/*16M-24M*/
#include<intrins.h>
#define WSCOUNT 10
sbit k=P1^0;
unsigned char WS2812_BUffer[WSCOUNT][3];
void WS2812_write_date()
{	
		bit w0,w1,w2,w3,w4,w5,w6,w7;
		unsigned char i,j,shu;
		for(i=0;i<WSCOUNT;i++)
		for(j=0;j<3;j++)
		{
				switch(j)
				{
					case 0:shu=WS2812_BUffer[i][1];break;
					case 1:shu=WS2812_BUffer[i][0];break;
					case 2:shu=WS2812_BUffer[i][2];break;
					
				}
				//shu=WS2812_BUffer[i][j];
				w7=shu&0x80;w6=shu&0x40;
				w5=shu&0x20;w4=shu&0x10;
				w3=shu&0x08;w2=shu&0x04;
				w1=shu&0x02;w0=shu&0x01;
			
				k=0;
				if(w7) k=1;
				else k=0;
				k=1; k=0;
				if(w6) k=1;
				else k=0;
				k=1; k=0;
				if(w5) k=1;
				else k=0;
				k=1; k=0;
				if(w4) k=1;
				else k=0;
				k=1; k=0;
				if(w3) k=1;
				else k=0;
				k=1; k=0;
				if(w2) k=1;
				else k=0;
				k=1; k=0;
				if(w1) k=1;
				else k=0;
				k=1; k=0;
				if(w0) k=1;
				else k=0;
				k=1; k=0;
		}
}
void WS2812_Ser()
{
		static unsigned char count=0;
		count++;
		switch(count)
		{
			case 1:k=0;break;
			case 50:EA=0;WS2812_write_date();EA=1;break;
			case 51:k=0;break;
		}
		count%=60;
}
void WS2812_Allot()
{
		unsigned char i,j;
		static unsigned char count=0;
		count++;
		if(count==60)
		{
				for(j=0;j<WSCOUNT;j++)
				{
						for(i=0;i<3;i++)
						{
								if(i==1)
									WS2812_BUffer[j][i]=40;
								else 
									WS2812_BUffer[j][i]=0;
						}
				}
		}
		WS2812_Ser();
}
void main()
{
		while(1)
		{
				WS2812_Allot();
		}
}