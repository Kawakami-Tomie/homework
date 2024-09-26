#include <REGX52.H>
#include "intrins.h"
#include "stdio.h"

unsigned int count = 0;

#define BUF_SIZE 2  // ��������С�����ڴ洢���յ�������  
  
unsigned char rx_buffer[BUF_SIZE];  // ���ջ�����  
unsigned char rx_index = 0;  // ���ջ��������� 

void Uart1_Init(void)	//4800bps@12.000MHz
{
  
	PCON |= 0x80;		//ʹ�ܲ����ʱ���λSMOD
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xF3;			//���ö�ʱ��ʼֵ
	TH1 = 0xF3;			//���ö�ʱ����ֵ
	ET1 = 0;			//��ֹ��ʱ���ж�
	TR1 = 1;			//��ʱ��1��ʼ��ʱ
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
	    if (RI) {  // ������յ�����  
        RI = 0;  // ��������жϱ�־λ  
        rx_buffer[rx_index++] = SBUF;  // �����յ������ݴ洢����������  
        if (rx_index == BUF_SIZE) {  // ������յ����㹻���ֽ�  
            count=(rx_buffer[0]<<8)+rx_buffer[1];// 
						count = (count-2)/3;
						UART_SendByte(count);
            rx_index = 0;  // ���û�����������׼��������һ������  
        }  
    } 
}

void main()
{
    Uart1_Init();
    
    while(1)
    {    
    }
}
