#include <REGX52.H>




#define RELOAD_COUNT 0xFA //宏定义波特率发生器的载入值 9600

//配置蓝牙串口
//void UART_Init(void)
//{
//	SCON=0X50;			//设置为工作方式1
//	TMOD=0X20;			//设置计数器工作方式2
//	PCON=0X80;			//波特率加倍
//	TH1=RELOAD_COUNT;	//计数器初始值设置
//	TL1=TH1;
//	ES=1;				//打开接收中断
//	EA=1;				//打开总中断
//	TR1=1;				//打开计数器
//}



void UART_Init(void)	//4800bps@12.000MHz
{
	SCON=0x50;   //方式1   REN置1 允许/禁止数据接收的控制位  允许接收 REN置1
	PCON |= 0x80;  //波特率加倍  
	
	//配置定时器1 模式二 8位自动重装
	TMOD&=0x0F;
	TMOD|=0x20;  //模式二
	TL1 = 0xF4;		//设定定时初值
	TH1 = 0xF4;		//设定定时器重装值
	
	ET1=0;   //不用开启中断 定时器在这里的作用是产生波特率
	TR1=1;   //启动定时器1
	
	//接收数据完成后就触发中断
	ES=1;
	EA=1;
}


void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;  //向缓存器中写入内容
	while(TI==0);  

	TI=0;
}

