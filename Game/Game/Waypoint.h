#pragma once

#include "SaveSlot.h"

class Waypoint : public DrawableObject
{
	friend class CharacterMovingSystem;

	int id;
	int track;
	vector<int> tracksChoices;
	int nextTrack;
	int nextLocation;

	bool isChoosingTrack;
	bool isChangingLocation;
	bool isChangingTrack;
	bool isLocationEntrance;
public:
	Waypoint();

	void GetDataFromString(const std::string& command, const std::string& value);

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f point);

	void SetTexture(sf::Texture& texture);

	void AddNextTrackChoice(int trackID);

	void CheckIfCanChooseTrackAndSetItTrue();

	int GetNextTrack(int choiceNumber);
	void SetTrack(int trackID);
	int GetTrack();

	void SetNextLocation(int nextLocation);
	int GetNextLocation();
	void IsLocationEntrance(bool value);
	void IsLocationEntrance(std::string value);
	bool IsLocationEntrance();

	void SetNextTrack(int trackID);
	int GetNextTrack();
};