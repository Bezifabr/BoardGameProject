#pragma once

#include "Renderer.h"

class Player : public Character
{
protected:
	sf::Texture texture;
public:
	virtual ~Player() {};
};