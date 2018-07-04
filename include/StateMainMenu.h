#pragma once

#include "State.h"

class StateMainMenu : public State
{
	virtual void Update();

	virtual void Load();

	virtual void Unload();
};