//#include<reg51.h>
//#include"charcode.h"

//sbit CS0  = P0^0;		//片选
//sbit RST  = P0^1;		//复位
//sbit RS   = P2^7; 		//数据命令选择端
//sbit SCL  = P2^6;		//SPI时钟端
//sbit SDA  = P2^5;		//SPI数据端

//void Delay10ms(unsigned int c)   //误差 0us
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

//    WriteComm(0xe2);		  //软件复位
//	WriteComm(0xc8);		  //0xC8普通方向选择选择反向，0xC0为正常方向
//	WriteComm(0xa0);		  //0xA0段方向选择正常方向（0xA1为反方向
//	WriteComm(0x2f);
//	WriteComm(0x26);
//	WriteComm(0x81);		  //背景光对比度
//	WriteComm(0x10);
//	WriteComm(0xaf);		  //开启显示

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

//	//--Y的坐标只能从0到7，大于则直接返回--//
//	if(y > 7)
//	{
//		return 0;
//	}

//	//--X的坐标只能从0到96，大于则直接返回--//
//	if(x > 96)
//	{
//		return 0;
//	}
//	y += 0xB0;	   //求取Y坐标的值
//	//--设置Y坐标--//
//	WriteComm(y);
//	while ( *cn != '\0')	 //在C语言中字符串结束以‘\0’结尾
//	{	
//	
//		//--设置Y坐标--//
//		WriteComm(y);

//		x1 = (x >> 4) & 0x0F;   //由于X坐标要两句命令，分高低4位，所以这里先取出高4位
//		x2 = x & 0x0F;          //去低四位
//		//--设置X坐标--//
//		WriteComm(0x10 + x1);   //高4位
//		WriteComm(0x00 + x2);	//低4位
//		for (wordNum=0; wordNum<30; wordNum++)
//		{
//		    //--查询要写的字在字库中的位置--//
//			if ((CN16CHAR[wordNum].Index[0] == *cn)
//			     &&(CN16CHAR[wordNum].Index[1] == *(cn+1)))
//			{
//				for (j=0; j<32; j++) //写一个字
//				{		
//					if (j == 16)	 //由于16X16用到两个Y坐标，当大于等于16时，切换坐标
//					{
//						//--设置Y坐标--//
//			   			WriteComm(y + 1);
//			
//						//--设置X坐标--//
//						WriteComm(0x10 + x1);   //高4位
//						WriteComm(0x00 + x2);	//低4位
//					}
//					WriteData(CN16CHAR[wordNum].Msk[j]);
//				}
//				x += 16;
//			}//if查到字结束		
//		} //for查字结束
//		cn += 2;
//		
//	}	//while结束
//	return 1;
//}


