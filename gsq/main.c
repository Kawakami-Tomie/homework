#include<reg51.h>
   #include<stdio.h>
   #include<intrins.h>
   #include<absacc.h>
   #define uchar unsigned char
   #define uint unsighed int
   uchar VAR=0xFE;
	 
	 unsigned char flag=0;
	 
	 int Num=0;
	 
	 void TIMER_0(void) interrupt 1
	 {
		 TH0=(65536-46080)/256;
		 TL0=(65536-46080)%256;
		 flag=1;
		 Num++;
	 }
	 void main()
	 {
		 TMOD=0x01;
		 TH0=(65536-46080)/256;
		 TL0=(65536-46080)%256;
		 TR0=1;
		 EA=1;
		 ET0=1;
		 while(1)
		 {
			 if(flag==1)
			 {
				 flag=0;
			 if(Num%20==0){VAR=VAR^0x01;}
			 if(Num%40==0){VAR=VAR^0x02;}
			 if(Num%60==0){VAR=VAR^0x04;}
			 if(Num%80==0){VAR=VAR^0x08;}
			 if(Num%100==0){VAR=VAR^0x10;}
			 if(Num%120==0){VAR=VAR^0x20;}
			 if(Num%140==0){VAR=VAR^0x40;}
			 if(Num%160==0){VAR=VAR^0x80;}
			 
			 if(Num=16800){Num=0;}
		 }
			 P1=VAR;
		 }
	 }
	 
	 
	 
	 
	 