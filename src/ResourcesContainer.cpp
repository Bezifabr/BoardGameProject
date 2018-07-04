#include "ResourcesContainer.h"

void ResourcesContainer::LoadTexture(const string & ID, const string & source)
{
	assert(textures[ID].loadFromFile(source));
}

void ResourcesContainer::LoadSound(const string & ID, const string & source)
{
	assert(tempSoundBuffer.loadFromFile(source));
	sounds[ID].setBuffer(tempSoundBuffer);
}

sf::Texture & ResourcesContainer::GetTexture(const string & ID)
{
	assert(textures.count(ID) == 1);
	return textures[ID];
}

sf::Sound & ResourcesContainer::GetSound(const string & ID)
{
	assert(sounds.count(ID) == 1);
	return sounds[ID];
}

void ResourcesContainer::Clear()
{
	sounds.clear();
	textures.clear();
}
