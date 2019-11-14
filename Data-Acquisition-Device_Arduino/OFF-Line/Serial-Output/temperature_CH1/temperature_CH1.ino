void setup() {
  pinMode(15, OUTPUT);
  digitalWrite(15,LOW);
  pinMode(14, INPUT_PULLUP); //A0
  // initialize the serial communication:
  Serial.begin(9600);
}

void loop() {
  // send the value of analog input 0:
  int CH1 = analogRead(A0);
  
  Serial.print("0,200,");
  Serial.println(CH1);

  // wait a bit for the analog-to-digital converter to stabilize after the last
  // reading:
  delay(50);
}
