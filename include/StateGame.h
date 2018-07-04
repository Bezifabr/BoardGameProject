#pragma once

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