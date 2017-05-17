#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int gas = 8;
const int water = 7;
const int fire = 6;

const int buzzer = 3;

void setup() 
{
  pinMode (gas,INPUT);
  pinMode (water,INPUT);
  pinMode (fire,INPUT);
  pinMode(buzzer,OUTPUT);
  
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
} 
void loop() {
  boolean Gstate = digitalRead(gas);
  boolean Wstate = digitalRead(water);
  boolean Fstate = digitalRead(fire);
  
for (int positionCounter = 0; positionCounter < 29; positionCounter++) {  

  if(Gstate == LOW)
{
  digitalWrite(buzzer,LOW);
  lcd.setCursor(0,0);
  lcd.print("Gas/Smoke ON");
  delay(50);
}
}
lcd.clear();
  
for (int positionCounter = 0; positionCounter < 29; positionCounter++) {  
  
  if(Wstate == LOW)
{
  digitalWrite(buzzer,LOW);
  lcd.setCursor(8,0);
  lcd.print("Water ON");
  delay(50);
}
}
lcd.clear();
  
for (int positionCounter = 0; positionCounter < 29; positionCounter++) {  

  if (Fstate == LOW) 
{
  digitalWrite(buzzer,LOW);
  lcd.setCursor(0,1);
  lcd.print("Fire/Flame ON");
  delay(50);
}
}
lcd.clear();

for (int positionCounter = 0; positionCounter < 29; positionCounter++) {  

if (Gstate == HIGH && Wstate && HIGH && Fstate == HIGH)
{
  digitalWrite(buzzer,HIGH);
  lcd.setCursor(0,1);
  lcd.print("All Sensors OFF");
  delay(50);
}
}
  lcd.clear();
  delay(50);
} 