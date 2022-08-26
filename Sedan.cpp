#include "Sedan.h"

Sedan::Sedan()
{
	this->setSpeed(10);
	this->setVehicleName("Sedan");
}

std::string Sedan::randomEvent()
{
	int randomEvent = rand() % 5;
	if (randomEvent == 0) return this->crash();
	if (randomEvent >= 1 && randomEvent < 4) return this->fillGas();
	if (randomEvent == 4) return this->stuckInMud();
}

std::string Sedan::crash()
{
	this->addDelay(40);
	this->setSpeed(std::max(2, this->getSpeed() - 1));
	if (this->getSpeed() > 2) 
		return "Sedan crashes. Loses some speed.";
	return "Sedan crashes. It's as slow as it's going to get.";
}

std::string Sedan::fillGas()
{
	this->addDelay(15);
	return "Sedan fills gas.";
}

std::string Sedan::stuckInMud()
{
	this->addDelay(85);
	return "Sedan gets stuck in some mud.";
}