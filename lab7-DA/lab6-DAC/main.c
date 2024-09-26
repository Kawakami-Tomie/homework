//#include "delay.h"
//#include "seg.h"
//#include "XPT2046.h"
//#include "Nixie.h"

//unsigned int ADValue;
//bit flag1=0;
//bit flag2=0;
//bit flag3=0;
//sbit DA=P2^1;

//unsigned char Counter,Compare;	//计数值和比较值，用于输出PWM
//unsigned char i;



//void Timer0_Init(void)		//1微秒@12.000MHz
//{
////	AUXR |= 0x80;			//定时器时钟1T模式
//	TMOD &= 0xF0;			//设置定时器模式
//	TMOD |= 0x01;			//设置定时器模式
//	TL0 = 0xFF;				//设置定时初始值
//	TH0 = 0xFF;				//设置定时初始值
//	TF0 = 0;				//清除TF0标志
//	TR0 = 1;				//定时器0开始计时
//	ET0 = 1;				//使能定时器0中断
//	EA=1;
//}




//void main(void)
//{
//	Timer0_Init();

//	while(1)
//	{
//			Compare=5;
//			ADValue=XPT2046_ReadAD(XPT2046_AUX);		//读取AIN0，可调电阻
////			Nixie_Scan(8,ADValue/1000%10);
////			Nixie_Scan(7,(ADValue%1000/100)+12);
////			Nixie_Scan(5,ADValue/10%10);
////			Nixie_Scan(6,ADValue%10);
////			Nixie_Scan(1,10);
////			Nixie_Scan(2,10);
////			Nixie_Scan(3,10);
////	        Nixie_Scan(4,10);
////			Nixie_Loop();//调用一次数码管驱动函数
//			flag1 =0;
//				
//		Delay(80);
//	}
//}
//void Timer0_Isr(void) interrupt 1
//{
//	
//		
//	TL0 = 0xF0;				//设置定时初始值
//	TH0 = 0xFF;				//设置定时初始值
//	Counter++;
//	Counter%=10;	//计数值变化范围限制在0~99
//	if(Counter<Compare)	//计数值小于比较值
//	{
//		DA=1;		//输出1
//	}
//	else				//计数值大于比较值
//	{
//		DA=0;		//输出0
//	}
//	
//}



//void Timer1_Isr(void) interrupt 3
//{
//	TL1 = 0x18;				//设置定时初始值
//	TH1 = 0xFC;				//设置定时初始值

//}

#include "delay.h"
#include "XPT2046.h"
#include "Nixie.h"

unsigned int ADValue;

sbit DA=P2^1;

unsigned char Counter,Compare;	//计数值和比较值，用于输出PWM
unsigned char i;



void Timer0_Init(void)		//10us@12.000MHz
{
	
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0xFF;				//设置定时初始值
	TH0 = 0xFF;					
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0 = 1;				//使能定时器0中断
	EA = 1;
	
}


void main(void)
{
	Timer0_Init();

	while(1)
	{
			Compare = 5;
			ADValue=XPT2046_ReadAD(XPT2046_AUX);		//读取AIN3，可调电阻
//			Nixie_Scan(4,ADValue/1000%10);
//			Nixie_Scan(3,ADValue/100%10);
//			Nixie_Scan(2,ADValue/10%10);
//			Nixie_Scan(1,ADValue%10);
//			Nixie_Scan(5,10);
//			Nixie_Scan(6,10);
//			Nixie_Scan(7,10);
//			Nixie_Scan(8,10);
			Delay(20);
	}
}
void Timer0_Isr(void) interrupt 1
{
	P1_0 = ~P1_0;
	TL0 = 0xF0;				//设置定时初始值
	TH0 = 0xFF;					
	Counter++;
	Counter%=10;	//计数值变化范围限制在0~99
	if(Counter<Compare)	//计数值小于比较值
	{
		DA=1;		//输出1
	}
	else				//计数值大于比较值
	{
		DA=0;		//输出0
	}
	
}

