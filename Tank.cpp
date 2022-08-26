#include "Tank.h"

Tank::Tank()// std::mutex* mutex) :Vehicle(mutex)
{
	this->setSpeed(6);
	this->setVehicleName("Tank");
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
	return "Tank crashes. It smashes whatever was in its path.";
}

std::string Tank::fillGas()
{
	this->addDelay(30);
	return "Tank fills gas.";
}

std::string Tank::treadRepair()
{
	this->addDelay(45);
	return "Tank crew repairs treads.";
}

