#include<stdio.h>
#include<wiringPi.h>
#include<softPwm.h>

#define LEDB 25
#define LEDR 23
#define LEDG 24

int main(void)
{
	int bright = 0;
	if(wiringPiSetupGpio() == -1)
		return 1;
	pinMode(LEDR,OUTPUT);
	pinMode(LEDG,OUTPUT);
	pinMode(LEDB,OUTPUT);

	digitalWrite(LEDR,LOW);
	digitalWrite(LEDG,LOW);
	digitalWrite(LEDB,LOW);

	softPwmCreate(LEDR,0,200);
	softPwmCreate(LEDG,0,200);
	softPwmCreate(LEDB,0,200);
	int i = 0;
	while(1)
	{
		for(i=0;i<100;i++) {
			softPwmWrite(LEDR,bright);
			delay(10);
			bright+=2;
			if(bright > 200)
				bright = 0;
		}
		for(i=0;i<100;i++) {
			softPwmWrite(LEDG,bright);
			delay(10);
			bright+=2;
			if(bright > 200)
				bright = 0;
		}
		for(i=0;i<100;i++) {
			softPwmWrite(LEDB,bright);
			delay(10);
			bright+=2;
			if(bright > 200)
				bright = 0;
		}
	
	}
	return 0;
}