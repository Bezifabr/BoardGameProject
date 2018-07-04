#include "InterfaceAlignmentSystem.h"

void InterfaceAlignmentSystem::SetCameraPosition(sf::Vector2f center)
{
	cameraCenter = center;
}

void InterfaceAlignmentSystem::AddEventObjects(map<string, CustomText*>* customTexts, map<string, InterfaceObject*>* interfaceObjects)
{
	this->interfaceObjects = interfaceObjects;
	this->customTexts = customTexts;
	assert(this->interfaceObjects);
	assert(this->customTexts);
}

void InterfaceAlignmentSystem::AlignGUIObjects()
{
	if (!interfaceObjects->empty())
		for (auto itr = interfaceObjects->begin(); itr != interfaceObjects->end(); itr++)
			itr->second->SetPosition(itr->second->GetGUIPosition() + GetLeftTopCornerOfCamera());

	if (!customTexts->empty())
		for (auto itr = customTexts->begin(); itr != customTexts->end(); itr++)
			itr->second->SetPosition(itr->second->GetGUIPosition() + GetLeftTopCornerOfCamera());

}

sf::Vector2f InterfaceAlignmentSystem::GetLeftTopCornerOfCamera()
{
	return cameraCenter - sf::Vector2f((float)WINDOW_SIZE.x / 2, (float)WINDOW_SIZE.y / 2);
}
