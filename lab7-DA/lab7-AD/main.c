#include <REGX52.H>
#include "XPT2046.h"
#include "Nixie.h"
unsigned int ADValue;

unsigned char count = 0;
unsigned char compared = 2;

void Timer1_Isr(void) interrupt 3
	
{
//	TL1 = 0xFC;				//���ö�ʱ��ʼֵ
//	TH1 = 0xFC;				//���ö�ʱ����ֵ
	count++;
	if(count >= 10){
		count = 0;
	}
	if(count < compared){
		P2_1 = 1;
	}
	else{
		P2_1 = 0;
	}
}

void Timer1_Init(void)		
{
	TMOD &= 0x0F;			//���ö�ʱ��ģʽ
	TMOD |= 0x20;			//���ö�ʱ��ģʽ
	TL1 = 0xFF;				//���ö�ʱ��ʼֵ
	TH1 = 0xFF;				//���ö�ʱ����ֵ
	TF1 = 0;				//���TF1��־
	TR1 = 1;				//��ʱ��1��ʼ��ʱ
	ET1 = 1;				//ʹ�ܶ�ʱ��1�ж�

	EA = 1;
}


void main(){
	Timer1_Init();
	while(1){
		
			ADValue=XPT2046_ReadAD(XPT2046_AUX);		//��ȡAIN3���ɵ�����
//			Nixie_SetBuf(4,ADValue/1000%10);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
//			Nixie_SetBuf(3,ADValue/100%10);
//			Nixie_SetBuf(2,ADValue/10%10);
//			Nixie_SetBuf(1,ADValue%10);
//			Nixie_SetBuf(5,10);
//			Nixie_SetBuf(6,10);
//			Nixie_SetBuf(7,10);
//			Nixie_SetBuf(8,10);

	}
}