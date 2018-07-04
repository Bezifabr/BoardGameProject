#include "GameWindowsBuilder.h"

GameWindowsBuilder::~GameWindowsBuilder()
{
	delete window;
}

void GameWindowsBuilder::CreateWindowAndSetFrameRate()
{
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE, sf::Style::Default);
	SetFrameRateLimit();
}

void GameWindowsBuilder::AddFunctionality(const std::string & windowKey, Window * gameWindow)
{
	assert(window != NULL);
	gameWindow->window = window;
	windowsFunctionality[windowKey] = gameWindow;
}

Window* GameWindowsBuilder::GetFunctionality(const std::string & windowKey)
{
	assert(!windowsFunctionality.empty());
	assert(windowsFunctionality[windowKey]);
	return windowsFunctionality[windowKey];
}

bool GameWindowsBuilder::IsOpened()
{
	assert(window != NULL);
	return window->isOpen();
}

void GameWindowsBuilder::SetFrameRateLimit()
{
	assert(window != NULL);
	window->setFramerateLimit(WINDOW_FRAME_RATE_LIMIT);
}
