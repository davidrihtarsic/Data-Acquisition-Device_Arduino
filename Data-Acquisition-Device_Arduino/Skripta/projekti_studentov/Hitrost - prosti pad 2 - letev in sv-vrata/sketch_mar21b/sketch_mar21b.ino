#define prekinjeno 0
#define neprekinjeno 1

long dt[30];
float hitrost[30];
float pospesek[30];
void setup() {
  // put your setup code here, to run once:
  pinMode(14, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int n = 0; n < 10; n++) {

    while (digitalRead(14) == prekinjeno) {
      //čakamo črno,torej smo na prozornem
    }
    long t1 = micros();
    delay(0.1);

    while (digitalRead(14) == neprekinjeno) {
      //smo na črnem
    }

    while (digitalRead(14) == prekinjeno) {
      //čakamo črno,torej smo na prozornem
    }
    long t3 = micros();
    delay(0.1);

    dt[n] = t3 - t1;
  }

  for (int n = 0; n < 10; n++) {
    hitrost[n] = 10000.0 / dt[n];
    Serial.print(" hitrost ");
    Serial.println(hitrost[n]);
  }

    for (int n = 0; n < 9; n++) {
    pospesek[n] =(hitrost[n+1]-hitrost[n])/ dt[n] / 0.000001;
    Serial.print(" pospesek ");
    Serial.println(pospesek[n]);
  }
}


