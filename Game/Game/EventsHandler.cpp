#include "EventsHandler.h"

EventsHandler::EventsHandler(EventWindow * gameWindow)
{
	SetGameWindow(gameWindow);
}

EventsHandler::~EventsHandler()
{
	assert(event);
	delete event;
	event = nullptr;
	assert(!event);

	assert(gameWindow);
	gameWindow = nullptr;
	assert(!gameWindow);

	assert(eventObjects);
	eventObjects = nullptr;
	assert(!eventObjects);
}

void EventsHandler::SetGameWindow(EventWindow * gameWindow)
{
	this->gameWindow = gameWindow;
	assert(gameWindow != NULL);
}

void EventsHandler::EventsLoop()
{
	assert(gameWindow != NULL);
	assert(event != NULL);
	while (gameWindow->PollEvent((*event)))
		HandleEvents();
}

void EventsHandler::GetDataFromDataContainer(vector<EventObject*>* eventObjects)
{
	this->eventObjects = eventObjects;
	assert(this->eventObjects);
}

void EventsHandler::HandleEvents()
{
	CheckWindowClosing();

	assert(eventObjects);
	if (!eventObjects->empty())
		for (auto itr = eventObjects->begin(), end = eventObjects->end(); itr != end; itr++)
			(*itr)->IsActivated(CheckEvent((*itr)));
}

void EventsHandler::CheckWindowClosing()
{
	if (event->type == sf::Event::Closed)
		gameWindow->CloseWindow();
}

bool EventsHandler::CheckEvent(EventObject * itr)
{
	assert(itr);
	if (itr->GetEventType().CheckEventType(event->type))
		if (itr->GetMouseEvent().CheckMouseButton(event->mouseButton.button))
			if (itr->CheckIfRectContainsMouse(gameWindow->GetRelativeMousePosition()))
				if (itr->GetKeyboardEvent().CheckKeyboardKey(event->key.code))
					return true;
	return false;
}
