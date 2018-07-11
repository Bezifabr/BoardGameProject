#ifndef PLAYERS_CONTROL_SYSTEM_H
#define PLAYERS_CONTROL_SYSTEM_H

#include "CharacterMovingSystem.h"

class PlayersControlSystem
{
	map<string, Player*> players;

	int currentPlayersKey = 0;
	vector<string> playersKeysVector;

	int movesLeft;
	sf::Clock movingTimer;

	bool isPlayerMoving = false;
	bool isCurrentPlayerChanged = true;
public:

	Player* AddPlayer(string name, Player* newPlayer);

	void AddMoves(int movesLeft);

	void MakePlayerMoving(float delayBetweenMoves = 750);

	Player* GetCurrentPlayer();

	bool CheckIfMovesLeftAreZeroAndCurrentPlayerIsChanged();
private:

	void NextPlayer();

	void MovePlayer();
};

#endif // !PLAYERS_CONTROL_SYSTEM_H