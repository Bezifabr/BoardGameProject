#ifndef PLAYER_H
#define PLAYER_H

#include "Renderer.h"

class Player : public Character
{
protected:
	sf::Texture texture;
public:
	virtual ~Player() {};
};

#endif // !PLAYER_H