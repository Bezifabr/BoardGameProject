#ifndef PLAYER_OSLAS_H
#define PLAYER_OSLAS_H

#include "Player.h"

class PlayerOslas : public Player
{
public:
	PlayerOslas(int location, int waypoint);
	virtual ~PlayerOslas() {};
};

#endif // !PLAYER_OSLAS_H