#include "dock.h"

#include "handlecommand.h"

bool isDelim(char c) {
	return c == ',' || c == ' ';
}

Dock::Dock() : m_bufferPos(0) {
	memset(m_channels, 0, sizeof(m_channels));
}

void Dock::parseBuffer() {
	char** toks = m_tokenPtrs;
	*toks = NULL;

	if (m_bufferPos > 0 && !isDelim(m_inputBuffer[0])) {
		*toks++ = m_inputBuffer;
		for (size_t n = 1; n < m_bufferPos; n++) {
			if (isDelim(m_inputBuffer[n])) {
				m_inputBuffer[n] = 0;
			} else {
				if (m_inputBuffer[n - 1] == 0) {
					*toks++ = m_inputBuffer + n;
				}
			}
		}
	}
	*toks = NULL;
}

void Dock::handleBuffer() {
	m_inputBuffer[m_bufferPos] = 0;
	parseBuffer();
	handleCommand(m_tokenPtrs);
	m_bufferPos = 0;
}

void Dock::AddModule(Module* mod) {
	int chan = mod->Channel();

	m_channels[chan - 1] = mod;
}

void Dock::ProcessInput(Stream* stream) {
	int avail = stream->available();
	for (int n = 0; n < avail; n++) {
		int c = stream->read();
		switch (c) {
			case '\r':
				handleBuffer();
				break;
			case '\n':
				break;
			default:
				m_inputBuffer[m_bufferPos++] = (char)c;
		}
	}
}

void Dock::Update(Stream* stream) {
	for (size_t n = 0; n < NUM_MODULES; n++) {
		if (m_channels[n] != NULL) {
			m_channels[n]->Update(stream);
		}
	}
}
