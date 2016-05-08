/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include <Arduino.h>

#define LED 2



void setup() {
  Serial.begin(115200);

  // initialize LED digital pin as an output.
  pinMode(LED, OUTPUT);
}

void loop() {
  Serial.println("hello world");

  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED, HIGH);

  // wait for a second
  delay(1000);

  // turn the LED off by making the voltage LOW
  digitalWrite(LED, LOW);

  // wait for a second
  delay(1000);
}
