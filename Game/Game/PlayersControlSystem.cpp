#include "PlayersControlSystem.h"

Player * PlayersControlSystem::AddPlayer(string name, Player * newPlayer)
{
	players[name] = newPlayer;
	assert(players[name]);
	playersKeysVector.push_back(name);

	return players[name];
}

void PlayersControlSystem::AddMoves(int movesLeft)
{
	if (this->movesLeft == 0)
		if (this->movesLeft + movesLeft >= 0)
		{
			this->movesLeft += movesLeft;
			isPlayerMoving = true;
			isCurrentPlayerChanged = false;
			movingTimer.restart();
		}
}

void PlayersControlSystem::MakePlayerMoving(float delayBetweenMoves)
{
	if (isPlayerMoving)
		if (movingTimer.getElapsedTime().asSeconds() > delayBetweenMoves / 1000)
		{
			movingTimer.restart();
			MovePlayer();
		}
}

Player * PlayersControlSystem::GetCurrentPlayer()
{
	return players[playersKeysVector[currentPlayersKey]];
}

bool PlayersControlSystem::CheckIfMovesLeftAreZeroAndCurrentPlayerIsChanged()
{
	if (movesLeft == 0 && isCurrentPlayerChanged)
		return true;
	else
		return false;
}

void PlayersControlSystem::NextPlayer()
{
	if (currentPlayersKey < playersKeysVector.size() - 1)
		currentPlayersKey++;
	else
		currentPlayersKey = 0;
	isCurrentPlayerChanged = true;
}

void PlayersControlSystem::MovePlayer()
{
	if (movesLeft > 0)
	{
		assert(GetCurrentPlayer());
		GetCurrentPlayer()->GoToNextWaypoint();
		movesLeft--;
	}
	else
	{
		if (isPlayerMoving)
			NextPlayer();
		isPlayerMoving = false;
	}
}
