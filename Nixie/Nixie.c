#include <REG51.H>
#include "STRING.H"
#include "Nixie.h"
#include "STDLIB.H"
#include "LCD1602.h"

/**********************************************/
/*      第零部分  Nixie数码管显示库配置         */
/*  (如果要在不同的开发板上使用，需要修改这个)   */
/*********************************************/
#define NIXIE_PUZHONG_A2        // 开发板类型（普中A2开发板：PUZHONG_A2; 普中A7开发板：PUZHONG_A7）
#define NIXIE_SEGCODE_PORT P0   // 开发板段选端口
sbit i38_A = P2^2;
sbit i38_B = P2^3;
sbit i38_C = P2^4;
// 数码管阴码
code unsigned char Nixie_NumTable[] = 
{0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};



/**************************************/
/*    第一部分  硬件抽象层，与硬件交互   */
/*      例如进行：位选、段选等操作      */
/*************************************/
// 段选
#define Nixie_HardwareSetSegCode(x) {NIXIE_SEGCODE_PORT = x;}
// 位选
void Nixie_HardwareSelectNixie(unsigned char location){
    unsigned char Ynum = 0;

#ifdef NIXIE_PUZHONG_A7
    Ynum = location-1;
#else
#ifdef NIXIE_PUZHONG_A2
    Ynum = 8-location;
#else
    #error "非普中开发板必须要自定义重新实现位选函数!"
#endif // NIXIE_PUZHONG_A2
#endif // NIXIE_PUZHONG_A7

    switch (Ynum)
    {
    case 0:i38_A = 0;i38_B = 0;i38_C = 0;break;
    case 1:i38_A = 1;i38_B = 0;i38_C = 0;break;  
    case 2:i38_A = 0;i38_B = 1;i38_C = 0;break;
    case 3:i38_A = 1;i38_B = 1;i38_C = 0;break;
    case 4:i38_A = 0;i38_B = 0;i38_C = 1;break;
    case 5:i38_A = 1;i38_B = 0;i38_C = 1;break;
    case 6:i38_A = 0;i38_B = 1;i38_C = 1;break;
    case 7:i38_A = 1;i38_B = 1;i38_C = 1;break;    
    default:break;
    }
}

/**************************************/
/*    第二部分  调用底层函数           */
/*        实现动态数码管扫描           */
/*************************************/
unsigned char Nixie_DisplayBuffer[8] = {0x00};
void Nixie_Loop(){
    static unsigned char order = 1;
    Nixie_HardwareSetSegCode(0);        // 段清零
    Nixie_HardwareSelectNixie(order);   // 位选
    Nixie_HardwareSetSegCode(Nixie_DisplayBuffer[order - 1]);   // 段选
    if(order >= 8){
        order = 1;
    }
    else{
        order++;
    }
}


/**************************************/
/*    第三部分  上层函数，修改缓冲区    */
/*     实现改变下次扫描时数码管状态     */
/*************************************/

/**
 * @brief 提取一个数字的各位并将其右对齐储存在名为output的数组中
 *        如果数字的长度小于数组的长度，则其左侧补0
 *        如果数字的长度大于数组的长度，则其左侧超出的部分做截断
 * 
 * @param number 待拆分的数字
 * @param length 拆分进入的数组的长度
 * @param base 进制（如果十进制就说明从右往左分别是个位、十位......对应的数字）
 * @param output 指向输出数组的指针
 *
*/
void Nixie_SplitNumToArray(unsigned int number, unsigned char length, 
                                unsigned char base, char* output)
{
    unsigned i;
    for(i = length; i >= 1; i--){
        output[i-1] = number%base;
        number /= base;
    }
}

/**
 * @brief 清除从左向右数第left个数码管到第right个数码管间的显示内容
 * 
 * @param left 待清除区间的左端点
 * @param right 待清除区间的右端点（包含在清除区间内）
 */
void Nixie_Clear(unsigned left, unsigned right){
    memset(Nixie_DisplayBuffer, 0, right - left + 1);
}

/**
 * @brief 从第position个数码管开始显示number，长度为length
 *        如果数字长度和length不匹配则向左侧补零或截断
 * 
 * @param position 开始显示的数码管位置
 * @param number   待显示的数字
 * @param length    显示的数字的长度（左侧补零或截断）
 */
