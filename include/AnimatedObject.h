#ifndef ANIMATED_OBJECT_H
#define ANIMATED_OBJECT_H

#include "Sequences.h"
#include <SFML/System/Clock.hpp>
#include <map>

class AnimatedObject : public DrawableObject
{
	Sequences sequences;

	int framesPerSecond;
	float timeBetweenFrames;
	sf::Clock sequenceTimer;
	bool isSequencePlaying;

public:
	virtual ~AnimatedObject() {};

	void StartSequence(std::string sequenceName);
	void StopSequence();
	void PlaySequence();

	void SetFramesPerSecond(int fps);

	void CreateSequenceAndSetAsCurrent(const std::string& sequenceID);
	void AddFrameToCurrentSequence(sf::IntRect frameRect);
private:

	void CountTimeBetweenFrames();

	void NextFrame();

	void UpdateObjectsFrame();
};

#endif // !ANIMATED_OBJECT_H