Author: Miha �arn, Ale� Pr�in

Date: 2018-03-22 

# Kotna hitrost vrtljive plo��e

S pomo�jo mikrokrmilnika Arduino nano bomo izmerili kotno hitrost plo��e, ki se vrti okoli svoje osi. 

##  Potrebna oprema

Za meritev potrebujemo mikrokrmilnik Arduino nano, svetlobna vrata, ra�unalnik in ute�i. Koda, ki jo vnesemo v program prilagava spodaj. 
+ Arduino nano ali uno [link](https://www.aliexpress.com/item/Nano-CH340-ATmega328P-MicroUSB-Compatible-for-Arduino-Nano-V3/32572612009.html)

## Navodila in uporaba

Mikrokrmilnik Arduino nano priklju�imo na ra�unalnik. Na sam Arduino pa ve�emo svetlobna vrata, tako kot je zapisano v spodnji tabeli.
Pri priklju�ku za signal lahko uporabimo katerikoli pin za digitalni vhod.

| Arduino priklju�ek  | senzor priklju�ek |
|:-------------------:|:-----------------:|
| +5V                 | VCC               |
| GND                 | GND               |
| D2                  | Signal            |

Meritev izvajamo tado, da med svetlobna vrata postavimo vrtljivo plo��o s temnimi in prozornimi progami.
Vrvico navijemo okoli vrte�ega podstavka. Na konec vrvi obesimo ute�i in jo spustimo, da prosto pada.
Pred tem za�enemo program, s katerim sprogramiramo mikrokrmilnik Arduino nano.

![Alt text za sliko](postavitev.jpg)

## Program

S spodnjo kodo definiramo digitalni vhod, na katerega se bomo sklicevali skozi kodo.
```c++
#define vhodni_pin 2
```

Spodnja koda nam deklarira spremenljivko za izra�un kotne hitrosti
```c++
float kotna_hitrost;
```
V naslednji kodi imamo funkcijo setup(), v kateri nastavimo digitalni vhod in vklju�imo serijski vmesnik.
```c++
void setup() {                                  
   pinMode(vhodni_pin, INPUT);                   
  Serial.begin(9600);                           
  Serial.println("Spodaj se bodo izpisovale vrednosti kotne hitrosti v �/s");
}
```

Z naslednjo kodo ustvarimo zanko, ki bo merila �as med prvim prehodom med prozorno in �rno liso na vrtljivi plo��i
in drugim prehodom med prozorno in �rno liso. Na koncu kode je �e ena�ba za kotno hitrost in ukaz, ki izpisuje
vrednosti kotnih hitrosti.
```c++
void loop() {                                           
    int stanje_vhoda = 0;                      
  stanje_vhoda = digitalRead(vhodni_pin);

  while (digitalRead(vhodni_pin) == 0) {  
    }
  long t1 = millis();                         

  while (digitalRead(vhodni_pin) == 1) {  
     }

  while (digitalRead(vhodni_pin) == 0) { 
      }
  long t2 = millis();                           
     
  long dt =t2 - t1;

  kotna_hitrost = 360.0/12/dt*1000;            
    Serial.println(kotna_hitrost);
}
```


