#pragma once

#include "StateGame.h"

void StateGame::Update()
{
	assert(GetCharacters());
	assert(GetWaypoints());

	if (playersControlSystem.CheckIfMovesLeftAreZeroAndCurrentPlayerIsChanged() && canAddMoves == false)
	{
		canAddMoves = true;
		timeOfMove.restart();
	}

	characterMovingSystem.AddCharactersAndVectors(GetCharacters(), GetWaypoints());
	characterMovingSystem.MoveCharactersToWaypoints(timeOfMovement);

	interfaceAlignmentSystem.SetCameraPosition(GetCurrentView().getCenter());
	interfaceAlignmentSystem.AddEventObjects(GetCustomTexts(), GetInterfaceObjects());
	interfaceAlignmentSystem.AlignGUIObjects();

	if (timeOfMove.getElapsedTime().asMilliseconds() >= timeOfMovement + 500)
		currentPlayer = playersControlSystem.GetCurrentPlayer();


	playersControlSystem.MakePlayerMoving(timeOfMovement + 250);


	cameraMovingSystem.SetCamera(GetCamera());
	cameraMovingSystem.MoveCameraToTargetPositionInTime(currentPlayer->GetRealPosition(), timeOfMovement + 250);


	if ((*GetInterfaceObjects())["Cube"]->IsActivated() && timeOfMove.getElapsedTime().asMilliseconds() >= timeOfMovement + 500 && canAddMoves)
	{
		(*GetInterfaceObjects())["Cube"]->Activate(false);
		timeOfMove.restart();
		int randomedNumber = Utilities::GetRandomNumber(1, 6);
		cout << to_string(randomedNumber) << endl;
		playersControlSystem.AddMoves(randomedNumber);
		canAddMoves = false;
	}


}

void StateGame::Load()
{
	std::cout << "StateGame" << std::endl;

	InitializeLoadingSystem();

	if (GAME_TESTS && MAP_LOADING_TEST)
		MapLoadingTest();
	else
		loadingSystem->LoadMap("Maps/Game.txt");

	AddPlayer("Oslas", new PlayerOslas((*GetCurrentLocation()), 0));
	AddPlayer("Mefisto", new PlayerMefisto((*GetCurrentLocation()), 1));
	AddPlayer("Seph", new PlayerSeph((*GetCurrentLocation()), 2));
	AddPlayer("Fahren", new PlayerFahren((*GetCurrentLocation()), 3));
	currentPlayer = playersControlSystem.GetCurrentPlayer();

	resourcesContainer->LoadTexture("GUI_Cube", "Graphics/Cube.png");
	SetAsButton(CreateInterfaceObject("Cube", "GUI_Cube", sf::Vector2f(150, 150)));

}

void StateGame::Unload()
{
}

void StateGame::InitializeLoadingSystem()
{
	loadingSystem = new LoadingSystem;
	assert(loadingSystem);

	assert(gameDataContainer);
	loadingSystem->AppendDataContainer(gameDataContainer);

	assert(resourcesContainer);
	loadingSystem->AppendResourcesContainer(resourcesContainer);
}

void StateGame::AddPlayer(string name, Player * newPlayer)
{
	Player* tempPlayer = playersControlSystem.AddPlayer(name, newPlayer);
	(*GetCharacters()).push_back(tempPlayer);
}

void StateGame::MapLoadingTest()
{
	assert(loadingSystem);
	loadingSystem->LoadMap("Maps/MapLoadingTest.txt");
}