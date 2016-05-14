//
// Created by lmw on 14/05/16.
//

#include "Arduino.h"

#ifndef ARDUINO_FLOTILLA_DUMMY_TIMEOUT_H
#define ARDUINO_FLOTILLA_DUMMY_TIMEOUT_H

class TimeOut {
	uint32_t end;

  public:
	TimeOut(uint32_t timeoutms = 0) {
		end = (uint32_t)millis() + timeoutms;
	}

	bool hasTimedOut() const {
		return millis() > end;
	}
}

#endif  // ARDUINO_FLOTILLA_DUMMY_TIMEOUT_H
