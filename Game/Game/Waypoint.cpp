#include "Waypoint.h"

Waypoint::Waypoint()
{
	SetLayer(1);
	SetLocation(1);
}

void Waypoint::GetDataFromString(const std::string & command, const std::string & value)
{
	assert(!command.empty());
	assert(!value.empty());
	cout << command << " = " << value << endl;

	if (command == "Pos_x")
		SetPosition(sf::Vector2f(stof(value), GetPosition().y));
	else if (command == "Pos_y")
		SetPosition(sf::Vector2f(GetPosition().x, stof(value)));
	else if (command == "FirstTrack" || command == "SecondTrack")//TODO: Change commands names in editor
		AddNextTrackChoice(stoi(value));
	else if (command == "Track")
		SetTrack(stoi(value));
	else if (command == "NextLocation")
		SetNextLocation(stoi(value));
	else if (command == "LocationEntrance")
		IsLocationEntrance(value);
	else if (command == "NextTrack")
		SetNextTrack(stoi(value));
}

sf::Vector2f Waypoint::GetPosition()
{
	return sprite.getPosition();
}

void Waypoint::SetPosition(sf::Vector2f point)
{
	sprite.setPosition(point);
}

void Waypoint::SetTexture(sf::Texture & texture)
{
	sprite.setTexture(texture);
}

void Waypoint::AddNextTrackChoice(int trackID)
{
	assert(trackID >= 0);
	assert(tracksChoices.size() <= 2);
	tracksChoices.push_back(trackID);
}

void Waypoint::CheckIfCanChooseTrackAndSetItTrue()
{
	if (tracksChoices.size() >= 2)
		isChoosingTrack = true;
}

int Waypoint::GetNextTrack(int choiceNumber)
{
	assert(choiceNumber > 0);
	assert(choiceNumber <= 2);
	assert(tracksChoices[choiceNumber] >= 0);
	return tracksChoices[choiceNumber];
}

void Waypoint::SetTrack(int trackID)
{
	assert(trackID >= 0);
	track = trackID;
}

int Waypoint::GetTrack()
{
	assert(track >= 0);
	return track;
}

void Waypoint::SetNextLocation(int nextLocation)
{
	assert(nextLocation >= 0);
	this->nextLocation = nextLocation;
}

int Waypoint::GetNextLocation()
{
	assert(nextLocation >= 0);
	return nextLocation;
}

void Waypoint::IsLocationEntrance(bool value)
{
	isLocationEntrance = value;
}

void Waypoint::IsLocationEntrance(std::string value)
{
	if (value == "true" || value == "TRUE" || value == "1")
		IsLocationEntrance(true);
	else
		IsLocationEntrance(false);
}

bool Waypoint::IsLocationEntrance()
{
	if (isLocationEntrance == true)
		return true;
	else if (isLocationEntrance == false)
		return false;
}

void Waypoint::SetNextTrack(int trackID)
{
	assert(trackID >= 0);
	nextTrack = trackID;
}

int Waypoint::GetNextTrack()
{
	assert(nextTrack >= 0);
	return nextTrack;
}
