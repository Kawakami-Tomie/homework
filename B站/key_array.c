#include "key_array.h"
/**************************************************
反转法识别键号
输入：Port:端口
返回：有键按下返回键值，无键返回0xff
*********************************************/
unsigned char key_array()
{
		unsigned char btn;	
		unsigned char key_v;
		key_v = 0xff;
		KEYPort = 0xFF;
		KEYPort = 0xf0;						//列输入
		if(0xf0 != (KEYPort&0xf0))  			//识别列中是否有键按下
		{
			DelayMs(10);				//去抖动
			if(0xf0 != (btn=KEYPort&0xf0))	//再次识别并送列码
			{
				KEYPort = 0x0f;				//行输入
				btn |= (KEYPort&0x0f);		//取行码，并与列码组合
				while(KEYPort != 0x0f);//等松开
				switch(btn)				//判键值
				{						 
					case 0xee:key_v=0;break; 
					case 0xde:key_v=4;break;
					case 0xbe:key_v=8;break; 
					case 0x7e:key_v=12;break; 
					case 0xed:key_v=1;break;
					case 0xdd:key_v=5;break;
					case 0xbd:key_v=9;break;
					case 0x7d:key_v=13;break;
					case 0xeb:key_v=2;break;
					case 0xdb:key_v=6;break;
					case 0xbb:key_v=10;break;
					case 0x7b:key_v=14;break;
					case 0xe7:key_v=3;break;
					case 0xd7:key_v=7;break;
					case 0xb7:key_v=11;break;
					case 0x77:key_v=15;break;
				}
			}
		} 
		return key_v;	
}

