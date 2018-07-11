#ifndef GAME_LOADING_SYSTEM_H
#define GAME_LOADING_SYSTEM_H

#include "GameDataAccessor.h"
#include "ResourcesContainer.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>

class LoadingSystem
{
	ResourcesContainer* resourcesContainer;
	GameDataContainer* gameDataContainer;

	Waypoint tempWaypoint;
	Character tempNPC;

	int currentLocation;
	std::vector<std::string>locations;

	sf::Vector2f tempCameraPosition;
	sf::Texture tempBackground;
	bool isBackgroundLoaded;

public:
	~LoadingSystem();

	void AppendDataContainer(GameDataContainer* gameDataContainer);

	void AppendResourcesContainer(ResourcesContainer* resourcesContainer);

	void LoadMap(const char* source);

	int ConvertLocationNameToLocationNumber(const string& locationName);

	void CallWaypointCommand(std::stringstream& stream);

	void CallCharacterCommand(std::stringstream& stream);

	void LoadResourcesFromFile(const char* source);
};

#endif // !GAME_LOADING_SYSTEM_H