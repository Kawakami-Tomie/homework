#include <REGX52.H>
#include "LCD1602.h"
#include <intrins.h>
#include "Key.h"
#include "BlueTooth.h"
#include "Timer0.h"
#include "DHT11.h"

#define USART_MAX_RECV_LEN	1

unsigned char USART_RX_BUF[USART_MAX_RECV_LEN];

unsigned char KeyNum,MODE,TimeSetSelect,TimeSetFlashFlag;

unsigned char time[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//定义数码管上0-f  16位数字的段选码
unsigned char time_buf[3]={0};//定义数码管对应位
extern unsigned char  hum;//湿度
extern unsigned char  tem;//温度

sbit Motor=P2^5;
sbit beep=P3^6;
int beepflag=0;
int Compare=0;
int blue=0;//蓝牙控制标志

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

/**
*@breaf 数码管显示函数
*@para  显示的段选数据 数组
*@retval无
*/
void smg_display(unsigned char dat[])
{
	unsigned char i=0;
	for(i=0;i<4;i++)//扫描
	{
	   	switch(i)//位选
		{
		case 0:	P2_0=0;	P2_1=1;	P2_2=1;P2_3=1;break;
		case 1:	P2_0=1;	P2_1=0;	P2_2=1;P2_3=1;break;
		case 2:	P2_0=1;	P2_1=1;	P2_2=0;P2_3=1;break;
		case 3:	P2_0=1;	P2_1=1;	P2_2=1;P2_3=0;break;	
		}
		if(i==1)P0=~(dat[i]|0x80);
		else P0=~dat[i];
		Delay1ms(1)	;//延时一段时间，等待显示稳定
		P0=0xff;//消影
	}
}

 
void main ()
{	

	UART_Init();//初始化蓝牙

	DHT11_Init();
	Timer0Init();
	Timer1_Init();

	Delay1ms(1000);


		while(1)
		{
			//为了不打断dht11读取的时序，需要暂停定时器
			TR0 = 0;
			TR1 = 0;
		  DHT11_receive();
			TR0 = 1;
			TR1 = 1;
			
			time_buf[0]=time[tem/10];
			time_buf[1]=time[tem%10];
			time_buf[2]=time[hum/10];
			time_buf[3]=time[hum%10];
			smg_display(time_buf);
		
			if((hum>=77)&&(blue==0)){Compare=500;beepflag=1;}
			else {Motor=0;beepflag=0;}		

			KeyNum=Key();
				
			  if(KeyNum==1)//按键1按下
				{
						Compare+=100;
				}
				else if(KeyNum==2)//按键2按下
				{
						Compare-=100;
				}
				
				if(Compare<=0)Compare=0;
				if(Compare>=1000)Compare=1000;
			


    	}
}

//串口中断函数
void Uart1_Isr() interrupt 4
{
	if(RI)
	{
		USART_RX_BUF[0]=SBUF;
		blue=1;//进入蓝牙控制
		RI = 0;//清除接收中断标志位
		if((USART_RX_BUF[0]==0x31)&&(beepflag==1))Compare=300;
		if((USART_RX_BUF[0]==0x32)&&(beepflag==1))Compare=400;
		if((USART_RX_BUF[0]==0x33)&&(beepflag==1))Compare=500;
		if((USART_RX_BUF[0]==0x34)&&(beepflag==1))Compare=600;
		if((USART_RX_BUF[0]==0x35)&&(beepflag==1))Compare=700;
		if((USART_RX_BUF[0]==0x36)&&(beepflag==1))Compare=800;
		if((USART_RX_BUF[0]==0x37)&&(beepflag==1))Compare=950;
		if((USART_RX_BUF[0]==0x38)&&(beepflag==1))blue=0;//退出蓝牙控制
		UART_SendByte(SBUF);
		RI=0;
	}								 
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x9C;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
	
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


void Timer1_Isr(void) interrupt 3
{
		TL1 = 0x18;				//设置定时初始值
	  TH1 = 0xFC;				//设置定时初始值
	
	  if(beepflag==1)	beep=~beep;
}





	
	