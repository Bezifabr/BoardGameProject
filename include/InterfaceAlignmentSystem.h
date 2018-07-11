#ifndef INTERFACE_ALIGNMENT_SYSTEM_H
#define INTERFACE_ALIGNMENT_SYSTEM_H

#include "PlayersControlSystem.h"

class InterfaceAlignmentSystem
{
	map<string, InterfaceObject*>* interfaceObjects;
	map<string, CustomText*>* customTexts;

	sf::Vector2f cameraCenter;
public:

	void SetCameraPosition(sf::Vector2f center);

	void AddEventObjects(map<string, CustomText*>* customTexts, map<string, InterfaceObject*>* interfaceObjects);

	void AlignGUIObjects();

private:

	sf::Vector2f GetLeftTopCornerOfCamera();
};

#endif // !INTERFACE_ALIGNMENT_SYSTEM_H