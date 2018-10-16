# cd ~
# git clone https://github.com/adafruit/Adafruit_Python_DHT.git
# sudo python3 setup.py install
# sudo python3 dht11.py

import Adafruit_DHT

sensor = Adafruit_DHT.DHT11
pin = 4

humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)

if humidity is not None and temperature is not None:
    print('Temp={0:0.1f}*C  Humidity={1:0.1f}%'.format(temperature, humidity))
else:
    print('Failed to get reading. Try again!')
