#include "Vehicle.h"

Vehicle::Vehicle()
{
}

Vehicle::~Vehicle()
{
}

void Vehicle::setSpeed(int newSpeed)
{
	this->_baseSpeed = newSpeed;
}

int Vehicle::getSpeed()
{
	return this->_baseSpeed;
}

void Vehicle::addDelay(int delay)
{
	this->_delay = this->_delay + delay;
}

void Vehicle::decrementDelay()
{
	this->_delay -= 1;
}

int Vehicle::getDelay()
{
	return this->_delay;
}

void Vehicle::move(int moveBy)
{
	this->_distance += moveBy;
	//std::cout << this->getVehicleName() << " moves.\n";
}

int Vehicle::getDistance()
{
	return this->_distance;
}

void Vehicle::setVehicleName(std::string newName)
{
	this->_vehicleName = newName;
}

std::string Vehicle::getVehicleName()
{
	return this->_vehicleName;
}

void Vehicle::race(std::mutex* mutex, std::string* leaderName, int* leaderDistance, int* raceDistance)
{
	std::string message = "";
	while (true)
	{

		//give a small delay so it looks cooler and gives the other threads a chance to pick up execution.
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000));

		mutex->lock();
		//check if another vehicle won the race
		if (*leaderDistance >= *raceDistance)
		{
			std::cout << this->getVehicleName() << " lost the race. Distance: " << this->getDistance() << "/" << *raceDistance << "\n";
			mutex->unlock();
			return;
		}
		mutex->unlock();

		

		//do a random event 1/50 of the time.
		if (rand() % 50 == 0 && this->getDelay() <= 0) {
			message = this->randomEvent();
			mutex->lock();
			std::cout << message << " Distance: " << this->getDistance() << "/" << *raceDistance << "\n";
			mutex->unlock();
		}

		if (this->getDelay() > 0)
		{
			this->decrementDelay();
		}
		else {
			
			//critical section
			mutex->lock();

			//std::cout << "leader name: " << *leaderName << ", leader distance: " << *leaderDistance << "\n";

			this->move(this->getSpeed());

			//std::cout << this->getVehicleName() << "'s Distance: " << this->getDistance() << "/" << *raceDistance << "\n";

			//std::cout << "race step\n";
			
			// surpassed the leader
			if (this->getDistance() > *leaderDistance)
			{
				if (*leaderName != this->getVehicleName())
				{
					std::cout << this->getVehicleName() << " takes the lead! Distance: " << this->getDistance() << "/" << *raceDistance << "\n";
				}
				*leaderName = this->getVehicleName();
				*leaderDistance = this->getDistance();
				
			}

			//check if it won
			if (this->getDistance() >= *raceDistance)
			{
				std::cout << this->getVehicleName() << " wins the race!\n";
				mutex->unlock();
				return;
			}

			mutex->unlock();
		}
	}
	/*int i = 0;
	while (true) {
		mutex->lock();
		std::cout << "test, " << this->getVehicleName() << "\n";
		mutex->unlock();
		i++;
		if (i >= 100) return;
	}*/
	return;
}