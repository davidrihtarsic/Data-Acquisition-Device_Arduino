---
title: Arduino-DAQ
author: dr. David Rihtaršič
date:  2018-03-05
---
\tableofcontents  

# Merilne naprave

Pri fizikalnih eksperimentih pogosto uporabljamo merilne naprave, s katerimi želimo potrditi teoretične principe in fizikalne pojave. V šolskem prostoru najpogosteje uporabljamo Vernier-jevo merilno napravo LabQuest Hardware @LabQuest30:online , ki nam omogoča raznovrstne meritve.

![Vernier-jeva merilna naprava LabQuest2](/home/david/Files/GitHub_noSync/Arduino-Data-Acquisition-Device/Skripta/slike/labq2.jpg)

Poglejmo si nekaj podatkov o napravi:

- **Display**
  + 11.2 cm x 6.7 cm (13.1 cm diagonal) screen
  + 00 x 480 pixel color display at 188 dpi
  + ED backlight
  + ortrait or landscape screen orientation
  + igh-contrast mode for outdoor visibility
- **Processor**
  + 800 MHz Application Processor
- **Connectivity**
  + Wi-Fi 802.11 b/g/n @ 2.4GHz
  + Bluetooth Smart for WDSS and Go Wireless Sensors
- **User Interface**
  + Resistive touch screen
  + Touch and stylus navigation for efficiency and precision
- **Data Acquisition**
  + 100,000 samples per second
  + 12-bit resolution
  + Built-in GPS, 3-axis accelerometer, ambient temperature, light, and microphone
- **Environmental Durability**
  + Operating Temperature: 0  + 45°C
  + Storage Temperature: -30  + 60°C
  + Splash resistant
  + Rugged enclosure designed to withstand a fall from lab bench
- **Size and Weight**
  + Size: 8.8 cm x 15.4 cm x 2.5 cm
  + Weight: 350 g
- **Ports**
  + 5 sensor channels
  + USB port for sensors, flash drives, and peripherals
  + USB mini port
  + DC power jack
  + MicroSD/MMC slot
  + Audio in and out
- **Storage**
  + 200 MB
  + Expandable with MicroSD and USB flash drive
- **Power**
  + Rechargeable, high-capacity battery
  + DC charging/powering through external adapter (included)
- **cena:**
  + $455

## Vzorčenje
- pojav prepošasnega vzorčenja
  + 1kHz signal --> 1kHz vzorčenje = DC signal!!!
- pomembnost resolucije ADC-ja
  + prispevek LSB

Seveda pa morate dokupiti še senzorje, ki tudi niso cenovno ugodni, saj se njihova cena giblje od $30 ... naprej.

> Kaj ko bi si lahko naredili svojo merilno napravo?

