
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
uchar D1[6]={0x89,0x86,0xC7,0xC7,0xC0,0xFF};//hello
 
uchar C[6]={0xDF,0xEF,0xF7,0xFB,0xFD,0xFE};
int i;
int j;
uchar temp;//��ʱ����
   void main()
{
		 IT0=1;//�½��ش���
	EA=1;
	EX0=1; 
   		while(1)
		{	 
			if(flag==1)//��־λ��1
				{
					 
					flag=0;
					temp=D1[5];
					for(j=5;j>0;j--)//HELLOƽ��
					{
						D1[j]=D1[j-1];
					 
					}
					 D1[0]= temp;
				}
					for(i=0;i<6;i++)//ѭ����ʾ
					{
							
						P0=D1[i];
						P1=C[i];
						delay(1);
						P0=0xFF;
						delay(9);
					}
		}
	}
		 
 



 