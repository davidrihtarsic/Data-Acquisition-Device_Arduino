#!/usr/bin/env python
from Arduino import Arduino
import time
# setup an Arduino-board object
ArduinoNano = Arduino()

print('ADC  TIME[s]')
for x in range(5):
	CH1 = ArduinoNano.analogRead(0)
	print(CH1, time.time())
	time.sleep(1)
