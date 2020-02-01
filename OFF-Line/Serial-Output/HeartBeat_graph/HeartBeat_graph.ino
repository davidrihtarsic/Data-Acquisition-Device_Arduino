#include <Wire.h>¸                                              
#include <LiquidCrystal_I2C.h>                               
LiquidCrystal_I2C DaqLcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

int sensorPin = 7;
double alpha = 0.75;
int period =100;
double change =0.0;
double minval = 0.0;

void setup() {
  DaqLcd.begin(8, 2);
  Serial.begin(9600);
}

void loop() {
  int i = 0;
  long ch = 0;
  for (i=0;i<64;i++){
    ch += analogRead(7); 
  }
 
  float val = ch/64.0;
  Serial.println(val);
}
