#include <REGX51.H>
//#include "LCD1602.h"
static unsigned int i;
void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}
unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void Nixie(unsigned char Location,Number)
{
	switch(Location)		
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=NixieTable[Number];	
	Delay(1);				
	P0=0x00;				
}


void Timer0_Init()
{

	TMOD &= 0xF0;		
	TMOD |= 0x01;		
	TL0 = 0x11;	
	TH0 = 0xFE;
	TF0 = 0;		
	TR0 = 1;		
	ET0=1;
	EA=1;
	PT0=0;
}

void Timer1_Init()
{

	TMOD &= 0x0F;		
	TMOD |= 0x10;		
	TL1 = 0x00;		
	TH1 = 0x00;		
	TF1 = 0;		
	TR1 = 1;
}

void Int0_Init()
{
	IT0=1;
	EX0=1;
	EA=1;
}

void main()
{
	LCD_Init();
	Timer0_Init();
	Timer1_Init();
	Int0_Init();
	while(1)
	{
		unsigned int f=1000000/i;
		Nixie(3,f/100);
		Nixie(2,(f/10)%10);
		Nixie(1,f%10);
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count=0;
	TL0 = 0x17;	
	TH0 = 0xFE;			
	T0Count++;
	if(T0Count>=2)
	{
		T0Count=0;
		P1_0=~P1_0;
	}
}
void Int0_Routine()   interrupt 0
{
	unsigned int a,b;
	TR1 = 0;
	a=TH1;
	b=TL1;
	
	i=(a<<8)+b;


	TL1 = 0x0E;		
	TH1 = 0x00;
	TR1 = 1;

}
	