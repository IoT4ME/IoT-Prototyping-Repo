#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int ledred = 5;
const int ledgreen = 6;
const int button = 7;
const int soundPin = A0;

void setup() {
pinMode (ledred,OUTPUT);
pinMode (ledgreen,OUTPUT);
pinMode (button,INPUT);

lcd.init();
lcd.backlight();
Serial.begin(9600);
}

void loop() {
  int value = analogRead(soundPin);
  Serial.println(value);
  boolean buttonstate = digitalRead(button);
for (int positionCounter = 0; positionCounter < 29; positionCounter++) {  

if (buttonstate == LOW)
{
  digitalWrite(ledgreen,HIGH);
  digitalWrite(ledred,LOW);
  lcd.setCursor(0,0);
  lcd.print("LED verde ON");
  delay(50);
}
}
lcd.clear();

for (int positionCounter = 0; positionCounter < 29; positionCounter++) {  
if (buttonstate == HIGH)
{
  digitalWrite(ledred,HIGH);
  digitalWrite(ledgreen,LOW);
  lcd.setCursor(0,0);
  lcd.print("LED rosso ON");
  delay(50);
}
}
lcd.clear();
delay(50);
}