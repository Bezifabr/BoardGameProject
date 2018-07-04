#pragma once

#include "Player.h"

class PlayerOslas : public Player
{
public:
	PlayerOslas(int location, int waypoint);
	virtual ~PlayerOslas() {};
};