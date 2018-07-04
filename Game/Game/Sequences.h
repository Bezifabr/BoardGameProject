#pragma once

#include "Sequence.h"

struct Sequences
{
private:

	std::map<std::string, Sequence*> sequences;
	std::string currentSequenceName;

public:
	~Sequences();

	void clear();
	sf::IntRect getCurrentFrame();
	size_t getFramesNumberOfCurrentSequence();
	void nextFrame();
	void setCurrentSequence(const std::string& sequenceID);
	void createSequenceAndSetAsCurrent(const std::string& sequenceID);
	void addFrameToCurrentSequence(sf::IntRect frameRect);
private:

	Sequence* GetCurrentSequence();
	void IsFrameCorrect(sf::IntRect frameRect);
};
