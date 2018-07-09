#pragma once

#include "MouseEvent.h"
#include "KeyboardEvent.h"
#include "EventType.h"
#include <SFML/Graphics/Rect.hpp>
class EventObject
{
	EventType eventType;
	MouseEvent mouseEvent;
	KeyboardEvent keyboardEvent;
	bool turnedOn;
	bool activated = false;
	bool isAttachedToCamera = false;

	sf::Vector2f guiPosition;
	sf::FloatRect box;

protected:
	void UpdateBox(sf::Vector2f position);

public:
	virtual ~EventObject() {};

	const sf::Vector2f& GetGUIPosition();
	void SetGUIPosition(sf::Vector2f guiPosition);

	void IsAttachedToCamera(bool isAttached);
	bool IsAttachedToCamera();

	void TurnOn(bool turnOn);
	void IsActivated(bool activate);
	bool IsActivated();

	EventType& GetEventType();
	MouseEvent& GetMouseEvent();
	KeyboardEvent& GetKeyboardEvent();

	bool CheckIfRectContainsMouse(sf::Vector2f position);

protected:

	void SetClickableBox(const sf::FloatRect& rect);
};
