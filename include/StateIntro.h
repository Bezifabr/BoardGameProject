#ifndef STATE_INTRO_H
#define STATE_INTRO_H

#include "State.h"

class StateIntro : public State
{
	virtual void Update();

	virtual void Load();

	virtual void Unload();

	sf::Texture testingTexture;
	void ButtonsTestAndTexturesLoading();
	void TestingButton();
};

#endif // !STATE_INTRO_H