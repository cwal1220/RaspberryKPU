import RPi.GPIO as GPIO        #GPIO를 사용하기 위해 추가
import time                    #time.sleep을 사용하기 위해 추가

LED_RED_1 = 23

GPIO.setmode(GPIO.BCM)        #BCM을 이용하면 GPIO num으로 표시, BOARD를 이용하면 Pin num으로 표시.
GPIO.setup(LED_RED_1, GPIO.OUT)    #GPIO23를 사용선언


while True:
	for i in range(0, 50, 1): 
		GPIO.output(LED_RED_1, True)
		time.sleep(i/100)           
		GPIO.output(LED_RED_1, False)
		time.sleep(i/100)

	for i in range(50, 0, -1):
		GPIO.output(LED_RED_1, True)
		time.sleep(i/100)           
		GPIO.output(LED_RED_1, False)
		time.sleep(i/100)


GPIO.cleanup()                #GPIO 초기화
