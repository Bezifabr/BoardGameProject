#ifndef PLAYER_SEPH_H
#define PLAYER_SEPH_H

#include "Player.h"

class PlayerSeph : public Player
{
public:
	PlayerSeph(int location, int waypoint);
	virtual ~PlayerSeph() {};
};

#endif // !PLAYER_SEPH_H