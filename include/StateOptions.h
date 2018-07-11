#ifndef STATE_OPTIONS_H
#define STATE_OPTIONS_H

#include "State.h"

class StateOptions : public State
{
	virtual void Update();
	virtual void Load();
	virtual void Unload();
};

#endif // !STATE_OPTIONS_H