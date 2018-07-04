#include "Slot.h"

bool Slot::IsOccupied()
{
	return isOccupied;
}

void Slot::IsOccupied(bool isOccupied)
{
	this->isOccupied = isOccupied;
}
