#ifndef WS2812
#define WS2812
/*******单片机主频=晶振频率/分频系数
WSCASE=8  8    6.5
WSCASE=9  6.5  4.5
WSCASE=10 4.5
*/
#define WSCASE 10//查表修改频率
#define WSCOUNT 10
sbit WS2812_DI=P0^0;
//sbit WS2812_DI=P5^5;
extern void WS2812_Ser();
extern u8 WS2812_BUffer[WSCOUNT][3];
#endif