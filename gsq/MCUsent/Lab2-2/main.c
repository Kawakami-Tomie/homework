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
uchar D[6]={0x80,0xFF,0xFF,0xFF,0xFF,0xFF};//hello
uchar C[6]={0xDF,0xEF,0xF7,0xFB,0xFD,0xFE};
int i;
   void main()
{
		 IT0=1;
	EA=1;
	EX0=1;
   		while(1)
		{
			if(flag==1)//���������£���־λ��1
		{			 
			flag=0;//��־λ��0
			VAR=_crol_(VAR,1);
			P1=C[i%6];//����P1�Ķ���������ѭ������
			P0=0x80;//P0������ʾ����8
			delay(20);
			i++;		 
			}
		}
		}
		 
 



 