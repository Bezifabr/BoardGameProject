#ifndef CHARACTER_H
#define CHARACTER_H

#include "CharactersArmorType.h"
#include "CharactersStatistics.h"
#include "CharactersItems.h"

class Character : public AnimatedObject
{
	friend class CharacterMovingSystem;

	sf::Vector2f realPosition;

	int currentWaypoint;

	int level;
	int experience;
	int experienceToNextLevel;

	std::string name;
	std::string id;

	int maximumHealthPoints;
	int healthPoints;

	int maximumSpellFuel;
	int spellFuel;

	CharacterItems items;
	CharacterStats statistics;
	ArmorType armorType;
public:
	Character();

	void SetRealPosition(sf::Vector2f realPosition);
	sf::Vector2f GetRealPosition();

	void GoToNextWaypoint();

	void GetDataFromString(const string& command, const string& value, const string& secondValue);

	void SetWaypoint(int waypoint);
	int GetWaypoint();

	void SetLevel(int level);
	int GetLevel();

	void SetExperience(int experience);
	int GetExperience();
	void SetExperienceToNextLevel(int experience);
	int GetExperienceToNextLevel();

	void SetName(const std::string& name);
	const std::string& GetName();
	void SetID(const std::string& id);
	const std::string& GetID();

	void SetHealthPoints(int health);
	int GetHealthPoints();
	void SetMaximumHealthPoints(int maximumHealth);
	int GetMaximumHealthPoints();

	void SetMaximumSpellFuel(int maximumSpellFuel);
	int GetMaximumSpellFuel();
	void SetSpellFuel(int spellFuel);
	int GetSpellFuel();

	CharacterItems& GetItems();
	CharacterStats& GetStats();
	ArmorType& GetArmorType();

	void setTexture(sf::Texture& texture);
};

#endif // !CHARACTER_H