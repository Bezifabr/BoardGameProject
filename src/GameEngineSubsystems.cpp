#include "GameEngineSubsystems.h"
#include "GameWindowRender.h"
#include "GameWindowEvents.h"
#include "GameWindowView.h"

void GameEngineSubsystems::Iterate()
{
	eventsHandler.EventsLoop();
	gameStatesMachine.CheckStatesUpdates();
	AccessData();
	renderer.ObjectsRendering();
}

void GameEngineSubsystems::Initialize()
{
	InitializeGameWindow();
	InitializeGameStates();
	InitializeEventsHandler();
	InitializeRenderer();

	AccessData();
}

bool GameEngineSubsystems::SendCloseSignalToGameLoop()
{
	return CheckIfStateIsFinished() || CheckIfWindowIsClosed();
}

bool GameEngineSubsystems::CheckIfWindowIsClosed()
{
	return !windowManager.IsOpened();
}

bool GameEngineSubsystems::CheckIfStateIsFinished()
{
	return gameStatesMachine.IsFinished();
}

void GameEngineSubsystems::InitializeGameStates()
{
	gameStatesMachine.ConnectWithViewWindow(dynamic_cast<ViewWindow*>(windowManager.GetFunctionality("Camera")));
	gameStatesMachine.InitializeAndLoadData(&gameDataAccessor);
	gameStatesMachine.CheckStatesUpdates();
}

void GameEngineSubsystems::InitializeGameWindow()
{
	windowManager.CreateWindowAndSetFrameRate();
	windowManager.AddFunctionality("Rendering", new RenderWindow);
	windowManager.AddFunctionality("Events", new EventWindow);
	windowManager.AddFunctionality("Camera", new ViewWindow);
}

void GameEngineSubsystems::InitializeEventsHandler()
{
	EventWindow* eventWindow = dynamic_cast<EventWindow*>(windowManager.GetFunctionality("Events"));
	assert(eventWindow);
	eventsHandler.ConnectWithGameWindow(eventWindow);
}

void GameEngineSubsystems::InitializeRenderer()
{
	RenderWindow* renderWindow = dynamic_cast<RenderWindow*>(windowManager.GetFunctionality("Rendering"));
	assert(renderWindow);
	renderer.ConnectWithRenderWindow(renderWindow);
}

void GameEngineSubsystems::AccessData()
{
	gameDataAccessor.AccessDataToEventsHandler(&eventsHandler);
	gameDataAccessor.AccessDataToRenderer(&renderer);
}
