#include <REG52.H>
#include "intrins.h"
#include "LCD1602.h"	//包含LCD1602头文件
#include "Delay.h"		//包含Delay头文件
#include "DS18B20.h"
#include "DHT11.h"
#include "Timer0.h"

sbit Motor=P0^0;
sbit P34 = P3^4;
sbit P35 = P3^5;
sbit P36 = P3^6;
sbit P37 = P3^7;
float T = 0;
extern unsigned char  hum;//湿度

unsigned char k1 = 5, k2 = 1, k3 = 10;
int sbz = 38, speed = 0, wbz = 25;
float bz = 0, xz = 0;
float p = 0,i = 0,d = 0;
float pid = 0;
int Compare = 0;
unsigned char DHTC = 0,DHTF = 0;
unsigned char sw = 0; //0湿度 ， 1温度
unsigned char kz = 0; //0档位控制, 1pid
unsigned char key = 0, key_keyNumber = 0;

void main()
{	
	Motor = 0;
	LCD_Init();
	DHT11_Init();
	DS18B20_ConvertT();
	Delay(1000);

	Timer0Init();
	Timer1Init();
	TR0 = 1;				//定时器0开始计时
	ET0=1;
	TR1 = 1;
	ET1 = 1;
	EA=1;//开启总中断

	while(1)
	{	
		LCD_ShowString(1,1,"Tem:");
		LCD_ShowString(2,1,"Hum:");
		LCD_ShowChar(1,8,'.');	
		LCD_ShowChar(2,7,'%');

		TR0 = 0;
		TR1 = 0;
//		DS18B20_ConvertT();	//转换温度
//		T=DS18B20_ReadT();	//读取温度
		DHT11_receive();
		if(DHTF == 1)
		{
			
			DHTF = 0;
		}	
		TR0 = 1;
		TR1 = 1;

//		LCD_ShowNum(1,5,T,3);		//显示温度整数部分
//		LCD_ShowNum(1,9,(unsigned long)(T*10000)%10000,4);//显示温度小数部分
		LCD_ShowNum(2,5,hum,2);

		//LCD_ShowNum(1,5,Compare,4);
		//LCD_ShowNum(1,10,hu,2);LCD_ShowSignedNum(2,1,p,4);LCD_ShowSignedNum(2,6,i,4);LCD_ShowSignedNum(2,11,d,4);

		key = key_keyNumber;
		key_keyNumber = 0;
//		{
//			if(key == 1)
//			{
//				sw = 1 - sw;
//			}
//			else if(key == 2)
//			{
//				if(sw == 0)
//					sbz++;
//				else
//					wbz++;
//			}
//			else if(key == 3)
//			{
//				if(sw == 0)
//					sbz--;
//				else
//					wbz--;
//			}
//			else if(key == 4)
//			{
//				kz = 1 - kz;
//			}
//		}

//		if(sw == 1)
//		{
//			LCD_ShowNum(1,14,wbz,3);
//			LCD_ShowString(2,14,"   ");
//			xz = T;
//			bz = wbz;
//		}
//		else
//		{
//			LCD_ShowNum(2,14,sbz,3);
//			LCD_ShowString(1,14,"   ");
//			xz = hum;
//			bz = sbz;
//		}

//		if(kz)
//		{
//			LCD_ShowString(2,10,"PID");
//			d = xz - bz - p;
//			p = xz - bz;
//			i += p;
//			pid += (k1*p + k2*i + k3*d);

//			if(pid>=0 && pid<=1000)
//			{
//				Compare = pid;
//			}
//			else if(pid<0)
//			{
//				Compare = 0;
//				pid = 0;
//			}
//			else
//			{
//				Compare = 1000;
//				pid = 1000;
//			}
//		}
//		else
//		{
//			LCD_ShowString(2,10,"   ");
//			p = 0;i = 0; d = 0; pid = 0;
//			if(xz - bz >=10)
//			{
//				speed = 1000;
//			}
//			else if(xz - bz <=0)
//			{
//				speed = 0;
//			}
//			else
//			{
//				speed = (int)((xz - bz)*100);
//			}
//			Compare = speed ;
//		}
//		Delay(50);
	}
}

unsigned char Key_GetState()
{
	unsigned char keynum = 0;
	if(P34 == 0){keynum=1;}	//一有按键被按下，标志位keynum立即置位并返回，给key_loop函数处理
	if(P35 == 0){keynum=2;}
	if(P36 == 0){keynum=3;}
	if(P37 == 0){keynum=4;}
	return keynum;
}

//void key_loop()
//{
//	static unsigned char before_state,now_state;
//	before_state = now_state;
//	now_state = Key_GetState();		//获取按键标志位
//	if(before_state == 1 && now_state == 0)	
//	{
//		key_keyNumber = 1;	//全局变量key_keyNumber置1，使用key_return函数返回给main函数使用
//	}
//	if(before_state == 2 && now_state == 0)	
//	{
//		key_keyNumber = 2;
//	}
//	if(before_state == 3 && now_state == 0)	
//	{
//		key_keyNumber = 3;
//	}
//	if(before_state == 4 && now_state == 0)	
//	{
//		key_keyNumber = 4;
//	}
//}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0xA4;				//设置定时初始值
	TH0 = 0xFF;
	T0Count++;
	if(T0Count < Compare)
	{
		Motor = 1;
	}
	else
	{
		Motor = 0;
	}
	if (T0Count >= 1000)
	{
		T0Count = 0;
	}
}

void Timer1_Routine() interrupt 3
{
	static unsigned int T1Count;
	TL1 = 0x00;				
	TH1 = 0xDC;
//	T1Count++;
//	DHTC ++;
//	if(T1Count>=20)
//	{
////		key_loop();
//		T1Count = 0;
//	}
//	if(DHTC >=75)
//	{
//		DHTC = 0;
//		DHTF = 1;
//	}
}
