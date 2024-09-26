//51ͷ�ļ���ʹ��51���⹦�ܼĴ���
#include <reg51.h>
sbit SOUNDER = P3^7;
//������Ƶ������
unsigned int SoundFeqInit[]={64260,64400,64524,//����5��6��7
							64580,64684,64777,64820,64898,64968,65030,//���� 1-7
							65058,65110,65157,65178,65218};//����1��2��3��4��5

unsigned char Musical_note;	  //ȫ�ֱ��������������Ӧ�������е�Ԫ�غ�

void delayms(unsigned char t);//��ʱ��������

void main(void)
{
	unsigned char btn;
	P2 = 0xFF;
	TMOD |= 0x01; 	//��ʱ��0������ʽ1
	IE = 0x82;		//�����жϺͶ�ʱ��0�ж�
	TR0 = 0;		//��ʱ��ֹͣ����
	while(1)
	{
		P2 = 0xf0;						//������
		if(0xf0 != (P2&0xf0))  			//ʶ�������Ƿ��м�����
		{
			delayms(10);				//ȥ����
			if(0xf0 != (btn=P2&0xf0))	//�ٴ�ʶ��������
			{
				P2 = 0x0f;				//������
				btn |= (P2&0x0f);		//ȡ���룬�����������
				TR0 = 1;		//��ʱ����ʼ����
				switch(btn)				//�м�ֵ
				{						 
					case 0xee:Musical_note = 0;break; 
					case 0xde:Musical_note = 1;break;
					case 0xbe:Musical_note = 2;break; 
					case 0x7e:Musical_note = 3;break; 
					case 0xed:Musical_note = 4;break;
					case 0xdd:Musical_note = 5;break;
					case 0xbd:Musical_note = 6;break;
					case 0x7d:Musical_note = 7;break;
					case 0xeb:Musical_note = 8;break;
					case 0xdb:Musical_note = 9;break;
					case 0xbb:Musical_note = 10;break;
					case 0x7b:Musical_note = 11;break;
					case 0xe7:Musical_note = 12;break;
					case 0xd7:Musical_note = 13;break;
					case 0xb7:Musical_note = 14;break;
					default:TR0 = 0;break;
				}
			}
		} 
		if(0xf0 == P2)
		{
			TR0 = 0;
			SOUNDER = 1;
		}
	}
}

void T0Sev(void) interrupt 1
{
	TH0 =  SoundFeqInit[Musical_note] / 256;
	TL0 =  SoundFeqInit[Musical_note] % 256;
	SOUNDER = ~SOUNDER;		 //��ת���ţ���������������Ƶ�ʲ�ͬ������
}

//�������� 1��
void delayms(unsigned char t)
{
	unsigned int	i,k;
	for(k=0;k<t;k++)
	{
		for(i=0;i<500;i++){;}	 //	500*2us= 1ms
	}
}