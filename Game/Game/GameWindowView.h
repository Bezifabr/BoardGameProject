#pragma once

#include "GameWindow.h"
#include <SFML/Graphics/View.hpp>

class ViewWindow : public Window
{
public:
	virtual ~ViewWindow() {};

	void SetView(const sf::View& view);

	const sf::View& GetView();
};