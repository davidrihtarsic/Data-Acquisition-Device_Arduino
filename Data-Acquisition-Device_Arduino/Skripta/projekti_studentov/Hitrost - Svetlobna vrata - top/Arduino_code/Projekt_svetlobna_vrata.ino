/*Avtorja: Nejc Urbas
           Matjaž Jerala
  Datum: 2018-03-21

  OPIS PROJEKTA:
  Program je namenjen meritvi hitrosti izstrelka iz balističnega topa. 
*/
#define prekinjeno 1
#define prozorno 0
#define razdalja 100.000 // v milimetrih
void setup() {
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  Serial.begin(9600);
}

void loop() {
  while (digitalRead (14) == prozorno) {
  }
  long t1 = micros();
  while (digitalRead (15) == prozorno) {
  }
  long t2 = micros(); //mikrosekunde
  long dt = t2 - t1;
  float v = (razdalja / dt)*1000;
  Serial.print("Hitrost: ");
  Serial.print(v);
  Serial.println(" m/s");
}
