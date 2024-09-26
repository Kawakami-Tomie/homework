#ifndef __12864_H__
#define __12864_H__

#include <reg51.h>
#include <intrins.h>

#define uint unsigned int
#define uchar unsigned char
	
#define DATA P2 //LCD12864������
sbit RS=P3^2; // ���ݡ�ָ�� ѡ��
sbit RW=P3^1; // ����дѡ��
sbit EN=P3^0; // ����дʹ�ܣ��½���
sbit cs1=P3^4; // Ƭѡ1
sbit cs2=P3^3; // Ƭѡ2	
//��ģ����
uchar code Hzk[];
uchar code Szk[];
uchar code Fhk[];
uchar code Zmk[];

void CheckState();
void SendCommandToLCD(uchar com);
void SetLine(uchar page);
void SetStartLine(uchar startline);
void SetColumn(uchar column);
void SetOnOff(uchar onoff);
void WriteByte(uchar dat)	;
void SelectScreen(uchar screen);
void ClearScreen(uchar screen);	
void InitLCD() ;
void Display_HZ(uchar screen,uchar page,uchar column,uchar number);
void Display_SZ(uchar screen,uchar page,uchar column,uchar number);
void Display_ZM(uchar screen,uchar page,uchar column,uchar number);
void Display_FH(uchar screen,uchar page,uchar column,uchar number);

#endif