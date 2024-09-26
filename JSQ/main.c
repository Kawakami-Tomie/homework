#include"regx51.h"
sbit rs=P2^0;  			//data~command	rs=0??? rs=1???
sbit rw=P2^1;			//read~write
sbit en=P2^2;			//start
unsigned int key,temp,value;		//key->P1??? temp->P1?key?????    
unsigned int count,num;				//count->??????   num->??????
unsigned char state;				//state->???
unsigned int Num1,Num2;				//Num1->???1    Num2->???2
int answer;							//answer->????
unsigned char welcome;				//welcome->???????
void delay(unsigned int t)
{
    unsigned int i,j;
    for(i=0;i<t;i++)
    for(j=0;j<1275;j++);
}

void writecommand(unsigned char value)		//???
{
    rs=0;
    rw=0;
    P0=value;
    en=1;
    delay(1);
    en=0;
}

void writedata(unsigned char value)			//???
{
    rs=1;
    rw=0;
    P0=value;
    en=1;
    delay(1);
    en=0;
}

void LCD_init()
{
    writecommand(0x38);//??????,????,5*7??
	writecommand(0x0c);//???,???,???
	writecommand(0x06);//???????,??????,????
	writecommand(0x01);//????,??
}


void set_cursor(unsigned char Line,unsigned char Column)	//????
{
	if(Line==1)
	{
		writecommand(0x80|(Column-1));
	}
	else if(Line==2)
	{
		writecommand(0x80|(Column-1+0x40));
	}
}

int LCD_Pow(int X,int Y)
{
	unsigned char i;
	int Result=1;
	for(i=0;i<Y;i++)
	{
		Result*=X;
	}
	return Result;
}

void show_num(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	set_cursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		writedata(Number/LCD_Pow(10,i-1)%10+'0');
	}
}

void show_string(unsigned char Line,unsigned char Column,char *String)
{
	unsigned char i;
	set_cursor(Line,Column);
	for(i=0;String[i]!='\0';i++)
	{
		writedata(String[i]);
	}
}

unsigned int scan()
{
    unsigned int result=0;
    P1 = 0Xf0;			//1111 0000
    temp = P1;	
    temp = temp &0Xf0;	//1111 0000	
	if(temp!=0xf0)	    //??????
	{		
        delay(20);		
		if(temp!=0xf0)		
		{			
            P1=0x0f;
            temp|=(P1&0x0f);
            key=temp;			
			switch(key)			
			{				
				case 0xee:		//1110 1110			
				result=8;		//????1	
				break;					
				case 0xde:		//1101 1110			
                result=9;				
				break;					
				case 0xbe:		//1100 1110			
				result=10;			
				break;					
				case 0x7e:		//0111 1110			
				result=11;		// ÷		
				break;					
				case 0xed:		//1110 1101			
				result=5;				
				break;					
				case 0xdd:		//1101 1101			
				result=6;			
				break;					
				case 0xbd:		//1011 1101			
				result=7;			
				break;					
				case 0x7d:		//0111 1101				
				result=12;		// ×	
				break;					
				case 0xeb:		//1110 1011			
				result=2;				
				break;					
				case 0xdb:		//1101 1011			
				result=3;				
				break;					
				case 0xbb:		//1011 1011			
				result=4;			
				break;					
				case 0x7b:		//0111 1011			
				result=13;		// -		
				break;					
				case 0xe7:		//1110 0111			
				result=14;		// ON/C		
				break;					
				case 0xd7:		//1101 0111			
				result=1;			
				break;					
				case 0xb7:		//1011 0111			
				result=15;		// =		
				break;					
				case 0x77:		//0111 0111			
				result=16;		// +	
				break;			
				}		
			}	
		} 
    return result;
}

void main()
{
    LCD_init();   
    while(1)
    {
        value=scan();		//?????1
        if(value)
        {
            if(welcome==0)		//welcome=0?,??????
            {
                if(value==14)
                {
                    show_string(1,1,"Welcome to");
                    show_string(2,1,"Calculator!");
                    delay(200);				//???????
                    show_string(1,1,"00          ");
                    show_string(2,1,"            ");
                    welcome++;				//????????
                }
                
            }
            else		//?????????
         {          
            if(value<=10)
           {
               if(count<2)			//??????
               {
                   num*=10;			//??
                   num+=(value-1)%10;
                   count++;
               }
               show_num(1,1,num,2);
           }               
           else if(value>10 && value!=15)		//?????
           {           
                Num1=num;						//?????1
                count=0;
                num=0;
                show_string(1,1,"       ");
               switch(value)
               {
                   case 11: state='/';
                            show_string(1,1,"/");
                   break;
                   case 12: state='x';
                            show_string(1,1,"x");
                   break;
                   case 13: state='-';
                            show_string(1,1,"-");
                   break;
                   case 14: count=0;			//ON/C???
                            num=0;
                            Num1=0;
                            Num2=0;
                            answer=0;
                            show_num(1,1,00,2);
                   break;
                   case 16: state='+';
                            show_string(1,1,"+");
                   break;
               }
               
           }
           else if(value==15)				// =?
           {
               Num2=num;					//??????2
               show_string(1,1,"      ");
               if(state=='+')
               {
                   answer=Num1+Num2;
                   if(answer>=100)  show_num(1,1,answer,3);
                   else show_num(1,1,answer,2);
               }
               else if(state=='-')
               {
                   answer=Num1-Num2;
                   if(answer>=0)   show_num(1,1,answer,2);
                   else 
                   {
                       answer=-answer;
                       show_string(1,1,"-");
                       if(answer>=10) show_num(1,2,answer,2);
                       else show_num(1,2,answer,1);
                   }
               }
               else if(state=='x')
               {
                   answer=Num1*Num2;
                   if(answer>=1000) {show_num(1,1,answer,4);}
                   else if(100<=answer<1000) {show_num(1,1,answer,3);}
                   else if(10<=answer<100) {show_num(1,1,answer,2);}
                   else {show_num(1,1,answer,1);}
               }
                                
               else if(state=='/')
               {
                   if(Num2==0)
                   {
                       show_string(1,1,"ERROR");
                   }
                   else 
                   {
                       answer=Num1/Num2;
                       if(answer>=10)   show_num(1,1,answer,2);
                       else show_num(1,1,answer,1);
                   }
               }
             }
         }      
       }
     }
}
