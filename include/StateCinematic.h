#ifndef STATE_CINEMATIC_H
#define STATE_CINEMATIC_H

#include "State.h"

class StateCinematic : public State
{
	virtual void Update();
	virtual void Load();
	virtual void Unload();
};

#endif // !STATE_CINEMATIC_H