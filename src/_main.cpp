#include "GameEngine.h"

int main()
{
	Language::SetLanguages("English");

	GameEngine engine;
	engine.Initialize();
	engine.RunGame();

	return 0;
}