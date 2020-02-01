#define Correction 100 // Sensor Sensitivity Correction Percent
#define Filtre 1// Filtre=1 If using the module filters
#define Echantillon 5000 // number of samples
#define CS 10 // Assignment of the CS pin

#include <SPI.h> // call library

int MSB;
int LSB;
double valeur;
float total = 0;
float K = 0;
signed int milli_amps;

unsigned long t;

void setup()
{
  Serial.begin(115200); // initialization of serial communication
  SPI.begin(); // initialization of SPI port
  SPI.setDataMode(SPI_MODE0); // configuration of SPI communication in mode 0
  SPI.setClockDivider(SPI_CLOCK_DIV16); // configuration of clock at 1MHz
  pinMode(CS, OUTPUT);
  //K
  K = 1.15 * 10000 / 899;
}

void loop()
{
  if (Filtre == 1)
  {
    total = 0;
    for (int i; i < Echantillon; i++)
    {
      digitalWrite(CS, LOW); // activation of CS line
      MSB = SPI.transfer(0x00); // MSBs recovery
      LSB = SPI.transfer(0x00); // LSBs recovery
      digitalWrite(CS, HIGH); // deactivation of CS line
      //float Data = ((MSB<<8)+LSB-2048)*12.7;
      total += ((MSB << 8) + LSB - 2048) * 12.45;
    }
    milli_amps = total / Echantillon;
  }
  else
  {
    digitalWrite(CS, LOW); // activation of CS line
    MSB = SPI.transfer(0x00); // MSBs recovery
    LSB = SPI.transfer(0x00); // LSBs recovery
    digitalWrite(CS, HIGH); // deactivation of CS line
    int Data = (MSB << 8) + LSB;
    milli_amps =  1.15 * 10000 / 899 * (Data - 2048);
    //milli_amps = (Correction / 100) * (10000 * (((MSB<<8) | LSB) - 2048)) / 899; // Formula given in the

  }
  Serial.print(" Courant=");
  Serial.print(milli_amps);
  Serial.println(" mA");
  //delay(100);
}