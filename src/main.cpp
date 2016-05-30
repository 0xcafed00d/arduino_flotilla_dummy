#include "Arduino.h"
#include "dock.h"
#include "moduletouch.h"
#include "modulerainbow.h"
#include "led.h"

Dock dock;
ModuleTouch modTouch;
ModuleRainbow modRainbow;

LED led1;

void setup() {
	Serial.begin(115200);

	while (!Serial) {
		;  // wait for serial port to connect. Needed for native USB
	}

	led1.Setup(3);

	modTouch.Init(1);
	modRainbow.Init(2);

	dock.AddModule(&modTouch);
	dock.AddModule(&modRainbow);
}

void loop() {
	led1.Toggle();

	dock.Update(&Serial);
	dock.ProcessInput(&Serial);
	Serial.flush();
	delay(100);
}
