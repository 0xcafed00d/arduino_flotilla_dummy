
#include "modulerainbow.h"

void ModuleRainbow::Init(int chan) {
	SetChannel(chan);

	m_leds[0].Setup(1);
	m_leds[1].Setup(1);
	m_leds[2].Setup(1);
	m_leds[3].Setup(1);
	m_leds[4].Setup(1);
}

void ModuleRainbow::OnEnquire(Stream* stream) {
	stream->print("c ");
	stream->print(Channel());
	stream->print("/rainbow\r");
}

void ModuleRainbow::Set(int* params, int paramc) {
	if (paramc == 15) {
	} else if (paramc == 3) {
	}
}
