#include "Arduino.h"
#include "dock.h"
#include "moduletouch.h"
#include "modulerainbow.h"

Dock dock;
ModuleTouch modTouch;
ModuleRainbow modRainbow;

void setup() {
	Serial.begin(115200);
	modTouch.Init(1);
	modRainbow.Init(2);
}

void loop() {
	if (Serial) {
		dock.ProcessInput(&Serial);
	}
}
