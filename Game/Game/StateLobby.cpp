#include "StateLobby.h"

void StateLobby::Update()
{
	for (int i = 0; i != 6; i++)
		if (IsSlotSelected(i))
		{
			std::cout << "Clicked" << std::endl;
			SetNewState("Game");
			GetSavingSlot(i)->IsOccupied(true);
		}

	if (IsButtonClicked("Lobby_Back"))
		SetNewState("MainMenu");
}

void StateLobby::Load()
{
	(*GetCurrentLocation()) = 0;
	assert(GetFont()->loadFromFile(DEFAULT_FONT_SOURCE));
	CreateCenterText("Lobby_Title", sf::Vector2f((float)WINDOW_SIZE.x / 2, 50), 50);
	SetAsButton(CreateText("Lobby_Back", sf::Vector2f((float)WINDOW_SIZE.x - 175, (float)WINDOW_SIZE.y - 100), 50));
	SetAsButton(CreateSavingSlot(sf::Vector2f((float)WINDOW_SIZE.x / 5, (float)WINDOW_SIZE.y / 4), sf::Vector2f(1.0f, 1.0f), 0, 1));
	SetAsButton(CreateSavingSlot(sf::Vector2f((float)WINDOW_SIZE.x / 5 * 2, (float)WINDOW_SIZE.y / 4), sf::Vector2f(1.0f, 1.0f), 0, 1));
	SetAsButton(CreateSavingSlot(sf::Vector2f((float)WINDOW_SIZE.x / 5 * 3, (float)WINDOW_SIZE.y / 4), sf::Vector2f(1.0f, 1.0f), 0, 1));
	SetAsButton(CreateSavingSlot(sf::Vector2f((float)WINDOW_SIZE.x / 5, (float)WINDOW_SIZE.y / 4 * 2), sf::Vector2f(1.0f, 1.0f), 0, 1));
	SetAsButton(CreateSavingSlot(sf::Vector2f((float)WINDOW_SIZE.x / 5 * 2, (float)WINDOW_SIZE.y / 4 * 2), sf::Vector2f(1.0f, 1.0f), 0, 1));
	SetAsButton(CreateSavingSlot(sf::Vector2f((float)WINDOW_SIZE.x / 5 * 3, (float)WINDOW_SIZE.y / 4 * 2), sf::Vector2f(1.0f, 1.0f), 0, 1));
}

void StateLobby::Unload()
{
}
