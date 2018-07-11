#ifndef GAME_WINDOW_EVENTS_H
#define GAME_WINDOW_EVENTS_H

#include "GameWindow.h"
#include <SFML/Window/Mouse.hpp>

class EventWindow : public Window
{
public:
	virtual ~EventWindow() {};

	bool PollEvent(sf::Event& event);

	void CloseWindow();

	sf::Vector2f GetRelativeMousePosition();

private:
};

#endif // !GAME_WINDOW_EVENTS_H