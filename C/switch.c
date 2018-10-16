#include <stdio.h>
#include <wiringPi.h>

#define SW 18 // GPIO18, Pin12 스위치 핀 정의
#define LED1 23 // GPIO23, LED 포트를 pin16으로 정의

int main()
{
	if(wiringPiSetupGpio() == -1)   // GPIO포트 초기화
		// wiringPiSetupGpio()를 사용하는 경우 gpio readall의 wPi 값 사용
		return 1 ;
	pinMode(SW, INPUT); // switch 포트는 입력으로 설정
	pinMode(LED1, OUTPUT); // LED1 포트는 출력으로 설정
	while(1)
	{
		if(digitalRead(SW) == 0)  //스위치가 눌러 졌는지 확인
		{
			digitalWrite(LED1, HIGH); // LED1 포트에 ‘1’을 출력
			delay(500); // 500mS 지연
		} 
		else  
		{
			digitalWrite(LED1, LOW); // LED1 포트에 ‘0’을 출력
			delay(500); // 500mS 지연 
		}
	}
	return 0 ;
}
