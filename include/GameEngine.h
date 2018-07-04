#pragma once

#include "GameEngineSubsystems.h"

class GameEngine
{
	bool isGameRunning;
	GameEngineSubsystems subsystems;
public:
	void InitializeSubsystems();
	void StartMainLoop();

private:
	void IterateMainLoop();
	void WaitForClosingSignal();
};