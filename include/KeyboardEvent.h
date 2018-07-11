#ifndef KEYBOARD_EVENT_H
#define KEYBOARD_EVENT_H

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

#endif // !KEYBOARD_EVENT_H