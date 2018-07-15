#include "GameEngine.h"

int main()
{
	Language::SetLanguages("English");

	GameEngine engine;
	engine.StartMainLoop();

	return 0;
}