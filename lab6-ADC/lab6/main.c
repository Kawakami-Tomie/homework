#include "delay.h"
#include "seg.h"
#include "XPT2046.h"
#include "Nixie.h"

unsigned int ADValue;
bit flag1=0;
bit flag2=0;
bit flag3=0;
void Timer0_Init(void)		//1����@12.000MHz
{	
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0x18;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
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
	
		if(flag1 ==1){
			ADValue=XPT2046_ReadAD(XPT2046_XP);		//��ȡAIN0���ɵ�����
			Nixie_SetBuf(4,ADValue/1000%10);
			Nixie_SetBuf(3,(ADValue%1000/100)+12);
			Nixie_SetBuf(2,ADValue/10%10);
			Nixie_SetBuf(1,ADValue%10);
			Nixie_SetBuf(5,10);
			Nixie_SetBuf(6,10);
			Nixie_SetBuf(7,10);
			Nixie_SetBuf(8,1);
			flag1 =0;
		}
		if(flag2 ==1){
			ADValue=XPT2046_ReadAD(XPT2046_YP);		//��ȡAIN1���¶�
			Nixie_SetBuf(4,ADValue/1000);
			Nixie_SetBuf(3,(ADValue%1000/100)+12);
			Nixie_SetBuf(2,ADValue%100/10);
			Nixie_SetBuf(1,ADValue%10);
			Nixie_SetBuf(5,10);
			Nixie_SetBuf(6,10);
			Nixie_SetBuf(7,10);
			Nixie_SetBuf(8,2);
			flag2 =0;
		}
		if(flag3 ==1){
			ADValue=XPT2046_ReadAD(XPT2046_VBAT);	//��ȡAIN2����������
			Nixie_SetBuf(4,ADValue/1000);
			Nixie_SetBuf(3,(ADValue%1000/100)+12);
			
			Nixie_SetBuf(2,ADValue%100/10);
			Nixie_SetBuf(1,ADValue%10);
			Nixie_SetBuf(5,10);
			Nixie_SetBuf(6,10);
			Nixie_SetBuf(7,10);
			Nixie_SetBuf(8,3);
			flag3 =0;
		}
		Delay(100);
	}
}
void Timer0_Isr(void) interrupt 1
{
	static unsigned int T0Count1,T0Count2,T0Count3;
	TL0 = 0x18;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	T0Count3++;
	if(T0Count3>=1000){
		T0Count1++;
		T0Count3 = 0;
	}
	
	if(T0Count1<=10)
	{
		flag1 = 1;
	}
	else if(T0Count1>10&&T0Count1<=20){
		flag2 = 1;
	
	}
	else if(T0Count1>20&&T0Count1<=30){
		flag3 = 1;
	
	}
	else if(T0Count1>30){
		T0Count1=0;
	
	}
	T0Count2++;
	if(T0Count2>=2)
	{
		T0Count2=0;
		Nixie_Loop();//2ms����һ���������������
	}

}

