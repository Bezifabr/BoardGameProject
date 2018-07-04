#include "EventType.h"

void EventType::SetEventType(sf::Event::EventType eventType)
{
	EnableEvent();
	this->eventType = eventType;
}

void EventType::EnableEvent()
{
	enabled = true;
}

void EventType::DisableEvent()
{
	enabled = false;
}

bool EventType::CheckEventType(sf::Event::EventType eventType)
{
	if (enabled)
		return this->eventType == eventType;
	return true;
}
