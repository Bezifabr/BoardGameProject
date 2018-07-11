#ifndef STATE_OUTRO_H
#define STATE_OUTRO_H

#include "State.h"

class StateOutro : public State
{
	virtual void Update();
	virtual void Load();
	virtual void Unload();
};

#endif // !STATE_OUTRO_H