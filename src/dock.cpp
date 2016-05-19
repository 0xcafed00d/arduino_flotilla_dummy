#include "dock.h"

#include "handlecommand.h"

bool isDelim(char c) {
	return c == ',' || c == ' ';
}

void Dock::parseBuffer() {
	char** eptrs = m_elementPtrs;
	*eptrs = NULL;

	if (m_bufferPos > 0 && !isDelim(m_inputBuffer[0])) {
		*eptrs++ = m_inputBuffer;
		for (size_t n = 1; n < m_bufferPos; n++) {
			if (isDelim(m_inputBuffer[n])) {
				m_inputBuffer[n] = 0;
			} else {
				if (m_inputBuffer[n - 1] == 0) {
					*eptrs++ = m_inputBuffer + n;
				}
			}
		}
	}
	*eptrs = NULL;
}

void Dock::handleBuffer() {
	m_inputBuffer[m_bufferPos] = 0;
	parseBuffer();
	handleCommand(m_elementPtrs);
	m_bufferPos = 0;
}

void AddModule(Module* mod) {
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
