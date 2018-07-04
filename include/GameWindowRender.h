#pragma once

#include "GameWindow.h"

class RenderWindow : public Window
{
public:
	virtual ~RenderWindow() {};

	void Clear();
	void Display();
	void Draw(sf::Drawable& drawable);
};
