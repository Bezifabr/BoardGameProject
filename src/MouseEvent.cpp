#include "MouseEvent.h"

void MouseEvent::SetMouseButton(sf::Mouse::Button mouseButton)
{
	EnableMouseButton();
	this->mouseButton = mouseButton;
}

void MouseEvent::EnableMouseButton()
{
	enabled = true;
}

void MouseEvent::DisableMouseButton()
{
	enabled = false;
}

bool MouseEvent::CheckMouseButton(sf::Mouse::Button & button)
{
	if (enabled)
		return mouseButton == button;
	return true;
}

bool MouseEvent::NeedMousePosition()
{
	return needMousePosition;
}

void MouseEvent::NeedMousePosition(bool needMousePosition)
{
	this->needMousePosition = needMousePosition;
}
