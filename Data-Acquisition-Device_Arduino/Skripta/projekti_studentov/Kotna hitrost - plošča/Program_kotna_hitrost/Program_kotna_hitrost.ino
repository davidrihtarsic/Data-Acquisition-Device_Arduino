/*Avtor: Ales Prsin
 *       Miha Zarn
 *       
 *Datum: 2018-03-21

 *OPIS PROJEKTA: 
 *Ta program je namenjen merjenju kotne hitrosti vrtljive pšlošče skozi svetlobna vrata.
 */

/* Spremenljivke
 *  vhodni pin (Pri ukazu #define lahko spremenimo številko vhodnega pina)
 */
 
#define vhodni_pin 2

float kotna_hitrost;                            //Deklariramo spremenljivko za izračun kotne hitrosti
void setup() {                                  
  pinMode(vhodni_pin, INPUT);                   //Definiramo vhodni pin
  Serial.begin(9600);                           //Vključimo uporabo serijskega vmesnika
  Serial.println("Spodaj se bodo izpisovale vrednosti kotne hitrosti v °/s");
}

void loop() {                                   //Definiramo zanko, ki bo merila čas prehoda temne in prozorne proge          
    int stanje_vhoda = 0;                      
  stanje_vhoda = digitalRead(vhodni_pin);

  while (digitalRead(vhodni_pin) == 0) {  //Primerjanje vrednosti 0 in 1
    //čakamo na spremembo vrednosti
  }
  long t1 = millis();                           //čas prve prekinitve svetlobnih vrat

  while (digitalRead(vhodni_pin) == 1) {  //Primerjanje vrednosti 0 in 1
    //čakamo na spremembo vrednosti
  }

  while (digitalRead(vhodni_pin) == 0) {  //Primerjanje vrednosti 0 in 1
    //čakamo na spremembo vrednosti
  }
  long t2 = millis();                           //čas druge prekinitve svetlobnih vrat
     
  long dt =t2 - t1;                             //čas med obema prekinitvama
    

  kotna_hitrost = 360.0/12/dt*1000;             //izračun kotne hitrosti (enote: °/s)
    Serial.println(kotna_hitrost);
  }
