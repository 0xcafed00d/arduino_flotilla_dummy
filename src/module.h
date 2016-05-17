//
// Created by lmw on 17/05/16.
//

#ifndef ARDUINO_FLOTILLA_DUMMY_MODULE_H
#define ARDUINO_FLOTILLA_DUMMY_MODULE_H

#include "Arduino.h"

struct Module {
	virtual int Channel() = 0;
	virtual void OnEnquire(Stream* stream) = 0;
	virtual void Set(int* params, int paramc) {
	}
	virtual void Update(Stream* stream) {
	}
};

#endif  // ARDUINO_FLOTILLA_DUMMY_MODULE_H
