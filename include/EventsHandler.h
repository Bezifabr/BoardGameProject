#ifndef EVENTS_HANDLER_H
#define EVENTS_HANDLER_H

#include "Character.h"
#include "GameWindowEvents.h"

class EventsHandler
{
	sf::Event* event = new sf::Event();
	EventWindow* gameWindow;

	vector<EventObject*>* eventObjects;

public:
	EventsHandler() {}
	EventsHandler(EventWindow* gameWindow);
	~EventsHandler();

	void ConnectWithGameWindow(EventWindow* gameWindow);
	void EventsLoop();
	void GetDataFromDataContainer(vector<EventObject*>*eventObjects);

private:

	void HandleEvents();
	void CheckWindowClosing();
	bool CheckEvent(EventObject* itr);
};

#endif // !EVENTS_HANDLER_H