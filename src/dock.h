#ifndef ARDUINO_FLOTILLA_DUMMY_DOCK_H
#define ARDUINO_FLOTILLA_DUMMY_DOCK_H

#include "Arduino.h"
#include "module.h"

class Dock {
  private:
	static const size_t BUFFER_SZ = 128;
	static const size_t NUM_MODULES = 8;

	char m_inputBuffer[BUFFER_SZ + 1];
	size_t m_bufferPos = 0;
	char* m_tokenPtrs[32];
	Module* m_channels[NUM_MODULES];

	void handleBuffer();
	void parseBuffer();

  public:
	Dock();
	void AddModule(Module* mod);
	void ProcessInput(Stream* stream);
	void Update(Stream* stream);
};

#endif  // ARDUINO_FLOTILLA_DUMMY_DOCK_H
