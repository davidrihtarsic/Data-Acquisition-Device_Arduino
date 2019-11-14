//BLDC controll----------------
#include <Servo.h>
Servo BLDC_motor_controller;  // create servo object to control a servo
#define BLCD_controller_pin 3
#define joystic_pin 0  // analog pin used to connect the potentiomete
int joy_val;    // variable to read the value from the analog pin

//RPM -------------------------
#define rpm_pin 2

//CURRENT----------------------
#define CS 10 // Assignment of the CS pin
#define Echantillon 50 // number of samples
#define n 35
#include <SPI.h> // call library
int MSB;
int LSB;
double valeur;
float total = 0;
float K = 0;
signed int milli_amps;

//VOLTAGE---------------------
#define volt_pin 1
#define R_1 1
#define R_2 2.2

void setup() {
  BLDC_motor_controller.attach(BLCD_controller_pin);  // attaches the servo on pin 9 to the servo object
  pinMode(rpm_pin, INPUT);

  Serial.begin(9600);
  SPI.begin(); // initialization of SPI port
  SPI.setDataMode(SPI_MODE0); // configuration of SPI communication in mode 0
  SPI.setClockDivider(SPI_CLOCK_DIV16); // configuration of clock at 1MHz
  pinMode(CS, OUTPUT);
  K = 1.15 * 10000 / 899;
}

void loop() {
  motorControl();
  //rpmMeasure();
  currentMeasure();
  voltageMeasure();
  Serial.println();
}

void motorControl() {
  joy_val = analogRead(joystic_pin);            // reads the value of the potentiometer (value between 0 and 1023)
  joy_val = map(joy_val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  BLDC_motor_controller.write(joy_val);                  // sets the servo position according to the scaled value
}

void rpmMeasure() {
  unsigned long duration;
  duration = pulseIn(rpm_pin, HIGH);
  duration += pulseIn(rpm_pin, LOW);
  Serial.print(" t[ms]= ");
  Serial.print(duration);
}

void currentMeasure() {
  total = 0;
  for (int i; i < Echantillon; i++)
  {
    digitalWrite(CS, LOW); // activation of CS line
    MSB = SPI.transfer(0x00); // MSBs recovery
    LSB = SPI.transfer(0x00); // LSBs recovery
    digitalWrite(CS, HIGH); // deactivation of CS line
    total += ((MSB << 8) + LSB - 2048) * 12.45 + n;
  }
  milli_amps = total / Echantillon;
  Serial.print(" I[mA]= ");
  Serial.print(milli_amps);
}

void voltageMeasure() {
  // timesheet: 2018-05-20 18:00-20:16, NIO9, voltage function
  int volt = analogRead(volt_pin);
  volt = volt*5.0/1023*(R_1+R_2)/R_2;
  Serial.print(" U[V]= ");
  Serial.print(volt);
}

