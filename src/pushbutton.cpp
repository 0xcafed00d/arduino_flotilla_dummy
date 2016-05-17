#include "pushbutton.h"

void PushButton::Setup(uint8_t pin) {
	pinMode(pin, INPUT_PULLUP);
	m_last = false;
	m_current = false;
	m_pin = pin;
}

bool PushButton::StateChanged() {
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
