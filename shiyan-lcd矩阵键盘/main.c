#include <REGX51.H>
#include "LCD1602.h"
 
#include "MatrixKey.h"
/***********************************************

				| 1 | | 2 | | 3 | | 4 |
				| 5 | | 6 | | 7 | | 8 |
				| 9 | | 0 | | + | | - |
				| * | | / | | = | |clear|

***********************************************/
 
int shuju[5];  //存放数据的数组
char yunsuan[5];   //存放运算符的数组
int keynum;  //返回矩阵键盘的
int dat;
int j=0;
int bb=0;
int i=0;
int jj;
int ii;
int j3=0;
int i3=0;
int yshuju[5];    //存储*与/对应的数据
char youxian[5];  //存储 *与/运算符的数组
 
void result() //结果显示函数
{
	LCD_ShowString(1,16," ");
	if(shuju[jj]<=9){LCD_ShowNum(2,8,shuju[jj],1);}
	if(shuju[jj]>9&&shuju[jj]<=99){LCD_ShowNum(2,8,shuju[jj],2);}
	if(shuju[jj]>99&&shuju[jj]<=999){LCD_ShowNum(2,8,shuju[jj],3);}
}
 
void showdata()  //显示输入的数据
{
	
	if(dat<=9){LCD_ShowNum(1,1,dat,1);}
	if(dat>9&&dat<=99){LCD_ShowNum(1,1,dat,2);}
	if(dat>99&&dat<=999){LCD_ShowNum(1,1,dat,3);}

}
void showdata1()  //显示输入的数据
{
	
	if(dat<=9){LCD_ShowNum(1,4,dat,1);}
	if(dat>9&&dat<=99){LCD_ShowNum(1,4,dat,2);}
	if(dat>99&&dat<=999){LCD_ShowNum(1,4,dat,3);}

}

 int flag=0;

void main()
{
	LCD_Init();
	
	LCD_ShowString(2,1,"OUTPUT:");
	
	while(1)
	{
		
		keynum=MatrixKey(); //返回矩阵键盘的键值
		if(keynum)
		{			
			if(keynum>10)
			{	
				flag=1;				
				shuju[j]=dat;
				j++;
				dat=0;
				LCD_ShowString(1,7,"      ");
				if(keynum==11){yunsuan[i]='+';LCD_ShowString(1,3,"+");i++;}  
				if(keynum==12){yunsuan[i]='-';LCD_ShowString(1,3,"-");i++;}
				if(keynum==13){yunsuan[i]='*';LCD_ShowString(1,3,"*");i++;}
				if(keynum==14){yunsuan[i]='/';LCD_ShowString(1,3,"/");i++;}
				if(keynum==15)//计算结果
				{
					for(ii=0,jj=1;jj<j;jj++) //优先遍历，找出*与/对应的数组元素，并优先计算
					{
						if(yunsuan[ii]=='*'|yunsuan[ii]=='/')
						{
							youxian[i3]=yunsuan[ii];
							yshuju[j3]=shuju[jj];
							if(youxian[i3]=='*')
							{
								yshuju[j3]=shuju[jj]*shuju[jj-1];
								shuju[jj]=yshuju[j3];
								shuju[jj-1]=0;
							}
							if(youxian[i3]=='/')
							{
								if(shuju[jj]==0){LCD_ShowString(2,8," ERROR");}
								else 
								yshuju[j3]=shuju[jj-1]/shuju[jj];
								shuju[jj]=yshuju[j3];
								shuju[jj-1]=0;
							}
							yunsuan[ii]='+';
						}
						ii++;
					}
					for(ii=0,jj=1;jj<j;jj++) //第二次遍历，计算+ -法
					{
						if(yunsuan[ii]=='+')
						{
							shuju[jj]=shuju[jj]+shuju[jj-1];
							result();
						}
						if(yunsuan[ii]=='-')
						{
							shuju[jj]=shuju[jj-1]-shuju[jj];
							result();
						}
						if(yunsuan[ii]=='*')
						{
							shuju[jj]=shuju[jj]*shuju[jj-1];
							result();
						}
						if(yunsuan[ii]=='/')
						{
							shuju[jj]=shuju[jj-1]/shuju[jj];
							result();
						}
						ii++;
					}
				}
				if(keynum==16){//清空，所有变量置0
					youxian[5]=0;yshuju[5]=0;
					j=0;i=0; jj=0;ii=0;	j3=0;i3=0;
					flag=0;yunsuan[5]=0;LCD_ShowString(1,1,"      ");
				shuju[5]=0;dat=0;LCD_ShowString(2,8,"      ");}
			}
		if(keynum<=10)  //输入的数据处理，若超过两位则左移
			{		
				dat*=10;
				dat+=keynum%10; 
				if(flag==0){showdata();}
				if(flag==1){showdata1();}
				
			}
		}
	}
}
