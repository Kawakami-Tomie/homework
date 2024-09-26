#include <REGX52.H>
#include "DHT11.h"

#define uchar unsigned char	
#define uint unsigned int

sbit Data = P3^6;//定义数据线
unsigned char rec_dat[15];   //用于显示的接收数据数组

/*------------------------------------------------
              DHT11延时函数
------------------------------------------------*/
void DHT11_delay_us(uchar n)
{
    while(--n);
}
 
void DHT11_delay_ms(uint z)
{
   uint i,j;
   for(i=z;i>0;i--)
      for(j=110;j>0;j--);
}
/*------------------------------------------------
              DHT11开始信号
------------------------------------------------*/
void DHT11_start()
{
   Data=1;
   DHT11_delay_us(2);
   Data=0;
   DHT11_delay_ms(20);   //延时18ms以上
   Data=1;
   DHT11_delay_us(30);
}
/*------------------------------------------------
              接收八位二进制
------------------------------------------------*/
uchar DHT11_rec_byte()      //接收一个字节
{
   uchar i,dat=0;
  for(i=0;i<8;i++)    //从高到低依次接收8位数据
   {          
      while(!Data);   //等待50us低电平过去
      DHT11_delay_us(8);     //延时60us，如果还为高则数据为1，否则为0 
      dat<<=1;           //移位使正确接收8位数据，数据为0时直接移位
      if(Data==1)    //数据为1时，使dat加1来接收数据1
         dat+=1;
      while(Data);  //等待数据线拉低    
    }  
    return dat;
}
/*------------------------------------------------
              接收40bit数据
------------------------------------------------*/
void DHT11_receive()      //接收40位的数据
{
    unsigned char	 R_H,R_L,T_H,T_L,RH,RL,TH,TL,revise; 
    DHT11_start();
 
    if(Data==0)
    {
	
        while(Data==0);   //等待拉高     
		
        DHT11_delay_us(40);  //拉高后延时80us
        R_H=DHT11_rec_byte();    //接收湿度高八位  
        R_L=DHT11_rec_byte();    //接收湿度低八位  
        T_H=DHT11_rec_byte();    //接收温度高八位  
        T_L=DHT11_rec_byte();    //接收温度低八位
        revise=DHT11_rec_byte(); //接收校正位
			 
        DHT11_delay_us(25);    //结束
 
        if((R_H+R_L+T_H+T_L)==revise)      //校正
        {
            RH=R_H;
            RL=R_L;
            TH=T_H;
            TL=T_L;
        } 
        /*数据处理，方便显示*/
        rec_dat[0]='0'+(RH/10);
        rec_dat[1]='0'+(RH%10);
		rec_dat[2] =' ';
		rec_dat[3] = 'R' ;
		rec_dat[4] = 'H';
        rec_dat[5]=' ';
        rec_dat[6]=' ';
        rec_dat[7]=' ';
        rec_dat[8]=' ';
        rec_dat[9]='0'+(TH/10);
        rec_dat[10]='0'+(TH%10);
		rec_dat[11] =' ';
		rec_dat[12] = 'C';
		rec_dat[13] = ' ' ;
        rec_dat[14]=' ';
    }
}
