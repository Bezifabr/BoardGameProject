#ifndef CHARACTERS_ITEMS_H
#define CHARACTERS_ITEMS_H

#include <map>
#include "Item.h"

struct CharacterItems
{
	void AddItem(int slotNumber, Item* item);
	void RemoveItem(int slotNumber);
	Item* GetItem(int slotNumber);

	void AddLootItem(int slotNumber, Item* item);
	void RemoveLootItem(int slotNumber);
	Item* GetLootItem(int slotNumber);

	void SetLootChance(int slotNumber, float chance);
	float GetLootChance(int slotNumber);
	void RemoveLootChance(int slotNumber);

private:
	std::map<int, Item*> items;
	std::map<int, Item*> lootItems;
	std::map<int, float> lootChance;
};

#endif // !CHARACTERS_ITEMS_H