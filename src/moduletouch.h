//
// Created by lmw on 17/05/16.
//

#ifndef ARDUINO_FLOTILLA_DUMMY_MODULETOUCH_H
#define ARDUINO_FLOTILLA_DUMMY_MODULETOUCH_H

#include "module.h"
#include "pushbutton.h"

class ModuleTouch : public Module {
  private:
	PushButton m_buttons[4];
	bool m_prevStates[4];

  public:
	void Init(int chan);

	const char* Name() {
		return "touch";
	}

	virtual void OnEnquire(Stream* stream);

	virtual void Update(Stream* stream);
};

#endif  // ARDUINO_FLOTILLA_DUMMY_MODULETOUCH_H
