#include <REGX51.H>
#include "Delay.h"
#include "LCD9648.h"
#include "ST7565.h"

#include<intrins.h> //��ΪҪ�õ������ƺ��������Լ������ͷ�ļ�
typedef unsigned int u16; //���������ͽ�����������
typedef unsigned char u8;

////�޸Ĵ�ֵ�ɸı�����ת�ٶȣ����ܹ�����С 2-10

sbit KEY1=P3^0;
sbit KEY2=P3^1;
sbit KEY3=P3^2;
sbit KEY4=P3^3;

 

int stepmove=0;//���������ת��־λ��0Ϊֹͣ��1Ϊ��ת

//typedef unsigned int u16;	//��ϵͳĬ���������ͽ����ض���
//typedef unsigned char u8;
//typedef unsigned long u32;

 //ʹ�ú궨������������µļ�ֵ
#define KEY1_PRESS	1
#define KEY2_PRESS	2
#define KEY3_PRESS	3
#define KEY4_PRESS	4
#define KEY_UNPRESS	0

unsigned char key_scan()
{
	static u8 key=1;

//	if(mode)key=1;//����ɨ�谴��
	if(key==1&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))//���ⰴ������
	{
		Delay(20);//����
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
	else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1)	//�ް�������
	{
		key=1;			
	}
	return KEY_UNPRESS;		
}



unsigned char Counter,Compare;	//����ֵ�ͱȽ�ֵ���������PWM
unsigned char KeyNum,Speed;

void Timer0_Init(void)
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x9C;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0=1;
	EA=1;
	PT0=0;
}

#define SPEEDMAX 20
void Timer0Init(void)		//1����@12.000MHz
{
//	AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x18;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
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
	  
	  
	  if(key==KEY1_PRESS)//����һ������������ת��ֹͣ
			{
				stepmove=!stepmove;
			}				
		
			if(stepmove==1)	//�ж��Ƿ�Ҫ�ò��������ת
			{
//				step_28byj48_control(step++,dir);
				if(step==8)	step=0;
				Delay(speed);
			}
			
			if(key==KEY4_PRESS)//���°�������������ת	
			{
				dir=!dir;			
			}	
//*********��������ٶȿ��ƻ���		
			else if (key==KEY2_PRESS)//���°���������������se if (key==KEY3_PRESS)  
			{
				if(speed>SPEEDMAX)
					speed-=1;
			}	
			{
//				if(speed<SPEEDMIN) //���°���������������
					speed+=1;	
			}Delay(SPEEDMAX);//ͨ��ÿһ������ʱ�����ڲ���������ٶ�			

	  if(P3_4==0){Delay(20);while(P3_3==0);Delay(20);
		//flag=0;
	  
//			Speed++;
//			Speed%=6;
//			if(Speed==0){Compare=0;LCD12864_Write16CnCHAR(0,0,"Ժ�տտտտ�");}	//���ñȽ�ֵ���ı�PWMռ�ձ�
//			if(Speed==1){Compare=20;LCD12864_Write16CnCHAR(0,0,"��Ժ�տտտ�");}
//			if(Speed==2){Compare=40;LCD12864_Write16CnCHAR(0,0,"����Ժ�տտ�");}
//			if(Speed==3){Compare=60;LCD12864_Write16CnCHAR(0,0,"�弼��Ժ�տ�");}
//			if(Speed==4){Compare=80;LCD12864_Write16CnCHAR(0,0,"��弼��Ժ��");}	//���ñȽ�ֵ���ı�PWMռ�ձ�
//			if(Speed==5){Compare=100;LCD12864_Write16CnCHAR(0,0,"����弼��Ժ");}
		
	  
	  
	  }

	  
	  
		
			  	if(P3_1==0)			//���K2��������
		{
			flag=0;
			Delay(20);
			while(P3_1==0);
			Delay(20);

				
			  Clear();
			while(1){
			LCD12864_Write16CnCHAR(0,0,"Ժ�տտտտ�");Compare=10;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"��Ժ�տտտ�");Compare=30;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"����Ժ�տտ�");Compare=40;
			Delay(100);
			LCD12864_Write16CnCHAR(0,0,"�弼��Ժ�տ�");Compare=60;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"��弼��Ժ��");Compare=80;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"����弼��Ժ");Compare=100;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"������弼��");Compare=80;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"�տ�����弼");Compare=60;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"�տտ������");Compare=40;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"�տտտ�����");Compare=30;
			Delay(100);
				if(P3_7==0) break;
			LCD12864_Write16CnCHAR(0,0,"�տտտտ���");	Compare=20;				
			Delay(100);

			if(P3_7==0) break;}
			
			
		}
		
		if(P3_5==0)			//���K5��������
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			flag++;
		}
		if(P3_6==0)			//���K6��������
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			fg++;
			flag--;
		}
		
		if(P3_7==0||flag==1)			//���K7��������
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);				
			
			//compare=0;
		    LCD12864_Write16CnCHAR(0,0,"���ÿտղ˵�");
		    LCD12864_Write16CnCHAR(0,4,"��ʾѧУ����");
			flag=1;
			
		}
		
		if(flag==2){
		
	  
      LCD12864_Write16CnCHAR(0,0,"����弼��Ժ");
		LCD12864_Write16CnCHAR(0,4,"��ʾרҵ����");	
		
		}
		if(flag==3){
		
	  
      LCD12864_Write16CnCHAR(0,0,"������Ϣ�տ�");
			LCD12864_Write16CnCHAR(0,4,"��ʾ��������");	
		
		}
		if(flag==4){
		
	  
      LCD12864_Write16CnCHAR(0,0,"����˹�տտ�");
			LCD12864_Write16CnCHAR(0,4,"�˵��տտ�");	
		
		}	
		if(flag>=5)flag=1;		
		
    
  }
  
  
}





