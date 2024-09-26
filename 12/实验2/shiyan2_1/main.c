
#include <reg51.h>  
  
#define FOSC 11059200L  // 晶振频率  
#define TIMER0_RELOAD_VALUE 60928  // 定时器重载值  
  
sbit buzzer = P1^0;  
  
void Timer0_Init() {  
    TMOD &= 0xF0;   
    TMOD |= 0x01;  
	  TH0=237;
	  TL0=176;
    ET0 = 1;   
    EA = 1;   
    TR0 = 1;   
}  
  

void main() {  
    Timer0_Init();  
    while (1) {  
        
    }  
}

void Timer0_ISR() interrupt 1 {  
    static unsigned char state = 0;  
    TH0=237;
	TL0=176;
    state = ~state;   
    buzzer = state;   
}  
  