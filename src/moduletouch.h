//
// Created by lmw on 17/05/16.
//

#ifndef ARDUINO_FLOTILLA_DUMMY_MODULETOUCH_H
#define ARDUINO_FLOTILLA_DUMMY_MODULETOUCH_H

#include "module.h"

class ModuleTouch : public Module {
  public:
	virtual int Channel() {
		return 0;
	}

	virtual void OnEnquire(Stream* stream) {
	}

	virtual void Update(Stream* stream) {
		Module::Update(stream);
	}
};

#endif  // ARDUINO_FLOTILLA_DUMMY_MODULETOUCH_H
