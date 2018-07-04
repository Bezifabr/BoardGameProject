#include "GameWindowEvents.h"

bool EventWindow::PollEvent(sf::Event & event)
{
	assert(window != NULL);
	return window->pollEvent(event);
}

void EventWindow::CloseWindow()
{
	assert(window != NULL);
	window->close();
}

sf::Vector2f EventWindow::GetRelativeMousePosition()
{
	return window->mapPixelToCoords(sf::Mouse::getPosition((*window)));
}
