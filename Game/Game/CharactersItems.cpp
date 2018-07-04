#include "CharactersItems.h"

void CharacterItems::AddItem(int slotNumber, Item * item)
{
	if (items.count(slotNumber) == 0 && slotNumber >= 0)
		items[slotNumber] = item;
}

void CharacterItems::RemoveItem(int slotNumber)
{
	if (items.count(slotNumber) == 1)
	{
		auto itr = items.begin();
		for (int i = 0; i != slotNumber; i++)
			itr++;
		items.erase(itr);
	}
}

Item * CharacterItems::GetItem(int slotNumber)
{
	if (items.count(slotNumber) == 1)
		return items[slotNumber];
}

void CharacterItems::AddLootItem(int slotNumber, Item * item)
{
	if (slotNumber >= 0)
		if (lootItems.count(slotNumber) == 0 && lootChance.count(slotNumber) == 0)
		{
			lootItems[slotNumber] = item;
			lootChance[slotNumber] = 100;
		}
}

void CharacterItems::RemoveLootItem(int slotNumber)
{
	if (lootItems.count(slotNumber) == 1)
	{
		auto itr = lootItems.begin();
		for (int i = 0; i != slotNumber; i++) itr++;
		lootItems.erase(itr);
	}
}

Item * CharacterItems::GetLootItem(int slotNumber)
{
	if (lootItems.count(slotNumber) == 1)
		return lootItems[slotNumber];
}

void CharacterItems::SetLootChance(int slotNumber, float chance)
{
	if (lootChance.count(slotNumber) == 0 && slotNumber >= 0)
	{
		lootChance[slotNumber] = chance;
		if (chance > 100)
			lootChance[slotNumber] = 100;
		if (chance < 0)
			lootChance[slotNumber] = 0;
	}
}

float CharacterItems::GetLootChance(int slotNumber)
{
	if (lootChance.count(slotNumber) == 1)
		return lootChance[slotNumber];
}

void CharacterItems::RemoveLootChance(int slotNumber)
{
	if (lootChance.count(slotNumber) == 1)
	{
		auto itr = lootChance.begin();
		for (int i = 0; i != slotNumber; i++) itr;
		lootChance.erase(itr);
	}
}
