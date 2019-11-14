Author: Ana Dejak, Ma�a Vizovi�ek

Date: 2018-03-22 

# Merjenje pospe�ka s svetlobnimi vrati

Namen najinega projekta je, da z od�itavanjem hitrosti vozi�ka na dveh svetlobnih vratih dobimo pospe�ek vozi�ka. 
Hirosti sva izmerili s pomo�jo svetlobnih vrat tako, da smo mo merili �as med tem, ko so bila vrata prekinjena, dol�ino prepreke pa sva izmerili.
Program bi lahko uporabili za demonstracijo pospe�enega in pojemajo�ega gibanja. Demonstracijo pa lahko z meritvami potrdimo tako, da lahko od�itamo hitrost in pospe�ek. 

## Potrebna oprema
Potreb��ine, ki jih potrebujemo za izvedbo poskusa: 
+ Arduino nano [link](https://www.aliexpress.com/item/Nano-CH340-ATmega328P-MicroUSB-Compatible-for-Arduino-Nano-V3/32572612009.html)
+ Dvoja svetlobna vrata in podstavka zanju
+ Dr�o 
+Vozi�ek
+Dve vezni plo��i in �ice za priklju�itev vrat na Arduino nano

## Navodila in uporaba

Priklju�ke iz svetlobnih vratih ve�emo na Arduino nano tako, kot je prikazano v tabeli:
Ker priklju�ke iz vrat ne moremo vezati direktno, uporabimo vmesno vezno plo��o in preko nje �ice priklju�imo na Arduino nano.

| Arduino priklju�ek  | senzor priklju�ek              |
|:-------------------------:|:----------------------------------:|
| +5V                         | Rde� priklju�ek-VCC       |
| GND                        | �rn priklju�ek -GND         |
| A0-A6                      | Rumen priklju�ek-Signal |

Najprej seveda preverimo, �e vrata delujejo. To lahko storimo kar z rokami, tako da najprej prekinemo prva vrata in nato �e druga. V programu Arduino se nam morata izpisati obe hitrosti in pospe�ek.
Nato postavimo dr�o in vozi�ek in svetlobna vrata, tako da dr�a s svojim gibanjem prekine senzor na obeh svetlobnih vratih. V programu Arduino se nam izpi�eta hitrosti na obeh svetlobnih vratih in pospe�ek vozi�ka.

![Alt text za sliko](image1.jpg)

## Program

```c++
void setup() {
  // put your setup code here, to run once:
  pinMode(18,INPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int stanje_vhoda =0;
  stanje_vhoda = digitalRead(16); // Prva vrata smo priklju�ili na vhod �tevila 16 (A2).

   while(digitalRead(16) == 0){  
   }
   long t1 = millis();
   delay(10);         //�akam...
   //Serial.println("prekinjeno"); // Ko so prve svetlobna vrata prekinjena nam izpi�e 0 oziroma prekinjeno. Za�nemo bele�iti �as (t1), ko se prekinejo.
  
   while(digitalRead(16) == 1){
   }
   long t2 = millis ();
   delay(10);     //�akam...
   //Serial.println("prosto");  //Ko prva svetlobna vrata niso prekinjena nam izpi�e 1 oziroma prosto. Zabele�imo �as(t2), ko so zopet prosta.
   
   long dt = (t2 - t1) ;  //Izra�un spremembe zabele�enih �asov na prvih svetlobnih vratih.
   //Serial.println(dt);
   delay(100);    //�akam...

    Serial.println("hitrost je:");
    float v  = 1300 / (dt);     //1300 mm je enako velikosti prepreke, ki potuje skozi svetlobna vrata.
    Serial.println(v);//Izpi�e se nam hitrost na prvih svetlobnih vratih. 
    delay(100);     //�akam...


    stanje_vhoda = digitalRead(17);   // Druga vrata smo priklju�ili na vhod �tevila 17 (A3).

   while(digitalRead(17) == 0){  
   }
   long t3 = millis();
   delay(10);    //�akam...
   //Serial.println("prekinjeno1");    //Ko so druga svetlobna vrata prekinjena nam izpi�e 0 oziroma prekinjeno1. Za�nemo bele�iti �as (t3), ko se prekinejo.
  
   while(digitalRead(17) == 1){
   }
   long t4 = millis ();
   delay(10);    //�akam...
   //Serial.println("prosto1");       //Ko prva svetlobna vrata niso prekinjena nam izpi�e 1 oziroma prosto1. Zabele�imo �as(t4), ko so zopet prosta.
   
   long dt1 = (t4 - t3) ;           //Izra�un spremembe zabele�enih �asov na drugih svetlobnih vratih.
   //Serial.println(dt1);
   delay(100);    //�akam...

    Serial.println("hitrost 1 je:");
    float v1  = 1300/ (dt1);         //1300 mm je enako velikosti prepreke, ki potuje skozi svetlobna vrata.
    Serial.println(v1);           //Izpi�e se nam hitrost na drugih svetlobnih vratih. 
    delay(100);    //�akam...
    
   Serial.println("pospesek je:");  // Izra�un pospe�eka na�e prepreke skozi prva in druga svetlobna vrata.
   float a = (v1-v)/(dt-dt1) *100;
   Serial.println(a);
   delay(100);   //�akam...


}
 ```c++
