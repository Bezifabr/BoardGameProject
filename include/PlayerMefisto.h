#ifndef PLAYER_MEFISTO_H
#define PLAYER_MEFISTO_H

#include "Player.h"

class PlayerMefisto : public Player
{
public:
	PlayerMefisto(int location, int waypoint);
	virtual ~PlayerMefisto() {};
};

#endif // !PLAYER_MEFISTO_H