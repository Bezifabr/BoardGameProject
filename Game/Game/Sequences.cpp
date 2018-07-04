#include "Sequences.h"

Sequences::~Sequences()
{
	clear();
}

void Sequences::clear()
{
	sequences.clear();
}

sf::IntRect Sequences::getCurrentFrame()
{
	return GetCurrentSequence()->GetCurrentFrame();
}

size_t Sequences::getFramesNumberOfCurrentSequence()
{
	return GetCurrentSequence()->GetFramesNumber();
}

void Sequences::nextFrame()
{
	assert(!sequences.empty());
	assert(sequences[currentSequenceName]);
	GetCurrentSequence()->NextFrame();
}

void Sequences::setCurrentSequence(const std::string & sequenceID)
{
	assert(!sequences.empty());
	assert(sequences.count(sequenceID) == 1);
	currentSequenceName = sequenceID;
}

void Sequences::createSequenceAndSetAsCurrent(const std::string & sequenceID)
{
	sequences[currentSequenceName = sequenceID] = new Sequence;
	assert(!currentSequenceName.empty());
}

void Sequences::addFrameToCurrentSequence(sf::IntRect frameRect)
{
	assert(!sequences.empty());
	assert(sequences[currentSequenceName]);
	IsFrameCorrect(frameRect);
	GetCurrentSequence()->AddFrame(frameRect);
}

Sequence * Sequences::GetCurrentSequence()
{
	return	sequences[currentSequenceName];
}

void Sequences::IsFrameCorrect(sf::IntRect frameRect)
{
	assert(frameRect.top >= 0);
	assert(frameRect.left >= 0);
	assert(frameRect.height >= 0);
	assert(frameRect.width >= 0);
}
