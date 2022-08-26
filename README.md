# ConsoleRace
A program to showcase some basic C++ development skills, including inheritance, polymorphism, 
multithreading, and inter-process communication.

This program creates four objects, each of a different subclass of the Vehicle class, each
representing a different type of vehicle. Then four threads are started on the "race" method
from each object. These threads use a mutex lock to access the several variables passed
into them by reference including a string for which vehicle is winning, the winning
vehicle's travel distance, and the total distance they must travel. They run functions on
each object which move the vehicle forward or cause a random event to happen which may delay
that vehicle from moving for a certain number of cycles.

Although this would be counter-productive in a real multithreaded application, I have added a small
delay in each loop of the race method's while loop. This is to make sure other threads have an
opportunity to pick up execution, and also to slow down the printing so it looks a little nicer
while running the program.

To run this project, I use Visual Studio Community 2022 with the C++ desktop development package
installed, on Windows 10, however it should work on Windows 11 as well. Simply download the project
files and open the .sln file with Visual Studio Community 2022, then click the play button labeled
"Local Windows Debugger" and the program will compile and run in the console.
