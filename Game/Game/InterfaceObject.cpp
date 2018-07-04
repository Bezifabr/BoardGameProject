#include "InterfaceObject.h"

InterfaceObject::InterfaceObject()
{
	TurnOn(true);
}

void InterfaceObject::SetPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
	UpdateBox(position);
}

void InterfaceObject::SetTexture(sf::Texture & texture)
{
	normalTexture = texture;
	sprite.setTexture(texture);
	SetClickableBox(sprite.getGlobalBounds());
}

void InterfaceObject::SetActivatedTexture(sf::Texture & texture)
{
	activatedTexture = texture;
}

void InterfaceObject::Activate(bool activate)
{
	IsActivated(activate);
	if (activate)
		sprite.setTexture(activatedTexture);
	else
		sprite.setTexture(normalTexture);
}

void InterfaceObject::CreateClickableBox()
{
	SetClickableBox(sprite.getGlobalBounds());
}
