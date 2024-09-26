//#include <REGX52.H>
//#include "intrins.h"
//#include "stdio.h"
//unsigned char NixieTable[]={0x3F,0x06,0x5B,
//0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
//unsigned int count = 0;
//unsigned int count1 = 255;


//#define BUF_SIZE 1  // 缓冲区大小，用于存储接收到的数据  
//  
//unsigned char rx_buffer[BUF_SIZE];  // 接收缓冲区  
//unsigned char rx_index = 0;  // 接收缓冲区索引 
//#define FOSC 12000000L  // 晶振频率12MHz  
//#define BAUD 9600       // 波特率9600  
//  
//// 定时器1重装值（波特率发生器）  
//#define RELOAD_VALUE ((65536 - FOSC / 12 / 32 / BAUD)) 


//void Uart1_Init(void)	//4800bps@12.000MHz
//{
//  
////	PCON |= 0x80;		//使能波特率倍速位SMOD
////	SCON = 0x50;		//8位数据,可变波特率
////	TMOD &= 0x0F;		//设置定时器模式
////	TMOD |= 0x20;		//设置定时器模式
////	TL1 = 0xF3;			//设置定时初始值
////	TH1 = 0xF3;			//设置定时重载值
////	ET1 = 0;			//禁止定时器中断
////	TR1 = 1;			//定时器1开始计时
////  EA = 1;
////  ES = 1;
//    TMOD |= 0x20;       // 设置定时器1为模式2（8位自动重装模式）  
//    TH1 = RELOAD_VALUE >> 8; // 设置定时器重装值的高8位  
//    TL1 = RELOAD_VALUE & 0xFF; // 设置定时器重装值的低8位  
//    TR1 = 1;            // 启动定时器1  
//    SCON = 0x50;        // 设置串口为模式1，允许接收（REN=1）  
//    EA = 1;             // 开启全局中断  
//    ES = 1;             // 开启串口中断  
//}
//void UART_SendByte(unsigned char Byte)
//{
//	SBUF=Byte;
//	while(TI==0);
//	TI=0;
//}

//void Uart_Isr() interrupt 4 using 1
//{
//	
//	    if (RI) {  // 如果接收到数据  
//        RI = 0;  // 清除接收中断标志位  
//        rx_buffer[rx_index++] = SBUF;  // 将接收到的数据存储到缓冲区中  
//        if (rx_index == BUF_SIZE) {  // 如果接收到了足够的字节  
//            count=rx_buffer[0];// 这里可以添加处理接收到的数据的代码 
//        if (count >= 'a' && count <= 'z') {  
//            count = count - 'a' + 'A'; // 将小写字母转为大写  
//        } 					
//						UART_SendByte(count);
//            rx_index = 0;  // 重置缓冲区索引，准备接收下一组数据  
//        }  
//    } 
//}


//void main()
//{
//    Uart1_Init();
//    
//    while(1)
//    {

//	
//    }
//}


#include <reg51.h>  
  
#define FOSC 12000000L  // 晶振频率12MHz  
#define BAUD 9600       // 波特率9600  
  
// 定时器1重装值（波特率发生器）  
#define RELOAD_VALUE ((65536 - FOSC / 12 / 32 / BAUD))  
  
// 串口初始化函数  
void Serial_Init() {  
    TMOD |= 0x20;       // 设置定时器1为模式2（8位自动重装模式）  
    TH1 = RELOAD_VALUE >> 8; // 设置定时器重装值的高8位  
    TL1 = RELOAD_VALUE & 0xFF; // 设置定时器重装值的低8位  
    TR1 = 1;            // 启动定时器1  
    SCON = 0x50;        // 设置串口为模式1，允许接收（REN=1）  
    EA = 1;             // 开启全局中断  
    ES = 1;             // 开启串口中断

  
}  
  
// 串口接收中断服务程序  
void Serial_ISR() interrupt 4 {  
    if (RI) {           // 检查接收中断标志  
        char data_ = SBUF; // 读取接收到的数据  
        RI = 0;         // 清除接收中断标志  
  
        // 数据处理：大写不变，小写变大写，数字不变  
        if (data_ >= 'a' && data_ <= 'z') {  
            data_ = data_ - 'a' + 'A'; // 将小写字母转为大写  
        }  
  
        // 发送处理后的数据  
        SBUF = data_;  
        while (!TI);    // 等待发送完成  
        TI = 0;         // 清除发送中断标志  
    }  
}  
  
void main() {  
    Serial_Init();      // 初始化串口  
  
    while (1) {  
        // 主程序循环，等待中断发生  
    }  
}