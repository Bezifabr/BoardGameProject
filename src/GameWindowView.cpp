#include "GameWindowView.h"

void ViewWindow::SetView(const sf::View & view)
{
	assert(window);
	window->setView(view);
}

const sf::View & ViewWindow::GetView()
{
	assert(window);
	return window->getView();
}
