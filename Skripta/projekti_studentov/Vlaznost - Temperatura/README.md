# Merjenje relativne vlažnosti - Bukovec, Hanžek Šušteršic, Lamovec

S pomoèjo mikrokrmilnika Arduino Uno izmerimo in na LCD zason izpišemo temperaturo in relativno vlažnost, ki se spreminja v neposredni bližini sestavljenega merilnika. 

##  Potrebna oprema

Za meritev potrebujemo mikrokrmilnik Arduino Uno, DHT11, ki meri relativno vlažnost (to je senzor, ki smo ga uporabile; za merjenje uporablja NTC termistor), LCD zaslon. 
Programska koda, ki je potrebna za  rešitev, je priložena spodaj.


## Navodila in uporaba

Mikrokrmilnik Arduino Uno prikljuèimo na raèunalnik. Na sam Arduino vežemo najprej DHT11,tako kot je prikazano na spodnji sliki, vezje povežemo še z LCD zaslonom.
Meritve so bile po veèini dokaj natanène; le pri nižjih vrednostih vlažnosti so se meritve razhajale od dejanskh vrednosti, preverjenih z drugimi merilnimi napravami. 
Razlog je ta, da je obmoèje veèje natanènosti DHT11 senzorja pri višjih vrednostih vlažnosti (medtem ko temperaturo kaže natanèno). 
Za veè informacij, pomoè: http://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/


| Arduino prikljuèek  | senzor prikljuèek |
|:-------------------:|:-----------------:|
| +7V                 | signal            |
| +5V                 | VCC               |
| GN                  | ground            |


Prikljuèitev LCDja je razvidno na spodnji sliki. 

![Alt text za sliko](SLIKA 0.jpg)

## Program


#include <Wire.h>¸                                              
#include <LiquidCrystal_I2C.h>                                  // dosegljivo na: https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Naslov LCDja (0x27) morate vpisati sami, 
#include <dht.h>



dht DHT; //vkljuèimo (import) ustrezne knjižnice - link

#define DHT11_PIN 7 //definiramo vhod


//naslednja funkcija je potrebna za vzpostavitev lcd zaslona in možnost prikazovanja
void setup(){
  lcd.begin(16, 2);
  pinMode(15, OUTPUT);
  digitalWrite(15,LOW);
  pinMode(14, INPUT_PULLUP);
  Serial.begin(9600);
}


//funkcija prebere vrednosti na DHT in jo zapiše kot intiger; spremenjivka t nam beleži temperaturo, h pa relativno vlažnost
void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  float t = DHT.temperature;
  float h = DHT.humidity / 2 ;
 

// izpis v besedi in številki na LCD zaslonu 
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


