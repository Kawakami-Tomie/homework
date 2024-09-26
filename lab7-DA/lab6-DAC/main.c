//#include "delay.h"
//#include "seg.h"
//#include "XPT2046.h"
//#include "Nixie.h"

//unsigned int ADValue;
//bit flag1=0;
//bit flag2=0;
//bit flag3=0;
//sbit DA=P2^1;

//unsigned char Counter,Compare;	//����ֵ�ͱȽ�ֵ���������PWM
//unsigned char i;



//void Timer0_Init(void)		//1΢��@12.000MHz
//{
////	AUXR |= 0x80;			//��ʱ��ʱ��1Tģʽ
//	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
//	TMOD |= 0x01;			//���ö�ʱ��ģʽ
//	TL0 = 0xFF;				//���ö�ʱ��ʼֵ
//	TH0 = 0xFF;				//���ö�ʱ��ʼֵ
//	TF0 = 0;				//���TF0��־
//	TR0 = 1;				//��ʱ��0��ʼ��ʱ
//	ET0 = 1;				//ʹ�ܶ�ʱ��0�ж�
//	EA=1;
//}




//void main(void)
//{
//	Timer0_Init();

//	while(1)
//	{
//			Compare=5;
//			ADValue=XPT2046_ReadAD(XPT2046_AUX);		//��ȡAIN0���ɵ�����
////			Nixie_Scan(8,ADValue/1000%10);
////			Nixie_Scan(7,(ADValue%1000/100)+12);
////			Nixie_Scan(5,ADValue/10%10);
////			Nixie_Scan(6,ADValue%10);
////			Nixie_Scan(1,10);
////			Nixie_Scan(2,10);
////			Nixie_Scan(3,10);
////	        Nixie_Scan(4,10);
////			Nixie_Loop();//����һ���������������
//			flag1 =0;
//				
//		Delay(80);
//	}
//}
//void Timer0_Isr(void) interrupt 1
//{
//	
//		
//	TL0 = 0xF0;				//���ö�ʱ��ʼֵ
//	TH0 = 0xFF;				//���ö�ʱ��ʼֵ
//	Counter++;
//	Counter%=10;	//����ֵ�仯��Χ������0~99
//	if(Counter<Compare)	//����ֵС�ڱȽ�ֵ
//	{
//		DA=1;		//���1
//	}
//	else				//����ֵ���ڱȽ�ֵ
//	{
//		DA=0;		//���0
//	}
//	
//}



//void Timer1_Isr(void) interrupt 3
//{
//	TL1 = 0x18;				//���ö�ʱ��ʼֵ
//	TH1 = 0xFC;				//���ö�ʱ��ʼֵ

//}

#include "delay.h"
#include "XPT2046.h"
#include "Nixie.h"

unsigned int ADValue;

sbit DA=P2^1;

unsigned char Counter,Compare;	//����ֵ�ͱȽ�ֵ���������PWM
unsigned char i;



void Timer0_Init(void)		//10us@12.000MHz
{
	
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0xFF;				//���ö�ʱ��ʼֵ
	TH0 = 0xFF;					
	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
	ET0 = 1;				//ʹ�ܶ�ʱ��0�ж�
	EA = 1;
	
}


void main(void)
{
	Timer0_Init();

	while(1)
	{
			Compare = 5;
			ADValue=XPT2046_ReadAD(XPT2046_AUX);		//��ȡAIN3���ɵ�����
//			Nixie_Scan(4,ADValue/1000%10);
//			Nixie_Scan(3,ADValue/100%10);
//			Nixie_Scan(2,ADValue/10%10);
//			Nixie_Scan(1,ADValue%10);
//			Nixie_Scan(5,10);
//			Nixie_Scan(6,10);
//			Nixie_Scan(7,10);
//			Nixie_Scan(8,10);
			Delay(20);
	}
}
void Timer0_Isr(void) interrupt 1
{
	P1_0 = ~P1_0;
	TL0 = 0xF0;				//���ö�ʱ��ʼֵ
	TH0 = 0xFF;					
	Counter++;
	Counter%=10;	//����ֵ�仯��Χ������0~99
	if(Counter<Compare)	//����ֵС�ڱȽ�ֵ
	{
		DA=1;		//���1
	}
	else				//����ֵ���ڱȽ�ֵ
	{
		DA=0;		//���0
	}
	
}

