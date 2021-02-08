#include"reg52.h"
sbit led=P2^7;

void delay(int i)
{	int m;
	while(i--)
	{
	for(m=100;m>0;m--)
	;
	}
}




void be_dark()
{	int y=0;
	while(40-y)
	{
	led=0;
	delay(40-y);
	led=1;
	delay(y);
	y++;
	}
}

void be_bright()
{	int y=0;
	while(40-y)
	{
	led=1;
	delay(40-y);
	led=0;
	delay(y);
	y++;
	}
}



int main()
{
	while(1)
	{
	be_bright();
	delay(10);
	
	be_dark();
	delay(10);	
	}

	return 0;
}