#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
 
#define SS_PIN 53
#define RST_PIN 5
#define LED_G 8 //define green LED pin
#define LED_R 9 //define red LED
#define BUZZER 2 //buzzer pin
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.
LiquidCrystal_I2C lcd(0x27,16,2);

Servo myServo; //define servo name
/* Database of RFID's */
String uid1 = "69 CD 70 59";
String uid2 = "32 D7 46 1E";
String uid3 = "99 92 84 83";
String uid4 = "E9 E1 16 2B";
 
void setup() 
{
  lcd.init();                      
  lcd.clear();
  lcd.backlight();
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(3); //servo pin
  myServo.write(0); //servo start position
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  //pinMode(BUZZER, OUTPUT);
  //noTone(BUZZER);
  
  Serial.println("Put your card to the reader...");
  Serial.println();

}
void loop() 
{
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Welcome ");
  lcd.setCursor(0,1);
  lcd.print("Scan Your ID    ");
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  lcd.clear();
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == uid1) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    //tone(BUZZER, 500);
    //delay(300);
    //noTone(BUZZER);
    myServo.write(180);
    delay(5000);
    myServo.write(0);
    digitalWrite(LED_G, LOW);
    lcd.setCursor(0,0);
    lcd.print("Tag 01");
    lcd.setCursor(0,1);
    lcd.print("Authorized access");
    delay(3000);
    lcd.clear();
  }
  else if (content.substring(1) == uid2) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    //tone(BUZZER, 500);
    //delay(300);
    //noTone(BUZZER);
    myServo.write(180);
    delay(5000);
    myServo.write(0);
    digitalWrite(LED_G, LOW);
    lcd.setCursor(0,0);
    lcd.print("Tag 02");
    lcd.setCursor(0,1);
    lcd.print("Authorized access");
    delay(3000);
    lcd.clear();
  }

 else if (content.substring(1) == uid3) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    //tone(BUZZER, 500);
    //delay(300);
    //noTone(BUZZER);
    myServo.write(180);
    delay(5000);
    myServo.write(0);
    digitalWrite(LED_G, LOW);
    lcd.setCursor(0,0);
    lcd.print("Tag 03");
    lcd.setCursor(0,1);
    lcd.print("Authorized access");
    delay(3000);
    lcd.clear();
  }

 else if (content.substring(1) == uid4) //change here the UID of the card that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    lcd.setCursor(0,0);
    lcd.print("Tag 04");
    lcd.setCursor(0,1);
    lcd.print("Authorized access");
    delay(3000);
    digitalWrite(LED_G, HIGH);
    //tone(BUZZER, 500);
    //delay(300);
    //noTone(BUZZER);
    myServo.write(180);
    delay(5000);
    myServo.write(0);
    digitalWrite(LED_G, LOW);
    lcd.clear();
    delay(1000);

  }
 else   {
    Serial.println(" Access Denied");
    Serial.println();
    lcd.setCursor(0,0);
    lcd.print("Unknown");
    lcd.setCursor(0,1);
    lcd.print("Access Denied");
    delay(3000);    
    digitalWrite(LED_R, HIGH);
    delay(2000);
    //tone(BUZZER, 300);
    //delay(1000);
    digitalWrite(LED_R, LOW);
    lcd.clear();
  }
  
}
