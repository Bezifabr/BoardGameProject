#include "StateMainMenu.h"

void StateMainMenu::Update()
{
	if (IsButtonClicked("Menu_Quit"))
		IsFinished(true);

	if (IsButtonClicked("Menu_Options"))
		SetNewState("Options");

	if (IsButtonClicked("Menu_Play"))
		SetNewState("Lobby");
}

void StateMainMenu::Load()
{
	(*GetCurrentLocation()) = 0;
	assert(GetFont()->loadFromFile(DEFAULT_FONT_SOURCE));
	CreateCenterText("Menu_Title", sf::Vector2f((float)WINDOW_SIZE.x / 2, 50), 50);
	SetAsButton(CreateCenterText("Menu_Play", sf::Vector2f((float)WINDOW_SIZE.x / 2, 250), 50));
	SetAsButton(CreateCenterText("Menu_Options", sf::Vector2f((float)WINDOW_SIZE.x / 2, 350), 50));
	SetAsButton(CreateCenterText("Menu_Quit", sf::Vector2f((float)WINDOW_SIZE.x / 2, 450), 50));
}

void StateMainMenu::Unload()
{
}
