#pragma once

#include "Player.h"

class PlayerFahren : public Player
{
public:
	PlayerFahren(int location, int waypoint);
	virtual ~PlayerFahren() {};
};