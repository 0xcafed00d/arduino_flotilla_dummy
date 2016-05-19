#ifndef ARDUINO_FLOTILLA_DUMMY_MODULERAINBOW_H
#define ARDUINO_FLOTILLA_DUMMY_MODULERAINBOW_H

#include "module.h"
#include "led.h"

class ModuleRainbow : public Module {
  private:
	LED m_leds[5];

  public:
	void Init(int chan);

	const char* Name() {
		return "rainbow";
	}

	virtual void Set(int* params, int paramc);

	virtual void OnEnquire(Stream* stream);
};

#endif  // ARDUINO_FLOTILLA_DUMMY_MODULERAINBOW_H
