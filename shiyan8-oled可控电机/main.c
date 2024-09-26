#include <REGX51.H>
#include "Delay.h"
#include "LCD9648.h"
#include "ST7565.h"

#include<intrins.h> //因为要用到左右移函数，所以加入这个头文件
typedef unsigned int u16; //对数据类型进行声明定义
typedef unsigned char u8;

////修改此值可改变电机旋转速度，不能过大或过小 2-10

sbit KEY1=P3^0;
sbit KEY2=P3^1;
sbit KEY3=P3^2;
sbit KEY4=P3^3;

 

int stepmove=0;//步进电机旋转标志位，0为停止，1为旋转

//typedef unsigned int u16;	//对系统默认数据类型进行重定义
//typedef unsigned char u8;
//typedef unsigned long u32;

 //使用宏定义独立按键按下的键值
#define KEY1_PRESS	1
#define KEY2_PRESS	2
#define KEY3_PRESS	3
#define KEY4_PRESS	4
#define KEY_UNPRESS	0

unsigned char key_scan()
{
	static u8 key=1;

//	if(mode)key=1;//连续扫描按键
	if(key==1&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))//任意按键按下
	{
		Delay(20);//消抖
		key=0;
		if(KEY1==0)
			return KEY1_PRESS;
		else if(KEY2==0)
			return KEY2_PRESS;
		else if(KEY3==0)
			return KEY3_PRESS;
		else if(KEY4==0)
			return KEY4_PRESS;	
	}
	else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1)	//无按键按下
	{
		key=1;			
	}
	return KEY_UNPRESS;		
}



unsigned char Counter,Compare;	//计数值和比较值，用于输出PWM
unsigned char KeyNum,Speed;

void Timer0_Init(void)
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x9C;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}

#define SPEEDMAX 20
void Timer0Init(void)		//1毫秒@12.000MHz
{
//	AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
}

	

void main()
{
	u8 key=0;
	u8 dir=0;
	u8 step=0;
	u8 speed=SPEEDMAX;	
  uchar i = 0;
  uchar j = 0;
	int flag=0;
	int fg=0;
	
  LCD_Init();
  Clear();
	Timer0_Init();
  while(1)
  {
	  
	  
	  if(key==KEY1_PRESS)//按键一按下令步进电机旋转或停止
			{
				stepmove=!stepmove;
			}				
		
			if(stepmove==1)	//判断是否要让步进电机旋转
			{
//				step_28byj48_control(step++,dir);
				if(step==8)	step=0;
				Delay(speed);
			}
			
			if(key==KEY4_PRESS)//按下按键四令步进电机反转	
			{
				dir=!dir;			
			}	
//*********步进电机速度控制环节		
			else if (key==KEY2_PRESS)//按下按键二令步进电机加速se if (key==KEY3_PRESS)  
			{
				if(speed>SPEEDMAX)
					speed-=1;
			}	
			{
//				if(speed<SPEEDMIN) //按下按键三令步进电机减速
					speed+=1;	
			}Delay(SPEEDMAX);//通过每一步的延时来调节步进电机的速度			

	  if(P3_4==0){Delay(20);while(P3_3==0);Delay(20);
		//flag=0;
	  
//			Speed++;
//			Speed%=6;
//			if(Speed==0){Compare=0;LCD12864_Write16CnCHAR(0,0,"院空空空空空");}	//设置比较值，改变PWM占空比
//			if(Speed==1){Compare=20;LCD12864_Write16CnCHAR(0,0,"术院空空空空");}
//			if(Speed==2){Compare=40;LCD12864_Write16CnCHAR(0,0,"技术院空空空");}
//			if(Speed==3){Compare=60;LCD12864_Write16CnCHAR(0,0,"村技术院空空");}
//			if(Speed==4){Compare=80;LCD12864_Write16CnCHAR(0,0,"湾村技术院空");}	//设置比较值，改变PWM占空比
//			if(Speed==5){Compare=100;LCD12864_Write16CnCHAR(0,0,"林湾村技术院");}
		
	  
	  
	  }

	  
	  
		
			  	if(P3_1==0)			//如果K2按键按下
		{
			flag=0;
			Delay(20);
			while(P3_1==0);
			Delay(20);

				
			  Clear();
			while(1){
			LCD12864_Write16CnCHAR(0,0,"院空空空空空");Compare=10;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"术院空空空空");Compare=30;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"技术院空空空");Compare=40;
			Delay(100);
			LCD12864_Write16CnCHAR(0,0,"村技术院空空");Compare=60;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"湾村技术院空");Compare=80;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"林湾村技术院");Compare=100;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"空林湾村技术");Compare=80;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"空空林湾村技");Compare=60;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"空空空林湾村");Compare=40;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"空空空空林湾");Compare=30;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"空空空空空林");	Compare=20;				
			Delay(100);

			if(P3_7==0) break;}
			
			
		}
		
		if(P3_5==0)			//如果K5按键按下
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			flag++;
		}
		if(P3_6==0)			//如果K6按键按下
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			fg++;
			flag--;
		}
		
		if(P3_7==0||flag==1)			//如果K7按键按下
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);				
			
			//compare=0;
		    LCD12864_Write16CnCHAR(0,0,"设置空空菜单");
		    LCD12864_Write16CnCHAR(0,4,"显示学校？空");
			flag=1;
			
		}
		
		if(flag==2){
		
	  
      LCD12864_Write16CnCHAR(0,0,"林湾村技术院");
		LCD12864_Write16CnCHAR(0,4,"显示专业？空");	
		
		}
		if(flag==3){
		
	  
      LCD12864_Write16CnCHAR(0,0,"电子信息空空");
			LCD12864_Write16CnCHAR(0,4,"显示姓名？空");	
		
		}
		if(flag==4){
		
	  
      LCD12864_Write16CnCHAR(0,0,"王乙斯空空空");
			LCD12864_Write16CnCHAR(0,4,"菜单空空空");	
		
		}	
		if(flag>=5)flag=1;		
		
    
  }
  
  
}





