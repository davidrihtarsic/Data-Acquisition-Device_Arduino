/*
  Data logger example:

  Set the values below
  according to your needs.
*/

const int NUM_OF_SAMPLES    = 100;   // number of recording data per channel 
const int NUM_OF_CHANNELS   = 1;     // number of recording channels
const int SAMPLING_RATE_MS  = 30;    // delay in ms between samples (must be grater than 20ms)

/*
 * PROGRAM...
 * change only if you know what wou're doing...
 */
#include <SPI.h>
#include <SD.h>

const int chipSelect = 9;

void setup() {
  //for DEMO we used A0 as sampled channel
  //and A1 as GND
  pinMode(14, INPUT_PULLUP);
  pinMode(15,OUTPUT);
  digitalWrite(15,0);
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
  int max_samples = NUM_OF_SAMPLES;
  int num_of_ch = NUM_OF_CHANNELS;
  int delay_time_ms = SAMPLING_RATE_MS;
  if (delay_time_ms > 20){
    delay_time_ms -= 20;
  }
  else{
    delay_time_ms = 0;
  }
  
  unsigned long time_start;
  unsigned long time_stop;
  unsigned long time_diff;

  Serial.print("Max Samples     = ");Serial.println(max_samples);
  Serial.print("Sampling        = ");Serial.print(num_of_ch);Serial.println(" channel(s)");
  Serial.print("Sampling period = ");Serial.print(delay_time_ms+20);Serial.println(" ms");
  Serial.print("Sampling time   = ");Serial.print((delay_time_ms+20)*max_samples/1000);Serial.println(" s");
  Serial.println("----------------------------------");

  //print same data to FIle...
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.print("Max Samples     = ");dataFile.println(max_samples);
    dataFile.print("Sampling        = ");dataFile.print(num_of_ch);dataFile.println(" channel(s)");
    dataFile.print("Sampling period = ");dataFile.print(delay_time_ms+20);dataFile.println(" ms");
    dataFile.print("Sampling time   = ");dataFile.print((delay_time_ms+20)*max_samples/1000);dataFile.println(" s");
    dataFile.println("----------------------------------");
    
    dataFile.close();
  }
  else {
    Serial.println("error opening datalog.txt");
  }
  
  
  delay(1000);
  time_start = millis();
  for (int n = 0; n < max_samples; n++) {
    String dataString = "";
    for (int analogPin = 0; analogPin < num_of_ch; analogPin++) {
      if (analogPin > 0) {
        dataString += ",";
      }
      dataString += String(analogRead(analogPin));
    }
    delay(delay_time_ms); 

    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    // if the file is available, write to it:
    if (dataFile) {
      dataFile.println(dataString);
      dataFile.close();
      // print to the serial port too:
      //Serial.println(dataString);
    }
    // if the file isn't open, pop up an error:
    else {
      Serial.println("error opening datalog.txt");
    }
  }
  time_stop = millis();
  time_diff = time_stop - time_start;
  Serial.print("Sampling time:"); Serial.print(time_diff); Serial.println(" ms");
  float period = (float)time_diff/max_samples;
  Serial.print("Sampling period:"); Serial.print(period,2); Serial.println(" ms");
  Serial.println("----------------------------------");

  //print same data to FIle...
  dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.print("Sampling time:"); dataFile.print(time_diff); dataFile.println(" ms");
    float period = (float)time_diff/max_samples;
    dataFile.print("Sampling period:"); dataFile.print(period,2); dataFile.println(" ms");
    dataFile.println("----------------------------------");
    
    dataFile.close();
  }
  else {
    Serial.println("error opening datalog.txt");
  }
}

void loop() {
  //no continous work...
}