void Nixie_ShowNum(unsigned char position,unsigned int number, unsigned char length){
    unsigned int i = 0;
    unsigned char splitNum[8];
    Nixie_SplitNumToArray(number,length, 10, splitNum);
    for(i = 0; i< length; i++){
        Nixie_DisplayBuffer[position+i-1] = Nixie_NumTable[splitNum[i]];
    }
}

/**
 * @brief 从第position个数码管开始十六进制显示number，长度为length
 *        如果数字长度和length不匹配则向左侧补零或截断
 * 
 * @param position 开始显示的数码管位置
 * @param number   待显示的数字
 * @param length    显示的数字的长度（左侧补零或截断）
 */
void Nixie_ShowHexNum(unsigned char position,unsigned int number, unsigned char length){
    unsigned int i = 0;
    unsigned char splitNum[8];
    Nixie_SplitNumToArray(number,length, 16, splitNum);
    for(i = 0; i< length; i++){
        Nixie_DisplayBuffer[position+i-1] = Nixie_NumTable[splitNum[i]];
    }
}

/**
 * @brief 从第position个数码管开始显示有符号数number，长度为length
 *        如果数字长度和length不匹配则向左侧补零或截断，
 *        第position个数码管固定显示符号
 * 
 * @param position 开始显示的数码管位置
 * @param number   待显示的数字
 * @param length    显示的数字的长度（左侧补零或截断）
 */
void Nixie_ShowSignedNum(unsigned char position,int number, unsigned char length){
    unsigned int i = 0;
    unsigned char splitNum[8];
    Nixie_SplitNumToArray(((number>=0)?number:-number),length-1, 10, splitNum);
    Nixie_DisplayBuffer[position - 1] = (number >= 0)? 0x00:0x40;
    for(i = 1; i < length; i++){
        Nixie_DisplayBuffer[position+i-1] = Nixie_NumTable[splitNum[i-1]];
    }
}

/**
 * @brief 从第position个数码管开始显示小数number，长度为length
 *        如果数字长度和length不匹配则向左侧补零或截断
 *        在数字占据的区域中从右往左数的第dotOffset个数码管上显示小数点
 * 
 * @param position 开始显示的数码管位置(符号位)
 * @param number 待显示的数字
 * @param length 显示的数字的长度（左侧补零或截断）
 * @param dotOffset 小数点偏移，在数字占据的区域中从右往左数的第dotOffset个数码管上显示小数点
 */
void Nixie_ShowDecimalNum(unsigned char position,int number, unsigned char length, unsigned char dotOffset){
    unsigned char i = 0;
    unsigned char splitNum[8];
    Nixie_SplitNumToArray(number,length, 10, splitNum);
    for(i = 0; i< length; i++){
        if(i == length - dotOffset - 1){
            Nixie_DisplayBuffer[position+i-1] = Nixie_NumTable[splitNum[i]] | 0x80;
        }
        else{
            Nixie_DisplayBuffer[position+i-1] = Nixie_NumTable[splitNum[i]];
        }
    }
}

/**
 * @brief 从第position个数码管开始显示小数number，长度为length
 *        如果数字长度和length不匹配则向左侧补零或截断
 *        在数字占据的区域中从右往左数的第dotOffset个数码管上显示小数点
 * 
 * @param position 开始显示的数码管位置(符号位)
 * @param number 待显示的数字
 * @param length 显示的数字的长度（左侧补零或截断）
 * @param dotOffset 小数点偏移，在数字占据的区域中从右往左数的第dotOffset个数码管上显示小数点
 */
void Nixie_ShowSignedDecimalNum(unsigned char position,int number, unsigned char length, unsigned char dotOffset){
    unsigned char i = 0;
    unsigned char splitNum[8];
    Nixie_SplitNumToArray(((number>=0)?number:-number),length, 10, splitNum);
    Nixie_DisplayBuffer[position - 1] = (number >= 0)? 0x00:0x40;
    for(i = 1; i< length; i++){
        if(i == length - dotOffset - 1){
            Nixie_DisplayBuffer[position+i-1] = Nixie_NumTable[splitNum[i]] | 0x80;
        }
        else{
            Nixie_DisplayBuffer[position+i-1] = Nixie_NumTable[splitNum[i]];
        }
    }
}

/**
 * @brief 在第position个数码管上显示符号
 * 
 * @param position 待显示的数码管编号
 * @param segCode  需要显示的符号对应的段码
 */
void Nixie_ShowCharacter(unsigned char position,unsigned char segCode){
    Nixie_DisplayBuffer[position-1] = segCode;
}
