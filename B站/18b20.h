#ifndef __18B20_H__
#define __18B20_H__

#include "delay.h"
//（默认）12位分辨率，温度位数为11位，温度转换时间超过750ms
/*******************************************************
指令：
					**********ROM操作*******************
			33H 读ROM中的编码、序列号
			55H 匹配ROM，此命令后紧跟64位ROM编码，多个芯片时使用
			F0H 搜索ROM 确定数量和ROM地址，多个芯片时使用
			CCH 跳过ROM 一个芯片时使用
			ECH 警告搜索 温度超过限值的芯片响应，多个芯片时使用
			
					**********RAM操作*******************
			44H 启动温度转换
			BEH 读RAM中9字节温度数据
			4EH 写RAM第2、3字节限值
			48H 复制RAM第2、3字节限值到EEPROM中
			B8H 重调EEPROM中数据恢复到RAM第2、3字节中
			B4H 读供电方式：0-寄生供电，1-外接电源
			
********************************************************/

sbit DQ=P3^7;			//DS18B20引脚

static unsigned char ROM_data[8];
bit Init_DS18B20(void);
unsigned char ReadOneChar(void);
void WriteOneChar(unsigned char dat);	
unsigned int ReadTemperature_m(unsigned char* ROM_D);
unsigned int ReadTemperature_s(void);
unsigned char* Read_ROM(void);

#endif