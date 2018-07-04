#include "StateOptions.h"

void StateOptions::Update()
{
	if (IsButtonClicked("Options_Back"))
		SetNewState("MainMenu");
}

void StateOptions::Load()
{
	assert(GetFont()->loadFromFile(DEFAULT_FONT_SOURCE));
	CreateCenterText("Options_Title", sf::Vector2f((float)WINDOW_SIZE.x / 2, 50), 50);
	SetAsButton(CreateCenterText("Options_Controls", sf::Vector2f((float)WINDOW_SIZE.x / 2, 250), 50));
	SetAsButton(CreateCenterText("Options_Graphics", sf::Vector2f((float)WINDOW_SIZE.x / 2, 350), 50));
	SetAsButton(CreateCenterText("Options_Back", sf::Vector2f((float)WINDOW_SIZE.x / 2, 450), 50));
}

void StateOptions::Unload()
{
}
