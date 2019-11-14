/TO-DO !!!!!!!!!!

#include <SPI.h>
#include <SD.h>
#include  <OneWire.h>

const int chipSelect = 9;

void setup() {
  int pin_gnd=8;
  int pin_vcc=9;
  pinMode(pin_gnd, OUTPUT);
  pinMode(pin_vcc, OUTPUT);
  digitalWrite(pin_gnd, LOW);
  digitalWrite(pin_vcc, HIGH);
  OneWire ds(10);
  Serial.begin(9600);
  delay(1000);

  
  doDataLogging();
  
}

void loop() {
  //no continous work...
  //Serial.println(Termistor(analogRead(0)));
  //delay(100);
}

double Termistor(int RawADC){
  double Temp;
  Temp = log(((10240000/RawADC) - 10000));
  Temp = 1/(0.001129148 + (0.000234125+(0.0000000876741*Temp*Temp))*Temp);
  Temp = Temp -273.15;
  return Temp;
}

void doDataLogging() {
  Serial.print("Initializing SD card...");
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
  //  Do n=100 samples of i=1 CH every t = 10ms &
  //  Save data to datalog.txt
  int max_samples = 100;
  int num_of_ch = 1;
  int delay_time_ms = 10;

  Serial.print("Max Samples     = "); Serial.println(max_samples);
  Serial.print("Sampling        = "); Serial.print(num_of_ch); Serial.println(" channel(s)");
  Serial.print("Sampling period = "); Serial.print(delay_time_ms); Serial.println(" ms");
  Serial.print("Sampling time   = "); Serial.print(delay_time_ms * max_samples / 1000); Serial.println(" s");
  Serial.println("----------------------------------");
  delay(1000);
  for (int n = 0; n < max_samples; n++) {
    String dataString = "";
    for (int analogPin = 0; analogPin < num_of_ch; analogPin++) {
      if (analogPin > 0) {
        dataString += ",";
      }
      dataString += String(Termistor(analogRead(analogPin)));
    }
    delay(10);

    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    // if the file is available, write to it:
    if (dataFile) {
      dataFile.println(dataString);
      dataFile.close();
      // print to the serial port too:
      Serial.println(dataString);
    }
    // if the file isn't open, pop up an error:
    else {
      Serial.println("error opening datalog.txt");
    }
  }
  Serial.println("----------------------------------");
}








