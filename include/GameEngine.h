#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

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

#endif // !GAME_ENGINE_H