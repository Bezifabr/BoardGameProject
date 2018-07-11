#ifndef CHARACTER_ARMOR_TYPE_H
#define CHARACTER_ARMOR_TYPE_H

#include <map>

struct ArmorType
{
	int GetArmor(const std::string& key);
	void SetArmor(const std::string& key, int valueOfArmor);
private:
	std::map<std::string, int> armors;
};

#endif // !CHARACTER_ARMOR_TYPE_H