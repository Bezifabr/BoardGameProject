#pragma once

#include <SFML\Window\Event.hpp>

class MouseEvent
{
	sf::Mouse::Button mouseButton;

	bool enabled = false;
	bool needMousePosition = false;
public:

	void SetMouseButton(sf::Mouse::Button mouseButton);
	void EnableMouseButton();
	void DisableMouseButton();
	bool CheckMouseButton(sf::Mouse::Button& button);
	bool NeedMousePosition();
	void NeedMousePosition(bool needMousePosition);
};
