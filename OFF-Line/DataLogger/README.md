# Arduino Data Logger

# Requirements
**Hardware**:
+ Arduino UNO
+ Data logger shield for Arduino, MicroSD-card + RTC [link](http://robotdyn.com/data-logger-shield-for-arduino-microsd-card-rtc.html)
+ SD card (micro)

**Software**:
+ Arduino IDE [download here](https://www.arduino.cc/en/Main/Software)
+ SD library (Arduino IDE --> Sketch --> Include library --> Manage Libraryes : SD by Arduino, SparkFun)

# Usage
1. Format SD card:

Linux:
    
    sudo mkdosfs -F 16 /dev/sdb1

2. Open example:
    Arduino IDE --> File --> Examples --> SD --> CardInfo.ino
3. Check/Change MISO/MOSI/CLK/CS pins

Used pins:

    D9  - CS
    D11 - MOSI
    D12 - MISO
    D13 - CLK
4. Upload sketsh & verifi output in serial monitor

Output:

    Initializing SD card...Wiring is correct and a card is present.

    Card type:         SD2
    Clusters:          60022
    Blocks x Cluster:  64
    Total Blocks:      3841408

    Volume type is:    FAT16
    Volume size (Kb):  1920704
    Volume size (Mb):  1875
    Volume size (Gb):  1.83

    Files found on the card (name, date and size in bytes): 

