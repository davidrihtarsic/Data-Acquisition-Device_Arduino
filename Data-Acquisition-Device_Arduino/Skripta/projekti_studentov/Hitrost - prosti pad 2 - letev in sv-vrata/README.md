Author: Tinka Gerjevič, Kelli Kogoj        

Date: 2018-03-22 

# Merjenje pospeška pri prostem padu

S pomoèjo svetlobnih vrat in plošèice s èrnimi in prozornimi èrtami, sva merili pospešek padajoèe plošèice. To sva naredili tako, da sva plošèico spustili skozi svetlobna vrata, ta so beležila èas prekinjenega svetlobnega snopa. Iz izmerjenega èasa in znane razdalje med èrnimi èrtami na plošèici, sva izraèunali hitrost padanja. Iz teh vrednosti pa potem pospešek. Ta eksperiment lahko uporabljamo, ko želimo izraèunati pospešek kateregakoli telesa, saj je pospešek sprememba hitrosti v spremembi èasa. 

## Potrebna oprema
Uèitelj pri tem eksperimentu potrebuje
- raèunalnik,
- svetlobna vrata s stojalom,
- Arduino-nano,
- žice,
- plošèico s èrnimi in prozornimi èrtami,
- vezno plošèo

## Navodila in uporaba

| Arduino prikljuèek  | senzor prikljuèek        |
|:-------------------:|:------------------------:|
| +5V                 | Rdeè prikljuèek - VCC    |
| GND                 | Èrn prikljuèek - GND     |
| A0                  | Rumen prikljuèek - Signal|

Arduino nano prikljuèimo v raèunalnik in zaženemo program Arduino 1.6.5. Svetlobna vrata prikljuèimo na Arduino nano, kot je prikazano v tabeli. Skozi svetlobna vrata spustimo plošèico, da prosto pade. V programu se nam izpišejo vrednosti hitrosti in pospeškov.

## Program
 ```c++
#define neprekinjeno 0
#define prekinjeno 1

long dt[30];
float hitrost[30];
float pospesek[30];
```
Definirali sva hitrost in pospešek za 30 meritev.

 ```c++
void setup() {

  pinMode(14, INPUT);
  Serial.begin(115200);
}
 ```
Signal s svetlobnih vrat sva prikljuèili na Arduino nano na digitalni vhod 14

 ```c++
void loop() {


  for (int n = 0; n < 10; n++) {
 ```

Program nam izmeri deset meritev in si jih zapomni, da lahko kasneje z meritvami operira.

 ```c++
    while (digitalRead(14) == neprekinjeno) {
    }
    long t1 = micros();
    delay(0.1);
  ```
Èakamo na prekinitev svetlobnega snopa.

 ```c++

    while (digitalRead(14) == prekinjeno) {

    }
 ```
V tem èasu je svetlobni snop prekinjen.

```c++
    while (digitalRead(14) == neprekinjeno) {
    }
long t3 = micros();
    delay(0.1);
```

Èakamo na prekinitev svetlobnega snopa.

```c++
    
    dt[n] = t3 - t1;
}

```
Definiramo spremembo èasa; pozorni moramo biti, da merimo èas med dvema prehodoma od neprekinjenega do prekinjenega snopa svetlobe.
  
```c++
  for (int n = 0; n < 10; n++) {
    hitrost[n] = 10000.0 / dt[n];
    Serial.print(" hitrost ");
    Serial.println(hitrost[n]);
  }
```
Iz izmerjenih èasov in znane razdalje med prekinjenim in neprekinjenim snopom program izraèuna hitrost padanja.

```c++
    for (int n = 0; n < 9; n++) {
    pospesek[n] =(hitrost[n+1]-hitrost[n])/ dt[n] / 0.000001;
    Serial.print(" pospesek ");
    Serial.println(pospesek[n]);
  }
}
```
Iz izraèunanih hitrosti in izmerjenih èasov program izraèuna pospešek padanja plošèice.