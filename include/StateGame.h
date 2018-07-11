#ifndef STATE_GAME_H
#define STATE_GAME_H

#include "State.h"

class StateGame : public State
{
	LoadingSystem * loadingSystem;

	Player* currentPlayer;

	CameraMovingSystem cameraMovingSystem;
	PlayersControlSystem playersControlSystem;
	InterfaceAlignmentSystem interfaceAlignmentSystem;
	CharacterMovingSystem characterMovingSystem;

	sf::Clock timeOfMove;
	bool canAddMoves = true;

	float timeOfMovement = 500;
	virtual void Update();

	virtual void Load();

	virtual void Unload();

	void InitializeLoadingSystem();
	void AddPlayer(string name, Player* newPlayer);

	sf::Texture testingTexture;
	void MapLoadingTest();
};

#endif // !STATE_GAME_H