#include "Sequence.h"

Sequence::~Sequence()
{
	frames.clear();
}

void Sequence::AddFrame(sf::IntRect frameRect)
{
	assert(frameRect.top >= 0 && frameRect.left >= 0 && frameRect.height >= 0 && frameRect.width >= 0);
	frames.push(frameRect);
}

size_t Sequence::GetFramesNumber()
{
	return frames.size();
}

sf::IntRect & Sequence::GetCurrentFrame()
{
	assert(currentFrame >= 0);
	return frames.getElement(currentFrame);
}

void Sequence::NextFrame()
{
	if (currentFrame < frames.size() - 1)
		currentFrame++;
}

void Sequence::ResetCurrentFrame()
{
	currentFrame = 0;
}
