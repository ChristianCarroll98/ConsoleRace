#include "Motorcycle.h"

Motorcycle::Motorcycle(std::string vehicleName) : Vehicle(vehicleName)
{
	this->setSpeed(15);
}

std::string Motorcycle::randomEvent()
{
	int randomEvent = rand() % 20;
	if (randomEvent >= 0 && randomEvent < 1) return this->crash();
	if (randomEvent >= 1 && randomEvent < 15) return this->fillGas();
	if (randomEvent >= 15 && randomEvent < 20) return this->heavyRain();
}

std::string Motorcycle::crash()
{
	if (this->getSpeed() > 4) {
		this->setSpeed(4);
		this->addDelay(50);
		return this->getVehicleName() + " crashes. The driver is okay somehow but the bike is damaged. Loses speed.";
	}
	this->addDelay(10);
	return this->getVehicleName() + "'s driver narrowly avoids a swerving car.";
}

std::string Motorcycle::fillGas()
{
	this->addDelay(10);
	return Vehicle::fillGas();
}

std::string Motorcycle::heavyRain()
{
	this->addDelay(150);
	return this->getVehicleName() + " takes cover from some heavy rain.";
}