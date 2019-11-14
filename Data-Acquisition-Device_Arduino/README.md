# Arduino Data Acquisition System
On the market we can find different DAQ systems which are hi-end products and often expencive (from 100 € .. n k€). Buy we can use Arduino (Uno, nano, ...) as low-cost data acqusition system if we do not need scientific accurate data (for pedagogical purposes).
![Parts of DAQ](http://www.ni.com/images/features/us/111201_fg_daq_info_graphic.jpg)[[NationalInstruments]]

# Importance of real-life experiments for students
* where theory finds its place
* greater motivation for learning
* more (learning) input --> beater understanding

---
* instant data processing
* explicit presentation of interdependent variables
* visualization of physical quantities that are detected by human nature

# Requirements
(Checked is required, unchecked is optional)

**Hardware**:
* [x] Computer
* [x] Arduino board ([Arduino UNO](https://store.arduino.cc/arduino-uno-rev3), [Arduino LEONARDO](https://store.arduino.cc/arduino-leonardo-with-headers), [Arduino NANO](https://store.arduino.cc/arduino-nano), [clone products](https://www.aliexpress.com/item/Nano-CH340-ATmega328P-MicroUSB-Compatible-for-Arduino-Nano-V3/32572612009.html?spm=2114.search0104.3.1.34b52b20RGIwod&ws_ab_test=searchweb0_0,searchweb201602_4_10152_10151_10065_10344_10068_10342_10343_10340_10341_10084_10083_10618_10304_10307_10301_5711212_10313_10059_10534_100031_10103_10627_10626_10624_10623_10622_10621_10620_5722413_5711313,searchweb201603_25,ppcSwitch_5&algo_expid=d5f1485f-be15-4f3e-93b6-b3120c7b8ac3-0&algo_pvid=d5f1485f-be15-4f3e-93b6-b3120c7b8ac3&transAbTest=ae803_3&priceBeautifyAB=0) )
* [x] basic electronics components for sensors
* [ ] arduino set starter [for example use this kit](https://www.aliexpress.com/item/The-Best-RFID-Starter-Kits-For-Arduino-Uno-R3-With-Tutorial-Power-Supply-Learning-Kit-US/32623921742.html?spm=2114.10010108.1000013.3.1f3929415iOC4y&traffic_analysisId=recommend_2088_2_90158_iswistore&scm=1007.13339.90158.0&pvid=256e4e8d-3f20-47e9-b3d3-56af5fadcd51&tpp=1)
* [ ] arduino sensors set [for example use this kit](https://www.aliexpress.com/item/37-In-1-Sensor-Kits-For-Arduino-Raspberry-Pi-Beginner-Learning-Sensor-Module-Suit-Ultimate-Top/32851582028.html?spm=2114.search0104.3.29.66a36682D8jqIb&ws_ab_test=searchweb0_0,searchweb201602_4_10152_10151_10065_10344_10068_10342_10343_10340_10341_10084_10083_10618_10304_10307_10301_5711211_10313_10059_10534_100031_10103_10627_10626_10624_10623_10622_5722411_5711315_10621_10620,searchweb201603_25,ppcSwitch_5&algo_expid=4674573e-7df9-4805-bd73-64edd1408ad6-4&algo_pvid=4674573e-7df9-4805-bd73-64edd1408ad6&transAbTest=ae803_3&priceBeautifyAB=0)

**Software**:

* [x] Arduino IDE [download here](https://www.arduino.cc/en/Main/Software)
* [ ] Python (>=3.0)
* [ ] pyserial
* [ ] Ms Excel

# Pros & Cons
| **Pros**                              | **Cons**                  |
|---------------------------------------|---------------------------|
| + Price (Arduino ~3€, sensors ~2-5€)  | - work in progress        |
| + Accessibility                       | - no plug&play solutions  |
| + Versatility                         | - DIY project             |
| + Easy importing data into MS Excel   | - low sampling rate ~6kHz |
| + točne časovne meritve               | - 10-bi resolutuin        |

More about DAQ you can read in further reading... 

# Data Acquisition System
Data acquisition is the process of sampling signals that measure real world physical conditions and converting the resulting samples into digital numeric values that can be manipulated by a computer [[Wikipedia]]. Data acquisition systems, abbreviated by the acronyms DAS or DAQ, typically convert analog waveforms into digital values for processing. The components of data acquisition systems include:
- Sensors, to convert physical parameters to electrical signals.
- Signal conditioning circuitry, to convert sensor signals into a form that can be converted to digital values.
- Analog-to-digital converters, to convert conditioned sensor signals to digital values.

Data acquisition applications are usually controlled by software programs developed using various general purpose programming languages such as Assembly, BASIC, C, C++, C#, Fortran, Java, LabVIEW, Lisp, Pascal, etc. Stand-alone data acquisition systems are often called data loggers[[Wikipedia]].

There are also open-source software packages providing all the necessary tools to acquire data from different hardware equipment. These tools come from the scientific community where complex experiment requires fast, flexible and adaptable software. Those packages are usually custom fit but more general DAQ package like the Maximum Integrated Data Acquisition System can be easily tailored and is used in several physics experiments worldwide[[Wikipedia]].

## Parts of a DAQ System [[NationalInstruments]]
![Parts of DAQ](http://www.ni.com/images/features/us/111201_fg_daq_info_graphic.jpg)

### What Is a Sensor?
The measurement of a physical phenomenon, such as the temperature of a room, the intensity of a light source, or the force applied to an object, begins with a sensor. A sensor, also called a transducer, converts a physical phenomenon into a measurable electrical signal. Depending on the type of sensor, its electrical output can be a voltage, current, resistance, or another electrical attribute that varies over time. Some sensors may require additional components and circuitry to properly produce a signal that can accurately and safely be read by a DAQ device [[NationalInstruments]].
### What Is a DAQ Device?
DAQ hardware acts as the interface between a computer and signals from the outside world. It primarily functions as a device that digitizes incoming analog signals so that a computer can interpret them. The three key components of a DAQ device used for measuring a signal are the signal conditioning circuitry, analog-to-digital converter (ADC), and computer bus. Many DAQ devices include other functions for automating measurement systems and processes. For example, digital-to-analog converters (DACs) output analog signals, digital I/O lines input and output digital signals, and counter/timers count and generate digital pulses[NationalInstruments].
### What Is a Computer’s Role in a DAQ System?
A computer with programmable software controls the operation of the DAQ device and is used for processing, visualizing, and storing measurement data. Different types of computers are used in different types of applications. A desktop may be used in a lab for its processing power, a laptop may be used in the field for its portability, or an industrial computer may be used in a manufacturing plant for its ruggedness [[NationalInstruments]].

# References
Wikipedia: Data acquisition - Wikipedia, https://en.wikipedia.org/wiki/Data_acquisition, Accessed on 03/08/2018
National Instruments: What Is Data Acquisition? - National Instruments, http://www.ni.com/data-acquisition/what-is/, Accessed on 03/08/2018

- [Wikipedia]: https://en.wikipedia.org/wiki/Data_acquisition "Data acquisition - Wikipedia, https://en.wikipedia.org/wiki/Data_acquisition, Accessed on 03/08/2018"
- [NationalInstruments]: http://www.ni.com/data-acquisition/what-is "What Is Data Acquisition? - National Instruments, http://www.ni.com/data-acquisition/what-is/, Accessed on 03/08/2018"
https://store.arduino.cc/arduino-nano
