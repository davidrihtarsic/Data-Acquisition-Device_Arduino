@echo off
color 30
SET /P comport=Enter COM port number ( 2 - for COM2 ):
avrdude.exe -v -F -p m328p -P COM%comport% -c arduino -b 115200 -Uflash:w:OnLineCom_v06.hex:a
pause
