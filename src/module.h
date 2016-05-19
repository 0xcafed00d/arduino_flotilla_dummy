#ifndef ARDUINO_FLOTILLA_DUMMY_MODULE_H
#define ARDUINO_FLOTILLA_DUMMY_MODULE_H

#include "Arduino.h"

class Module {
  private:
	int m_channel;

  protected:
	void SetChannel(int c) {
		m_channel = c;
	}

  public:
	int Channel() {
		return m_channel;
	}

	virtual const char* Name() = 0;

	virtual void OnEnquire(Stream* stream) = 0;

	virtual void Set(int* params, int paramc) {
	}

	virtual void Update(Stream* stream) {
	}
};

#endif  // ARDUINO_FLOTILLA_DUMMY_MODULE_H
