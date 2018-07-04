#pragma once

#include "State.h"

class StateLobby :public State
{
	virtual void Update();
	virtual void Load();
	virtual void Unload();
};