import RPi.GPIO as GPIO        #GPIO를 사용하기 위해 추가
import time                    #time.sleep을 사용하기 위해 추가

LEDB = 25
LEDR = 23
LEDG = 24

GPIO.setmode(GPIO.BCM)        #BCM을 이용하면 GPIO num으로 표시, BOARD를 이용하면 Pin num으로 표시.
GPIO.setup(LEDR, GPIO.OUT)
GPIO.setup(LEDG, GPIO.OUT)
GPIO.setup(LEDB, GPIO.OUT)

pwm_r = GPIO.PWM(LEDR, 200)	# Red LED PWM
pwm_g = GPIO.PWM(LEDG, 200)	# Greed LED PWM
pwm_b = GPIO.PWM(LEDB, 200)	# Blue LED PWM

pwm_r.start(0)
pwm_g.start(0)
pwm_b.start(0)

while True:
	for i in range(100):
		pwm_r.ChangeDutyCycle(i)
		time.sleep(0.01)
	for i in range(100):
		pwm_g.ChangeDutyCycle(i)
		time.sleep(0.01)
	for i in range(100):
		pwm_b.ChangeDutyCycle(i)
		time.sleep(0.01)

GPIO.cleanup()                #GPIO 초기화
