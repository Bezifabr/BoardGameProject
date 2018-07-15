#ifndef GAME_STATES_MACHINE_H
#define GAME_STATES_MACHINE_H

#include "State.h"
#include "GameWindowView.h"

class GameStatesMachine
{
	State* currentState;
	GameDataContainer* gameDataContainer;
	ViewWindow* viewWindow;

	bool isFinished = false;
public:
	GameStatesMachine() {}
	GameStatesMachine(ViewWindow* viewWindow);
	~GameStatesMachine();

	void ConnectWithViewWindow(ViewWindow* viewWindow);
	void InitializeAndLoadData(GameDataContainer* container);
	void CheckStatesUpdates();
	bool IsFinished();

private:

	void LoadStateByString(const std::string& stateName);
	void CreateNewState(State* newState);
	void ChangeState(const std::string& newStateName);
	void ExitGame();
	void SetGameContainer(GameDataContainer* container);

	sf::Texture sfmlTestingTexture;
	sf::Font sfmlTestingFont;
	void TestCharactersAndTexturesLoading();
	void TestGraphicObjectsAndTexturesLoading();
	void TestInterfaceObjectsAndTexturesLoading();
	void TestCustomTextObjectsAndFontsAndTexturesLoading();
};

#endif // !GAME_STATES_MACHINE_H