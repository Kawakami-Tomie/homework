#include <REGX52.H>

/**
  * @brief ���ڳ�ʼ��
  * @param  ��
  * @retval ��
  */
void Uart_Init()	//4800bps@11.0592MHz
{
	SCON=0x50;   //��ʽ1   REN��1 ����/��ֹ���ݽ��յĿ���λ  ������� REN��1
	PCON |= 0x80;  //�����ʼӱ�  
	
	//���ö�ʱ��1 ģʽ�� 8λ�Զ���װ
	TMOD&=0x0F;
	TMOD|=0x20;  //ģʽ��
	TL1 = 0xF4;		//�趨��ʱ��ֵ
	TH1 = 0xF4;		//�趨��ʱ����װֵ
	
	ET1=0;   //���ÿ����ж� ��ʱ��������������ǲ���������
	TR1=1;   //������ʱ��1
	
	//����������ɺ�ʹ����ж�
	ES=1;
	EA=1;
}

/**
  * @brief ���ڷ���һλ�ֽ�����
  * @param  Byte Ҫ���͵��ֽ�����
  * @retval ��
  */
void Uart_SendByte(unsigned char Byte)
{
	SBUF=Byte;   //�򻺴�����д������
	while(TI==0);   //�����жϱ�־λ �����⵽�˼Ĵ�����TIλ ���Ϊ0 �ͱ�ʾ����δ�������  ����ִ�б��������TIλ
	//���TIΪ1 �ͱ�ʾSUBF�������Ѿ����������  ����ִ��������佫TIλ����
	TI=0;
}

void main()
{
	Uart_Init();
	
	while(1)
	{
		
	}
}
void Uart_Routine() interrupt 4
{
	if(RI==1)   //������յ����� ������ɺ� �����ж� ����ǽ����ж�  
		//��������Ҳ������ж�
	{
		P2=SBUF;  //��SUBF�������ж�ȡ����
		Uart_SendByte(SBUF);
		RI=0;
	}
}



