#include "GameEngine.h"

int main()
{
	Language::SetLanguages("English");

	GameEngine engine;
	engine.InitializeSubsystems();
	engine.StartMainLoop();

	return 0;
}