#include <REGX52.H>
#include  "DS1302.h"
#include <intrins.h>
#include "Key.h"
#include "BlueTooth.h"

unsigned char time[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//定义数码管上0-f  16位数字的段选码
unsigned char time_buf[3]={0};//定义数码管对应位

#define USART_MAX_RECV_LEN	1

unsigned char USART_RX_BUF[USART_MAX_RECV_LEN];

unsigned char KeyNum=0,menu=0,MODE=0,TimeSetSelect=1;
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
		case 0:	P1_0=1;	P1_1=0;	P1_2=0;P1_3=0;break;
		case 1:	P1_0=0;	P1_1=1;	P1_2=0;P1_3=0;break;
		case 2:	P1_0=0;	P1_1=0;	P1_2=1;P1_3=0;break;
		case 3:	P1_0=0;	P1_1=0;	P1_2=0;P1_3=1;break;	
		}
		if((i==1)&&(menu!=0))P0=dat[i]|0x80;
		else P0=dat[i];//传送段选数据
		Delay1ms(1)	;//延时一段时间，等待显示稳定
		P0=0x00;//消音
	}
}





//按键扫描
void KeyScan(){
   
  KeyNum=Key();//读取键码
	 		
	if(KeyNum==1){
	  menu++;
		if(menu>=5) menu=0;
	}
	if(menu<3) MODE=0;
	else if(menu==3) {MODE=1;DS1302_SetTime();}//设置 时 分
	else if(menu==4) {MODE=1;DS1302_SetTime();}//设置 月 日
	

}

void TimeShow(void)//时间显示功能
{
	DS1302_ReadTime();//读取时间
					//显示学号
			    if(menu==0){
					time_buf[0]= time[1];//将BCD码转为十进制
					time_buf[1]= time[7];
					time_buf[2]= time[8];
					time_buf[3]= time[0];
					smg_display(time_buf);
					}
					//显示 时 分
					else if(menu==1){
					time_buf[0]= time[DS1302_Time[3]/10];//将BCD码转为十进制
					time_buf[1]= time[DS1302_Time[3]%10];
					time_buf[2]= time[DS1302_Time[4]/10];
					time_buf[3]= time[DS1302_Time[4]%10];
					smg_display(time_buf);
					}
					//显示 月 日
					else if(menu==2){
					time_buf[0]= time[DS1302_Time[1]/10];//将BCD码转为十进制
					time_buf[1]= time[DS1302_Time[1]%10];
					time_buf[2]= time[DS1302_Time[2]/10];
					time_buf[3]= time[DS1302_Time[2]%10];
					smg_display(time_buf);
					}	
}




//时间设置功能
void TimeSet(void)
{
	if(KeyNum==2)//按键2按下
	{
		TimeSetSelect++;//设置选择位加1
		if(TimeSetSelect>=5)TimeSetSelect=1;//越界清零
	}

	if(KeyNum==3)//按键3按下
	{
		DS1302_Time[TimeSetSelect]++;//时间设置位数值加1
	
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
		
	}
	if(KeyNum==4)//按键3按下
	{
		DS1302_Time[TimeSetSelect]--;//时间设置位数值减1
		
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
		
	}
}

void TimeChange(void)
{
  			 //设置 时 分
		  	 if(menu==3){
					TimeSet();
					time_buf[0]= time[DS1302_Time[3]/10];//将BCD码转为十进制
					time_buf[1]= time[DS1302_Time[3]%10];
					time_buf[2]= time[DS1302_Time[4]/10];
					time_buf[3]= time[DS1302_Time[4]%10];
					smg_display(time_buf);
					}
					//设置 月 日
					else if(menu==4){
					TimeSet();
					time_buf[0]= time[DS1302_Time[1]/10];//将BCD码转为十进制
					time_buf[1]= time[DS1302_Time[1]%10];
					time_buf[2]= time[DS1302_Time[2]/10];
					time_buf[3]= time[DS1302_Time[2]%10];
					smg_display(time_buf);
					}

}
 
void main ()
{	
		UART_Init();//初始化蓝牙
		DS1302_Init();//DS1302初始化
		DS1302_SetTime();//	DS1302设置时间
		while(1)
		{
					KeyScan();
					switch(MODE)//根据不同的功能执行不同的函数
							{
								case 0:TimeShow();break;
								case 1:TimeChange();break;
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
//		if(SBUF == 0xB1 || SBUF == 0xB9) KeyNum = 1;  
//		else if(SBUF == 0xB2 || SBUF == 0xBA) KeyNum = 2;  
//		else if(SBUF == 0xB3 || SBUF == 0xBB) KeyNum = 3;  
//		else if(SBUF == 0xB4 || SBUF == 0xBC) KeyNum = 4;    
//		else { KeyNum = 1;} 
		RI=0;
	}								 
}




	
	