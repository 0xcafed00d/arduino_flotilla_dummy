#ifndef ARDUINO_FLOTILLA_DUMMY_MODULERAINBOW_H
#define ARDUINO_FLOTILLA_DUMMY_MODULERAINBOW_H

#include "module.h"

class ModuleRainbow : public Module {
  private:
  public:
	virtual void Set(int* params, int paramc) {
	}

	virtual void OnEnquire(Stream* stream) {
	}
};

#endif  // ARDUINO_FLOTILLA_DUMMY_MODULERAINBOW_H