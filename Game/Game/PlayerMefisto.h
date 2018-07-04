#pragma once

#include "Player.h"

class PlayerMefisto : public Player
{
public:
	PlayerMefisto(int location, int waypoint);
	virtual ~PlayerMefisto() {};
};