#ifndef GRAPHIC_OBJECT_H
#define GRAPHIC_OBJECT_H

#include "AnimatedObject.h"

class GraphicObject : public AnimatedObject
{
protected:

	sf::IntRect GetTextureRect();;

	void SetTextureRect(const sf::IntRect& rectangle);

public:

	GraphicObject();

	virtual ~GraphicObject() {};

	void Move(const sf::Vector2f &offset);
	void SetPosition(const sf::Vector2f &position);
	void SetRotation(float angle);
	void Rotate(float angle);

	void SetTexture(const sf::Texture& texture);

private:
};

#endif // !GRAPHIC_OBJECT_H