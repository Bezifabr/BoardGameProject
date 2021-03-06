#ifndef FRAMES_H
#define FRAMES_H

#include "DrawableObject.h"
#include <vector>

struct Frames
{
	void clear();
	void push(sf::IntRect frameRect);
	sf::IntRect getElement(int currentFrame);
	size_t size();

private:
	std::vector<sf::IntRect>& GetFrames();

	std::vector<sf::IntRect> frames;
};

#endif // !FRAMES_H