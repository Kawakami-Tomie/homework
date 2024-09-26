#include "intrins.h"

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

void Delay1300ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 10;
	j = 27;
	k = 215;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
