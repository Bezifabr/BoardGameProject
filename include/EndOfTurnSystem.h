#ifndef END_OF_TURN_SYSTEM_H
#define END_OF_TURN_SYSTEM_H

#include "Waypoint.h"
#include "Character.h"

class EndOfTurnSystem
{
	vector<Waypoint*> waypointsvector;

public:

	void AddWaypointsVector(const vector<Waypoint*>& waypointsVector);
	void CheckTypeOfWaypoint(Character* currentCharacter);


private:


};

#endif // !END_OF_TURN_SYSTEM_H