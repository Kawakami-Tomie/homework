#include <REGX52.H>




#define RELOAD_COUNT 0xFA //�궨�岨���ʷ�����������ֵ 9600

//������������
void UART_Init(void)
{
	SCON=0X50;			//����Ϊ������ʽ1
	TMOD=0X20;			//���ü�����������ʽ2
	PCON=0X80;			//�����ʼӱ�
	TH1=RELOAD_COUNT;	//��������ʼֵ����
	TL1=TH1;
	ES=1;				//�򿪽����ж�
	EA=1;				//�����ж�
	TR1=1;				//�򿪼�����
}


void UART_SendByte(unsigned char dat)
{
	ES=0; //�رմ����ж�
	TI=0; //�巢������ж������־λ
	SBUF=dat; //����
	while(TI==0); //�ȴ��������
	TI=0; //�巢������ж������־λ
	ES=1; //�������ж�
}

