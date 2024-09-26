#include<all.h>
void ws2812_allot()
{
		u8 i,j;
		for(i=0;i<WSCOUNT;i++)
			for(j=0;j<3;j++)
			{
				if(j==1)
				WS2812_BUffer[i][j]=50;
				else
				WS2812_BUffer[i][j]=0;
			}
}
void main()
{
		while(1)
		{	
				ws2812_allot();
				WS2812_Ser();
		}
}