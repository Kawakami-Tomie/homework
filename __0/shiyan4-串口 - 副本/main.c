//#include <REGX52.H>
//#include "intrins.h"
//#include "stdio.h"
//unsigned char NixieTable[]={0x3F,0x06,0x5B,
//0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
//unsigned int count = 0;
//unsigned int count1 = 255;


//#define BUF_SIZE 1  // ��������С�����ڴ洢���յ�������  
//  
//unsigned char rx_buffer[BUF_SIZE];  // ���ջ�����  
//unsigned char rx_index = 0;  // ���ջ��������� 
//#define FOSC 12000000L  // ����Ƶ��12MHz  
//#define BAUD 9600       // ������9600  
//  
//// ��ʱ��1��װֵ�������ʷ�������  
//#define RELOAD_VALUE ((65536 - FOSC / 12 / 32 / BAUD)) 


//void Uart1_Init(void)	//4800bps@12.000MHz
//{
//  
////	PCON |= 0x80;		//ʹ�ܲ����ʱ���λSMOD
////	SCON = 0x50;		//8λ����,�ɱ䲨����
////	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
////	TMOD |= 0x20;		//���ö�ʱ��ģʽ
////	TL1 = 0xF3;			//���ö�ʱ��ʼֵ
////	TH1 = 0xF3;			//���ö�ʱ����ֵ
////	ET1 = 0;			//��ֹ��ʱ���ж�
////	TR1 = 1;			//��ʱ��1��ʼ��ʱ
////  EA = 1;
////  ES = 1;
//    TMOD |= 0x20;       // ���ö�ʱ��1Ϊģʽ2��8λ�Զ���װģʽ��  
//    TH1 = RELOAD_VALUE >> 8; // ���ö�ʱ����װֵ�ĸ�8λ  
//    TL1 = RELOAD_VALUE & 0xFF; // ���ö�ʱ����װֵ�ĵ�8λ  
//    TR1 = 1;            // ������ʱ��1  
//    SCON = 0x50;        // ���ô���Ϊģʽ1��������գ�REN=1��  
//    EA = 1;             // ����ȫ���ж�  
//    ES = 1;             // ���������ж�  
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
//	    if (RI) {  // ������յ�����  
//        RI = 0;  // ��������жϱ�־λ  
//        rx_buffer[rx_index++] = SBUF;  // �����յ������ݴ洢����������  
//        if (rx_index == BUF_SIZE) {  // ������յ����㹻���ֽ�  
//            count=rx_buffer[0];// ���������Ӵ�����յ������ݵĴ��� 
//        if (count >= 'a' && count <= 'z') {  
//            count = count - 'a' + 'A'; // ��Сд��ĸתΪ��д  
//        } 					
//						UART_SendByte(count);
//            rx_index = 0;  // ���û�����������׼��������һ������  
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
  
#define FOSC 12000000L  // ����Ƶ��12MHz  
#define BAUD 9600       // ������9600  
  
// ��ʱ��1��װֵ�������ʷ�������  
#define RELOAD_VALUE ((65536 - FOSC / 12 / 32 / BAUD))  
  
// ���ڳ�ʼ������  
void Serial_Init() {  
    TMOD |= 0x20;       // ���ö�ʱ��1Ϊģʽ2��8λ�Զ���װģʽ��  
    TH1 = RELOAD_VALUE >> 8; // ���ö�ʱ����װֵ�ĸ�8λ  
    TL1 = RELOAD_VALUE & 0xFF; // ���ö�ʱ����װֵ�ĵ�8λ  
    TR1 = 1;            // ������ʱ��1  
    SCON = 0x50;        // ���ô���Ϊģʽ1��������գ�REN=1��  
    EA = 1;             // ����ȫ���ж�  
    ES = 1;             // ���������ж�

  
}  
  
// ���ڽ����жϷ������  
void Serial_ISR() interrupt 4 {  
    if (RI) {           // �������жϱ�־  
        char data_ = SBUF; // ��ȡ���յ�������  
        RI = 0;         // ��������жϱ�־  
  
        // ���ݴ�����д���䣬Сд���д�����ֲ���  
        if (data_ >= 'a' && data_ <= 'z') {  
            data_ = data_ - 'a' + 'A'; // ��Сд��ĸתΪ��д  
        }  
  
        // ���ʹ���������  
        SBUF = data_;  
        while (!TI);    // �ȴ��������  
        TI = 0;         // ��������жϱ�־  
    }  
}  
  
void main() {  
    Serial_Init();      // ��ʼ������  
  
    while (1) {  
        // ������ѭ�����ȴ��жϷ���  
    }  
}