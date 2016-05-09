/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"

#define LED 2

const size_t BUFFER_SZ = 128;
char inputBuffer[BUFFER_SZ];
size_t bufferPos = 0;

void handleBuffer() {
	inputBuffer[bufferPos] = 0;
	Serial.println(inputBuffer);
	bufferPos = 0;
}


void setup() {
	Serial.begin(115200);
	pinMode(LED, OUTPUT);
}

bool toggle = false;

void loop() {

	int avail = Serial.available();
	for (int n = 0; n < avail; n++) {
		digitalWrite(LED, (int) toggle);
		toggle = !toggle;
		int c = Serial.read();
		if (c == '\r') {
			handleBuffer();
		}
		else {
			inputBuffer[bufferPos++] = (char) c;
		}
	}
}
