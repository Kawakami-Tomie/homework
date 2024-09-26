
#include <reg51.h>  
  
//500HZ
//  TL0 = 0x66;		//设置定时初值
//  TH0 = 0xFC;		//设置定时初值
//1KHz
//	TL0 = 0x33;		//设置定时初值
//	TH0 = 0xFE;
//10KHz
//TL0 = 0xD7;		//设置定时初值
//TH0 = 0xFD;
//100KHz
//TL0 = 0xC9;		//设置定时初值
//TH0 = 0xFF;		//设置定时初值
  
sbit buzzer = P1^0;  
  
 
    void Timer0Init(void)		//1毫秒@11.0592MHz
{
	
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
}
  

  

void main() {  
    Timer0Init();  
    while (1) {  
        
    }  
}

void Timer0_ISR() interrupt 1 {  
    static unsigned char state = 0;  
    TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
    state = ~state;   
    buzzer = state;   
}  
  