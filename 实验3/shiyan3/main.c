#include <REGX51.H>
unsigned int count = 0;
unsigned int number = 0;
unsigned char NixieTable[]={0x3F,0x06,0x5B,
0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void Timer0_Isr(void) interrupt 1
{
  static unsigned int count_1 = 0;
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
  P1_0=~P1_0;
  count_1++;
  if(count_1>=1000){
		number = count;
		count = 0;
		count_1=0;
	}
}

void Timer0_Init(void)		//1毫秒@12.000MHz
{
	
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0 = 1;				//使能定时器0中断
  EA = 1;
}
void Int0_Init(){
	IT0 = 1; // 边沿触发方式（下降沿) 
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
//数码管显示子函数
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
  P0=NixieTable[Number];	//段码输出
	Delay(1);				//显示一段时间
	P0=0x00;				//段码清0，消影
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