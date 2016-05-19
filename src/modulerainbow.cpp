#include "modulerainbow.h"

void ModuleRainbow::Init(int chan) {
	SetChannel(chan);

	m_leds[0].Setup(3);
	m_leds[1].Setup(5);
	m_leds[2].Setup(6);
	m_leds[3].Setup(9);
	m_leds[4].Setup(10);
}

void ModuleRainbow::OnEnquire(Stream* stream) {
	stream->print("c ");
	stream->print(Channel());
	stream->print("/");
	stream->print(Name());
	stream->print("\r\n");
}

void ModuleRainbow::Set(int* params, int paramc) {
	if (paramc == 15) {
		for (int n = 0; n < 5; n++) {
			int val = (params[n * 3] + params[n * 3 + 1] + params[n * 3 + 2]) / 3;
			m_leds[n].Brightness(val);
		}
	} else if (paramc == 3) {
		int val = (params[0] + params[1] + params[2]) / 3;
		for (int n = 0; n < 5; n++) {
			m_leds[n].Brightness(val);
		}
	}
}
