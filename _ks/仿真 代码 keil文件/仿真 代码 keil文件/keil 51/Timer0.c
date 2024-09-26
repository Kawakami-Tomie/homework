#include <REG52.H>

/**
  * @brief  ��ʱ��0��ʼ����100us@12.000MHz
  * @param  ��
  * @retval ��
  */


void Timer0Init(void)		//100΢��@11.0592MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0xA4;				//���ö�ʱ��ʼֵ
	TH0 = 0xFF;				//���ö�ʱ��ʼֵ
	PT0 = 1;
}

void Timer1Init(void)		//20����@11.0592MHz
{
	TMOD &= 0x0F;			//���ö�ʱ��ģʽ
	TMOD |= 0x10;			//���ö�ʱ��ģʽ
	TL1 = 0x00;				//���ö�ʱ��ʼֵ
	TH1 = 0xDC;
	TR1 = 1;				//��ʱ��1��ʼ��ʱ
	PT1 = 0;
}

/*��ʱ���жϺ���ģ��
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x9C;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		
	}
}
*/
