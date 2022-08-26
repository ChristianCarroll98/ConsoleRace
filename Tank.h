#pragma once
#include "Vehicle.h"
class Tank :
	public Vehicle
{
public:
	Tank();//std::mutex* mutex);

	std::string randomEvent();
	std::string crash();
	std::string fillGas();
	std::string treadRepair();
};

