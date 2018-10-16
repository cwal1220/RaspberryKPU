import RPi.GPIO as GPIO
import time

LED = 23
SW = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(SW, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(LED, GPIO.OUT)

# 인터럽트 발생시 호출되는 함수
def interrupt_callback(channel):
	print('Interrupt :', channel)
	GPIO.output(LED, True) # LED On
	time.sleep(1) # 1초 대기
	GPIO.output(LED, False) # LED Off

# FALLING엣지 검출 시 콜백함수 호출
GPIO.add_event_detect(SW, GPIO.FALLING, callback=interrupt_callback, bouncetime=300)

# 무한 대기..
while True:
	pass