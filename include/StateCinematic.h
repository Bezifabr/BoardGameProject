#pragma once

#include "State.h"

class StateCinematic : public State
{
	virtual void Update();
	virtual void Load();
	virtual void Unload();
};