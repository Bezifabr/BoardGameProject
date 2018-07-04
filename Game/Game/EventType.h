#pragma once
#include <SFML/Window/Event.hpp>

class EventType
{
	sf::Event::EventType eventType;

	bool enabled = false;
public:

	void SetEventType(sf::Event::EventType eventType);
	void EnableEvent();
	void DisableEvent();

	bool CheckEventType(sf::Event::EventType eventType);
};