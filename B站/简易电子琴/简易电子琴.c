//51头文件，使用51特殊功能寄存器
#include <reg51.h>
sbit SOUNDER = P3^7;
//声音的频率数据
unsigned int SoundFeqInit[]={64260,64400,64524,//低音5、6、7
							64580,64684,64777,64820,64898,64968,65030,//中音 1-7
							65058,65110,65157,65178,65218};//高音1、2、3、4、5

unsigned char Musical_note;	  //全局变量，存放音符对应的数组中的元素号

void delayms(unsigned char t);//延时函数声明

void main(void)
{
	unsigned char btn;
	P2 = 0xFF;
	TMOD |= 0x01; 	//定时器0工作方式1
	IE = 0x82;		//开总中断和定时器0中断
	TR0 = 0;		//定时器停止计数
	while(1)
	{
		P2 = 0xf0;						//列输入
		if(0xf0 != (P2&0xf0))  			//识别列中是否有键按下
		{
			delayms(10);				//去抖动
			if(0xf0 != (btn=P2&0xf0))	//再次识别并送列码
			{
				P2 = 0x0f;				//行输入
				btn |= (P2&0x0f);		//取行码，并与列码组合
				TR0 = 1;		//定时器开始计数
				switch(btn)				//判键值
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
	SOUNDER = ~SOUNDER;		 //反转引脚，输出方波，即输出频率不同的音符
}

//函数定义 1次
void delayms(unsigned char t)
{
	unsigned int	i,k;
	for(k=0;k<t;k++)
	{
		for(i=0;i<500;i++){;}	 //	500*2us= 1ms
	}
}