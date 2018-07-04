#include "SaveSlot.h"

void SaveSlot::SetEmpty()
{
	assert(lastGameFrameTexture.loadFromFile(SAVE_SLOT_EMPTY));
	sprite.setTexture(lastGameFrameTexture);
}

void SaveSlot::SetPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void SaveSlot::SetSourceOfSavedFile(const char * source)
{
	sourceOfSavedFile = source;
}

void SaveSlot::SetLastGameFrame(sf::Image & screenshot)
{
	lastGameFrameTexture.loadFromImage(screenshot);
	sprite.setTexture(lastGameFrameTexture);
	sprite.setScale(0.1f, 0.1f);
}

const char * SaveSlot::GetSourceOfSavedFile()
{
	return sourceOfSavedFile;
}
