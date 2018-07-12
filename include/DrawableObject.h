#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include "GameWindowsBuilder.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class DrawableObject
{
	uint8_t layer;
	uint8_t location;

protected:
	sf::Sprite sprite;
public:
	virtual ~DrawableObject() {};
	
	virtual sf::Drawable& GetDrawable();

	void SetLayer(uint8_t layer);
	uint8_t GetLayer();

	void SetLocation(const uint8_t &location);
	uint8_t GetLocation();

	sf::FloatRect GetFloatRect();
};

#endif // !DRAWABLE_OBJECT_H