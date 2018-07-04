#include "Skill.h"

sf::Drawable & Skill::GetDrawable()
{
	return icon;
}

bool Skill::IsUsable()
{
	return isUsable;
}

void Skill::IsUsable(bool isUsable)
{
	this->isUsable = isUsable;
}

bool Skill::IsUsableOnTarget()
{
	return isUsableOnTarget;
}

void Skill::IsUsableOnTarget(bool isUsable)
{
	isUsableOnTarget = isUsable;
}

bool Skill::IsUsableImmediately()
{
	return isUsableImmediately;
}

void Skill::IsUsableImmediately(bool isUsable)
{
	isUsableImmediately = isUsable;
}

bool Skill::IsTargetingAlly()
{
	return isTargetingAlly;
}

void Skill::IsTargetingAlly(bool isTargeting)
{
	isTargetingAlly = isTargeting;
}

bool Skill::IsTargetingEnemy()
{
	return isTargetingEnemy;
}

void Skill::IsTargetingEnemy(bool isTargeting)
{
	isTargetingEnemy = isTargeting;
}

bool Skill::IsTargetingSelf()
{
	return isTargetingSelf;
}

void Skill::IsTargetingSelf(bool isTargeting)
{
	isTargetingSelf = isTargeting;
}

void Skill::SetTimeOfCooldown(int time)
{
	timeOfCooldown = time;
}

int Skill::GetTimeOfCooldown()
{
	return timeOfCooldown;
}

void Skill::SetIconTexture(sf::Texture & texture)
{
	icon.setTexture(texture);
}

void Skill::SetDescription(const string & description)
{
	this->description = description;
}

const string & Skill::GetDescription()
{
	return description;
}

void Skill::SetName(const string & name)
{
	this->name = name;
}

const string & Skill::GetName()
{
	return name;
}

void Skill::SetID(const string & id)
{
	this->id = id;
}

const string & Skill::GetID()
{
	return id;
}
