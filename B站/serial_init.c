#include "serial_init.h"
void serial_init(void)
{
	SCON = 0x50;		//串口工作方式1，允许接受
	TMOD |= 0x20;	 	//	定时器1，工作方式2，8位自动重装
	TH1 = 0xfd;			//11.0952MHz晶振时产生9600波特率
	TL1 = 0xfd;			//11.0952MHz晶振时产生9600波特率
	TR1 = 1;				//开启定时器1
	TI = 1;					//请求发送数据
}