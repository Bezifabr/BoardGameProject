#pragma once

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
