#pragma once

#include "Character.h"
#include "GameWindowEvents.h"

class EventsHandler
{
	sf::Event* event = new sf::Event();
	EventWindow* gameWindow;

	vector<EventObject*>* eventObjects;

public:
	EventsHandler(EventWindow* gameWindow);
	~EventsHandler();

	void SetGameWindow(EventWindow* gameWindow);
	void EventsLoop();
	void GetDataFromDataContainer(vector<EventObject*>*eventObjects);

private:

	void HandleEvents();
	void CheckWindowClosing();
	bool CheckEvent(EventObject* itr);
};