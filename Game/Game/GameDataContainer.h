#pragma once

#include "InterfaceAlignmentSystem.h"
#include "Camera.h"

class GameDataContainer
{
	friend class State;

protected:
	int currentLocation = 0;
	map<int, Camera*>locationsCameraPositions;
	map<int, sf::Sprite*>locationsBackgrounds;
	map<int, bool>locationsIsBackgroundLoaded;

	vector<Waypoint*> waypoints;
	vector<Character*> characters;
	vector<GraphicObject*> graphicObjects;
	map<string, InterfaceObject*> interfaceObjects;
	map<string, CustomText*> texts;
	vector<SaveSlot*> savingSlots;


	sf::Font font;

	void PrepareCamera();

	Camera* GetCurrentCamera();
public:
	bool IsBackgroundLoaded();

	void AddWaypoint(Waypoint* waypoint);

	void AddCharacter(Character* character);

	void AddGraphicObject(GraphicObject* graphicObject);

	void AddInterfaceObject(string objectsName, InterfaceObject* interfaceObject);

	void AddCustomText(string objectsName, CustomText* text);
	void Clear();

	void SetLocationBackground(int locationNumber, sf::Texture& texture);

	void SetLocationIsBackgroundLoaded(int locationNumber, bool isBackgroundLoaded);

	void SetCameraPosition(int locationNumber, sf::Vector2f cameraPosition);
private:
};