/*
  Accensione di due LED sui pin 12 e 13 rispettivamente per 2 ed 1 secondo. 
*/

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);                       // wait for two second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);     
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}