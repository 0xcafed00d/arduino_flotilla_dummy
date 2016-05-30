#include "led.h"

void LED::Setup(uint8_t pin, bool activeHigh = true) {
	pinMode(pin, OUTPUT);
	m_activeHigh = activeHigh;
	m_pin = pin;
	Off();
}

void LED::Off() {
	m_state = false;
	if (m_activeHigh)
		digitalWrite(m_pin, 0);
	else
		digitalWrite(m_pin, 1);
}

void LED::On() {
	m_state = true;
	if (m_activeHigh)
		digitalWrite(m_pin, 1);
	else
		digitalWrite(m_pin, 0);
}

void LED::Set(bool state) {
	if (state)
		On();
	else
		Off();
}
