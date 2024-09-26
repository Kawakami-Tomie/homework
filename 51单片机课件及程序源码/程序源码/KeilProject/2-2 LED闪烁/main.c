#include <REGX52.H>
#include <INTRINS.H>

void Delay200us(void)	//@12.000MHz
{
	unsigned char data i;

	_nop_();
	i = 97;
	while (--i);
}



void main()
{
	while(1)
	{
		P2_1=0;	//1111 1110
		Delay200us();
		P2_1=1;	//1111 1111
		Delay200us();
	}
}
