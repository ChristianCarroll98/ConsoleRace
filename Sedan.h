#pragma once
#include "Vehicle.h"
class Sedan :
    public Vehicle
{
public:
	Sedan();

	std::string randomEvent();
	std::string crash();
	std::string fillGas();
	std::string stuckInMud();
};

