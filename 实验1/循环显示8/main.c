#include <REGX52.H>

//数码管段码表
unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0xFF,0x7F,0x6F};

////延时子函数
void Delayms(unsigned int xms)
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

//数码管显示子函数
void Nixie(unsigned char Location,Number)
{
	switch(Location)		
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=NixieTable[Number];
	Delayms(1);				
	P0=0x00;				
}

void main()
{
	while(1)
	{
		Nixie(4,8);		//在数码管的第1位置显示1
//		Delayms(1000);
//		Nixie(2,8);		
//		Delayms(1000);
//		Nixie(3,8);		
//		Delayms(1000);
//		Nixie(4,8);		
//		Delayms(1000);
//		Nixie(5,8);		
//		Delayms(1000);
//		Nixie(6,8);		
//		Delayms(1000);
//		Nixie(7,8);		
//		Delayms(1000);
//		Nixie(8,8);		
//		Delayms(1000);
	}
}
