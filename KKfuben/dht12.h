#ifndef __DHT11_H__
#define __DHT11_H__

#include "delay.h"
#include <reg51.h>

//ע�⣺
//DHT11һ��ͨѶʱ�����3ms��������������������鲻С��100ms�����2�����ϡ�

sbit Data = P1^7; 
#define uchar unsigned char
#define uint unsigned int
typedef struct {
	uchar temp_i;
	uchar temp_d;
	uchar humi_i;
	uchar humi_d;
}dht11_t;
void DHT11_start();
uchar DHT11_rec_byte();
dht11_t DHT11_receive(void) ;
#endif