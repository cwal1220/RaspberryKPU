import RPi.GPIO as GPIO        #GPIO를 사용하기 위해 추가
import time                    #time.sleep을 사용하기 위해 추가

LED1 = 23
SW = 18

GPIO.setmode(GPIO.BCM)        #BCM을 이용하면 GPIO num으로 표시, BOARD를 이용하면 Pin num으로 표시.
GPIO.setup(LED1, GPIO.OUT)    #GPIO23를 사용선언
GPIO.setup(SW, GPIO.IN, pull_up_down=GPIO.PUD_UP) #풀업 설정

key_state = False # 키 상태 저장 변수

while True:
	if GPIO.input(SW) == False: # 버튼을 눌렀을 때
		key_state = not key_state
		GPIO.output(LED1, key_state)
		time.sleep(0.5) # 중복 입력 방지를 위한 0.5초 대기
GPIO.cleanup()                #GPIO 초기화
