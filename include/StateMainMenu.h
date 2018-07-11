#ifndef STATE_MAIN_MENU_H
#define STATE_MAIN_MENU_H

#include "State.h"

class StateMainMenu : public State
{
	virtual void Update();

	virtual void Load();

	virtual void Unload();
};

#endif // !STATE_MAIN_MENU_H