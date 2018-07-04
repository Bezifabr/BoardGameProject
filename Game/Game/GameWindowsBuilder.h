#pragma once

#include "GameWindow.h"
#include <SFML/Graphics/View.hpp>

class GameWindowsBuilder
{
	sf::RenderWindow* window;

	map<std::string, Window*>windowsFunctionality;

public:
	~GameWindowsBuilder();

	void CreateWindowAndSetFrameRate();

	void AddFunctionality(const std::string& windowKey, Window* gameWindow);

	Window* GetFunctionality(const std::string& windowKey);

	bool IsOpened();
private:

	void SetFrameRateLimit();
};