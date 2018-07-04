#include "EventObject.h"

void EventObject::UpdateBox(sf::Vector2f position)
{
	box.left = position.x;
	box.top = position.y;
}

const sf::Vector2f & EventObject::GetGUIPosition()
{
	return guiPosition;
}

void EventObject::SetGUIPosition(sf::Vector2f guiPosition)
{
	this->guiPosition = guiPosition;
}

void EventObject::IsAttachedToCamera(bool isAttached)
{
	isAttachedToCamera = isAttached;
}

bool EventObject::IsAttachedToCamera()
{
	return isAttachedToCamera;
}

void EventObject::TurnOn(bool turnOn)
{
	turnedOn = turnOn;
}

void EventObject::IsActivated(bool activate)
{
	activated = activate;
}

bool EventObject::IsActivated()
{
	return activated;
}

EventType & EventObject::GetEventType()
{
	if (turnedOn)
		return eventType;
}

MouseEvent & EventObject::GetMouseEvent()
{
	if (turnedOn)
		return mouseEvent;
}

KeyboardEvent & EventObject::GetKeyboardEvent()
{
	if (turnedOn)
		return keyboardEvent;
}

bool EventObject::CheckIfRectContainsMouse(sf::Vector2f position)
{
	if (mouseEvent.NeedMousePosition())
		return box.contains(position);
	return true;
}

void EventObject::SetClickableBox(sf::FloatRect & rect)
{
	box = rect;
}
