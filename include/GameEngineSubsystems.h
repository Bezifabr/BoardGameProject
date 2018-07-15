#ifndef GAME_ENGINE_SUBSYSTEMS_H
#define GAME_ENGINE_SUBSYSTEMS_H

#include "GameStatesMachine.h"
#include "EventsHandler.h"
#include "Renderer.h"
#include "GameDataAccessor.h"
#include "GameWindowsBuilder.h"

class GameEngineSubsystems
{
	GameWindowsBuilder windowManager;
	EventsHandler eventsHandler;
	Renderer renderer;
	GameDataAccessor gameDataAccessor;
	GameStatesMachine gameStatesMachine;
public:

	void Iterate();
	void Initialize();
	bool SendCloseSignalToGameLoop();

private:
	bool CheckIfWindowIsClosed();
	bool CheckIfStateIsFinished();
	void InitializeGameStates();
	void InitializeGameWindow();
	void InitializeEventsHandler();
	void InitializeRenderer();
	void AccessData();

};

#endif // !GAME_ENGINE_SUBSYSTEMS_H