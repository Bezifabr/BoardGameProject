#include "CustomText.h"

CustomText::CustomText()
{
	SetLocation(0);
	SetLayer(1);
	SetColor(sf::Color::White);
}

sf::Drawable & CustomText::GetDrawable()
{
	return text;
}

void CustomText::SetString(const std::string & textString)
{
	assert(!textString.empty());
	text.setString(textString);
	SetClickableBox(text.getGlobalBounds());
}

void CustomText::SetPosition(sf::Vector2f position)
{
	text.setPosition(position);
	UpdateBox(position);
}

void CustomText::SetFont(sf::Font & font)
{
	text.setFont(font);
	SetClickableBox(text.getGlobalBounds());
}

void CustomText::SetColor(sf::Color textColor)
{
//	text.setColor(textColor);
}

void CustomText::SetSize(unsigned int characterSize)
{
	text.setCharacterSize(characterSize);
}

void CustomText::CreateClickableBox()
{
	SetClickableBox(text.getGlobalBounds());
}

void CustomText::AlignCenter()
{
	text.setPosition(text.getPosition().x - text.getGlobalBounds().width / 2, text.getPosition().y);
	CreateClickableBox();
}
