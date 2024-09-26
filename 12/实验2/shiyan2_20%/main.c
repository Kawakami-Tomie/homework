#include <reg51.h>  
 
sbit buzzer = P1^0;  
  
void Timer0Init(void)		//400΢��@11.0592MHz
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x8F;		//���ö�ʱ��ֵ
	TH0 = 0xFE;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
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
    TL0 = 0x8F;		//���ö�ʱ��ֵ
	TH0 = 0xFE;		//���ö�ʱ��ֵ
	if(T0Count%5==0){
    buzzer = 1; 
	}else buzzer = 0;	
      
}  
 

