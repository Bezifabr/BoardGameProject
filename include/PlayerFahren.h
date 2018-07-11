#ifndef PLAYER_FAHREN_H
#define PLAYER_FAHREN_H

#include "Player.h"

class PlayerFahren : public Player
{
public:
	PlayerFahren(int location, int waypoint);
	virtual ~PlayerFahren() {};
};

#endif // !PLAYER_FAHREN_H