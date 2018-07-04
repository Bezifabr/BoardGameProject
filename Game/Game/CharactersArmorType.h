#pragma once
#include <map>

struct ArmorType
{
	int GetArmor(const std::string& key);
	void SetArmor(const std::string& key, int valueOfArmor);
private:
	std::map<std::string, int> armors;
};
