#include <REGX51.H>
unsigned int count = 0;
unsigned int number = 0;
unsigned char NixieTable[]={0x3F,0x06,0x5B,
0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void Timer0_Isr(void) interrupt 1
{
  static unsigned int count_1 = 0;
	TL0 = 0x18;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
  P1_0=~P1_0;
  count_1++;
  if(count_1>=1000){
		number = count;
		count = 0;
		count_1=0;
	}
}

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
void Int0_Init(){
	IT0 = 1; // ���ش�����ʽ���½���) 
	EX0 = 1;
	EA = 1;
}

void INTCounts() interrupt 0{
	count++;
}

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
//�������ʾ�Ӻ���
void Nixie(unsigned char Location,Number)
{
	switch(Location){
    case 1:P2_4=0;P2_3=0;P2_2=0;break;
    case 2:P2_4=0;P2_3=0;P2_2=1;break;
		case 3:P2_4=0;P2_3=1;P2_2=0;break;
    case 4:P2_4=0;P2_3=1;P2_2=1;break;     
    case 5:P2_4=1;P2_3=0;P2_2=0;break;
    case 6:P2_4=1;P2_3=0;P2_2=1;break;    
    case 7:P2_4=1;P2_3=1;P2_2=0;break;
    case 8:P2_4=1;P2_3=1;P2_2=1;break;
  }
  P0=NixieTable[Number];	//�������
	Delay(1);				//��ʾһ��ʱ��
	P0=0x00;				//������0����Ӱ
}
void main(){
	Timer0_Init();
	Int0_Init();
	while(1){
		Nixie(1,number /100);
		Nixie(2,number %100/10);
		Nixie(3,number %10);
		
	}
}