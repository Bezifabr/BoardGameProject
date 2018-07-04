#include "GameEngine.h"

class Main
{
	GameEngine* gameEngine = new GameEngine();

	void InitializeGameEngine()
	{
		assert(gameEngine != NULL);
		gameEngine->Initialize();
	}

	void RunGameEngine()
	{
		assert(gameEngine != NULL);
		gameEngine->RunGame();
	}
public:

	~Main()
	{
		delete gameEngine;
	}

	int Run()
	{
		InitializeGameEngine();
		RunGameEngine();
		return EXIT_SUCCESS;
	}
};

int main()
{
	Language::SetLanguages("English");
	Main main;
	return main.Run();
}