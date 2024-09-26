#include <REGX52.H>


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


/**
  * @brief  ��ȡ������������
  * @param  ��
  * @retval ���°����ļ��룬��Χ��0~4���ް�������ʱ����ֵΪ0
  */
unsigned char Key()
{
	unsigned char KeyNumber=0;
	
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=1;}//set
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=2;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=3;}
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=4;}
	return KeyNumber;
}
