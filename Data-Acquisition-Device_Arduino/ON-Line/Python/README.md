# Arduino serial API
This Arduino serial API is clone from [Python-Arduino-Command-API](https://github.com/thearn/Python-Arduino-Command-API) made by Tristan Hearn. Tristan has made good work on cross platform support (Win, OSX and Linux) for Arduno board self recognition. The main difference is in Firmware where this version has no particular functions to execute digitalWrite or rigitalRead but allows to controll Arduino's I/O registers directly.

## Simple example
```python
#!/usr/bin/env python
from Arduino import Arduino
from Arduino import m328
import time

def Blink():
    """
    Blinks an LED in 1 sec intervals
    """
    board.pinMode(13, 'OUTPUT')
    board.digitalWrite(13,'HIGH')
    time.sleep(1)
    board.digitalWrite(13,'LOW')

if __name__ == "__main__":
    board = Arduino()
    Blink()
```

## Requirements
- Python 3
- pyserial
- Arduino board with mega328 microcontroller (or similar)
- 
## Firmware
Firmware is written in BASCOM (mostly in assembler) but you can upload the OnLineCom_v06.hex by script that is included. Script uses avrdude which is included in Arduino IDE program. 

### Communication with firmware
ON LINE KOMUNIKACIJA je vedno sestavljena iz 2 Bytov. Za veèino funkcij je to dovolj, le funkcijo "Set_Register" je potrebno izvesti v dveh korakih (z dvema ukazoma):

1. najprej izvedete Set_Data kjer pošljete podatek, ki se bo vpisal v register,
2. nato še Set_Register, ki ta podatek vpiše v register...

ATmega328 ima v enoti UART le dva Byta prostora za pomnenje prihajajoèih podatkov, kar je premalo za nemoteno delovanje. Zato smo prihajajoèe podatke vezali na prekinitveno zastavico in jih shranjujemo v SRAM. Od tam pa jih nato beremo in izvršujemo, ko za to najdemo èas. V SRAMu smo za to proceduro namenili 256 Bytov prostora, kar zadostuje za 128 ukazov.
Èe upoštevamo, da nekatere funkcije potrebujejo 2 ukaza, bo shranjenih funkcij nekoliko manj, vendar še vedno dovolj za kratke, hitre operacije.
Komunikacija poteka s hitrostjo 115200 bitov/s, kar pomeni, da prenos enega funkcije (=2 byta) traja cca 175us. Izvršitev le-tega pa se zgodi v cca 8us.
But the speed of executing the code's instructions mostly depends on how fast can computer (is allowed by OS) write to the USB - which is around every 2 ms - quite slow. If you want to speed up things you should put instructions into fhe Arduino's buffer. Whit that technique you can get ADC sampling rate of one channel up to 6k samples/second with 10bit resolution.                                                               
                                                                         
### Communication concept                                                       
1. Byte                                                                  
     Je sestavljen iz 4-h bitov za ukaz in 4-h bitov za številko bita v
     registru, ki ga bomo nastavljali.                                   
                                                                         
    &B_kkkk_xbit                                                      
         ^    ^                                                          
         |    |                                                          
         |    +---- bit number = {0..7}                               
         +--------- command                                              
                                                                         
2. Byte                                                                  
     Je addressa registra ali vrednost registra                          
                                                                         
### Firmware commands                                                            
                                                                         
     ukaz:                                                                   
     0x0b 0xAA      - Skok v Program                                          
     0x1b 0xAA      - Branje I/O registra                                     
                      Ukaz prebere vrednost v I/O registru z naslovom [ AA]   
                      in jo pošlje po UARTU. Ukaz sicer ne potrebuje zadnjega 
                      Byta a ga moramo vseeno poslati, zaradi konsistentnosti 
                      komunikacije.                                           
     0x20 0xAA      - Vpis podatkov v r16 v register z Addreso AA             
     0x3b 0xAA      - Nastavitev bita v registru z naslovom [AA] na           
                      logièno "1". [b] je številka bita in je lahko od 0-7.   
                      V nasprotnem primeru (ko je številka veèja) se izbira   
                      bita nadaljuje, vkljuèno s carry bitom - torej številka 
                      9 na tem mestu, bi pomenila bit 0; številka 10 pa bit 1.
     0x4b 0xAA      - Nastavljanje [b]-tega bita v I/O registru z naslovom    
                      [AAA] na logièno "0"                                    
     0x5b 0xAA      - Branje vrednosti pina [b] v I/O registru z naslovom     
                      [AAA]. Rezultat funkcije je 1 ali 0. Ta podatek pošlemo 
                      preko UARTa.                                            
     0x6b 0xAA      - Wait until bit in register is set                       
     0x7b 0xAA      - Wait until bit in register is cleard                    
     0x80 0xAA      - Read 16 bit value from register address AAA and AAA+1   
     0x9A 0xAA      - Read 16 bit value from register address AAA and AAA-1   
     0xA0 0xDD      - Repeat last DD commands in CMD buffer. (do-loop can be  
                      created).
     0xB0 0xDD      - Nastavitev Podatkov [DD] v DATA register r16. Ti podatki
                      bodo v naslednjem koraku zapisani v nek register...     
     0xC0 0x00      - Reserved
     0xD0 0x00      - Reserved
     0xE0 0x00      - Reserved
     0xF0 0x00      - Reserved
