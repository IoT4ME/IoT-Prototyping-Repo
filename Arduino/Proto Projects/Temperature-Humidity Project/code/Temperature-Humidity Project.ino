#include <dht.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2); 

dht DHT;

const int DHT11_PIN = 7;

void setup() {
lcd.init();
lcd.backlight();
Serial.begin(9600);
}
void loop() {
  Serial.print("DHT11, \t");
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    Serial.print("OK,\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Time out error,\t"); 
    break;
    default: 
    Serial.print("Unknown error,\t"); 
    break;
}
lcd.setCursor(0,0);
lcd.print("Temp: ");
lcd.print(DHT.temperature,1);
lcd.print(char(223));
lcd.print("C");
lcd.setCursor(0,1);
lcd.print("Umid: ");
lcd.print(DHT.humidity,1);
lcd.print(" %");
delay(200);
}