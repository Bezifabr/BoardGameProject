#pragma once

#include "GraphicObject.h"
#include "EventObject.h"

class InterfaceObject : public GraphicObject, public EventObject
{
	sf::Texture normalTexture;
	sf::Texture activatedTexture;

public:
	InterfaceObject();

	virtual ~InterfaceObject() {};

	void SetPosition(sf::Vector2f position);

	void SetTexture(sf::Texture& texture);

	void SetActivatedTexture(sf::Texture& texture);
	void Activate(bool activate);

	void CreateClickableBox();
};