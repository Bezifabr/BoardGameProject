#include "GameEngine.h"


GameEngine::GameEngine()
{
	subsystems.Initialize();
	isGameRunning = true;
}

void GameEngine::StartMainLoop()
{
	IterateMainLoop();
}

void GameEngine::IterateMainLoop()
{
	while (isGameRunning == true)
	{
		subsystems.Iterate();
		WaitForClosingSignal();
	}
}

void GameEngine::WaitForClosingSignal()
{
	if (subsystems.SendCloseSignalToGameLoop())
		isGameRunning = false;
}
