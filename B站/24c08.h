#ifndef __24C08_H__
#define __24C08_H__

#include <reg51.h> 
#include "delay.h"

#define	OP_READ	0xa1	// 器件地址以及读取操作,0xa1即为1010 0001B
#define	OP_WRITE 0xa0	// 器件地址以及写入操作,0xa1即为1010 0000B
sbit SDA=P1^5;          //将串行数据总线SDA位定义在为P1.5引脚
sbit SCL=P1^4;          //将串行时钟总线SDA位定义在为P1.4引脚

void start();
void stop();
unsigned char ReadData();
bit WriteCurrent(unsigned char y);
void WriteSet(unsigned char add, unsigned char dat);
unsigned char ReadCurrent();
unsigned char ReadSet(unsigned char set_add);

#endif