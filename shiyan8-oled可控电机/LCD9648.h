#ifndef __LCD9648_H
#define __LCD9648_H

#include <REGX51.H>
void Delay10ms(unsigned int c) ;
void  SendDataSPI(unsigned char dat);
void WriteComm(unsigned int i);
void WriteData(unsigned int i);
void LCD_Init(void);
void Clear();
unsigned char LCD12864_Write16CnCHAR(unsigned char  x, unsigned char y, unsigned char *cn);
#endif
