#include "GameDataAccessor.h"

GameDataAccessor::~GameDataAccessor()
{
	drawableObjects.clear();
	eventObjects.clear();
}

void GameDataAccessor::AccessDataToRenderer(Renderer * renderer)
{
	assert(renderer);
	RenderingByLocationTest();
	MergeDrawableDerivedClasses();
	renderer->GetGameDataFromDataContainer(&drawableObjects, &currentLocation);
}

void GameDataAccessor::AccessDataToEventsHandler(EventsHandler * eventsHandler)
{
	assert(eventsHandler);
	MergeEventDerivedClasses();
	eventsHandler->GetDataFromDataContainer(&eventObjects);
}

void GameDataAccessor::MergeEventDerivedClasses()
{
	Utilities::MapToVector(interfaceObjects, eventObjects);
	Utilities::MapToVector(texts, eventObjects);
	Utilities::MergeVectors(savingSlots, eventObjects);
}

void GameDataAccessor::MergeDrawableDerivedClasses()
{
	drawableObjects.clear();
	Utilities::MergeVectors(waypoints, drawableObjects);
	Utilities::MergeVectors(graphicObjects, drawableObjects);
	Utilities::MergeVectors(characters, drawableObjects);
	Utilities::MergeVectors(savingSlots, drawableObjects);
	Utilities::MapToVector(interfaceObjects, drawableObjects);
	Utilities::MapToVector(texts, drawableObjects);
}

void GameDataAccessor::RenderingByLocationTest()
{
	if (RENDERING_LOCATION_TEST && GAME_TESTS)
	{
		currentLocation = 1;

		assert(testingTexture.loadFromFile(TESTING_GRAPHIC_SOURCE));
		GraphicObject* dontRender = new GraphicObject;
		GraphicObject* render = new GraphicObject;
		dontRender->SetLocation(0);
		render->SetLocation(1);
		dontRender->SetTexture(testingTexture);
		render->SetTexture(testingTexture);

		render->SetPosition(sf::Vector2f((float)WINDOW_SIZE.x / 2, (float)WINDOW_SIZE.y / 2));
		dontRender->SetPosition(sf::Vector2f(50, 50));

		AddGraphicObject(dontRender);
		AddGraphicObject(render);
	}
}