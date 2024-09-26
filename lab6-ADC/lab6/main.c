#include "delay.h"
#include "seg.h"
#include "XPT2046.h"
#include "Nixie.h"

unsigned int ADValue;
bit flag1=0;
bit flag2=0;
bit flag3=0;
void Timer0_Init(void)		//1毫秒@12.000MHz
{	
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
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
	
		if(flag1 ==1){
			ADValue=XPT2046_ReadAD(XPT2046_XP);		//读取AIN0，可调电阻
			Nixie_SetBuf(4,ADValue/1000%10);
			Nixie_SetBuf(3,(ADValue%1000/100)+12);
			Nixie_SetBuf(2,ADValue/10%10);
			Nixie_SetBuf(1,ADValue%10);
			Nixie_SetBuf(5,10);
			Nixie_SetBuf(6,10);
			Nixie_SetBuf(7,10);
			Nixie_SetBuf(8,1);
			flag1 =0;
		}
		if(flag2 ==1){
			ADValue=XPT2046_ReadAD(XPT2046_YP);		//读取AIN1，温度
			Nixie_SetBuf(4,ADValue/1000);
			Nixie_SetBuf(3,(ADValue%1000/100)+12);
			Nixie_SetBuf(2,ADValue%100/10);
			Nixie_SetBuf(1,ADValue%10);
			Nixie_SetBuf(5,10);
			Nixie_SetBuf(6,10);
			Nixie_SetBuf(7,10);
			Nixie_SetBuf(8,2);
			flag2 =0;
		}
		if(flag3 ==1){
			ADValue=XPT2046_ReadAD(XPT2046_VBAT);	//读取AIN2，光敏电阻
			Nixie_SetBuf(4,ADValue/1000);
			Nixie_SetBuf(3,(ADValue%1000/100)+12);
			
			Nixie_SetBuf(2,ADValue%100/10);
			Nixie_SetBuf(1,ADValue%10);
			Nixie_SetBuf(5,10);
			Nixie_SetBuf(6,10);
			Nixie_SetBuf(7,10);
			Nixie_SetBuf(8,3);
			flag3 =0;
		}
		Delay(100);
	}
}
void Timer0_Isr(void) interrupt 1
{
	static unsigned int T0Count1,T0Count2,T0Count3;
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	T0Count3++;
	if(T0Count3>=1000){
		T0Count1++;
		T0Count3 = 0;
	}
	
	if(T0Count1<=10)
	{
		flag1 = 1;
	}
	else if(T0Count1>10&&T0Count1<=20){
		flag2 = 1;
	
	}
	else if(T0Count1>20&&T0Count1<=30){
		flag3 = 1;
	
	}
	else if(T0Count1>30){
		T0Count1=0;
	
	}
	T0Count2++;
	if(T0Count2>=2)
	{
		T0Count2=0;
		Nixie_Loop();//2ms调用一次数码管驱动函数
	}

}

