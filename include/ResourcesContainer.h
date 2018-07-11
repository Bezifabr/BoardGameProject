#ifndef RESOURCES_CONTAINER_H
#define RESOURCES_CONTAINER_H

#include <string>
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <assert.h>

using namespace std;

class ResourcesContainer
{
	sf::SoundBuffer tempSoundBuffer;

	std::map<string, sf::Texture> textures;
	std::map<string, sf::Sound>	 sounds;
public:

	void LoadTexture(const string& ID, const string& source);
	void LoadSound(const string& ID, const string& source);
	sf::Texture& GetTexture(const string& ID);
	sf::Sound& GetSound(const string& ID);

	void Clear();
};

#endif // !RESOURCES_CONTAINER_H