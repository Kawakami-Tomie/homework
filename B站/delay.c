#include "delay.h"

/*------------------------------------------------
		 us延时函数
		 输入参数: unsigned char t
		 无返回值
		 晶振12M
		 实际延时时间= t*2 + 5 us 
------------------------------------------------*/
void DelayUs(unsigned char t)
{   
 while(--t);
}
/*------------------------------------------------
			 ms延时函数
			含有输入参数 unsigned int t
			无返回值
			晶振12M
------------------------------------------------*/
void DelayMs(unsigned int z)
{     
	unsigned int i,j;
  for(i=z;i>0;i--)
      for(j=123;j>0;j--);
}