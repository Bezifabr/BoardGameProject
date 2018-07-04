#include "GameEngine.h"

GameEngine::~GameEngine()
{
	delete gameEngineSubsystems;
}

void GameEngine::Initialize()
{
	gameEngineSubsystems->Initialize();
	isGameRunning = true;
}

void GameEngine::RunGame()
{
	assert(gameEngineSubsystems);
	gameEngineSubsystems->TestSubsystemsBeforeGameStarts();
	RunMainLoop();
}

void GameEngine::RunMainLoop()
{
	while (isGameRunning == true)
	{
		assert(gameEngineSubsystems);
		gameEngineSubsystems->Run();
		WaitForClosingSignal();
	}
}

void GameEngine::WaitForClosingSignal()
{
	assert(gameEngineSubsystems);
	if (gameEngineSubsystems->SendCloseSignalToGameLoop())
		isGameRunning = false;
}
