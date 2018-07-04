#include "GameLoadingSystem.h"

LoadingSystem::~LoadingSystem()
{
	assert(gameDataContainer);
	gameDataContainer = nullptr;
	assert(!gameDataContainer);

	assert(resourcesContainer);
	resourcesContainer = nullptr;
	assert(!resourcesContainer);
}

void LoadingSystem::AppendDataContainer(GameDataContainer * gameDataContainer)
{
	this->gameDataContainer = gameDataContainer;
	assert(gameDataContainer);
}

void LoadingSystem::AppendResourcesContainer(ResourcesContainer * resourcesContainer)
{
	this->resourcesContainer = resourcesContainer;
	assert(resourcesContainer);
}

void LoadingSystem::LoadMap(const char * source)
{
	assert(gameDataContainer);
	assert(resourcesContainer);

	LoadResourcesFromFile(source);

	std::ifstream openfile(source);
	if (openfile.is_open())
	{
		gameDataContainer->Clear();
		std::string tempType;

		while (!openfile.eof())
		{
			std::string line;
			std::getline(openfile, line); //< Load line
			line.erase(std::remove(line.begin(), line.end(), ' '), line.end()); //< Remove spaces from line

			if (line.find("//") != std::string::npos)
				line.erase(line.begin(), line.end());

			else if (line.find("Place{") != std::string::npos)
			{
				tempType = "Place";
				line.erase(line.begin(), line.end());
			}

			else if (line.find("NPC{") != std::string::npos)
			{
				tempType = "NPC";
				line.erase(line.begin(), line.end());
			}

			else if (line.find("Locations=") != std::string::npos)
				tempType = "Locations";
			else if (line.find("Location[") != std::string::npos)
				tempType = "Location";
			else if (line.find("Settings{") != std::string::npos)
				tempType = "Settings";

			else if (line.find('}') != std::string::npos)
			{
				line.erase(std::remove(line.begin(), line.end(), '}' + 1), line.end());
				std::cout << " Type(" << tempType << ")" << std::endl;

				if (tempType == "Place")
				{
					tempWaypoint.SetLocation(currentLocation);
					gameDataContainer->AddWaypoint(new Waypoint(tempWaypoint));
				}

				if (tempType == "NPC")
				{
					tempNPC.SetLocation(currentLocation);
					gameDataContainer->AddCharacter(new Character(tempNPC));
				}

				line.erase(line.begin(), line.end());
			}

			else if (line.find(']') != string::npos)
			{
				gameDataContainer->SetCameraPosition(currentLocation, tempCameraPosition);
				gameDataContainer->SetLocationBackground(currentLocation, tempBackground);
				gameDataContainer->SetLocationIsBackgroundLoaded(currentLocation, isBackgroundLoaded);

				isBackgroundLoaded = false;

				line.erase(line.begin(), line.end());
			}

			std::stringstream stream(line);

			if (tempType == "Place")
				CallWaypointCommand(stream);

			if (tempType == "NPC")
				CallCharacterCommand(stream);

			/*
			if (tempType == "NPC")
			else if (line.find("Role=") != std::string::npos || line.find("role=") != std::string::npos)
			{
			line.erase(0, line.find('=') + 1);
			tempNPC.SetRole(line);
			std::cout << "Role(" << line << ")" << std::endl;
			}
			else if (line.find("SpellFuelType=") != std::string::npos || line.find("spellfueltype=") != std::string::npos)
			{
			line.erase(0, line.find('=') + 1);
			tempNPC.SetSpellFuelType(line);
			std::cout << "SpellFuelType(" << line << ")" << std::endl;
			}
			else if (line.find("Spell=") != std::string::npos || line.find("spell=") != std::string::npos)
			{
			line.erase(0, line.find('=') + 1);
			tempNPC.AddSpell(line);
			std::cout << "Spell(" << line << ")" << std::endl;
			}

			else if (line.find("Item=") != std::string::npos || line.find("item=") != std::string::npos)
			{
			line.erase(0, line.find('=') + 1);
			tempNPC.AddItem(line);
			std::cout << "Item(" << line << ")" << std::endl;
			}
			else if (line.find("Loot=") != std::string::npos || line.find("loot=") != std::string::npos)
			{
			line.erase(0, line.find('=') + 1);
			tempNPC.AddLoot(line);
			std::cout << "Loot(" << line << ")" << std::endl;
			}
			else if (line.find("LootChance=") != std::string::npos || line.find("lootchance=") != std::string::npos)
			{
			line.erase(0, line.find('=') + 1);
			tempNPC.AddLootChance(atoi(line.c_str()));
			std::cout << "ChanceOfLoot(" << line << ")" << std::endl;
			}
			*/
			if (tempType == "Settings")
				if (line.find("Camera_x=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempCameraPosition.x = stof(line);
					std::cout << "Camera_x(" << tempCameraPosition.x << ")" << std::endl;
				}
				else if (line.find("Camera_y=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempCameraPosition.y = stof(line);
					std::cout << "Camera_y(" << tempCameraPosition.y << ")" << std::endl;
				}
				else if (line.find("Background=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);

					tempBackground = resourcesContainer->GetTexture(line);
					isBackgroundLoaded = true;
					std::cout << "Background(" << line << ")" << std::endl;
				}

			if (tempType == "Locations")
			{
				line.erase(0, line.find('=') + 1);

				std::stringstream str(line);

				while (str)
				{
					std::getline(str, line, ',');
					if (line != "")
					{
						locations.push_back(line);
						line.erase(std::remove(line.begin(), line.end(), ',' + 1), line.end());
					}
				}
			}

			if (tempType == "Location")
			{
				line.erase(0, line.find('[') + 1);
				currentLocation = ConvertLocationNameToLocationNumber(line);
			}
		}
	}
}

int LoadingSystem::ConvertLocationNameToLocationNumber(const string & locationName)
{
	for (int i = 0; i < locations.size(); i++)
		if (locations[i] == locationName)
			return i;
	assert(locations[0] == locationName);
	return 0;
}

void LoadingSystem::CallWaypointCommand(std::stringstream & stream)
{
	string command[2];
	for (int i = 0; i < 2; i++)
		getline(stream, command[i], '=');

	if (!command[0].empty() && !command[1].empty())
	{
		if (command[0] == "Texture")
			tempWaypoint.SetTexture(resourcesContainer->GetTexture(command[1]));
		else
			tempWaypoint.GetDataFromString(command[0], command[1]);
	}
}

void LoadingSystem::CallCharacterCommand(std::stringstream & stream)
{
	string command[3];
	for (int i = 0; i < 3; i++)
		getline(stream, command[i], '=');

	if (!command[0].empty() && !command[1].empty())
	{
		if (command[0] == "Texture")
			tempNPC.setTexture(resourcesContainer->GetTexture(command[1]));
		else
			tempNPC.GetDataFromString(command[0], command[1], command[2]);
	}
}

void LoadingSystem::LoadResourcesFromFile(const char * source)
{
	std::ifstream openfile(source);
	if (openfile.is_open())
	{
		std::string tempType;
		std::string tempName;
		std::string tempSource;
		while (!openfile.eof())
		{
			assert(resourcesContainer);

			std::string line;

			std::getline(openfile, line); //< Load line

			line.erase(std::remove(line.begin(), line.end(), ' '), line.end()); //< Remove spaces from line

			if (line.find("//") != std::string::npos)
				line.erase(line.begin(), line.end());

			else if (line.find("Texture{") != std::string::npos)
				tempType = "Texture";
			else if (line.find("Sound{") != std::string::npos)
				tempType = "Sound";

			if (tempType == "Texture" || tempType == "Sound")
				if (line.find("Name=") != std::string::npos || line.find("name=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempName = line;
					std::cout << "Name(" << line << ")" << std::endl;
				}
				else if (line.find("Source=") != std::string::npos || line.find("source=") != std::string::npos)
				{
					line.erase(0, line.find('=') + 1);
					tempSource = line;
					std::cout << "Source(" << line << ")" << std::endl;
				}

			if (line.find('}') != std::string::npos)
			{
				line.erase(std::remove(line.begin(), line.end(), '}' + 1), line.end());
				std::cout << " Type(" << tempType << ")" << std::endl;
				if (tempType == "Texture")
					resourcesContainer->LoadTexture(tempName, tempSource);
				else if (tempType == "Sound")
					resourcesContainer->LoadSound(tempName, tempSource);

				tempName = "";
				tempSource = "";
				tempType = "";
			}
		}
	}
}
