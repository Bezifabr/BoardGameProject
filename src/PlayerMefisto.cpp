#include "PlayerMefisto.h"

PlayerMefisto::PlayerMefisto(int location, int waypoint)
{
	SetID("P_Mefisto");
	SetName("Mefisto");
	SetLevel(1);
	SetMaximumHealthPoints(100);
	SetMaximumSpellFuel(100);

	SetLocation(location);
	SetWaypoint(waypoint);

	SetExperience(0);
	SetExperienceToNextLevel(100);

	GetStats().SetStatistic("Strength", 10);
	GetStats().SetStatistic("Agility", 10);
	GetStats().SetStatistic("WillPower", 10);
	GetStats().SetStatistic("Speed", 10);
	GetStats().SetStatistic("Endurance", 10);
	GetStats().SetStatistic("Intelligence", 10);

	GetArmorType().SetArmor("CuttingArmor", 10);
	GetArmorType().SetArmor("CrushingArmor", 10);
	GetArmorType().SetArmor("MagicalArmor", 10);
	GetArmorType().SetArmor("PiercingArmor", 10);

	assert(texture.loadFromFile("Graphics/NPC/P_Mefisto.png"));
	setTexture(texture);
}
