	  
#include "reg52.h"
typedef unsigned int u16;
typedef unsigned char u8;
void delay(int x);
void main()
{		
	while(1)
	{
	P3=0X1e;//位选
	P2=0x5b;//共阴段选
	P1=0xf9;//共阳段选
	delay(5);
	//
	P3=0X2d;
	P2=0x3f;
	P1=0xa4;
	delay(5);

	P3=0X4b;
	P2=0x3f;
	P1=0xa4;
	delay(5);

	P3=0X87;
	P2=0x06;
	P1=0xf9;
	delay(5);
	}
}
void delay(int i)

{
int j;
for(;i>0;i--)

for(j=110;j>0;j--);

}
