#include "moduletouch.h"

void ModuleTouch::Init(int chan) {
	SetChannel(chan);

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
	stream->print("/");
	stream->print(Name());
	stream->print("\r\n");
}

void ModuleTouch::Update(Stream* stream) {
	bool send = false;

	for (int n = 0; n < 4; n++) {
		bool state = m_buttons[n].IsPressed();
		if (m_prevStates[n] != state) {
			m_prevStates[n] = state;
			send = true;
		}
	}

	if (send) {
		stream->print("u ");
		stream->print(Channel());
		stream->print("/");
		stream->print(Name());
		stream->print(m_prevStates[0] ? " 1," : " 0,");
		stream->print(m_prevStates[1] ? "1," : "0,");
		stream->print(m_prevStates[2] ? "1," : "0,");
		stream->print(m_prevStates[3] ? "1\r\n" : "0\r\n");
	}
}
