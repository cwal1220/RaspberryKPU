#include <stdio.h>
#include <wiringPi.h>   //GPIO Access Library 헤더파일 포함
#define LED_RED_1 23  // GPIO23, LED 포트 RED핀(pin16) 정의

int main (void)
{     
	int i=0;
	if(wiringPiSetupGpio() == -1) 
		//Wiring Pi의 GPIO를 사용하기 위한 설정(초기화)
		return 1;
	printf("GPIO LED Test \n");

	pinMode(LED_RED_1,OUTPUT); 
	//LED 포트 RED1 핀 출력 설정 
	digitalWrite(LED_RED_1,LOW); 
	//LED RED1 핀에 LOW(0) 출력

	while(1)
	{
		printf("GPIO LED Test =%d\n", i);
		digitalWrite(LED_RED_1,HIGH);  // LED ON
		delay(500);  //500ms 지연
		digitalWrite(LED_RED_1,LOW);   //LED OFF
		delay(500);
		i++;
	}
	return 0;
}
