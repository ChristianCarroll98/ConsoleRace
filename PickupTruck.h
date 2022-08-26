#pragma once
#include "Vehicle.h"
class PickupTruck :
	public Vehicle
{
public:
	PickupTruck(std::string vehicleName);

	std::string randomEvent();
	std::string crash();
	std::string fillGas();
	std::string stopForBeer();
};

