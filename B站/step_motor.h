#ifndef __STEP_MOTOR_H__
#define __STEP_MOTOR_H__
#include <reg51.h>       //51оƬ�ܽŶ���ͷ�ļ�
#include "delay.h"

#define SMPort P1

void  motor_ffw45X(unsigned char N);//ת45*N��
void  motor_rev45X(unsigned char N);//ת45*N��

#endif