#ifndef STATE_H
#define STATE_H

#include "CameraMovingSystem.h"

class State
{
	bool isFinished = false;
	bool isChanging = false;
	std::string newState;

public:
	void LoadData(GameDataContainer* container);
	void UnloadData();
	void UpdateState();
	bool IsFinished();
	bool IsChangingState();
	std::string NewState();
	const sf::View& GetCurrentView();
	void InitializeGameCamera();

protected:
	ResourcesContainer* resourcesContainer;
	GameDataContainer* gameDataContainer;

	void IsFinished(bool isFinished);
	void IsChanging(bool isChanging);
	void SetNewState(const std::string& newState);

	template<class EvOb>
	void SetAsButton(EvOb * eventObject);

	vector<Character*>* GetCharacters();
	vector<GraphicObject*>* GetGraphicObjects();
	map<string, InterfaceObject*>* GetInterfaceObjects();
	map<string, CustomText*>* GetCustomTexts();
	vector<SaveSlot*>* GetSavingSlots();
	vector<Waypoint*>* GetWaypoints();
	sf::Font* GetFont();
	int* GetCurrentLocation();
	Camera* GetCamera();
	CustomText* CreateCenterText(std::string key, sf::Vector2f Position, unsigned int size);
	CustomText* CreateText(std::string key, sf::Vector2f position, unsigned int size);
	CustomText* GetCustomText(std::string key);
	InterfaceObject* CreateInterfaceObject(const string& objectsKey, const string& textureID, sf::Vector2f guiPosition);
	bool IsButtonClicked(std::string keyOfButton);
	bool IsSlotSelected(int slotKey);
	SaveSlot* GetSavingSlot(int key);
	SaveSlot* CreateSavingSlot(sf::Vector2f position, sf::Vector2f scale, int location, int layer);

	virtual void Update() = 0;
	virtual void Load() = 0;
	virtual void Unload() = 0;
};

template<class EvOb>
inline void State::SetAsButton(EvOb * eventObject)
{
	eventObject->GetEventType().SetEventType(sf::Event::MouseButtonPressed);
	eventObject->GetMouseEvent().SetMouseButton(sf::Mouse::Left);
	eventObject->GetMouseEvent().NeedMousePosition(true);
	eventObject->CreateClickableBox();
	eventObject->IsAttachedToCamera(true);
}

#endif // !STATE_H