#ifndef ARDUINO_FLOTILLA_DUMMY_DOCK_H
#define ARDUINO_FLOTILLA_DUMMY_DOCK_H

#include "Arduino.h"
#include "module.h"

class Dock {
  private:
	static const size_t BUFFER_SZ = 128;
	char m_inputBuffer[BUFFER_SZ + 1];
	size_t m_bufferPos = 0;
	char* m_elementPtrs[32];

	void handleBuffer();
	void parseBuffer();

  public:
	void AddModule(Module* mod);
	void ProcessInput(Stream* stream);
};

#endif  // ARDUINO_FLOTILLA_DUMMY_DOCK_H
