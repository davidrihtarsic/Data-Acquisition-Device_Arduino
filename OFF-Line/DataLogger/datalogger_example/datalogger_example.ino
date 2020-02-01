/*
  SD card datalogger

  This example shows how to log data from three analog sensors
  to an SD card using the SD library.

  The circuit:
   analog sensors on analog ins 0, 1, and 2
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 9

  created  24 Nov 2010
  by Tom Igoe
  modified 2018-03-08
  changed by
  David Rihtaršič

  This example code is in the public domain.

*/

#include <SPI.h>
#include <SD.h>

const int chipSelect = 9;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


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
  int num_of_ch = 3;
  int delay_time_ms = 10;

  Serial.print("Max Samples     = ");Serial.println(max_samples);
  Serial.print("Sampling        = ");Serial.print(num_of_ch);Serial.println(" channel(s)");
  Serial.print("Sampling period = ");Serial.print(delay_time_ms);Serial.println(" ms");
  Serial.print("Sampling time   = ");Serial.print(delay_time_ms*max_samples/1000);Serial.println(" s");
  Serial.println("----------------------------------");
  delay(1000);
  for (int n = 0; n < max_samples; n++) {
    String dataString = "";
    for (int analogPin = 0; analogPin < num_of_ch; analogPin++) {
      if (analogPin > 0) {
        dataString += ",";
      }
      dataString += String(analogRead(analogPin));
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

void loop() {
  //no continous work...
}









