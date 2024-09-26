#ifndef __NIXIE_H__
#define __NIXIE_H__

void Nixie_SetBuf(unsigned char Location,Number);
void Nixie_SetBuf1(unsigned char Location,Number);
void Nixie_Scan(unsigned char Location,Number);
void Nixie_Scan1(unsigned char Location,Number);
void Nixie_Loop(void);
void Nixie_Loop1(void);
#endif
