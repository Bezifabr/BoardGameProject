#pragma once

#include <SFML\Window\Event.hpp>

class KeyboardEvent
{
	sf::Keyboard::Key keyboardKey;
	bool enabled = false;

public:

	void SetKeyboardKey(sf::Keyboard::Key keyboardKey);
	void EnableKeyboardKey();
	void DisableKeyboardKey();
	bool CheckKeyboardKey(sf::Keyboard::Key& key);
};
