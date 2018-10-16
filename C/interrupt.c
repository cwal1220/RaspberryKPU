#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>

#define INT_GPIO 18  //GPIO18(Pin12)
#define LED 23       //BCM_GPIO23(pin16)

volatile int INTcounter =0;

// GPIO_ISR:  ISP 서버루틴, 이벤트가 일어날때마다 call
void GPIO_ISR(void) {
	INTcounter++;
	printf("Interrupt Event count = %d\n",INTcounter);
	digitalWrite(LED, HIGH);
	delay(1000);
	digitalWrite(LED, LOW);
	delay(1000);
}

int main(void) {
	if (wiringPiSetupGpio() == -1)
		return 1;
	pinMode(LED, OUTPUT); 
	digitalWrite(LED, LOW);
	pinMode(INT_GPIO, INPUT);
	// 18번 입력 핀에 인터럽트 부착
	if(wiringPiISR(INT_GPIO, INT_EDGE_FALLING, &GPIO_ISR) < 0)        
	{ 
		fprintf(stderr,"Unable to setup ISR %s\n",strerror(errno));
		return 1;
	}

	while ( 1 ) 
	{
		if(waitForInterrupt(INT_GPIO, 5000000) <1)
		{
			printf( "waitForInterrupt error occurred \n");
			return 1;
		}
	return 0;
	}
}
