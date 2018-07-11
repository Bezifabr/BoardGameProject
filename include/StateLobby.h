#ifndef STATE_LOBBY_H
#define STATE_LOBBY_H

#include "State.h"

class StateLobby :public State
{
	virtual void Update();
	virtual void Load();
	virtual void Unload();
};

#endif // !STATE_LOBBY_H