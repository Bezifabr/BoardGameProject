#include "CharactersArmorType.h"

int ArmorType::GetArmor(const std::string & key)
{
	if (armors.count(key) == 1)
		return armors[key];
}

void ArmorType::SetArmor(const std::string & key, int valueOfArmor)
{
	armors[key] = valueOfArmor;
	if (valueOfArmor < 0)
		armors[key] = 0;
}
