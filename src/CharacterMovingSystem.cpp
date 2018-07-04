#include "CharacterMovingSystem.h"

void CharacterMovingSystem::MoveCharactersToWaypoints(float timeOfMovement)
{
	timeOfMove = timeOfMovement;

	float deltaTime = moveTimer.restart().asMilliseconds();
	if (!charactersVector->empty() && !waypointsVector->empty())
		for (int i = 0; i < charactersVector->size(); i++)
		{
			(*charactersVector)[i]->realPosition = (*waypointsVector)[(*charactersVector)[i]->currentWaypoint]->GetPosition();
			CalculateDistanceBetweenWaypointAndTarget((*waypointsVector)[(*charactersVector)[i]->currentWaypoint], (*charactersVector)[i]);
			CalculateSpeed();
			CalculateSpeedWithDeltaTime(deltaTime);

			(*charactersVector)[i]->sprite.move(speed);
		}
}

bool CharacterMovingSystem::IsCharacterInsideOfWaypoint(Waypoint * waypoint, Character * character)
{
	if (waypoint->sprite.getGlobalBounds().contains(character->sprite.getGlobalBounds().left, character->sprite.getGlobalBounds().top)
		|| waypoint->sprite.getGlobalBounds().contains(character->sprite.getGlobalBounds().left, character->sprite.getGlobalBounds().top + character->sprite.getGlobalBounds().height)
		|| waypoint->sprite.getGlobalBounds().contains(character->sprite.getGlobalBounds().left + character->sprite.getGlobalBounds().width, character->sprite.getGlobalBounds().top)
		|| waypoint->sprite.getGlobalBounds().contains(character->sprite.getGlobalBounds().left + character->sprite.getGlobalBounds().width, character->sprite.getGlobalBounds().top + character->sprite.getGlobalBounds().height))
		return true;
	else
		return false;
}

void CharacterMovingSystem::AddCharactersAndVectors(vector<Character*>* charactersVector, vector<Waypoint*>* waypointsVector)
{
	this->charactersVector = charactersVector;
	this->waypointsVector = waypointsVector;
	assert(this->charactersVector);
	assert(this->waypointsVector);
}

void CharacterMovingSystem::CalculateDistanceBetweenWaypointAndTarget(Waypoint* waypoint, Character* character)
{
	distance = waypoint->GetPosition() - character->sprite.getPosition();
}

void CharacterMovingSystem::CalculateSpeed()
{
	speed = sf::Vector2f(distance.x / timeOfMove, distance.y / timeOfMove);

}

void CharacterMovingSystem::CalculateSpeedWithDeltaTime(float deltaTime)
{
	speed.x *= deltaTime;
	speed.y *= deltaTime;
}

bool CharacterMovingSystem::CheckIfCharactersStayOnWaypoint(Waypoint * waypoint, Character * character)
{
	return waypoint->sprite.getGlobalBounds().contains(character->sprite.getPosition());
}
