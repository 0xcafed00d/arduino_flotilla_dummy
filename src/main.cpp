#include "Arduino.h"

#include "handlecommand.h"
#include "handleupdate.h"
#include "pushbutton.h"
#include "led.h"

LED redLED;
LED rxLED;
PushButton button1;
PushButton button2;
PushButton button3;
PushButton button4;

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
int brightness = 0;

void setup() {
	Serial.begin(115200);
	button1.Setup(21);
	button2.Setup(20);
	button3.Setup(19);
	button4.Setup(18);
	redLED.Setup(10);
	rxLED.Setup(17, false);
}

void loop() {
	TXLED0;

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
		redLED.Set(toggle);
		rxLED.Set(toggle);
	}

	if (button2.Pressed()) {
		brightness += 10;
		redLED.Brightness(brightness);
	}

	if (button3.Pressed()) {
		brightness -= 10;
		redLED.Brightness(brightness);
	}

	// delay(100);
}
