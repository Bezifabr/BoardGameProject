#include "DrawableObject.h"

sf::Drawable & DrawableObject::GetDrawable()
{
	return sprite;
}

void DrawableObject::SetLayer(uint8_t layer)
{
	assert(layer <= 255);
	assert(layer >= 0);
	if (layer >= MAX_LAYER_NUMBER)
		layer = MAX_LAYER_NUMBER;
	this->layer = layer;
}

void DrawableObject::SetLocation(const uint8_t & location)
{
	assert(location <= 255);
	assert(location >= 0);
	this->location = location;
}

uint8_t DrawableObject::GetLayer()
{
	assert(layer <= 255);
	assert(layer >= 0);
	return layer;
}

uint8_t DrawableObject::GetLocation()
{
	assert(location <= 255);
	assert(location >= 0);
	return location;
}

const sf::FloatRect & DrawableObject::GetFloatRect()
{
	return sprite.getGlobalBounds();
}
