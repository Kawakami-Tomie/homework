#ifndef WS2812
#define WS2812
/*******��Ƭ����Ƶ=����Ƶ��/��Ƶϵ��
WSCASE=1 30 29 28 27 26 25 24 
WSCASE=2 24 23 22 21 20 19
WSCASE=3 19 18 17 16 15
WSCASE=4 15 14 13 12
WSCASE=5 12 11
WSCASE=6 11 10
WSCASE=7 10  9  8
*/
#define WSCASE 5//����޸�Ƶ��
#define WSCOUNT 10
sbit WS2812_DI=P3^7;
//sbit WS2812_DI=P5^5;
extern void WS2812_Ser();
extern u8 WS2812_BUffer[WSCOUNT][3];
#endif