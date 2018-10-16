import RPi.GPIO as GPIO        #GPIO를 사용하기 위해 추가
import time                    #time.sleep을 사용하기 위해 추가

LED_RED_1 = 23

GPIO.setmode(GPIO.BCM)        #BCM을 이용하면 GPIO num으로 표시, BOARD를 이용하면 Pin num으로 표시.
GPIO.setup(LED_RED_1, GPIO.OUT)    #GPIO23를 사용선언

i=0
while True:
    print('LED Test :',i) 
    GPIO.output(LED_RED_1, True)    #LED에 불이 들어옴
    time.sleep(0.5)            #500ms 대기
    GPIO.output(LED_RED_1, False)
    time.sleep(0.5)		# 500ms 대기
    i += 1

GPIO.cleanup()                #GPIO 초기화
