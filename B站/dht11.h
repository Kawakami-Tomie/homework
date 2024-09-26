#ifndef __DHT11_H__
#define __DHT11_H__

#include "delay.h"
#include <reg51.h>

//注意：
//DHT11一次通讯时间最大3ms，主机连续采样间隔建议不小于100ms，最好2秒以上。

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