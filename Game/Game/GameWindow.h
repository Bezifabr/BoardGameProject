#pragma once

#include "Config.h"

#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>

using namespace std;

class Window
{
	friend class GameWindowsBuilder;
public:
	virtual ~Window();
protected:
	sf::RenderWindow* window;
};
