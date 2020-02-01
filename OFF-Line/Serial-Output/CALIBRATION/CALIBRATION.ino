String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int adc_ch  = A0;                // A0 - input
int pin_gnd = 15;                // A1 - GND
int pin_vcc = 16;                // A2 - +5V


void setup() {
  pinMode(adc_ch, INPUT_PULLUP);
  pinMode(pin_gnd, OUTPUT);
  pinMode(pin_vcc, OUTPUT);
  digitalWrite(pin_gnd, LOW);
  digitalWrite(pin_vcc, HIGH);
  // initialize the serial communication:
  Serial.begin(9600);
  Serial.println("###########################################");
  Serial.println("# INSTRUCTIONS:                           #");
  Serial.println("#   1. Input measured real phisical       #");
  Serial.println("#      value (example: 22.4)              #");
  Serial.println("#   2. then press ENTER and               #");
  Serial.println("#      change the conditions              #");
  Serial.println("#   3. repeat steps 1. and 2. ...         #");
  Serial.println("# When you are done with calibration:     #");
  Serial.println("#   4. Copy data to spreadsheet.          #");
  Serial.println("#   5. Fit some polynome to the points.   #");
  Serial.println("#   6. Use coeficients for calculation.   #");
  Serial.println("#      example: 'temperature.ino'         #");
  Serial.println("###########################################");
  Serial.println("Val. ADC");
  inputString.reserve(20);
}

void loop() {

  if (stringComplete) {
    Serial.print(inputString);
    Serial.print(" ");
    inputString = "";
    stringComplete = false;

    // send the value of analog input 0:
    long CH1 = 0;

    int i;
    for (i = 0; i < 128; i++) {
      CH1 += analogRead(adc_ch);
      delay(1);
    }
    float Vol_CH1 = float(CH1/128.0);     // calibration in ADC values...
    //float Vol_CH1 = CH1*5.0/1023;         // calibration in Voltage...
    Serial.println(Vol_CH1);
    //Serial.println(analogRead(adc_ch));
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();  // get the new byte:
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;              // add it to the inputString:
    }
  }
}
