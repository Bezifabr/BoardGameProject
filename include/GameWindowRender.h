#ifndef GAME_WINDOW_RENDER_H
#define GAME_WINDOW_RENDER_H

#include "GameWindow.h"

class RenderWindow : public Window
{
public:
	virtual ~RenderWindow() {};

	void Clear();
	void Display();
	void Draw(sf::Drawable& drawable);
};

#endif // !GAME_WINDOW_RENDER_H