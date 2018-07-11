#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "Frames.h"

class Sequence
{
	Frames frames;
	int currentFrame;
public:
	~Sequence();

	void AddFrame(sf::IntRect frameRect);
	size_t GetFramesNumber();
	sf::IntRect GetCurrentFrame();
	void NextFrame();
	void ResetCurrentFrame();
};

#endif // !SEQUENCE_H