# RFID-based-door-lock-system
This is a simple project which can be implemented on security door  or for any security purpose to restrict the entry of public using Arduino Mega
 Connections :
 
 Working Video Link (just a demo) : https://youtu.be/oFBnLb1kVkU




**LCD_I2C CONNECTIONS**
 
  SCL - PIN 21 
  SDA - PIN 20
  VCC - 5V
  GND - GND
   
**RFID-RC522 CONNECTIONS**
SDA - PIN 53
SCK - PIN 52
MOSI- PIN 51
GND - ANY ground pin
RST-  PIN 5
POWER (3.3V) - 3.3V
 
 **#include <MFRC522.h> Library used for interfacing RFID with my arduino mega
 
 **Servo Motor Connections
 
 VCC -  5V
 GND - GND (Any ground PIN )
 PWM - PWM (PIN 3 for Arduino Mega)
  
  LED green : PIN 8
  LED red :   PIN 9
  
  Buzzer (PIN 10) (I dint used a buzzer in this project.. its optional i used to get annoyed with buzzer often :P )
  
  Dump the code without any changes and let me know if there is any errors
