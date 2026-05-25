const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9;  // Analog output pin that the LED is attached to
int sensorValue = 0;  // value read from the pot
int outputValue = 0;  // value output to the PWM (analog out)
//
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 
//
void setup() {
  Serial.begin(9600);
  lcd.init();                      
  lcd.backlight();
}

void loop() {
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(analogOutPin, outputValue);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  //
  lcd.setCursor(0,0);
  lcd.print(outputValue);
  lcd.print(" ");
  delay(500);
}