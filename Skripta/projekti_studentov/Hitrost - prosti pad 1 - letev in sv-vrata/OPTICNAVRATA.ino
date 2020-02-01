long dt[30];

void setup() {
  // put your setup code here, to run once:
  pinMode(14, INPUT);
  Serial.begin(115200);
  Serial.print(digitalRead(14));
}

void loop() {
  // put your main code here, to run repeatedly:
  int stanje_vhoda = 0;
  int i = 0;
  stanje_vhoda = digitalRead(14);

  for (int n = 0; n < 20; n++) {
    while (digitalRead(14) == 0) {
      //čakamo... dva enačaja -> primerja, en enačaj -> definiraš --- prozorna
    }

    long t1 = micros();
    //delay(0.1);  //zakasnitev, da dobimo ustreznejše rezultate - odstranimo nepravilnosti iz okolice

    while (digitalRead(14) == 1) {
      // čakamo, da sprostimo snop ---- črna
    }
    //delay(0.1);  //zakasnitev, da dobimo ustreznejše rezultate - odstranimo nepravilnosti iz okolice

    while (digitalRead(14) == 0) {
      // ---- prozorna 2.
    }
    long t2 = micros();
    //delay(0.1);
    dt[n] = t2 - t1;
  }

   for (int n = 0; n < 10; n++) {
    Serial.print(dt[n]);
    Serial.print(" ");
    float v = 10000.0 / dt[n] ;
    Serial.print(v);
    Serial.println("m/s");
    }
    delay(10000);
}
