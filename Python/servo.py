import RPi.GPIO as GPIO        #GPIO를 사용하기 위해 추가
import time                    #time.sleep을 사용하기 위해 추가

SERVO = 6

GPIO.setmode(GPIO.BCM)        #BCM을 이용하면 GPIO num으로 표시, BOARD를 이용하면 Pin num으로 표시.
GPIO.setup(SERVO, GPIO.OUT)    #GPIO23를 사용선언

pwm = GPIO.PWM(SERVO, 50)	#PWM 200Hz 주파수 설정
pwm.start(5) # 출력이 0%인 상태에서 시작

while True:
	pwm.ChangeDutyCycle(5) # Max Left
	time.sleep(1) # 1초 대기
	pwm.ChangeDutyCycle(7.5) # Middle
	time.sleep(1) # 1초 대기

GPIO.cleanup()                #GPIO 초기화
