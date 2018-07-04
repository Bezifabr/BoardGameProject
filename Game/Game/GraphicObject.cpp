#include "GraphicObject.h"

sf::IntRect GraphicObject::GetTextureRect()
{
	return sprite.getTextureRect();
}

void GraphicObject::SetTextureRect(const sf::IntRect & rectangle)
{
	return sprite.setTextureRect(rectangle);
}

GraphicObject::GraphicObject()
{
	SetLayer(1);
	SetLocation(1);
}

void GraphicObject::Move(const sf::Vector2f & offset)
{
	sprite.move(offset);
}

void GraphicObject::SetPosition(const sf::Vector2f & position)
{
	sprite.setPosition(position);
}

void GraphicObject::SetRotation(float angle)
{
	if (angle > 360)
		sprite.setRotation(360);
	else if (angle < 0)
		sprite.setRotation(0);
	else
		sprite.setRotation(angle);
}

void GraphicObject::Rotate(float angle)
{
	sprite.rotate(angle);
}

void GraphicObject::SetTexture(const sf::Texture & texture)
{
	sprite.setTexture(texture);
}
