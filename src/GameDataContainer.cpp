#include "GameDataContainer.h"

void GameDataContainer::PrepareCamera()
{
	SetCameraPosition(currentLocation, sf::Vector2f((float)WINDOW_SIZE.x / 2, (float)WINDOW_SIZE.y / 2));
	GetCurrentCamera()->SetSize(sf::Vector2f((float)WINDOW_SIZE.x, (float)WINDOW_SIZE.y));
}

Camera * GameDataContainer::GetCurrentCamera()
{
	assert(!locationsCameraPositions.empty());
	assert(locationsCameraPositions.count(currentLocation) == 1);
	return locationsCameraPositions[currentLocation];
}

bool GameDataContainer::IsBackgroundLoaded()
{
	return locationsIsBackgroundLoaded[currentLocation];
}

void GameDataContainer::AddWaypoint(Waypoint * waypoint)
{
	waypoints.push_back(waypoint);
}

void GameDataContainer::AddCharacter(Character * character)
{
	characters.push_back(character);
}

void GameDataContainer::AddGraphicObject(GraphicObject * graphicObject)
{
	graphicObjects.push_back(graphicObject);
}

void GameDataContainer::AddInterfaceObject(string objectsName, InterfaceObject * interfaceObject)
{
	interfaceObjects[objectsName] = interfaceObject;
}

void GameDataContainer::AddCustomText(string objectsName, CustomText * text)
{
	texts[objectsName] = text;
}

void GameDataContainer::Clear()
{
	characters.clear();
	graphicObjects.clear();
	interfaceObjects.clear();
	texts.clear();
}

void GameDataContainer::SetLocationBackground(int locationNumber, sf::Texture & texture)
{
	locationsBackgrounds[locationNumber] = new sf::Sprite;
	assert(locationsBackgrounds[locationNumber]);
	locationsBackgrounds[locationNumber]->setTexture(texture);
}

void GameDataContainer::SetLocationIsBackgroundLoaded(int locationNumber, bool isBackgroundLoaded)
{
	locationsIsBackgroundLoaded[locationNumber] = isBackgroundLoaded;
}

void GameDataContainer::SetCameraPosition(int locationNumber, sf::Vector2f cameraPosition)
{
	locationsCameraPositions[locationNumber] = new Camera;
	locationsCameraPositions[locationNumber]->SetPosition(cameraPosition);
	GetCurrentCamera()->SetSize(sf::Vector2f((float)WINDOW_SIZE.x, (float)WINDOW_SIZE.y));
}
