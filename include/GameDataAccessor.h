#pragma once

#include "GameDataContainer.h"

class GameDataAccessor : public GameDataContainer
{
	vector<DrawableObject*> drawableObjects;
	vector<EventObject*> eventObjects;
public:
	~GameDataAccessor();

	void AccessDataToRenderer(Renderer* renderer);

	void AccessDataToEventsHandler(EventsHandler* eventsHandler);

private:

	void MergeEventDerivedClasses();

	void MergeDrawableDerivedClasses();
	
	//Testing
	sf::Texture testingTexture;
	void RenderingByLocationTest();
};
