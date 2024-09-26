#include <REGX52.H>
#include "intrins.h"
#include "stdio.h"
unsigned char NixieTable[]={0x3F,0x06,0x5B,
0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int count = 0;
unsigned int count1 = 255;


#define BUF_SIZE 2  // 缓冲区大小，用于存储接收到的数据  
  
unsigned char rx_buffer[BUF_SIZE];  // 接收缓冲区  
unsigned char rx_index = 0;  // 接收缓冲区索引 


void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}

void Nixie(unsigned char Location, unsigned char Number)
{
    switch(Location){
        case 1: P2_4=0; P2_3=0; P2_2=0; break;
        case 2: P2_4=0; P2_3=0; P2_2=1; break;
        case 3: P2_4=0; P2_3=1; P2_2=0; break;
        case 4: P2_4=0; P2_3=1; P2_2=1; break;     
        case 5: P2_4=1; P2_3=0; P2_2=0; break;
        case 6: P2_4=1; P2_3=0; P2_2=1; break;    
        case 7: P2_4=1; P2_3=1; P2_2=0; break;
        case 8: P2_4=1; P2_3=1; P2_2=1; break;
    }

    P0 = NixieTable[Number];      // 段码输出
    Delay(1);                                // 显示一段时间
    P0 = 0x00;                               // 段码清0，消影
}
void Uart1_Init(void)	//4800bps@12.000MHz
{
  
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF3;			//设置定时初始值
	TH1 = 0xF3;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
  EA = 1;
  ES = 1;
}
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}

void Uart_Isr() interrupt 4 using 1
{
	
	    if (RI) {  // 如果接收到数据  
        RI = 0;  // 清除接收中断标志位  
        rx_buffer[rx_index++] = SBUF;  // 将接收到的数据存储到缓冲区中  
        if (rx_index == BUF_SIZE) {  // 如果接收到了足够的字节  
            count=(rx_buffer[0]<<8)+rx_buffer[1];// 这里可以添加处理接收到的数据的代码  
						count = (count-2)/3;
						UART_SendByte(count);
            rx_index = 0;  // 重置缓冲区索引，准备接收下一组数据  
        }  
    } 
}


void main()
{
    Uart1_Init();
    
    while(1)
    {
       
		Nixie(1,count/100);
		Nixie(2,count %100/10);
		Nixie(3,count%10 );
	
    }
}
