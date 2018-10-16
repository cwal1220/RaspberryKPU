import RPi.GPIO as GPIO        #GPIO를 사용하기 위해 추가
import time                    #time.sleep을 사용하기 위해 추가

LED1 = 23

GPIO.setmode(GPIO.BCM)        #BCM을 이용하면 GPIO num으로 표시, BOARD를 이용하면 Pin num으로 표시.
GPIO.setup(LED1, GPIO.OUT)    #GPIO23를 사용선언

pwm = GPIO.PWM(LED1, 200)	#PWM 200Hz 주파수 설정
pwm.start(0) # 출력이 0%인 상태에서 시작

while True:
	pwm.ChangeDutyCycle(50) #밝기 50%
	time.sleep(1) # 1초 대기
	pwm.ChangeDutyCycle(100) #밝기 100%
	time.sleep(1) # 1초 대기

GPIO.cleanup()                #GPIO 초기화
