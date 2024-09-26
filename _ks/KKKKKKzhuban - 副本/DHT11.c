#include "reg52.H"
#include "intrins.h"
#include <math.h>


sbit  Data=P3^7;
unsigned char  hum;//湿度
unsigned char  tem;//温度


void Delay1s(unsigned char t)		//@12.0000MHz
{
	unsigned char i, j;
	while(t--)
		{
		_nop_();
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}

void DHT11_Init(void)
{
	Data = 1;
	Delay1s(1000);
}



void Delay10us()		//@11.0592MHz
{
	unsigned char i;

	i = 2;
	while (--i);
}

void Delay30us()		//@11.0592MHz
{
	unsigned char i;

	i = 11;
	while (--i);
}

void Delay40us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 15;
	while (--i);
}

void Delay80us()		//@11.0592MHz
{
	unsigned char i;

	i = 34;
	while (--i);
}


void Delay30ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 54;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void DHT11_start()
{
	Data = 1;
	Delay10us();
	Data = 0;
	Delay30ms();
	Data = 1;
	Delay30us();
}

unsigned char DHT11_rec_byte()      //接收一个字节
{
	unsigned char i,dat = 0;
	for( i = 0; i<8;i++)
	{
		while(Data == 0);
		Delay40us();
		dat <<= 1;
		if(Data == 1)
			dat += 1;
		while(Data == 1);
	}
	return dat;
}

void DHT11_receive()      //接收40位的数据
{
    unsigned char R_H,R_L,T_H,T_L,RH,RL,TH,TL,revise;
	DHT11_start();
	if(Data == 0)
	{
		while(Data == 0);
		while(Data == 1);
		R_H=DHT11_rec_byte();    //接收湿度高八位
        R_L=DHT11_rec_byte();    //接收湿度低八位
        T_H=DHT11_rec_byte();    //接收温度高八位
        T_L=DHT11_rec_byte();    //接收温度低八位
        revise=DHT11_rec_byte(); //接收校正位
		Delay30us();Delay30us();
		if((R_H+R_L+T_H+T_L)==revise)      //校正
		{
			RH=R_H;
			RL=R_L;
			TH=T_H;
			TL=T_L;
		}
		hum = RH;//湿度
		tem = TH;//温度
	}
}