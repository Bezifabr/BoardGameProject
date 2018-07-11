#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

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

#endif // !MOUSE_EVENT_H