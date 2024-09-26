#ifndef __24C08_H__
#define __24C08_H__

#include <reg51.h> 
#include "delay.h"

#define	OP_READ	0xa1	// ������ַ�Լ���ȡ����,0xa1��Ϊ1010 0001B
#define	OP_WRITE 0xa0	// ������ַ�Լ�д�����,0xa1��Ϊ1010 0000B
sbit SDA=P1^5;          //��������������SDAλ������ΪP1.5����
sbit SCL=P1^4;          //������ʱ������SDAλ������ΪP1.4����

void start();
void stop();
unsigned char ReadData();
bit WriteCurrent(unsigned char y);
void WriteSet(unsigned char add, unsigned char dat);
unsigned char ReadCurrent();
unsigned char ReadSet(unsigned char set_add);

#endif