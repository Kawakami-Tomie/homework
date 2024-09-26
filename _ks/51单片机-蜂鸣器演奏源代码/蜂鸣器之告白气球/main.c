#include <REGX52.H>
#include "Delay.h"
#include "Time.h"

//���������
sbit Buzzer = P2^5;

//�����ٶ�
#define SPEED 100

//��,��,����
#define P0  0
#define L1  1
#define L1_ 2
#define L2  3
#define L2_ 4
#define L3  5
#define L4  6
#define L4_ 7
#define L5  8
#define L5_ 9
#define L6  10
#define L6_ 11
#define L7  12
#define M1  13
#define M1_ 14
#define M2  15
#define M2_ 16
#define M3  17
#define M4  18
#define M4_ 19
#define M5  20
#define M5_ 21
#define M6  22
#define M6_ 23
#define M7  24
#define H1  25
#define H1_ 26
#define H2  27
#define H2_ 28
#define H3  29
#define H4  30
#define H4_ 31
#define H5  32
#define H5_ 33
#define H6  34
#define H6_ 35
#define H7  36

//����װֵ
unsigned int FreqTable[]=
{
	 63628,63731,63835,63928,64021,64103,64185,64260,64331,64400,64463,64528,
	 64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030,
   65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283,
};

//��������������
unsigned char code Music[]={
	//�ܽ���-���������
	//��һ��
	P0,4,
	P0,2,
	M5,2,
	H1,2,
	M7,2,
	M5,2,
	M1,2,
	
	M1,4,
	M5,2,
	M2,4,
	M3,2,
	M3,2,
	
	M3,4,
	P0,2,
	M5,2,
	H1,2,
	M4,2,
	M5,2,
	M1,2,
	
	M1,4,
	M5,2,
	M2,4,
	M3,2,
	M4,2,
	M3,2,
	
	//�ڶ���
	M3,4,
	P0,2,
	M5,2,
	H2,2,
	H1,2,
	M7,2,
	H1,2,
	
	H1,4,
	H2,2,
	H3,4,
	H1,2,
	H1,2,
	M6,2,
	
	M6,4,
	M7,2,
	H1,4,
	M5,2,
	M5,2,
	M1,2,
	
	M5,2,
	M4,2,
	M3,2,
	M2,4,
	M1,2,
	M1,4,
	
	//������
	M1,4+2,
	L7,2,
	L7,4+4,
	
	P0,1,
	H1,1,
	H1,1,
	M7,1,
	H1,2,
	P0,1,
	M7,1,
	H1,1,
	M1,1,
	H1,2,
	P0,2,
	H2,1,
	H3,1,
	
	//������
	P0,1,
	M7,1,
	M7,1,
	M6,1,
	M7,2,
	P0,1,
	M6,1,
	M7,1,
	M6,1,
	M7,2,
	P0,2,
	H1,2,
	
	P0,4,
	M6,2,
	H1,2,
	H3,2,
	H2,2,
	H1,2,
	H3,2,
	
	H3,4+4,
	P0,2,
	H3,2,
	H3,2,
	H2,1,
	H1,1,
	
	//������
	P0,1,
	H1,1,
	H1,1,
	M7,1,
	H1,2,
	P0,1,
	M7,1,
	H1,1,
	M7,1,
	H1,2,
	P0,2,
	H2,2,
	H3,2,
	
	P0,1,
	M7,1,
	M7,1,
	M6,1,
	M7,2,
	P0,1,
	M6,1,
	M7,1,
	M6,1,
	M7,2,
	P0,2,
	H1,2,
	
	//������
	P0,4,
	M6,2,
	H1,2,
	H3,2,
	H2,2,
	H1,2,
	H1,2,
	
	H1,4+4+4,
	M6,2,
	M7,2,
	
	H1,2,
	H1,2,
	H1,2,
	H1,2,
	M6,4,
	M6,2,
	M7,2,
	
	//������
	H1,2,
	H1,2,
	H1,2,
	H2,2,
	H2,4,
	H5,2,
	H6,2,
	
	M7,2,
	M7,2,
	M7,2,
	M7,2,
	M5,4,
	M5,2,
	M6,2,
	
	M7,2,
	M7,2,
	M7,2,
	H1,2,
	H1,2+1,
	H1,1,
	H1,2,
	H2,2,
	
	//�ڰ���
	H3,2,
	H3,2,
	H3,2,
	M6,2,
	H1,4,
	H1,2,
	H2,2,
	
	H3,2,
	H3,2,
	H6,2,
	H3,1,
	H2,1,
	H1,4,
	H1,2,
	H2,2,
	
	H3,2,
	H3,2,
	H3,2,
	H3,4,
	H1,2,
	H3,2,
	H2,2,
	
	//�ھ���ͬ����1
	H2,4+4,
	P0,2,
	M5,2,
	H4,2,
	H3,2,
	
	H3,4,
	H4,2,
	H3,4,
	H2,2,
	H2,4,
	
	H1,4,
	H2,2,
	H3,4,
	H6,2,
	H6,4,
	
	H5,4,
	M7,2,
	H1,4,
	H2,2,
	H2,2,
	H1,2,
	
	//�ھ���ͬ����2
	H2,4+4,
	P0,2,
	M5,2,
	H4,2,
	H3,2,
	
	H3,4,
	H4,2,
	H3,4,
	H2,2,
	H2,4,
	
	H1,4,
	H2,2,
	H3,4,
	H6,2,
	H6,4,
	
	H5,4,
	M7,2,
	H1,4,
	H2,2,
	H2,2,
	H1,2,
	
	//��ʮ��ͬ����1
	H3,4+4,
	P0,2,
	M5,2,
	H4,2,
	H3,2,
	
	H3,4,
	H4,2,
	H3,4,
	H2,2,
	H2,4,
	
	H1,4,
	H2,2,
	H3,4,
	H6,2,
	H6,4,
	
	H5,4,
	M7,2,
	H1,4,
	H2,2,
	H2,2,
	H1,2,
	
	//��ʮ��ͬ����2
	H3,4+4,
	P0,2,
	M5,2,
	H4,2,
	H3,2,
	
	H3,4,
	H4,2,
	H3,4,
	H2,2,
	H2,4,
	
	H1,4,
	H2,2,
	H3,4,
	H6,2,
	H6,4,
	
	H5,4,
	M7,2,
	H1,4,
	H2,2,
	H2,2,
	H1,2,
	//��ʮ��ͬ����3
	H3,4+4,
	P0,2,
	M5,2,
	H4,2,
	H3,2,
	
	H3,4,
	H4,2,
	H3,4,
	H2,2,
	H2,4,
	
	H1,4,
	H2,2,
	H3,4,
	H6,2,
	H6,4,
	
	H5,4,
	M7,2,
	H1,4,
	H2,2,
	H2,2,
	H1,2,
	
	//��ʮһ��
	H1,4+4+4,
	H1,2,
	H2,2,
	
	H3,4,
	H5,4,
	H2,4+4,
	
	H1,4,
	H5,4,
	M7,4+2,
	M7,1,
	M7,1,
	
	M6,4,
	M7,4,
	H1,4+2,
	H2,2,
	
	H3,4+4,
	P0,2,
	M5,2,
	H1,2,
	H2,2,
	//��
	0xFF
	
};

//����
unsigned char FreqSelect,MusicSelect;

//������
void main()
{
	Timer0Init();
	while(1)
	{
		if(Music[MusicSelect]!=0xFF)
		{
		FreqSelect=Music[MusicSelect];
		MusicSelect++;
		Delay(SPEED/4*Music[MusicSelect]);
		MusicSelect++;
		TR0=0;
		Delay(5);
		TR0=1;
		}
		else
		{
			TR0=0;
			while(1);
		}
	}
}

void Timer0_Routine() interrupt 1
{
	if(FreqTable[FreqSelect])
	{
			TL0 = FreqTable[FreqSelect]%256;
			TH0 = FreqTable[FreqSelect]/256;
			Buzzer=!Buzzer;
	
	}

}
