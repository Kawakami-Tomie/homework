#include <REGX52.H>
#include "XPT2046.h"
#include "Nixie.h"
unsigned int ADValue;

unsigned char count = 0;
unsigned char compared = 2;

void Timer1_Isr(void) interrupt 3
	
{
//	TL1 = 0xFC;				//设置定时初始值
//	TH1 = 0xFC;				//设置定时重载值
	count++;
	if(count >= 10){
		count = 0;
	}
	if(count < compared){
		P2_1 = 1;
	}
	else{
		P2_1 = 0;
	}
}

void Timer1_Init(void)		
{
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x20;			//设置定时器模式
	TL1 = 0xFF;				//设置定时初始值
	TH1 = 0xFF;				//设置定时重载值
	TF1 = 0;				//清除TF1标志
	TR1 = 1;				//定时器1开始计时
	ET1 = 1;				//使能定时器1中断

	EA = 1;
}


void main(){
	Timer1_Init();
	while(1){
		
			ADValue=XPT2046_ReadAD(XPT2046_AUX);		//读取AIN3，可调电阻
//			Nixie_SetBuf(4,ADValue/1000%10);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
//			Nixie_SetBuf(3,ADValue/100%10);
//			Nixie_SetBuf(2,ADValue/10%10);
//			Nixie_SetBuf(1,ADValue%10);
//			Nixie_SetBuf(5,10);
//			Nixie_SetBuf(6,10);
//			Nixie_SetBuf(7,10);
//			Nixie_SetBuf(8,10);

	}
}