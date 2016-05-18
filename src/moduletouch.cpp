//
// Created by lmw on 17/05/16.
//

#include "moduletouch.h"

void ModuleTouch::Init(int chan) {
	m_buttons[0].Setup(21);
	m_buttons[1].Setup(20);
	m_buttons[2].Setup(19);
	m_buttons[3].Setup(18);

	for (int n = 0; n < 4; n++) {
		m_prevStates[n] = m_buttons[n].IsPressed();
	}
}

void ModuleTouch::OnEnquire(Stream* stream) {
	stream->print("c ");
	stream->print(Channel());
	stream->print("/touch\r");
}

void ModuleTouch::Update(Stream* stream) {
	bool send = false;

	for (int n = 0; n < 4; n++) {
		bool state = m_buttons[n].Pressed();
		if (m_prevStates[n] != state) {
			m_prevStates[n] = state;
			send = true;
		}
	}

	if (send) {
		stream->print("c ");
		stream->print(Channel());
		stream->print(" ");
		stream->print(m_prevStates[0] ? "0," : "1,");
		stream->print(m_prevStates[1] ? "0," : "1,");
		stream->print(m_prevStates[2] ? "0," : "1,");
		stream->print(m_prevStates[3] ? "0" : "1");
	}
}
