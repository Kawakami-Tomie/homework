
#include <reg51.h>  
  
//500HZ
//  TL0 = 0x66;		//���ö�ʱ��ֵ
//  TH0 = 0xFC;		//���ö�ʱ��ֵ
//1KHz
//	TL0 = 0x33;		//���ö�ʱ��ֵ
//	TH0 = 0xFE;
//10KHz
//TL0 = 0xD7;		//���ö�ʱ��ֵ
//TH0 = 0xFD;
//100KHz
//TL0 = 0xC9;		//���ö�ʱ��ֵ
//TH0 = 0xFF;		//���ö�ʱ��ֵ
  
sbit buzzer = P1^0;  
  
 
    void Timer0Init(void)		//1����@11.0592MHz
{
	
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x66;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
}
  

  

void main() {  
    Timer0Init();  
    while (1) {  
        
    }  
}

void Timer0_ISR() interrupt 1 {  
    static unsigned char state = 0;  
    TL0 = 0x66;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
    state = ~state;   
    buzzer = state;   
}  
  