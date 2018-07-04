#include "GameWindowRender.h"

void RenderWindow::Clear()
{
	assert(window != NULL);
	window->clear();
}

void RenderWindow::Display()
{
	assert(window != NULL);
	window->display();
}

void RenderWindow::Draw(sf::Drawable & drawable)
{
	assert(window != NULL);
	window->draw(drawable);
}
