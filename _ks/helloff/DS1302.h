#ifndef __DS1302_H  
#define __DS1302_H  
 
extern unsigned char DS1302_Time[];//��������ʱ�������
void  DS1302_Init();//������ʼ������
void  DS1302_WriteBety(unsigned char command,Data);//�������ֽ�д�뺯��
unsigned char   DS1302_ReadBety(unsigned char command);//�������ֽڶ�������
void DS1302_SetTime();//���������ڲ�ʱ�亯��
void DS1302_ReadTime();//������ȡ�ڲ�ʱ�亯��

#endif
