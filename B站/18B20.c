#include <reg51.h>    
#include "18b20.h"

/*****************************************************
函数功能：将DS18B20传感器初始化，读取应答信号
入口参数：无
返回参数：dat -是否存在的标志，dat=0，表示存在；dat=1，表示不存在
使用方法：初始化-在其它函数中有调用，用于识别18B20是否存在
***************************************************/
bit Init_DS18B20(void)	
{
	 bit dat=0;
	 DQ = 1;   
	 DelayUs(5);   		//稍做延时
	 DQ = 0;        
	 DelayUs(200); 
	 DelayUs(200);		//精确延时：480us~960us		约810us
	 DQ = 1;        	
	 DelayUs(40);//***80us以内:太短255（或-1）；150us以上死循环，根据晶振调整****
	 dat=DQ;       
	 DelayUs(25); 		//稍作延时,给硬件一点反应时间
	 return dat;
}
/*****************************************************
函数功能：从DS18B20读取一个字节数据
入口参数：无
返回参数：dat-读出的一个字节数据
***************************************************/ 
unsigned char ReadOneChar(void)
 {
		unsigned char i=0;
		unsigned char dat = 0;
		for (i=8;i>0;i--)
		 {
				DQ = 0; // 给脉冲信号
				dat>>=1;//先低后高
				DQ = 1; // 给脉冲信号
				if(DQ)dat|=0x80;
				DelayUs(25);//***延时47us以上，根据晶振调整，此处约55us***
		 }
		 return(dat);
}
/*****************************************************
函数功能：向DS18B20写入一个字节控制数据
入口参数：dat-要写的命令
返回参数：无
***************************************************/  
void WriteOneChar(unsigned char dat)
{
	unsigned char i=0;
	 for (i=8; i>0; i--)
	 {
			DQ = 0;
		  DelayUs(5);//延时确定15us
			DQ = dat&0x01;
			DelayUs(5);//***采样数据，0：延时0~45us；1：延时0~35us，根据晶振调整，此处约15us***
			DQ = 1;
			dat>>=1;
	 }
	DelayUs(25);//稍作延时,给硬件一点反应时间
} 

/*****************************************************
函数功能: 读芯片ROM
入口参数：无
返回参数：64位ROM数值
//产品类型标号28H，芯片序列号48位，CRC校验码
使用方法：根据需要调用
***************************************************/ 
unsigned char* Read_ROM(void)
{
	Init_DS18B20();
	WriteOneChar(0x33);//读ROM
	DelayMs(10);
	ROM_data[0] = ReadOneChar();
	ROM_data[1] = ReadOneChar();
	ROM_data[2] = ReadOneChar();
	ROM_data[3] = ReadOneChar();
	ROM_data[4] = ReadOneChar();
	ROM_data[5] = ReadOneChar();
	ROM_data[6] = ReadOneChar();
	ROM_data[7] = ReadOneChar();
	return (ROM_data);
}

/*****************************************************
函数功能: 单个芯片根据序列号读温度
入口参数：无
返回参数：t-16位温度数值
使用方法：初始化
***************************************************/ 
unsigned int ReadTemperature_s(void)
{
		unsigned char a=0;
		unsigned int b=0;
		unsigned int t=0;
	
		Init_DS18B20();
		WriteOneChar(0xCC); // 跳过读序列号的操作	
		WriteOneChar(0x44); // 启动温度转换	  
		DelayMs(800);//（默认）12位分辨率，温度转换时间超过750ms
	
		Init_DS18B20();
		WriteOneChar(0xCC);// 跳过读序列号的操作	
		WriteOneChar(0xBE); //读取温度寄存器,前两个分别是温度的低位和高位	
	
		a=ReadOneChar();   //低位
		b=ReadOneChar();   //高位
		b<<=8;
		t=a|b;
		return(t);
}
/*****************************************************
函数功能: 一个IO口连接多个芯片时，根据序列号读温度
入口参数：ROM_D-芯片序列号
返回参数：t-16位温度数值
使用方法：初始化
***************************************************/ 
unsigned int ReadTemperature_m(unsigned char* ROM_D)
{
		unsigned char i,a=0;
		unsigned int b=0;
		unsigned int t=0;
	
		Init_DS18B20();	
		WriteOneChar(0x55); // 匹配序列号的操作,后紧跟64位ROM数据
	  for(i=0;i<8;i++)
		{
			WriteOneChar(ROM_D[i]);
		}
		WriteOneChar(0x44); // 启动温度转换	  
		DelayMs(800);//（默认）12位分辨率，温度转换时间超过750ms
		
		Init_DS18B20();
		WriteOneChar(0x55); // 匹配序列号的操作,后紧跟64位ROM数据
	  for(i=0;i<8;i++)
		{
			WriteOneChar(ROM_D[i]);
		}		
		WriteOneChar(0xBE); //读取温度寄存器,前两个分别是温度的低位和高位	
		
		a=ReadOneChar();   //低位
		b=ReadOneChar();   //高位
		b<<=8;
		t=a|b;
		return(t);
}