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

bool state = false;

void loop() {
	state = !state;
	led1.Set(state);

	dock.Update(&Serial);
	dock.ProcessInput(&Serial);
	delay(100);
}
