#include "PickupTruck.h"

PickupTruck::PickupTruck()
{
    this->setSpeed(8);
    this->setVehicleName("Pickup Truck");
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
        return "Pickup Truck crashes. Loses some speed.";
    return "Pickup Truck crashes. It's as slow as it's going to get.";
}

std::string PickupTruck::fillGas()
{
    this->addDelay(20);
    return "Pickup Truck fills gas.";
}

std::string PickupTruck::stopForBeer()
{
    this->addDelay(80);
    return "Pickup Truck's driver stops for a beer.";
}
