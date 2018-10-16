#include <wiringPi.h> 
#include <stdio.h>
#include <stdlib.h>
#include <softPwm.h>

#define MOTOR 6

int main(void)
{
	int pos = 10 ;
	int dir = 1 ;
	if (wiringPiSetupGpio() == -1) 
		return -1; //init wiringPi

	pinMode(MOTOR, OUTPUT) ; //set the 0 pin as OUTPUT
	digitalWrite(MOTOR, LOW) ; //0 pin output LOW voltage

	softPwmCreate(MOTOR, 0, 200) ; 
					 //pwm initialize HIGH time 0, LOW time 200ms
	while(1) {
		pos += dir ;
		if (pos < 5 || pos > 24) dir *= -1 ;
			softPwmWrite(MOTOR, pos);
		delay(500);
		printf("%d\n", pos);
		}
	return 0 ;
}