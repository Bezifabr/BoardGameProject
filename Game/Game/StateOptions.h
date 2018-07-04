#pragma once

#include "State.h"

class StateOptions : public State
{
	virtual void Update();
	virtual void Load();
	virtual void Unload();
};