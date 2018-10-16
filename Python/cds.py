import RPi.GPIO as GPIO        #GPIO를 사용하기 위해 추가
import time                    #time.sleep을 사용하기 위해 추가

CDS = 10

GPIO.setmode(GPIO.BCM)        #BCM을 이용하면 GPIO num으로 표시, BOARD를 이용하면 Pin num으로 표시.
GPIO.setup(CDS, GPIO.IN)    #GPIO23를 사용선언

while True:
	if GPIO.input(CDS):
		print('Bright!!!')
	else:
		print('Dark....')
	time.sleep(0.2)