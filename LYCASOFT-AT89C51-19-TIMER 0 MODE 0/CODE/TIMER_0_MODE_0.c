#include<reg51.h>
//#include "8051_delay.h"

sbit LED = P2^0;

void T0_M0_delay()	//100ms delay
{
	int i;
	TMOD = 0X00;
	for(i=0;i<120;i++)
	{
		TH0=0X0D;
		TL0=0XFF;
		TR0=1;
		while(!TF0);
		TF0=0;
		TR0=0;
	}
}

void main()
{
	LED = ~LED;
	T0_M0_delay();
}