#pragma once
#include <map>

struct CharacterStats
{
	int GetStatistic(const std::string& key);
	void SetStatistic(const std::string& key, int valueOfStat);
private:
	std::map<std::string, int> statistics;
};