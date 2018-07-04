#include "CharactersStatistics.h"

int CharacterStats::GetStatistic(const std::string & key)
{
	if (statistics.count(key) == 1)
		return statistics[key];
}

void CharacterStats::SetStatistic(const std::string & key, int valueOfStat)
{
	statistics[key] = valueOfStat;
	if (valueOfStat < 0)
		statistics[key] = 0;
}
