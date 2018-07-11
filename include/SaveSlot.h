#ifndef SAVE_SLOT_H
#define SAVE_SLOT_H

#include "Slot.h"
#include "CustomText.h"
#include <SFML/Graphics.hpp>

class SaveSlot : public Slot, public InterfaceObject
{
	const char* sourceOfSavedFile;
	sf::Texture lastGameFrameTexture;
	sf::RectangleShape background;
public:
	void SetEmpty();

	void SetPosition(sf::Vector2f position);

	void SetSourceOfSavedFile(const char* source);

	void SetLastGameFrame(sf::Image& screenshot);

	const char* GetSourceOfSavedFile();
};

#endif // !SAVE_SLOT_H