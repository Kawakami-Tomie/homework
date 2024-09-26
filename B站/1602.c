#include "1602.h"
#include "delay.h"
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int

/*******************************************
函数名称：LcdReset
功    能：对1602液晶模块进行复位操作
参    数：无
返回值  ：无
使用方法：初始化1
********************************************/
void LcdReset(void) 
{
    DelayMs(50);
    LcdWriteCommand(0x38, 1);		//显示模式设置
    LcdWriteCommand(0x08, 1);		//显示关闭
    LcdWriteCommand(0x01, 1);	  //显示清屏，光标加左上角
    LcdWriteCommand(0x06, 1);		//写字符时整体不移动，地址指针及光标+1
    LcdWriteCommand(0x0c, 1);		//显示开，不开游标，不闪烁
}	

/*********************************************
功    能：清屏
参    数：无
返回值  ：无
使用方法：初始化2或必要时使用
*********************************************/
void LcdClear(void) 
{ 
	LcdWriteCommand(0x01,1); 
	DelayMs(5);
}


/*******************************************
函数名称：Disp1Char
功    能：在某个位置显示一个字符
参    数：x--列坐标
          y--行坐标
          data--显示的字符
返回值  ：无
********************************************/
void Disp1Char(uchar x,uchar y,uchar Data) 
{
    PosXY( x, y );			
    LcdWriteData( Data );		
}

/************************************************************************
函数名称：DispStr
功    能：从某个位置起连续显示一个字符串，一行结束，不再显示
参    数：x--列坐标
          y--行坐标
          Str--待显示的字符串指针/数组
返回值  ：无
*************************************************************************/
void DispStr(uchar x,uchar y,uchar *Str) 
{
    uchar *temp;
    uchar i,n = 0;
    
    temp = Str;
    while(*Str++ != '\0')   n++;//计算字符的个数n
    
    for (i=0;i<n;i++)
    {
        Disp1Char(x++,y,temp[i]);//在同一行逐个显示
        if (x == 0x10)//一行结束，不再显示
        {
            break;
        }
    }
}
/**************************************************************************
函数名称：DispNchar
功    能：从某个位置起连续显示N个字符，一行结束，继续换行或从头显示
参    数：x--列坐标
          y--行坐标
          n--字符个数
          str--指向字符存放位置的指针
返回值  ：无
**************************************************************************/
void DispNChar(uchar x,uchar y, uchar n,uchar *str) 
{
    uchar i;
    
    for (i=0;i<n;i++)
    {
        Disp1Char(x++,y,str[i]);//在同一行逐个显示
        if (x == 0x10)//一行结束，继续换行或从头显示
        {
           x = 0; 
           y ^= 1;
        }
    }
}
/*******************************************
函数名称：PosXY
功    能：输入显示字符坐标信息
参    数：x--列坐标
          y--行坐标
返回值  ：无
********************************************/
void PosXY(uchar x,uchar y) 
{
    uchar temp;

    temp = x&0x0f;
    y &= 0x01;
    if(y)   temp |= 0x40;  //如果在第2行
    temp |= 0x80;

    LcdWriteCommand(temp,1);
}

/*******************************************
函数名称：LcdWriteCommand
功    能：写入命令
参    数：cmd--命令，
          chk--是否判忙的标志，1：判忙，0：不判
返回值  ：无
********************************************/
void LcdWriteCommand(uchar cmd, uchar chk) 
{

    if (chk) WaitForEnable();   // 检测忙信号,仿真时可屏蔽
    
    RS = 0;	
    RW = 0; 
    _nop_();

    DataPort = cmd;             //将命令字写入数据端口 
    _nop_();					
    
    EN = 1;                     //产生使能脉冲信号
    _nop_();
    _nop_();
    EN = 0;			
}

/*******************************************
函数名称：LcdWriteData
功    能：向当前地址写入显示数据
参    数：data--显示字符数据
返回值  ：无
********************************************/
void LcdWriteData( uchar Data ) 
{
    WaitForEnable();        //等待液晶不忙
    RS = 1;
    RW = 0; 
	
    EN = 1;	
		_nop_();
    DataPort = Data;        //将显示数据写入数据端口               
    _nop_();//产生使能脉冲信号
    _nop_(); 
    _nop_(); 
    EN = 0;		
}

/*******************************************
函数名称：WaitForEnable
功    能：等待1602液晶完成内部操作或超时跳出
参    数：无
返回值  ：无
********************************************/
void WaitForEnable(void) 
{
  	unsigned int later=0;
		DataPort=0xff;
    RS = 0;
    RW = 1;
    _nop_();
    EN = 1; 
    _nop_();
    _nop_();  
    while(((DataPort&0x80)!=0)&&(later<1000))  //检测忙标志
    {
      DelayUs(2);
      later++;        
    }
    EN = 0;
}		

