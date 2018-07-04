#pragma once

#include "Waypoint.h"

class Skill : public InterfaceObject
{
	string id;
	string name;
	string description;
	sf::Sprite icon;

	int timeOfCooldown;

	bool isTargetingSelf;
	bool isTargetingEnemy;
	bool isTargetingAlly;

	bool isUsableImmediately;
	bool isUsableOnTarget;
	bool isUsable;
public:
	virtual ~Skill() {};

	virtual sf::Drawable& GetDrawable();

	bool IsUsable();
	void IsUsable(bool isUsable);

	bool IsUsableOnTarget();
	void IsUsableOnTarget(bool isUsable);
	bool IsUsableImmediately();
	void IsUsableImmediately(bool isUsable);

	bool IsTargetingAlly();
	void IsTargetingAlly(bool isTargeting);
	bool IsTargetingEnemy();
	void IsTargetingEnemy(bool isTargeting);
	bool IsTargetingSelf();
	void IsTargetingSelf(bool isTargeting);

	void SetTimeOfCooldown(int time);
	int GetTimeOfCooldown();

	void SetIconTexture(sf::Texture& texture);

	void SetDescription(const string& description);
	const string& GetDescription();

	void SetName(const string& name);
	const string& GetName();

	void SetID(const string& id);
	const string& GetID();
};