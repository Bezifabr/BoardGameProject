#ifndef CUSTOM_TEXT_H
#define CUSTOM_TEXT_H

#include "InterfaceObject.h"
#include <SFML/Graphics/Text.hpp>

class CustomText : public DrawableObject, public EventObject
{
	sf::Text text;

public:
	CustomText();

	virtual sf::Drawable& GetDrawable();

	void SetString(const std::string& textString);

	void SetPosition(sf::Vector2f position);

	void SetFont(sf::Font& font);

	void SetColor(sf::Color textColor);

	void SetSize(unsigned int characterSize);

	void CreateClickableBox();
	void AlignCenter();
};

#endif // !CUSTOM_TEXT_H