#ifndef __18B20_H__
#define __18B20_H__

#include "delay.h"
//��Ĭ�ϣ�12λ�ֱ��ʣ��¶�λ��Ϊ11λ���¶�ת��ʱ�䳬��750ms
/*******************************************************
ָ�
					**********ROM����*******************
			33H ��ROM�еı��롢���к�
			55H ƥ��ROM������������64λROM���룬���оƬʱʹ��
			F0H ����ROM ȷ��������ROM��ַ�����оƬʱʹ��
			CCH ����ROM һ��оƬʱʹ��
			ECH �������� �¶ȳ�����ֵ��оƬ��Ӧ�����оƬʱʹ��
			
					**********RAM����*******************
			44H �����¶�ת��
			BEH ��RAM��9�ֽ��¶�����
			4EH дRAM��2��3�ֽ���ֵ
			48H ����RAM��2��3�ֽ���ֵ��EEPROM��
			B8H �ص�EEPROM�����ݻָ���RAM��2��3�ֽ���
			B4H �����緽ʽ��0-�������磬1-��ӵ�Դ
			
********************************************************/

sbit DQ=P3^7;			//DS18B20����

static unsigned char ROM_data[8];
bit Init_DS18B20(void);
unsigned char ReadOneChar(void);
void WriteOneChar(unsigned char dat);	
unsigned int ReadTemperature_m(unsigned char* ROM_D);
unsigned int ReadTemperature_s(void);
unsigned char* Read_ROM(void);

#endif