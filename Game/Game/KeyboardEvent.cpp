#include "KeyboardEvent.h"

void KeyboardEvent::SetKeyboardKey(sf::Keyboard::Key keyboardKey)
{
	EnableKeyboardKey();
	this->keyboardKey = keyboardKey;
}

void KeyboardEvent::EnableKeyboardKey()
{
	enabled = true;
}

void KeyboardEvent::DisableKeyboardKey()
{
	enabled = false;
}

bool KeyboardEvent::CheckKeyboardKey(sf::Keyboard::Key & key)
{
	if (enabled)
		return keyboardKey == key;
	return true;
}
