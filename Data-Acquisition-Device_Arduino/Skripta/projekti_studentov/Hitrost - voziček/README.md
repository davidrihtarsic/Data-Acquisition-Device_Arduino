Author: Ana Dejak, Maša Vizovišek

Date: 2018-03-22 

# Merjenje pospeška s svetlobnimi vrati

Namen najinega projekta je, da z odèitavanjem hitrosti vozièka na dveh svetlobnih vratih dobimo pospešek vozièka. 
Hirosti sva izmerili s pomoèjo svetlobnih vrat tako, da smo mo merili èas med tem, ko so bila vrata prekinjena, dolžino prepreke pa sva izmerili.
Program bi lahko uporabili za demonstracijo pospešenega in pojemajoèega gibanja. Demonstracijo pa lahko z meritvami potrdimo tako, da lahko odèitamo hitrost in pospešek. 

## Potrebna oprema
Potrebšèine, ki jih potrebujemo za izvedbo poskusa: 
+ Arduino nano [link](https://www.aliexpress.com/item/Nano-CH340-ATmega328P-MicroUSB-Compatible-for-Arduino-Nano-V3/32572612009.html)
+ Dvoja svetlobna vrata in podstavka zanju
+ Drèo 
+Vozièek
+Dve vezni plošèi in žice za prikljuèitev vrat na Arduino nano

## Navodila in uporaba

Prikljuèke iz svetlobnih vratih vežemo na Arduino nano tako, kot je prikazano v tabeli:
Ker prikljuèke iz vrat ne moremo vezati direktno, uporabimo vmesno vezno plošèo in preko nje žice prikljuèimo na Arduino nano.

| Arduino prikljuèek  | senzor prikljuèek              |
|:-------------------------:|:----------------------------------:|
| +5V                         | Rdeè prikljuèek-VCC       |
| GND                        | Èrn prikljuèek -GND         |
| A0-A6                      | Rumen prikljuèek-Signal |

Najprej seveda preverimo, èe vrata delujejo. To lahko storimo kar z rokami, tako da najprej prekinemo prva vrata in nato še druga. V programu Arduino se nam morata izpisati obe hitrosti in pospešek.
Nato postavimo drèo in vozièek in svetlobna vrata, tako da drèa s svojim gibanjem prekine senzor na obeh svetlobnih vratih. V programu Arduino se nam izpišeta hitrosti na obeh svetlobnih vratih in pospešek vozièka.

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
  stanje_vhoda = digitalRead(16); // Prva vrata smo prikljuèili na vhod števila 16 (A2).

   while(digitalRead(16) == 0){  
   }
   long t1 = millis();
   delay(10);         //Èakam...
   //Serial.println("prekinjeno"); // Ko so prve svetlobna vrata prekinjena nam izpiše 0 oziroma prekinjeno. Zaènemo beležiti èas (t1), ko se prekinejo.
  
   while(digitalRead(16) == 1){
   }
   long t2 = millis ();
   delay(10);     //Èakam...
   //Serial.println("prosto");  //Ko prva svetlobna vrata niso prekinjena nam izpiše 1 oziroma prosto. Zabeležimo èas(t2), ko so zopet prosta.
   
   long dt = (t2 - t1) ;  //Izraèun spremembe zabeleženih èasov na prvih svetlobnih vratih.
   //Serial.println(dt);
   delay(100);    //Èakam...

    Serial.println("hitrost je:");
    float v  = 1300 / (dt);     //1300 mm je enako velikosti prepreke, ki potuje skozi svetlobna vrata.
    Serial.println(v);//Izpiše se nam hitrost na prvih svetlobnih vratih. 
    delay(100);     //Èakam...


    stanje_vhoda = digitalRead(17);   // Druga vrata smo prikljuèili na vhod števila 17 (A3).

   while(digitalRead(17) == 0){  
   }
   long t3 = millis();
   delay(10);    //Èakam...
   //Serial.println("prekinjeno1");    //Ko so druga svetlobna vrata prekinjena nam izpiše 0 oziroma prekinjeno1. Zaènemo beležiti èas (t3), ko se prekinejo.
  
   while(digitalRead(17) == 1){
   }
   long t4 = millis ();
   delay(10);    //Èakam...
   //Serial.println("prosto1");       //Ko prva svetlobna vrata niso prekinjena nam izpiše 1 oziroma prosto1. Zabeležimo èas(t4), ko so zopet prosta.
   
   long dt1 = (t4 - t3) ;           //Izraèun spremembe zabeleženih èasov na drugih svetlobnih vratih.
   //Serial.println(dt1);
   delay(100);    //Èakam...

    Serial.println("hitrost 1 je:");
    float v1  = 1300/ (dt1);         //1300 mm je enako velikosti prepreke, ki potuje skozi svetlobna vrata.
    Serial.println(v1);           //Izpiše se nam hitrost na drugih svetlobnih vratih. 
    delay(100);    //Èakam...
    
   Serial.println("pospesek je:");  // Izraèun pospešeka naše prepreke skozi prva in druga svetlobna vrata.
   float a = (v1-v)/(dt-dt1) *100;
   Serial.println(a);
   delay(100);   //Èakam...


}
 ```c++
