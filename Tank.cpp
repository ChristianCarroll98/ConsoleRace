#include "Tank.h"

Tank::Tank(std::string vehicleName) : Vehicle(vehicleName)
{
	this->setSpeed(6);
}

std::string Tank::randomEvent()
{
	int randomEvent = rand() % 5;
	if (randomEvent == 0) return this->fillGas();
	if (randomEvent >= 1 && randomEvent < 4) return this->crash();
	if (randomEvent == 4) return this->treadRepair();
}

std::string Tank::crash()
{
	this->addDelay(20);
	return this->getVehicleName() + " crashes. It smashes whatever was in its path.";
}

std::string Tank::fillGas()
{
	this->addDelay(30);
	return Vehicle::fillGas();
}

std::string Tank::treadRepair()
{
	this->addDelay(60);
	return this->getVehicleName() + " crew repairs treads.";
}

