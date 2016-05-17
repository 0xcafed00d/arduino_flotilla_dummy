//
// Created by lmw on 17/05/16.
//

#ifndef ARDUINO_FLOTILLA_DUMMY_MODULERAINBOW_H
#define ARDUINO_FLOTILLA_DUMMY_MODULERAINBOW_H

#include "module.h"

class ModuleRainbow : public Module {
  public:
	virtual void Set(int* params, int paramc) {
	}

	virtual int Channel() {
		return 0;
	}

	virtual void OnEnquire(Stream* stream) {
	}
};

#endif  // ARDUINO_FLOTILLA_DUMMY_MODULERAINBOW_H
