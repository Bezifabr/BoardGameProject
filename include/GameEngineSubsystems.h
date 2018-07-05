#pragma once

#include "GameStatesMachine.h"
#include "EventsHandler.h"
#include "Renderer.h"
#include "GameDataAccessor.h"
#include "GameWindowsBuilder.h"

class GameEngineSubsystems
{
	GameWindowsBuilder* windowManager;
	EventsHandler* eventsHandler;
	Renderer* renderer;
	GameDataAccessor* gameDataAccessor;
	GameStatesMachine* gameStatesMachine;
public:
	~GameEngineSubsystems();

	void Iterate();
	void Initialize();
	bool SendCloseSignalToGameLoop();
	void TestSubsystemsBeforeGameStarts();

private:
	bool CheckIfWindowIsClosed();
	bool CheckIfStateIsFinished();
	void InitializeGameStates();
	void InitializeGameWindow();
	void InitializeEventsHandler();
	void InitializeGameDataContainer();
	void InitializeRenderer();
	void AccessData();

};
