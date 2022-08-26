// ConsoleRace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include "Sedan.h"
#include "Tank.h"
#include "PickupTruck.h"
#include "Motorcycle.h"

int main()
{
    srand(time(NULL));

    //These variables are shared between all of the threads, passed in my reference.

    // The distance the vehicles need to travel to complete the "race"
    int *raceDistance = new int(10000);

    std::string *leaderName = new std::string("");
    int *leaderDistance = new int(0);

    std::mutex *mutex = new std::mutex();


    // Create the objects for each vehicle

    Sedan *sedan = new Sedan("Honda Accord");
    Tank* tank = new Tank("M5 Light Tank");
    PickupTruck* pickupTruck = new PickupTruck("Ford F150");
    Motorcycle* motorcycle = new Motorcycle("BMW R1200GS Dual-Sport Motorcycle");

    std::cout << "before threads start.\n";

    //Run the threads for each vehicle

    std::thread sedanThread(&Sedan::race, sedan, std::ref(mutex), std::ref(leaderName), std::ref(leaderDistance), std::ref(raceDistance));
    std::thread tankThread(&Tank::race, tank, std::ref(mutex), std::ref(leaderName), std::ref(leaderDistance), std::ref(raceDistance));
    std::thread pickupTruckThread(&PickupTruck::race, pickupTruck, std::ref(mutex), std::ref(leaderName), std::ref(leaderDistance), std::ref(raceDistance));
    std::thread motorcycleThread(&Motorcycle::race, motorcycle, std::ref(mutex), std::ref(leaderName), std::ref(leaderDistance), std::ref(raceDistance));

    std::cout << "after threads start.\n";

    sedanThread.join();
    tankThread.join();
    pickupTruckThread.join();
    motorcycleThread.join();

    std::cout << "after threads join.\n";

    delete raceDistance;
    delete leaderName;
    delete leaderDistance;
    delete mutex;
    delete sedan;
    delete tank;
    delete pickupTruck;
    delete motorcycle;

    return 0;
}