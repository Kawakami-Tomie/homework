#include <REGX52.H>

/**
  * @brief 串口初始化
  * @param  无
  * @retval 无
  */
void Uart_Init()	//4800bps@11.0592MHz
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

/**
  * @brief 串口发送一位字节数据
  * @param  Byte 要发送的字节数据
  * @retval 无
  */
void Uart_SendByte(unsigned char Byte)
{
	SBUF=Byte;   //向缓存器中写入内容
	while(TI==0);   //发送中断标志位 如果检测到了寄存器的TI位 如果为0 就表示数据未发送完成  反复执行本条语句检测TI位
	//如果TI为1 就表示SUBF的数据已经发送完成了  马上执行下条语句将TI位清零
	TI=0;
}

void main()
{
	Uart_Init();
	
	while(1)
	{
		
	}
}
void Uart_Routine() interrupt 4
{
	if(RI==1)   //如果接收到数据 接收完成后 产生中断 如果是接收中断  
		//发送数据也会产生中断
	{
		P2=SBUF;  //从SUBF缓存器中读取数据
		Uart_SendByte(SBUF);
		RI=0;
	}
}



