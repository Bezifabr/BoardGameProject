#pragma once

#include "GameEngineSubsystems.h"

class GameEngine
{
	bool isGameRunning;
	GameEngineSubsystems* gameEngineSubsystems = new GameEngineSubsystems;
public:
	~GameEngine();

	void Initialize();

	void RunGame();

private:
	void RunMainLoop();

	void WaitForClosingSignal();
};