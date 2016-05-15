//
// Created by lmw on 15/05/16.
//

#ifndef ARDUINO_FLOTILLA_DUMMY_LED_H
#define ARDUINO_FLOTILLA_DUMMY_LED_H

#include "Arduino.h"

class LED {
  public:
	void Setup(uint8_t pin, bool activeHigh = true) {
		pinMode(pin, OUTPUT);
		m_activeHigh = activeHigh;
		m_pin = pin;
	}

	void Off() {
		if (m_activeHigh)
			digitalWrite(m_pin, 0);
		else
			digitalWrite(m_pin, 1);
	}

	void On() {
		if (m_activeHigh)
			digitalWrite(m_pin, 1);
		else
			digitalWrite(m_pin, 0);
	}

	void Set(bool state) {
		if (state)
			On();
		else
			Off();
	}

  private:
	uint8_t m_pin;
	bool m_activeHigh;
};

#endif  // ARDUINO_FLOTILLA_DUMMY_LED_H
