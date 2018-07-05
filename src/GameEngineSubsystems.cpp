#include "GameEngineSubsystems.h"
#include "GameWindowRender.h"
#include "GameWindowEvents.h"
#include "GameWindowView.h"

GameEngineSubsystems::~GameEngineSubsystems()
{
	delete windowManager;
	delete eventsHandler;
	delete renderer;
	delete gameDataAccessor;
	delete gameStatesMachine;
}

void GameEngineSubsystems::Iterate()
{
	eventsHandler->EventsLoop();
	gameStatesMachine->CheckStatesUpdates();
	AccessData();
	renderer->ObjectsRendering();
}

void GameEngineSubsystems::Initialize()
{
	InitializeGameWindow();
	InitializeGameDataContainer();
	InitializeGameStates();
	InitializeEventsHandler();
	InitializeRenderer();

	AccessData();
}

bool GameEngineSubsystems::SendCloseSignalToGameLoop()
{
	return CheckIfStateIsFinished() || CheckIfWindowIsClosed();
}

void GameEngineSubsystems::TestSubsystemsBeforeGameStarts()
{
	assert(windowManager);
	assert(eventsHandler);
	assert(renderer);
	assert(gameDataAccessor);
	assert(gameStatesMachine);
}

bool GameEngineSubsystems::CheckIfWindowIsClosed()
{
	assert(windowManager != NULL);
	return !windowManager->IsOpened();
}

bool GameEngineSubsystems::CheckIfStateIsFinished()
{
	assert(gameStatesMachine);
	return gameStatesMachine->IsFinished();
}

void GameEngineSubsystems::InitializeGameStates()
{
	assert(windowManager != NULL);
	gameStatesMachine = new GameStatesMachine(dynamic_cast<ViewWindow*>(windowManager->GetFunctionality("Camera")));
	assert(gameStatesMachine);
	gameStatesMachine->InitializeAndLoadData(gameDataAccessor);
	gameStatesMachine->CheckStatesUpdates();
}

void GameEngineSubsystems::InitializeGameWindow()
{
	windowManager = new GameWindowsBuilder();
	assert(windowManager != NULL);
	windowManager->CreateWindowAndSetFrameRate();
	windowManager->AddFunctionality("Rendering", new RenderWindow);
	windowManager->AddFunctionality("Events", new EventWindow);
	windowManager->AddFunctionality("Camera", new ViewWindow);
}

void GameEngineSubsystems::InitializeEventsHandler()
{
	assert(windowManager != NULL);
	eventsHandler = new EventsHandler(dynamic_cast<EventWindow*>(windowManager->GetFunctionality("Events")));
	assert(windowManager != NULL);
}

void GameEngineSubsystems::InitializeGameDataContainer()
{
	gameDataAccessor = new GameDataAccessor;
	assert(gameDataAccessor);
}

void GameEngineSubsystems::InitializeRenderer()
{
	assert(windowManager != NULL);
	assert(gameDataAccessor);
	renderer = new Renderer(dynamic_cast<RenderWindow*>(windowManager->GetFunctionality("Rendering")));
	assert(renderer != NULL);
}

void GameEngineSubsystems::AccessData()
{
	gameDataAccessor->AccessDataToEventsHandler(eventsHandler);
	gameDataAccessor->AccessDataToRenderer(renderer);
}
