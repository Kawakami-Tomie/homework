//#include<reg51.h>
//#include"charcode.h"

//sbit CS0  = P0^0;		//Ƭѡ
//sbit RST  = P0^1;		//��λ
//sbit RS   = P2^7; 		//��������ѡ���
//sbit SCL  = P2^6;		//SPIʱ�Ӷ�
//sbit SDA  = P2^5;		//SPI���ݶ�

//void Delay10ms(unsigned int c)   //��� 0us
//{
//    unsigned char a,b;
//    for(;c>0;c--)
//        for(b=38;b>0;b--)
//            for(a=130;a>0;a--);
//}


//void  SendDataSPI(unsigned char dat)
//{  
//   unsigned char i;
//   
//   for(i=0; i<8; i++)			
//   {  
//      if( (dat&0x80)!=0 ) SDA = 1;
//        else SDA = 0;

//      dat <<= 1;

//	  SCL = 0;
//      SCL = 1;			
//   }
//}

//void WriteComm(unsigned int i)
//{

//    CS0 = 0;
//	RS  = 0;

//	SendDataSPI(i);	 ///

//	CS0 = 1;

//}
//void WriteData(unsigned int i)
//{
//    CS0 = 0;
//	RS  = 1;

//	SendDataSPI(i);

//	CS0 = 1;
//}

//void LCD_Init(void)
//{
//	unsigned int i;
//	//CS0=0;
//	
//	RST=1;  
//	for(i = 0; i < 1000; i++);
//	
//	RST=0;
//	for(i = 0; i < 1000; i++);

//	RST=1;
//	for(i = 0; i < 1000; i++);

//    WriteComm(0xe2);		  //�����λ
//	WriteComm(0xc8);		  //0xC8��ͨ����ѡ��ѡ����0xC0Ϊ��������
//	WriteComm(0xa0);		  //0xA0�η���ѡ����������0xA1Ϊ������
//	WriteComm(0x2f);
//	WriteComm(0x26);
//	WriteComm(0x81);		  //������Աȶ�
//	WriteComm(0x10);
//	WriteComm(0xaf);		  //������ʾ

//}


//void Clear()
//{
//	unsigned char i,j;
//	
//	for(i=0; i < 9; i++)
//	{
//		WriteComm(0x40);
//		WriteComm(0xb0+i);
//		WriteComm(0x10);
//		WriteComm(0x00);
//		
//		for(j = 0; j < 96; j++)
//		{
//			WriteData(0x00);	
//		}	
//	}		
//}


//unsigned char LCD12864_Write16CnCHAR(unsigned char  x, unsigned char y, unsigned char *cn)
//{
//	unsigned char j, x1, x2, wordNum;

//	//--Y������ֻ�ܴ�0��7��������ֱ�ӷ���--//
//	if(y > 7)
//	{
//		return 0;
//	}

//	//--X������ֻ�ܴ�0��96��������ֱ�ӷ���--//
//	if(x > 96)
//	{
//		return 0;
//	}
//	y += 0xB0;	   //��ȡY�����ֵ
//	//--����Y����--//
//	WriteComm(y);
//	while ( *cn != '\0')	 //��C�������ַ��������ԡ�\0����β
//	{	
//	
//		//--����Y����--//
//		WriteComm(y);

//		x1 = (x >> 4) & 0x0F;   //����X����Ҫ��������ָߵ�4λ������������ȡ����4λ
//		x2 = x & 0x0F;          //ȥ����λ
//		//--����X����--//
//		WriteComm(0x10 + x1);   //��4λ
//		WriteComm(0x00 + x2);	//��4λ
//		for (wordNum=0; wordNum<30; wordNum++)
//		{
//		    //--��ѯҪд�������ֿ��е�λ��--//
//			if ((CN16CHAR[wordNum].Index[0] == *cn)
//			     &&(CN16CHAR[wordNum].Index[1] == *(cn+1)))
//			{
//				for (j=0; j<32; j++) //дһ����
//				{		
//					if (j == 16)	 //����16X16�õ�����Y���꣬�����ڵ���16ʱ���л�����
//					{
//						//--����Y����--//
//			   			WriteComm(y + 1);
//			
//						//--����X����--//
//						WriteComm(0x10 + x1);   //��4λ
//						WriteComm(0x00 + x2);	//��4λ
//					}
//					WriteData(CN16CHAR[wordNum].Msk[j]);
//				}
//				x += 16;
//			}//if�鵽�ֽ���		
//		} //for���ֽ���
//		cn += 2;
//		
//	}	//while����
//	return 1;
//}


