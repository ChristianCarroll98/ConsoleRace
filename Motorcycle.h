#pragma once
#include "Vehicle.h"
class Motorcycle :
    public Vehicle
{
public:
	Motorcycle(std::string vehicleName);

	std::string randomEvent();
	std::string crash();
	std::string fillGas();
	std::string heavyRain();
};

