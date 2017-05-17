#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#define TRIGGER_PIN 2 
#define ECHO_PIN 3 
#define MAX_DISTANCE 50
#define PARKING_LIMIT 0.15

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

const int ledgreen = 5;
const int ledred = 6;

void setup() 
{
pinMode (ledgreen, OUTPUT);
pinMode (ledred, OUTPUT);

lcd.init(); 
lcd.backlight();

lcd.setCursor(0, 0);
lcd.print("Distanza:");
lcd.setCursor(0,1);
lcd.print("Parking:");


Serial.begin(115200); 
}
void loop() {
  delay(100);
  
  float uS = sonar.ping(); 
  float dist_m = uS / (US_ROUNDTRIP_CM * 100);
  
  Serial.print("Ping: ");
  Serial.print(dist_m);
  Serial.println("m");
  
  lcd.setCursor(10, 0);
  lcd.print(dist_m);
  lcd.setCursor(15, 0);
  lcd.print("m");

  if (dist_m > PARKING_LIMIT)
{
  digitalWrite (ledgreen, HIGH);
  digitalWrite (ledred, LOW);
  lcd.setCursor(10,1);
  lcd.print("Free");
}
delay(100);

  if (dist_m < PARKING_LIMIT) 
{
  digitalWrite (ledred, HIGH);
  digitalWrite (ledgreen, LOW);
  lcd.setCursor(10,1);
  lcd.print("Busy");
}
delay(100);
}