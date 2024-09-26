#ifndef __NIXIE_H__
#define __NIXIE_H__

void Nixie_Loop();
void Nixie_Clear(unsigned left, unsigned right);
void Nixie_ShowNum(unsigned char position,unsigned int number, unsigned char length);
void Nixie_ShowHexNum(unsigned char position,unsigned int number, unsigned char length);
void Nixie_ShowSignedNum(unsigned char position,int number, unsigned char length);
void Nixie_ShowDecimalNum(unsigned char position,int number, unsigned char length, unsigned char dotOffset);
void Nixie_ShowSignedDecimalNum(unsigned char position,int number, unsigned char length, unsigned char dotOffset);
void Nixie_ShowCharacter(unsigned char position,unsigned char segCode);

#endif // !__NIXIE_H__