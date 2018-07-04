#include "EndOfTurnSystem.h"

void EndOfTurnSystem::AddWaypointsVector(const vector<Waypoint*>& waypointsVector)
{
	this->waypointsvector = waypointsVector;
}

void EndOfTurnSystem::CheckTypeOfWaypoint(Character * currentCharacter)
{
	cout << waypointsvector[currentCharacter->GetWaypoint()]->GetType() << endl;
}
