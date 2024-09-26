#include <REG52.H>

//���Ŷ���
sbit OneWire_DQ=P2^2;

/**
  * @brief  �����߳�ʼ��
  * @param  ��
  * @retval �ӻ���Ӧλ��0Ϊ��Ӧ��1Ϊδ��Ӧ
  */
unsigned char OneWire_Init(void)
{
	unsigned char i;
	unsigned char AckBit;
	OneWire_DQ=1;
	OneWire_DQ=0;
	i = 247;while (--i);		//Delay 500us
	OneWire_DQ=1;
	i = 32;while (--i);			//Delay 70us
	AckBit=OneWire_DQ;
	i = 247;while (--i);		//Delay 500us
	return AckBit;
}

/**
  * @brief  �����߷���һλ
  * @param  Bit Ҫ���͵�λ
  * @retval ��
  */
void OneWire_SendBit(unsigned char Bit)
{
	unsigned char i;
	OneWire_DQ=0;
	i = 4;while (--i);			//Delay 10us
	OneWire_DQ=Bit;
	i = 24;while (--i);			//Delay 50us
	OneWire_DQ=1;
}

/**
  * @brief  �����߽���һλ
  * @param  ��
  * @retval ��ȡ��λ
  */
unsigned char OneWire_ReceiveBit(void)
{
	unsigned char i;
	unsigned char Bit;
	OneWire_DQ=0;
	i = 2;while (--i);			//Delay 5us
	OneWire_DQ=1;
	i = 2;while (--i);			//Delay 5us
	Bit=OneWire_DQ;
	i = 24;while (--i);			//Delay 50us
	return Bit;
}

/**
  * @brief  �����߷���һ���ֽ�
  * @param  Byte Ҫ���͵��ֽ�
  * @retval ��
  */
void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		OneWire_SendBit(Byte&(0x01<<i));
	}
}

/**
  * @brief  �����߽���һ���ֽ�
  * @param  ��
  * @retval ���յ�һ���ֽ�
  */
unsigned char OneWire_ReceiveByte(void)
{
	unsigned char i;
	unsigned char Byte=0x00;
	for(i=0;i<8;i++)
	{
		if(OneWire_ReceiveBit()){Byte|=(0x01<<i);}
	}
	return Byte;
}
