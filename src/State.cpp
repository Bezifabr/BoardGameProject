#include "State.h"

void State::LoadData(GameDataContainer * container)
{
	gameDataContainer = container;
	resourcesContainer = new ResourcesContainer;
	assert(gameDataContainer);
	assert(resourcesContainer);
	Load();
}

void State::UnloadData()
{
	Unload();
	assert(gameDataContainer);
	gameDataContainer->waypoints.clear();
	gameDataContainer->texts.clear();
	gameDataContainer->savingSlots.clear();
	gameDataContainer->characters.clear();
	gameDataContainer->graphicObjects.clear();
	gameDataContainer->interfaceObjects.clear();
	gameDataContainer = nullptr;
	assert(!gameDataContainer);
}

void State::UpdateState()
{
	Update();
}

bool State::IsFinished()
{
	return isFinished;
}

bool State::IsChangingState()
{
	return isChanging;
}

std::string State::NewState()
{
	return newState;
}

const sf::View & State::GetCurrentView()
{
	assert(gameDataContainer);
	return gameDataContainer->GetCurrentCamera()->GetCameraView();
}

void State::InitializeGameCamera()
{
	assert(gameDataContainer);
	gameDataContainer->PrepareCamera();
}

void State::IsFinished(bool isFinished)
{
	this->isFinished = isFinished;
}

void State::IsChanging(bool isChanging)
{
	this->isChanging = isChanging;
}

void State::SetNewState(const std::string & newState)
{
	IsChanging(true);
	this->newState = newState;
	assert(!this->newState.empty());
}

vector<Character*>* State::GetCharacters()
{
	return &gameDataContainer->characters;
}

vector<GraphicObject*>* State::GetGraphicObjects()
{
	return &gameDataContainer->graphicObjects;
}

map<string, InterfaceObject*>* State::GetInterfaceObjects()
{
	return &gameDataContainer->interfaceObjects;
}

map<string, CustomText*>* State::GetCustomTexts()
{
	return &gameDataContainer->texts;
}

vector<SaveSlot*>* State::GetSavingSlots()
{
	return &gameDataContainer->savingSlots;
}

vector<Waypoint*>* State::GetWaypoints()
{
	return &gameDataContainer->waypoints;
}

sf::Font * State::GetFont()
{
	return &gameDataContainer->font;
}

int * State::GetCurrentLocation()
{
	return &gameDataContainer->currentLocation;
}

Camera * State::GetCamera()
{
	return gameDataContainer->GetCurrentCamera();
}

CustomText * State::CreateCenterText(std::string key, sf::Vector2f Position, unsigned int size)
{
	CreateText(key, Position, size);
	GetCustomText(key)->AlignCenter();

	return GetCustomText(key);
}

CustomText * State::CreateText(std::string key, sf::Vector2f position, unsigned int size)
{
	(*GetCustomTexts())[key] = new CustomText;
	GetCustomText(key)->SetFont((*GetFont()));
	GetCustomText(key)->SetString(Language::Get()[key]);
	GetCustomText(key)->SetPosition(position);
	GetCustomText(key)->SetGUIPosition(position);
	GetCustomText(key)->SetSize(size);

	return GetCustomText(key);
}

CustomText * State::GetCustomText(std::string key)
{
	CustomText* customTextReplacemenet = new CustomText;
	if (GetCustomTexts()->count(key) == 1)
		return (*GetCustomTexts())[key];
	return customTextReplacemenet;
}

InterfaceObject * State::CreateInterfaceObject(const string & objectsKey, const string & textureID, sf::Vector2f guiPosition)
{
	InterfaceObject tempInterfaceObject;
	tempInterfaceObject.SetTexture(resourcesContainer->GetTexture(textureID));
	tempInterfaceObject.SetGUIPosition(guiPosition);
	tempInterfaceObject.SetPosition(guiPosition);
	tempInterfaceObject.SetLocation((*GetCurrentLocation()));
	(*GetInterfaceObjects())[objectsKey] = new InterfaceObject(tempInterfaceObject);
	return (*GetInterfaceObjects())[objectsKey];
}

bool State::IsButtonClicked(std::string keyOfButton)
{
	return GetCustomText(keyOfButton)->IsActivated();
}

bool State::IsSlotSelected(int slotKey)
{
	if (GetSavingSlot(slotKey)->IsOccupied() == false)
		return GetSavingSlot(slotKey)->IsActivated();
	return false;
}

SaveSlot * State::GetSavingSlot(int key)
{
	assert(!GetSavingSlots()->empty());
	return (*GetSavingSlots())[key];
}

SaveSlot * State::CreateSavingSlot(sf::Vector2f position, sf::Vector2f scale, int location, int layer)
{
	(*GetSavingSlots()).push_back(new SaveSlot);
	int lastKey = (int)GetSavingSlots()->size() - 1;
	GetSavingSlot(lastKey)->SetEmpty();
	GetSavingSlot(lastKey)->SetPosition(position);
	GetSavingSlot(lastKey)->SetLocation(location);
	GetSavingSlot(lastKey)->SetLayer(layer);
	GetSavingSlot(lastKey)->CreateClickableBox();

	return GetSavingSlot(lastKey);
}
