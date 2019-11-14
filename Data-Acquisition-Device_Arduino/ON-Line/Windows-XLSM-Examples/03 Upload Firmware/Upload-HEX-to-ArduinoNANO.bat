@echo off
color 30
SET /P comport=Enter COM port number ( 2 - for COM2 ):
::avrdude.exe -v -F -p atmega328p -P COM%comport% -c arduino -b 57600 -Uflash:w:%~s1:a
avrdude.exe -v -F -p atmega328p -P COM%comport% -c arduino -b 57600 -Uflash:w:OnLineCom_v06.hex:a
pause
