#pragma once

#include "State.h"

class StateOutro : public State
{
	virtual void Update();
	virtual void Load();
	virtual void Unload();
};