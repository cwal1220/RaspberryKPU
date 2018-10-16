#include <wiringPi.h>
#include <stdio.h>

#define BUZZER 17

int main(void)
{ 
	if(wiringPiSetupGpio() == -1) 
		return 1; 
	pinMode(BUZZER, OUTPUT);
	while(1)
	{ 
		digitalWrite(BUZZER, HIGH);
		delay(1000);
		digitalWrite(BUZZER, LOW);
		delay(1000); 
	}
	return 0;
}