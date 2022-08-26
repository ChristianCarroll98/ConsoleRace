#pragma once
#include "Vehicle.h"
class Tank :
	public Vehicle
{
public:
	Tank(std::string vehicleName);

	std::string randomEvent();
	std::string crash();
	std::string fillGas();
	std::string treadRepair();
};

