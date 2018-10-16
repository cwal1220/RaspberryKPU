import RPi.GPIO as GPIO        #GPIO를 사용하기 위해 추가
import time                    #time.sleep을 사용하기 위해 추가

LED1 = 23
SW = 18

GPIO.setmode(GPIO.BCM)        #BCM을 이용하면 GPIO num으로 표시, BOARD를 이용하면 Pin num으로 표시.
GPIO.setup(LED1, GPIO.OUT)    #GPIO23를 사용선언
GPIO.setup(SW, GPIO.IN, pull_up_down=GPIO.PUD_UP)

while True:
	if GPIO.input(SW): # 버튼을 누르지 않을 때
		GPIO.output(LED1, False)
	else:				# 버튼을 눌렀을  때
		GPIO.output(LED1, True)

GPIO.cleanup()                #GPIO 초기화
