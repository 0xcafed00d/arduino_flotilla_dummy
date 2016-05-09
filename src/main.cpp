#include "Arduino.h"

#define LED 2

const size_t BUFFER_SZ = 128;
char inputBuffer[BUFFER_SZ];
char elementIdx[32];
char elementCount;

size_t bufferPos = 0;

bool isDelim (char c) {
	return c == ',' || c == ' ';
}

void parseBuffer () {
	elementCount = 0;

	if (bufferPos > 0 && !isDelim(inputBuffer[0])) {
		elementIdx[elementCount++] = 0;
		for (size_t n = 1; n < bufferPos; n++){
			if (isDelim(inputBuffer[n])) {
				inputBuffer[n] = 0;
			} else {
				if (inputBuffer[n-1] == 0) {
					elementIdx[elementCount++] = n;
				}
			}
		}
	}
}


void handleBuffer() {
	parseBuffer();

	Serial.println ((int)elementCount);
	for (int n = 0; n < elementCount; n++){
		Serial.println(inputBuffer + elementIdx[n]);
	}

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
		switch (c) {
			case '\r':
				handleBuffer();
				break;
			case '\n':
				break;
			default:
				inputBuffer[bufferPos++] = (char) c;
		}
	}
}
