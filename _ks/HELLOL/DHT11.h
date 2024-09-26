#ifndef __DHT11_H__
#define __DHT11_H__

#define uchar unsigned char	
#define uint unsigned int
void DHT11_delay_us(uchar n);
void DHT11_delay_ms(uint z);
void DHT11_start();
uchar DHT11_rec_byte();
void DHT11_receive();

#endif
