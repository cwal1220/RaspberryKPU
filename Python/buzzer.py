import RPi.GPIO as GPIO
import time

BUZZER = 17

GPIO.setmode(GPIO.BCM)
GPIO.setup(BUZZER, GPIO.OUT)

while True:
    GPIO.output(BUZZER, True)    #LED에 불이 들어옴
    time.sleep(1)            #500ms 대기
    GPIO.output(BUZZER, False)
    time.sleep(1)		# 500ms 대기