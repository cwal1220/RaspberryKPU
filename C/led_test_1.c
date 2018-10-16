#include<stdlib.h>
#include<wiringPi.h>
#include<stdio.h>

#define LED_RED1 23

int main(void)
{
	int frq = 100;
	int i=0;
	if(wiringPiSetupGpio() == -1)
		return -1;
	pinMode(LED_RED1,OUTPUT);
	digitalWrite(LED_RED1,LOW);
	while(1)
	{
		for(i=0;i<50;i++)
		{
			frq+= i*10;
			digitalWrite(LED_RED1,HIGH);
			delay(frq);
			digitalWrite(LED_RED1,LOW);
			delay(frq);
		}
		for(i=0;i<50;i++)
		{
			frq-= i*10;
			digitalWrite(LED_RED1,HIGH);
			delay(frq);
			digitalWrite(LED_RED1,LOW);
			delay(frq);
		}
		
	}
	return 0;
}
