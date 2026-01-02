#include<lpc21xx.h>
#include "delay.c"

#define seg_d 0Xff
#define seg_1 1<<8
#define seg_2 1<<9
#define seg_3 1<<10
#define seg_4 1<<11

typedef unsigned char u8;

u8 seg_lut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};

void four_digitdisplay(int n)
{
	IOCLR0=seg_d;
	IOSET0=seg_lut[(n/1000)];
	IOSET0=seg_1;
	delay_ms(5);
	IOCLR0=seg_1;
	
	IOCLR0=seg_d;
	IOSET0=seg_lut[(n/100)%10];
	IOSET0=seg_2;
	delay_ms(5);
	IOCLR0=seg_2;
	
	IOCLR0=seg_d;
	IOSET0=seg_lut[(n/10)%10];
	IOSET0=seg_3;
	delay_ms(5);
	IOCLR0=seg_3;
	
	IOCLR0=seg_d;
	IOSET0=seg_lut[(n%10)];
	IOSET0=seg_4;
	delay_ms(5);
	IOCLR0=seg_4;
	
}

int main()
{
	IODIR0=seg_d|seg_1|seg_2|seg_3|seg_4;
	while(1)
		four_digitdisplay(1234);
}
