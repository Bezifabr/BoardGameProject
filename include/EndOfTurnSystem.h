#pragma once

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