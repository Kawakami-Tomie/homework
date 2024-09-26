#include <REGX52.H>
#include  "DS1302.h"
#include "LCD1602.h"
#include <intrins.h>
#include "Key.h"
#include "BlueTooth.h"
#include "Timer0.h"
#include "DHT11.h"

#define USART_MAX_RECV_LEN	1

unsigned char USART_RX_BUF[USART_MAX_RECV_LEN];

unsigned char KeyNum,MODE,TimeSetSelect,TimeSetFlashFlag;

extern unsigned char rec_dat[15];
char rec[8]={1,2,3,5,6,6,6,6};
 /**
 *@breaf 延时函数/@12.0000MHz  1ms为单位
 *@para   t 延时时间设置
 *@retval无
 */
void Delay1ms(unsigned char t)		//@12.0000MHz
{
	unsigned char i, j;
	while(t--)
		{
		_nop_();
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}


void TimeShow(void)//时间显示功能
{
	DS1302_ReadTime();//读取时间
	DS1302_ReadTime();//读取时间
	LCD_ShowNum(1,1,DS1302_Time[0],2);//显示年
	LCD_ShowNum(1,4,DS1302_Time[1],2);//显示月
	LCD_ShowNum(1,7,DS1302_Time[2],2);//显示日
	LCD_ShowNum(1,9,DS1302_Time[3],2);//显示时
	LCD_ShowNum(1,12,DS1302_Time[4],2);//显示分
	LCD_ShowNum(1,15,DS1302_Time[5],2);//显示秒	
}


//时间设置功能
void TimeSet(void)
{
		if(KeyNum==2)//按键2按下
	{
		TimeSetSelect++;//设置选择位加1
		TimeSetSelect%=6;//越界清零
	}
	if(KeyNum==3)//按键3按下
	{
		DS1302_Time[TimeSetSelect]++;//时间设置位数值加1
		if(DS1302_Time[0]>99){DS1302_Time[0]=0;}//年越界判断
		if(DS1302_Time[1]>12){DS1302_Time[1]=1;}//月越界判断
		if( DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || DS1302_Time[1]==7 || 
			DS1302_Time[1]==8 || DS1302_Time[1]==10 || DS1302_Time[1]==12)//日越界判断
		{
			if(DS1302_Time[2]>31){DS1302_Time[2]=1;}//大月
		}
		else if(DS1302_Time[1]==4 || DS1302_Time[1]==6 || DS1302_Time[1]==9 || DS1302_Time[1]==11)
		{
			if(DS1302_Time[2]>30){DS1302_Time[2]=1;}//小月
		}
		else if(DS1302_Time[1]==2)
		{
			if(DS1302_Time[0]%4==0)
			{
				if(DS1302_Time[2]>29){DS1302_Time[2]=1;}//闰年2月
			}
			else
			{
				if(DS1302_Time[2]>28){DS1302_Time[2]=1;}//平年2月
			}
		}
		if(DS1302_Time[3]>23){DS1302_Time[3]=0;}//时越界判断
		if(DS1302_Time[4]>59){DS1302_Time[4]=0;}//分越界判断
		if(DS1302_Time[5]>59){DS1302_Time[5]=0;}//秒越界判断
	}
	if(KeyNum==4)//按键3按下
	{
		DS1302_Time[TimeSetSelect]--;//时间设置位数值减1
		if(DS1302_Time[0]<0){DS1302_Time[0]=99;}//年越界判断
		if(DS1302_Time[1]<1){DS1302_Time[1]=12;}//月越界判断
		if( DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || DS1302_Time[1]==7 || 
			DS1302_Time[1]==8 || DS1302_Time[1]==10 || DS1302_Time[1]==12)//日越界判断
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=31;}//大月
			if(DS1302_Time[2]>31){DS1302_Time[2]=1;}
		}
		else if(DS1302_Time[1]==4 || DS1302_Time[1]==6 || DS1302_Time[1]==9 || DS1302_Time[1]==11)
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=30;}//小月
			if(DS1302_Time[2]>30){DS1302_Time[2]=1;}
		}
		else if(DS1302_Time[1]==2)
		{
			if(DS1302_Time[0]%4==0)
			{
				if(DS1302_Time[2]<1){DS1302_Time[2]=29;}//闰年2月
				if(DS1302_Time[2]>29){DS1302_Time[2]=1;}
			}
			else
			{
				if(DS1302_Time[2]<1){DS1302_Time[2]=28;}//平年2月
				if(DS1302_Time[2]>28){DS1302_Time[2]=1;}
			}
		}
		if(DS1302_Time[3]<0){DS1302_Time[3]=23;}//时越界判断
		if(DS1302_Time[4]<0){DS1302_Time[4]=59;}//分越界判断
		if(DS1302_Time[5]<0){DS1302_Time[5]=59;}//秒越界判断
	}
	//更新显示，根据TimeSetSelect和TimeSetFlashFlag判断可完成闪烁功能
	if(TimeSetSelect==0 && TimeSetFlashFlag==1){LCD_ShowString(1,1,"  ");}
	else {LCD_ShowNum(1,1,DS1302_Time[0],2);}
	if(TimeSetSelect==1 && TimeSetFlashFlag==1){LCD_ShowString(1,4,"  ");}
	else {LCD_ShowNum(1,4,DS1302_Time[1],2);}
	if(TimeSetSelect==2 && TimeSetFlashFlag==1){LCD_ShowString(1,7,"  ");}
	else {LCD_ShowNum(1,7,DS1302_Time[2],2);}
	if(TimeSetSelect==3 && TimeSetFlashFlag==1){LCD_ShowString(1,9,"  ");}
	else {LCD_ShowNum(1,9,DS1302_Time[3],2);}
	if(TimeSetSelect==4 && TimeSetFlashFlag==1){LCD_ShowString(1,12,"  ");}
	else {LCD_ShowNum(1,12,DS1302_Time[4],2);}
	if(TimeSetSelect==5 && TimeSetFlashFlag==1){LCD_ShowString(1,15,"  ");}
	else {LCD_ShowNum(1,15,DS1302_Time[5],2);}
}

 
void main ()
{	

	UART_Init();//初始化蓝牙
	LCD_Init();
	Timer0Init();
	DS1302_Init();
	LCD_ShowString(1,1,"  -  -  ");//静态字符初始化显示
	LCD_ShowString(1,9,"  :  :  ");
	
	DS1302_SetTime();//设置时间
		while(1)
		{
		  	DHT11_receive();
			LCD_ShowString(2,1,rec);

				KeyNum=Key();//读取键码
				if(KeyNum==1)//按键1按下
				{
					if(MODE==0){MODE=1;TimeSetSelect=0;}//功能切换
					else if(MODE==1){MODE=0;DS1302_SetTime();}
				}
				switch(MODE)//根据不同的功能执行不同的函数
				{
					case 0:TimeShow();break;
					case 1:TimeSet();break;
				}
    	}
}

//串口中断函数
void Uart1_Isr() interrupt 4
{
	if(RI)
	{
		USART_RX_BUF[0]=SBUF;
		RI = 0;//清除接收中断标志位
		UART_SendByte(SBUF);
		RI=0;
	}								 
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=500)//每500ms进入一次
	{
		T0Count=0;
		TimeSetFlashFlag=!TimeSetFlashFlag;//闪烁标志位取反
	}
}




	
	