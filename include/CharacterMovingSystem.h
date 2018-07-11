#ifndef CHARACTER_MOVING_SYSTEM_H
#define CHARACTER_MOVING_SYSTEM_H

#include "PlayerOslas.h"
#include "PlayerSeph.h"
#include "PlayerMefisto.h"
#include "PlayerFahren.h"

class CharacterMovingSystem
{
	vector<Character*>* charactersVector;
	vector<Waypoint*>* waypointsVector;

	sf::Vector2f distance;
	sf::Vector2f speed;

	sf::Clock moveTimer;
	float timeOfMove;

	sf::Clock elapsedTimer;
	bool didTimeElapsed;
public:

	void MoveCharactersToWaypoints(float timeOfMovement = 500);

	bool IsCharacterInsideOfWaypoint(Waypoint* waypoint, Character* character);

	void AddCharactersAndVectors(vector<Character*>* charactersVector, vector<Waypoint*>* waypointsVector);
private:
	void CalculateDistanceBetweenWaypointAndTarget(Waypoint* waypoint, Character* character);
	void CalculateSpeed();
	void CalculateSpeedWithDeltaTime(float deltaTime);

	bool CheckIfCharactersStayOnWaypoint(Waypoint* waypoint, Character* character);

};

#endif // !CHARACTER_MOVING_SYSTEM_H