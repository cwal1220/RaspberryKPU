#include <stdio.h>
#include <wiringPi.h>

#define SW 18 // GPIO18, Pin12 스위치 핀 정의
#define LED1 23 // GPIO23, LED 포트를 pin16으로 정의

int main()
{
	int keystate = 0;
	if(wiringPiSetupGpio() == -1)
		return 1;

	pinMode(SW, INPUT);
	pinMode(LED1, OUTPUT);

	while(1)
	{
		if(digitalRead(SW) == 1) // 스위치가 입력되면
		{
			keystate = !keystate; // 키 입력을 토글
			digitalWrite(LED1, keystate);
			delay(500);
		}
	}
	return 0;
}