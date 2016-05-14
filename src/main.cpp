#include "Arduino.h"

#include "handlecommand.h"
#include "handleupdate.h"
#include "pushbutton.h"

#define LED 17

PushButton<21> button1;

const size_t BUFFER_SZ = 128;
char inputBuffer[BUFFER_SZ + 1];
size_t bufferPos = 0;
char* elementPtrs[32];

bool isDelim(char c) {
	return c == ',' || c == ' ';
}

void parseBuffer() {
	char** eptrs = elementPtrs;
	*eptrs = NULL;

	if (bufferPos > 0 && !isDelim(inputBuffer[0])) {
		*eptrs++ = inputBuffer;
		for (size_t n = 1; n < bufferPos; n++) {
			if (isDelim(inputBuffer[n])) {
				inputBuffer[n] = 0;
			} else {
				if (inputBuffer[n - 1] == 0) {
					*eptrs++ = inputBuffer + n;
				}
			}
		}
	}
	*eptrs = NULL;
}

void handleBuffer() {
	inputBuffer[bufferPos] = 0;
	parseBuffer();
	handleCommand(elementPtrs);

	/*
	for (char **eptrs = elementPtrs; *eptrs; eptrs++) {
	    Serial.println(*eptrs);
	}*/

	bufferPos = 0;
}

bool toggle = false;

void setup() {
	Serial.begin(115200);
	pinMode(LED, OUTPUT);
	toggle = false;
	pinMode(21, INPUT_PULLUP);
}

void loop() {
	if (Serial) {
		int avail = Serial.available();
		for (int n = 0; n < avail; n++) {
			int c = Serial.read();
			switch (c) {
				case '\r':
					handleBuffer();
					break;
				case '\n':
					break;
				default:
					inputBuffer[bufferPos++] = (char)c;
			}
		}

		handleUpdate();
	}

	if (button1.Pressed()) {
		toggle = !toggle;
	}

	digitalWrite(LED, toggle);

	// delay(100);
}
