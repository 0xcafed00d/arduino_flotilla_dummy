//
// Created by lmw on 14/05/16.
//

#ifndef ARDUINO_FLOTILLA_DUMMY_PUSHBUTTON_H
#define ARDUINO_FLOTILLA_DUMMY_PUSHBUTTON_H

#include "Arduino.h"
#include "timeout.h"

class PushButton {
  public:
	PushButton() {
	}

	void Setup(uint8_t pin) {
		pinMode(pin, INPUT_PULLUP);
		m_last = false;
		m_current = false;
		m_pin = pin;
	}

	bool Pressed() {
		return StateChanged() && m_current;
	}

	bool Released() {
		return StateChanged() && !m_current;
	}

	bool IsPressed() {
		StateChanged();
		return m_current;
	}

	// return true for pressed & false for not pressed
	bool Raw() {
		return digitalRead(m_pin) == 0;
	}

  private:
	uint8_t m_pin;
	bool m_last;
	bool m_current;
	TimeOut m_debounce;

	bool StateChanged() {
		bool changed = false;
		if (m_debounce.hasTimedOut()) {
			m_current = Raw();
			if (m_current != m_last) {
				changed = true;
				m_last = m_current;
				m_debounce = TimeOut(50);
			}
		}
		return changed;
	}
};

#endif  // ARDUINO_FLOTILLA_DUMMY_PUSHBUTTON_H
