#include <reg51.h>  
  

char sdata;  
// ���ڳ�ʼ������  
void Serial_Init() {  
	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xF9;			//���ö�ʱ��ʼֵ
	TH1 = 0xF9;			//���ö�ʱ����ֵ
	ET1 = 0;			//��ֹ��ʱ���ж�
	TR1 = 1;			//��ʱ��1��ʼ��ʱ
  EA = 1; 
	ES = 1;				//ʹ�ܴ���1�ж�
}  
 

  

void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}


  
// ���ڽ����жϷ������  
void Serial_ISR() interrupt 4 {  
    if (RI) {           // �������жϱ�־  
        sdata = SBUF; // ��ȡ���յ�������  
        RI = 0;         // ��������жϱ�־  
        if (sdata >= 'a' && sdata <= 'z') {  
            sdata = 'A'; // ��Сд��ĸתΪ��д  
        }
			
				UART_SendByte(sdata);

    }  
}  
  
void main() {  
    Serial_Init();      // ��ʼ������  
  
    while (1) {  
        
    }  
}