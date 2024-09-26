#include <reg51.h>  
  

char sdata;  
// 串口初始化函数  
void Serial_Init() {  
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF9;			//设置定时初始值
	TH1 = 0xF9;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
  EA = 1; 
	ES = 1;				//使能串口1中断
}  
 

  

void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}


  
// 串口接收中断服务程序  
void Serial_ISR() interrupt 4 {  
    if (RI) {           // 检查接收中断标志  
        sdata = SBUF; // 读取接收到的数据  
        RI = 0;         // 清除接收中断标志  
        if (sdata >= 'a' && sdata <= 'z') {  
            sdata = 'A'; // 将小写字母转为大写  
        }
			
				UART_SendByte(sdata);

    }  
}  
  
void main() {  
    Serial_Init();      // 初始化串口  
  
    while (1) {  
        
    }  
}