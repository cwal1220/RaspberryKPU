#include <stdio.h>
#include <wiringPi.h>  //GPIO 라이브러리 사용
#define INPUT_PIN  18 // GPIO18, PIN No=12 
#define OUTPUT_PIN 27 // GPIO27, PIN=13
 
int main(void)
{    //GPIO 초기화
     if (wiringPiSetupGpio() == -1) {
        return 1;
    }
 
    pinMode(INPUT_PIN, INPUT); //GPIO18은 입력모드로 설정
    pinMode(OUTPUT_PIN, OUTPUT); //GPIO27은 출력모드로 설정
    
    pullUpDnControl (INPUT_PIN, PUD_UP); //핀18은 풀업
    printf("digitalRead (INPUT_PIN) : %d\n", digitalRead (INPUT_PIN));
    
    pullUpDnControl (INPUT_PIN, PUD_DOWN) ;
    printf("digitalRead (INPUT_PIN) : %d\n", digitalRead (INPUT_PIN));
 
    return 0; 
}

