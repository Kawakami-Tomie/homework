
#include<reg51.h>
   #include<stdio.h>
   #include<intrins.h>
   #include<absacc.h>
   #define uchar unsigned char
   #define uint unsighed int
   uchar VAR=0xFE;
	 unsigned char flag=0;
	 void delay(int n)//��ʱ����
   {
   int i,j;
   for(i=n;i>0;i--)
   {
   for(j=28;j>0;j--);
   }
   }

void INT_0(void) interrupt 0//��ʱ������
{
	delay(20);
	flag=1;
	IE0=0;
}
   
   void main()
{
		 IT0=1;
	EA=1;
	EX0=1;
   		while(1)
		{
		 
			if(flag==1)//��־λ��1
		{
			flag=0;
			VAR=_crol_(VAR,1);//ѭ������
	/	P1=VAR;													
		delay(1000);
		}
		}
		 
 }



 