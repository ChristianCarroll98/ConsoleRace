#pragma once
#include <string>
#include <mutex>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <iostream>
#include <chrono>

class Vehicle
{
public:

	Vehicle();
	~Vehicle();

	void setSpeed(int newSpeed);
	int getSpeed();

	void addDelay(int delay);
	void decrementDelay();
	int getDelay();

	void move(int moveBy);
	int getDistance();

	void setVehicleName(std::string newName);
	std::string getVehicleName();

	//main function that will be executed by threads
	void race(std::mutex* mutex, std::string* leaderName, int* leaderDistance, int* raceDistance);

	//virtual functions
	virtual std::string randomEvent() = 0;

	//random events shared by all vehicles:
	virtual std::string crash() = 0;
	virtual std::string fillGas() = 0;
	
	
private:

	// data
	int _baseSpeed = 0;
	int _delay = 0;
	int _distance = 0;
	std::string _vehicleName = "";
};

