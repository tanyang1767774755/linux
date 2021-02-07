#include "reg52.h"

sbit red_s=P0^0; 
sbit yellow_s=P0^1;
sbit green_s=P0^2;
sbit red_w=P0^3; 
sbit yellow_w=P0^4;
sbit green_w=P0^5;
char table[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void delay(int time)
{
 int i;
 while(time--) 
 for(i=0;i<120;i++);
}
sbit a=P2^0;
sbit b=P2^1;

void display(int time)
{
	int ten,second,ten2,second2,time2;
	while(time--)
	{	int tim=20;
		while(tim--)
		{	
			time2=time+5;
			ten2=time2/10;
			second2=time2%10;
			ten=time/10;
			second=time%10;
			
			P2=0x01;
			P3=table[ten];
			P1=table[ten2];
			delay(10);
			
			P2=0x02;
			P3=table[second];
			P1=table[second2];
			delay(10);
		}
	}
}
void display2(int time)
{
	int ten,second;
	while(time--)
	{	int tim=20;
		while(tim--)
		{
			ten=time/10;
			second=time%10;
			
			P2=0x01;
			P1=P3=table[ten];
			
			delay(10);
			
			P2=0x02;
			P1=P3=table[second];
			delay(10);
		}
	}
}

int main()
{
	int i=0;
	while(1)
	{	
		int time=0;
		switch(i)
		{
		case 0:
		red_s=0;yellow_s=1;green_s=1;
		
		red_w=1;yellow_w=1;green_w=0;
		display(25);
		//delay(3000);//换成倒计时
		i++;
		break;
		
		
		case 1:
		red_s=1;yellow_s=0;green_s=1;
		//red_w=1;yellow_w=0;green_w=1;//test
		//delay(1000);
		display2(5);
		i++;
		break;
		
		
		case 2:
	    red_s=1;yellow_s=1;green_s=0;
		
		red_w=0;yellow_w=1;	green_w=1;
		//delay(3000);
		display(25);
		i++;
		break;


		case 3:
		//red_s=1;  yellow_s=0;  green_s=1;
		red_w=1;yellow_w=0;green_w=1;
		//delay(1000);//换成倒计时
		display2(5);
		i=0;
		break;
		}
	}
	return 0;
}