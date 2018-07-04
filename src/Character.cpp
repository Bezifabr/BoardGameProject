#include "Character.h"

Character::Character()
{
	SetLayer(1);
	SetLocation(1);
}

void Character::SetRealPosition(sf::Vector2f realPosition)
{
	this->realPosition = realPosition;
}

sf::Vector2f Character::GetRealPosition()
{
	return realPosition;
}

void Character::GoToNextWaypoint()
{
	SetWaypoint(GetWaypoint() + 1);
}

void Character::GetDataFromString(const string & command, const string & value, const string & secondValue)
{
	assert(!command.empty());
	assert(!value.empty());
	cout << command << " = " << value << ", " << secondValue << endl;

	if (command == "Name")
		SetName(value);
	else if (command == "ID")
		SetID(value);
	else if (command == "Level")
		SetLevel(stoi(value));
	else if (command == "Health")
		SetMaximumHealthPoints(stoi(value));
	else if (command == "SpellFuel")
		SetMaximumSpellFuel(stoi(value));

	else if (command == "Statistic")
		statistics.SetStatistic(value, stoi(secondValue));
	else if (command == "Armor")
		armorType.SetArmor(value, stoi(secondValue));

	else if (command == "PositionWaypoint")
		SetWaypoint(stoi(value));
	else if (command == "PositionLocation")
		SetLocation(stoi(value));

	else if (command == "Loot")
		items.SetLootChance(stoi(value), stof(secondValue));
}

void Character::SetLevel(int level)
{
	this->level = level;
}

int Character::GetLevel()
{
	return level;
}

void Character::SetExperience(int experience)
{
	this->experience = experience;
}

int Character::GetExperience()
{
	return experience;
}

void Character::SetExperienceToNextLevel(int experience)
{
	experienceToNextLevel = experience;
}

int Character::GetExperienceToNextLevel()
{
	return this->experienceToNextLevel;
}

void Character::SetName(const std::string & name)
{
	this->name = name;
}

const std::string & Character::GetName()
{
	return name;
}

void Character::SetID(const std::string & id)
{
	this->id = id;
}

const std::string & Character::GetID()
{
	return id;
}

void Character::SetHealthPoints(int health)
{
	healthPoints = health;
}

int Character::GetHealthPoints()
{
	return healthPoints;
}

void Character::SetMaximumHealthPoints(int maximumHealth)
{
	maximumHealthPoints = maximumHealth;
	if (maximumHealth < 50)
		maximumHealthPoints = 50;
}

int Character::GetMaximumHealthPoints()
{
	return maximumHealthPoints;
}

void Character::SetMaximumSpellFuel(int maximumSpellFuel)
{
	this->maximumSpellFuel = maximumSpellFuel;
	if (maximumSpellFuel < 50)
		this->maximumSpellFuel = 50;
}

int Character::GetMaximumSpellFuel()
{
	return maximumSpellFuel;
}

void Character::SetSpellFuel(int spellFuel)
{
	this->spellFuel = spellFuel;
}

int Character::GetSpellFuel()
{
	return spellFuel;
}

CharacterItems & Character::GetItems()
{
	return items;
}

CharacterStats & Character::GetStats()
{
	return statistics;
}

ArmorType & Character::GetArmorType()
{
	return armorType;
}

void Character::SetWaypoint(int waypoint)
{
	if (waypoint <= 0)
		this->currentWaypoint = 0;
	else
		this->currentWaypoint = waypoint;
}

int Character::GetWaypoint()
{
	return currentWaypoint;
}

void Character::setTexture(sf::Texture & texture)
{
	sprite.setTexture(texture);
}
