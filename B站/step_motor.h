#ifndef __STEP_MOTOR_H__
#define __STEP_MOTOR_H__
#include <reg51.h>       //51芯片管脚定义头文件
#include "delay.h"

#define SMPort P1

void  motor_ffw45X(unsigned char N);//转45*N度
void  motor_rev45X(unsigned char N);//转45*N度

#endif