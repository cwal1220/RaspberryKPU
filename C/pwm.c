#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h> // pwm를 쓰기 위해서 라이브러리 파일

#define LED 23       //GPIO 23

int main(void)
{
	if(wiringPiSetupGpio() == -1) //GPIO 초기화
		return 1;    
	pinMode(LED, OUTPUT);  //GPIO LED핀을 출력으로 설정
	digitalWrite(LED, LOW);  //GPIO LED핀에 ‘0’값을 출력
	softPwmCreate(LED,0,200); 
	// softPwmCreate (int pin, int initialValue, int pwmRange)
	// PWM 핀을 설정,(사용할 핀, pwm값), PWM 값은 0~200사이 범위를 갖고 
	// 기본 값을 0으로 하는 PWM핀을 설정
	printf("Test Software PWM\n");    
	while(1)
	{
		softPwmWrite(LED,100); 
		//softPwmWrite (PWMpin, PWMvalue) value=0~1023
		delay(1000);
		softPwmWrite(LED,200); 
		delay(1000);        
	}
	return 0;
}