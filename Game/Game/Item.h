#pragma once

#include "Skill.h"

class Item : public Skill
{
	bool isPermament;

	int amountOfCharges;
	int price;
public:
	virtual ~Item() {};

	bool IsPermament();
	void IsPermament(bool isPermament);

	int GetAmountOfCharges();
	void SetAmountOfCharges(int amountOfCharges);

	int GetPrice();
	void SetPrice(int price);
};