V ta namen smo ustvarili nekaj vsebin na portalu [GitHub](https://github.com/davidrihtarsic/Arduino-Data-Acquisition-Device)...

# Arduino UNO

Arduino Uno je:
> The UNO is the best board to get started with electronics and coding. If this is your first experience tinkering with the platform, the UNO is the most robust board you can start playing with. The UNO is the most used and documented board of the whole Arduino family.
@ArduinoU75:online

![Arduino Uno](/home/david/Files/GitHub_noSync/Arduino-Data-Acquisition-Device/Skripta/slike/ArduinoUNO.jpg)

Na plošči vsebuje mikrokrmilnik **Atmega328**, ki lahko "opravi" podobne naloge, kot smo jih opisali v poglavju "Merilne naprave".

Poglejmo si nekaj karakteristik tega mikrokrmilnika @ATmega3211:online:

- **Advanced RISC Architecture**
  + 131 Powerful Instructions
  + Most Single Clock Cycle Execution
  + 32 x 8 General Purpose Working Registers
  + Fully Static Operation
  + Up to 20 MIPS Throughput at 20MHz
  + On-chip 2-cycle Multiplier
- **High Endurance Non-volatile Memory Segments**
  + 32KBytes of In-System Self-Programmable Flash program
Memory
  + 1KBytes EEPROM
  + 2KBytes Internal SRAM
  + Write/Erase Cycles: 10,000 Flash/100,000 EEPROM
  + Data Retention: 20 years at 85°C/100 years at 25°C(1)
  + Optional Boot Code Section with Independent Lock Bits
    - In-System Programming by On-chip Boot Program
    - True Read-While-Write Operation
  + Programming Lock for Software Security
- **Atmel® QTouch® Library Support**
  + Capacitive Touch Buttons, Sliders and Wheels
  + QTouch and QMatrix® Acquisition
  + Up to 64 sense channels
- **Peripheral Features**
  + Two 8-bit Timer/Counters with Separate Prescaler and Compare Mode
  + One 16-bit Timer/Counter with Separate Prescaler, Compare Mode, and Capture Mode
  + Real Time Counter with Separate Oscillator
  + Six PWM Channels
  + ADC
    * 8-channel 10-bit ADC in TQFP and QFN/MLF package
    * Temperature Measurement
    * 6-channel 10-bit ADC in PDIP Package
    * 10-bit Resolution
    * 0.5 LSB Integral Non-Linearity
    * ±2 LSB Absolute Accuracy
    * 13 - 260μs Conversion Time
    * Up to 76.9kSPS (Up to 15kSPS at Maximum Resolution)
    * Six Multiplexed Single Ended Input Channels
    * Two Additional Multiplexed Single Ended Input Channels (TQFP and VFQFN Package only)
    * Temperature Sensor Input Channel
    * Optional Left Adjustment for ADC Result Readout
    * 0 - VCC ADC Input Voltage Range
    * Selectable 1.1V ADC Reference Voltage
    * Free Running or Single Conversion Mode
    * Interrupt on ADC Conversion Complete
    * Sleep Mode Noise Canceler
  + Two Master/Slave SPI Serial Interface
  + One Programmable Serial USART
  + One Byte-oriented 2-wire Serial Interface (Philips I2C compatible)
  + Programmable Watchdog Timer with Separate On-chip Oscillator
  + One On-chip Analog Comparator
  + Interrupt and Wake-up on Pin Change
- **Special Microcontroller Features**
  + Power-on Reset and Programmable Brown-out Detection
  + Internal Calibrated Oscillator
  + External and Internal Interrupt Sources
  + Six Sleep Modes: Idle, ADC Noise Reduction, Power-save, Power-down, Standby, and
Extended Standby
- **I/O and Packages**
  + 23 Programmable I/O Lines
  + 28-pin PDIP, 32-lead TQFP, 28-pad QFN/MLF and 32-pad QFN/MLF
- **Operating Voltage:**
  + 1.8 - 5.5V
- **Temperature Range:**
  + -40°C to 105°C
- **Speed Grade:**
  + 0 - 4MHz @ 1.8 - 5.5V
  + 0 - 10MHz @ 2.7 - 5.5V
  + 0 - 20MHz @ 4.5 - 5.5V
- **Power Consumption at 1MHz, 1.8V, 25°C**
  + Active Mode: 0.2mA
  + Power-down Mode: 0.1μA
  + Power-save Mode: 0.75μA (Including 32kHz RTC)

## Arduino UNO pinout

![Arduino nano pinout](/home/david/Files/GitHub_noSync/Arduino-Data-Acquisition-Device/Skripta/slike/nano.png)

# Programiranje
- Arduino --> Blink

# senzorji
- delilnik
- toleranca uporov

# Meritve
Kako lahko merimo
- ADC 10 bit
- Uref

Arduino --> LEDica
Aduino --> Terminal
Aduino --> graph
  kako nastavimo območje
  - print 0,1023
  - println CH1

## Izračun napetosti

## Umeritev senzorjev

## Izpis temperature (stand-alone DAQ)

## Izpis na LCD (i2c)

# Časovne meritve
- med dvema sv. vratoma
- na enih vratih (koliko traja sprememba) --> hitrost klade, Dk = 5 cm ...
  + sprememba 0 -> 1  ni enaka 1 -> 0 (schmitt trigger)
  + Dklade != Dklade (pogrešek)

## millis()

## micros()

## pulsein()

## dt vzorčenja
delay ima to pomanjkljivost, da ne upoštevamo časov, ki jih potrebujejo drugi programski ukazi...
Zato upobimo millis v for zanki za čakanje kdaj je ta čas izpolnjen

```cpp
dt = millis();
dt += 1000;
while (dt > millis()){
  
}
```

\newpage
# Viri in literatura
