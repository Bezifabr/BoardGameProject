#include "GameEngine.h"


void GameEngine::InitializeSubsystems()
{
	subsystems.Initialize();
	isGameRunning = true;
}

void GameEngine::StartMainLoop()
{
	subsystems.TestSubsystemsBeforeGameStarts();
	IterateMainLoop();
}

void GameEngine::IterateMainLoop()
{
	while (isGameRunning == true)
	{
		subsystems.Run();
		WaitForClosingSignal();
	}
}

void GameEngine::WaitForClosingSignal()
{
	if (subsystems.SendCloseSignalToGameLoop())
		isGameRunning = false;
}
