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
  * @brief  获取独立按键键码
  * @param  无
  * @retval 按下按键的键码，范围：0~4，无按键按下时返回值为0
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
