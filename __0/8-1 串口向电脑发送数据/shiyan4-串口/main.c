#include <REGX52.H>
#include "intrins.h"
#include "stdio.h"
unsigned char NixieTable[]={0x3F,0x06,0x5B,
0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int count = 0;
unsigned int count1 = 255;


#define BUF_SIZE 2  // ��������С�����ڴ洢���յ�������  
  
unsigned char rx_buffer[BUF_SIZE];  // ���ջ�����  
unsigned char rx_index = 0;  // ���ջ��������� 


void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}

void Nixie(unsigned char Location, unsigned char Number)
{
    switch(Location){
        case 1: P2_4=0; P2_3=0; P2_2=0; break;
        case 2: P2_4=0; P2_3=0; P2_2=1; break;
        case 3: P2_4=0; P2_3=1; P2_2=0; break;
        case 4: P2_4=0; P2_3=1; P2_2=1; break;     
        case 5: P2_4=1; P2_3=0; P2_2=0; break;
        case 6: P2_4=1; P2_3=0; P2_2=1; break;    
        case 7: P2_4=1; P2_3=1; P2_2=0; break;
        case 8: P2_4=1; P2_3=1; P2_2=1; break;
    }

    P0 = NixieTable[Number];      // �������
    Delay(1);                                // ��ʾһ��ʱ��
    P0 = 0x00;                               // ������0����Ӱ
}
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
            count=(rx_buffer[0]<<8)+rx_buffer[1];// ���������Ӵ�����յ������ݵĴ���  
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
       
		Nixie(1,count/100);
		Nixie(2,count %100/10);
		Nixie(3,count%10 );
	
    }
}
