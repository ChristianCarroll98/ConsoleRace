// ConsoleRace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include "Sedan.h"
#include "Tank.h"

int main()
{
    srand(time(NULL));

    int *raceDistance = new int(5000);

    std::string *leaderName = new std::string("");
    int *leaderDistance = new int(0);

    std::mutex *mutex = new std::mutex();

    Sedan *sedan = new Sedan();
    Tank* tank = new Tank();

    std::cout << "before threads start.\n";

    std::thread sedanThread(&Sedan::race, sedan, std::ref(mutex), std::ref(leaderName), std::ref(leaderDistance), std::ref(raceDistance));
    std::thread tankThread(&Tank::race, tank, std::ref(mutex), std::ref(leaderName), std::ref(leaderDistance), std::ref(raceDistance));

    std::cout << "after threads start.\n";

    //std::cout << "sedan thread id: " << sedanThread.get_id() << ", joinable:" << sedanThread.joinable() << "\n";
    //std::cout << "tank thread id: " << tankThread.get_id() << ", joinable:" << tankThread.joinable() << "\n";

    sedanThread.join();
    tankThread.join();

    std::cout << "after threads join.\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
