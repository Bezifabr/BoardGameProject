#pragma once

#include <SFML/Graphics/View.hpp>

class Camera
{
	sf::View view;

public:
	const sf::View& GetCameraView();

	void SetPosition(sf::Vector2f position);

	void SetSize(sf::Vector2f size);

	void Move(sf::Vector2f moveValue);
};