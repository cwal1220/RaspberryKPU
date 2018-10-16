import RPi.GPIO as GPIO        #GPIO를 사용하기 위해 추가
import time                    #time.sleep을 사용하기 위해 추가

INPUT_PIN = 4

g_nPirState = False
g_nVal = 0

GPIO.setmode(GPIO.BCM)
GPIO.setup(INPUT_PIN, GPIO.IN)

while True:
	g_nVal = GPIO.input(INPUT_PIN)
	if g_nVal:
		if g_nVal:
			if not g_nPirState:
				print('Motion Detected!!')
			g_nPirState = True
	else:
		if g_nPirState:
			print('Motion ended...')
		g_nPirState = False