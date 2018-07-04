#include "Item.h"

bool Item::IsPermament()
{
	return isPermament;
}

void Item::IsPermament(bool isPermament)
{
	this->isPermament = isPermament;
}

int Item::GetAmountOfCharges()
{
	return amountOfCharges;
}

void Item::SetAmountOfCharges(int amountOfCharges)
{
	this->amountOfCharges = amountOfCharges;
}

int Item::GetPrice()
{
	return price;
}

void Item::SetPrice(int price)
{
	this->price = price;
}
