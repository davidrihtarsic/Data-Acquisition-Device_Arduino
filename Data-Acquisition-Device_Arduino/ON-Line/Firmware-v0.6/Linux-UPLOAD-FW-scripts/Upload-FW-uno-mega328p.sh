#!/bin/bash
# My first script

/home/david/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino9/bin/avrdude -C/home/david/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino9/etc/avrdude.conf -v -patmega328p -carduino -P/dev/ttyACM0 -b115200 -D -Uflash:w:OnLineCom_v06.hex:i
