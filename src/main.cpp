#include <Arduino.h>
#include <Wire.h>
// #include <ArduinoBLE.h>

// Set LED_BUILTIN if it is not defined by Arduino framework
#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif


int pwmPin = 26; // A0
int power = 20;

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pwmPin, OUTPUT);

  analogWriteResolution(8);
  analogWriteFrequency(10000); //set to 10kHz
  
  Wire.begin();
  Serial.begin(115200);
  analogWrite(pwmPin, power); // Apply the signal before entering PWM mode. 
  delay(10); // An abundance of caution here =P
  Serial.println("loaded Huzzah_play_1 v0.5");

}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  for (int i = 50; i<255; i++) {

    analogWrite(pwmPin, i);
    Serial.print("Vib Strength: ");
    Serial.println(i);
    delay(100);
  }
  // wait for a second
  delay(2000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  analogWrite(pwmPin, 0);

  // wait for a second
  delay(1000);
}