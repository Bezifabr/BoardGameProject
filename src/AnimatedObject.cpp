#include "AnimatedObject.h"

void AnimatedObject::StartSequence(std::string sequenceName)
{
	sequences.setCurrentSequence(sequenceName);
	isSequencePlaying = true;

	CountTimeBetweenFrames();
	UpdateObjectsFrame();
}

void AnimatedObject::StopSequence()
{
	isSequencePlaying = false;
}

void AnimatedObject::PlaySequence()
{
	assert(timeBetweenFrames > 0.1f);
	if (sequenceTimer.getElapsedTime().asSeconds() >= timeBetweenFrames)
	{
		sequenceTimer.restart();
		NextFrame();
		UpdateObjectsFrame();
	}
}

void AnimatedObject::SetFramesPerSecond(int fps)
{
	if (fps <= 0)
		fps = 1;
	if (fps >= WINDOW_FRAME_RATE_LIMIT)
		fps = 60;
	framesPerSecond = fps;
}

void AnimatedObject::CreateSequenceAndSetAsCurrent(const std::string & sequenceID)
{
	sequences.createSequenceAndSetAsCurrent(sequenceID);
}

void AnimatedObject::AddFrameToCurrentSequence(sf::IntRect frameRect)
{
	sequences.addFrameToCurrentSequence(frameRect);
}

void AnimatedObject::CountTimeBetweenFrames()
{
	assert(framesPerSecond > 0);
	assert(sequences.getFramesNumberOfCurrentSequence() > 0);

	float numberOfFramesInSecond = framesPerSecond / static_cast<float>(sequences.getFramesNumberOfCurrentSequence());
	timeBetweenFrames = 1 / numberOfFramesInSecond;

	assert(timeBetweenFrames > 0.1f);
}

void AnimatedObject::NextFrame()
{
	sequences.nextFrame();
}

void AnimatedObject::UpdateObjectsFrame()
{
	sprite.setTextureRect(sequences.getCurrentFrame());
}
