#ifndef ARDUINO_FLOTILLA_DUMMY_LED_H
#define ARDUINO_FLOTILLA_DUMMY_LED_H

#include "Arduino.h"

class LED {
  public:
	void Setup(uint8_t pin, bool activeHigh = true);
	void Off();
	void On();
	void Set(bool state);

	void Toggle() {
		Set(!m_state);
	}

	bool State() {
		return m_state;
	}

	void Brightness(int val) {
		analogWrite(m_pin, constrain(val, 0, 255));
	}

  private:
	bool m_state;
	uint8_t m_pin;
	bool m_activeHigh;
};

#endif  // ARDUINO_FLOTILLA_DUMMY_LED_H
