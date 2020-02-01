# Merjenje relativne vla�nosti - Bukovec, Han�ek �u�ter�ic, Lamovec

S pomo�jo mikrokrmilnika Arduino Uno izmerimo in na LCD zason izpi�emo temperaturo in relativno vla�nost, ki se spreminja v neposredni bli�ini sestavljenega merilnika. 

##  Potrebna oprema

Za meritev potrebujemo mikrokrmilnik Arduino Uno, DHT11, ki meri relativno vla�nost (to je senzor, ki smo ga uporabile; za merjenje uporablja NTC termistor), LCD zaslon. 
Programska koda, ki je potrebna za  re�itev, je prilo�ena spodaj.


## Navodila in uporaba

Mikrokrmilnik Arduino Uno priklju�imo na ra�unalnik. Na sam Arduino ve�emo najprej DHT11,tako kot je prikazano na spodnji sliki, vezje pove�emo �e z LCD zaslonom.
Meritve so bile po ve�ini dokaj natan�ne; le pri ni�jih vrednostih vla�nosti so se meritve razhajale od dejanskh vrednosti, preverjenih z drugimi merilnimi napravami. 
Razlog je ta, da je obmo�je ve�je natan�nosti DHT11 senzorja pri vi�jih vrednostih vla�nosti (medtem ko temperaturo ka�e natan�no). 
Za ve� informacij, pomo�: http://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/


| Arduino priklju�ek  | senzor priklju�ek |
|:-------------------:|:-----------------:|
| +7V                 | signal            |
| +5V                 | VCC               |
| GN                  | ground            |


Priklju�itev LCDja je razvidno na spodnji sliki. 

![Alt text za sliko](SLIKA 0.jpg)

## Program


#include <Wire.h>�                                              
#include <LiquidCrystal_I2C.h>                                  // dosegljivo na: https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Naslov LCDja (0x27) morate vpisati sami, 
#include <dht.h>



dht DHT; //vklju�imo (import) ustrezne knji�nice - link

#define DHT11_PIN 7 //definiramo vhod


//naslednja funkcija je potrebna za vzpostavitev lcd zaslona in mo�nost prikazovanja
void setup(){
  lcd.begin(16, 2);
  pinMode(15, OUTPUT);
  digitalWrite(15,LOW);
  pinMode(14, INPUT_PULLUP);
  Serial.begin(9600);
}


//funkcija prebere vrednosti na DHT in jo zapi�e kot intiger; spremenjivka t nam bele�i temperaturo, h pa relativno vla�nost
void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  float t = DHT.temperature;
  float h = DHT.humidity / 2 ;
 

// izpis v besedi in �tevilki na LCD zaslonu 
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);

  lcd.home();
  lcd.print("Temperatura = ");
  lcd.println(t);
  delay(2000);
  lcd.clear();
  delay(100);
  lcd.print("Vlaznost = ");
  lcd.println(h);
  delay(1000);
```


