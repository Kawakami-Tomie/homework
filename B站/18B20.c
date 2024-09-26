#include <reg51.h>    
#include "18b20.h"

/*****************************************************
�������ܣ���DS18B20��������ʼ������ȡӦ���ź�
��ڲ�������
���ز�����dat -�Ƿ���ڵı�־��dat=0����ʾ���ڣ�dat=1����ʾ������
ʹ�÷�������ʼ��-�������������е��ã�����ʶ��18B20�Ƿ����
***************************************************/
bit Init_DS18B20(void)	
{
	 bit dat=0;
	 DQ = 1;   
	 DelayUs(5);   		//������ʱ
	 DQ = 0;        
	 DelayUs(200); 
	 DelayUs(200);		//��ȷ��ʱ��480us~960us		Լ810us
	 DQ = 1;        	
	 DelayUs(40);//***80us����:̫��255����-1����150us������ѭ�������ݾ������****
	 dat=DQ;       
	 DelayUs(25); 		//������ʱ,��Ӳ��һ�㷴Ӧʱ��
	 return dat;
}
/*****************************************************
�������ܣ���DS18B20��ȡһ���ֽ�����
��ڲ�������
���ز�����dat-������һ���ֽ�����
***************************************************/ 
unsigned char ReadOneChar(void)
 {
		unsigned char i=0;
		unsigned char dat = 0;
		for (i=8;i>0;i--)
		 {
				DQ = 0; // �������ź�
				dat>>=1;//�ȵͺ��
				DQ = 1; // �������ź�
				if(DQ)dat|=0x80;
				DelayUs(25);//***��ʱ47us���ϣ����ݾ���������˴�Լ55us***
		 }
		 return(dat);
}
/*****************************************************
�������ܣ���DS18B20д��һ���ֽڿ�������
��ڲ�����dat-Ҫд������
���ز�������
***************************************************/  
void WriteOneChar(unsigned char dat)
{
	unsigned char i=0;
	 for (i=8; i>0; i--)
	 {
			DQ = 0;
		  DelayUs(5);//��ʱȷ��15us
			DQ = dat&0x01;
			DelayUs(5);//***�������ݣ�0����ʱ0~45us��1����ʱ0~35us�����ݾ���������˴�Լ15us***
			DQ = 1;
			dat>>=1;
	 }
	DelayUs(25);//������ʱ,��Ӳ��һ�㷴Ӧʱ��
} 

/*****************************************************
��������: ��оƬROM
��ڲ�������
���ز�����64λROM��ֵ
//��Ʒ���ͱ��28H��оƬ���к�48λ��CRCУ����
ʹ�÷�����������Ҫ����
***************************************************/ 
unsigned char* Read_ROM(void)
{
	Init_DS18B20();
	WriteOneChar(0x33);//��ROM
	DelayMs(10);
	ROM_data[0] = ReadOneChar();
	ROM_data[1] = ReadOneChar();
	ROM_data[2] = ReadOneChar();
	ROM_data[3] = ReadOneChar();
	ROM_data[4] = ReadOneChar();
	ROM_data[5] = ReadOneChar();
	ROM_data[6] = ReadOneChar();
	ROM_data[7] = ReadOneChar();
	return (ROM_data);
}

/*****************************************************
��������: ����оƬ�������кŶ��¶�
��ڲ�������
���ز�����t-16λ�¶���ֵ
ʹ�÷�������ʼ��
***************************************************/ 
unsigned int ReadTemperature_s(void)
{
		unsigned char a=0;
		unsigned int b=0;
		unsigned int t=0;
	
		Init_DS18B20();
		WriteOneChar(0xCC); // ���������кŵĲ���	
		WriteOneChar(0x44); // �����¶�ת��	  
		DelayMs(800);//��Ĭ�ϣ�12λ�ֱ��ʣ��¶�ת��ʱ�䳬��750ms
	
		Init_DS18B20();
		WriteOneChar(0xCC);// ���������кŵĲ���	
		WriteOneChar(0xBE); //��ȡ�¶ȼĴ���,ǰ�����ֱ����¶ȵĵ�λ�͸�λ	
	
		a=ReadOneChar();   //��λ
		b=ReadOneChar();   //��λ
		b<<=8;
		t=a|b;
		return(t);
}
/*****************************************************
��������: һ��IO�����Ӷ��оƬʱ���������кŶ��¶�
��ڲ�����ROM_D-оƬ���к�
���ز�����t-16λ�¶���ֵ
ʹ�÷�������ʼ��
***************************************************/ 
unsigned int ReadTemperature_m(unsigned char* ROM_D)
{
		unsigned char i,a=0;
		unsigned int b=0;
		unsigned int t=0;
	
		Init_DS18B20();	
		WriteOneChar(0x55); // ƥ�����кŵĲ���,�����64λROM����
	  for(i=0;i<8;i++)
		{
			WriteOneChar(ROM_D[i]);
		}
		WriteOneChar(0x44); // �����¶�ת��	  
		DelayMs(800);//��Ĭ�ϣ�12λ�ֱ��ʣ��¶�ת��ʱ�䳬��750ms
		
		Init_DS18B20();
		WriteOneChar(0x55); // ƥ�����кŵĲ���,�����64λROM����
	  for(i=0;i<8;i++)
		{
			WriteOneChar(ROM_D[i]);
		}		
		WriteOneChar(0xBE); //��ȡ�¶ȼĴ���,ǰ�����ֱ����¶ȵĵ�λ�͸�λ	
		
		a=ReadOneChar();   //��λ
		b=ReadOneChar();   //��λ
		b<<=8;
		t=a|b;
		return(t);
}