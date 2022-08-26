#include "PickupTruck.h"

PickupTruck::PickupTruck(std::string vehicleName) : Vehicle(vehicleName)
{
    this->setSpeed(8);
}

std::string PickupTruck::randomEvent()
{
    int randomEvent = rand() % 5;
    if (randomEvent == 0) return this->crash();
    if (randomEvent >= 1 && randomEvent < 4) return this->fillGas();
    if (randomEvent == 4) return this->stopForBeer();
}

std::string PickupTruck::crash()
{
    this->addDelay(30);
    this->setSpeed(std::max(5, this->getSpeed() - 1));
    if (this->getSpeed() > 5)
        return this->getVehicleName() + " crashes. Loses some speed.";
    return this->getVehicleName() + " crashes. It's as slow as it's going to get.";
}

std::string PickupTruck::fillGas()
{
    this->addDelay(20);
    return Vehicle::fillGas();
}

std::string PickupTruck::stopForBeer()
{
    this->addDelay(75);
    return this->getVehicleName() + "'s driver stops for a beer.";
}
