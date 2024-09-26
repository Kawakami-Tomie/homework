#include <reg51.h>  
 
sbit buzzer = P1^0;  
  
void Timer0Init(void)		//400微秒@11.0592MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x8F;		//设置定时初值
	TH0 = 0xFE;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}
 void main() {  
    Timer0Init();  

    while (1) {  
        
    }  
}

int T0Count=0;

void Timer0_ISR() interrupt 1 {  
	     
	T0Count++;
    TL0 = 0x8F;		//设置定时初值
	TH0 = 0xFE;		//设置定时初值
	if(T0Count%5==0){
    buzzer = 1; 
	}else buzzer = 0;	
      
}  
 

