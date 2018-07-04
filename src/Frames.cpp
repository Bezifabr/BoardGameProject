#include "Frames.h"

void Frames::clear()
{
	GetFrames().clear();
}

void Frames::push(sf::IntRect frameRect)
{
	GetFrames().push_back(frameRect);
}

sf::IntRect Frames::getElement(int currentFrame)
{
	return GetFrames()[currentFrame];
}

size_t Frames::size()
{
	return GetFrames().size();
}

std::vector<sf::IntRect>& Frames::GetFrames()
{
	assert(!frames.empty());
	return frames;
}
