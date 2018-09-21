/*/
This is a file defining all behaviours initialised in the System_Container class definition. 
The class does not inherit any state or functionality from other classes but uses other defined
classes to construct the system.
/*/

// Including necessary libraries and classes
#include "System_Container.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

// Default constructor for class
System_Container::System_Container()
{
	systemName = "Default";
}

System_Container::System_Container(string name)
{
	systemName = name;
}

// Function to set system container name
void System_Container::setSystemName(string newName)
{
	systemName = newName;
}

// Function to add an orbiting body to system container
void System_Container::addOrbitingBody(Orbiting_Body newSat)
{
	systemSatellites.push_back(newSat);
}

// Function to add a central object to system container - this should only be done once
void System_Container::addCentralObject(Central_Object newCentralObject)
{
	systemCentralObject = newCentralObject;
}

// Function to get total number of objects in system container
int System_Container::getNumObjects()
{
	int numObjects = 0;

	// Program functions so that a central object must always be created
	numObjects = systemSatellites.size() + 1; 

	return numObjects;
}

// Print error message in main file!!!!
// Remove an orbiting body from the system
bool System_Container::removeOrbitingBody(string satName) 
{
	// Initialising variables
	bool satFound = false;
	const int SIZE_VECTOR = systemSatellites.size();

	// Check if object found and erase if found
	for (int i = 0; i < SIZE_VECTOR; i++)
	{
		if (satName == systemSatellites[i].getName())
		{
			satFound = true;
			systemSatellites.erase(systemSatellites.begin() + i);
		}
	}	

	// Return boolean so that an error message can be printed in the driver in case object not found
	return satFound;
}

// Creates a text file catalogue of all objects in system at a given time
/*/ Catalogue of objects in file chosen over console output since the console is used for direct input
and visualisation for the simulation
/*/
void System_Container::getCatalogue()
{
	// Creates a data file called system_catalogue
	ofstream dataFile("system_catalogue.txt");
	const int SIZE_VECTOR = systemSatellites.size(); // Storing num orbiting objects

	// If data file is open writes to file
	if (dataFile.is_open())
	{
		dataFile << "Data Format: \n";
		dataFile << "Name, " << "Mass, " << "Temp, " << "Radius, " << "Orbital Radius, " << "Orbital Speed" << "\n";
		
		dataFile << "Central Body/Object \n";
		dataFile << systemCentralObject.getName() << ", " << systemCentralObject.getObjMass() << ", " << systemCentralObject.getTemp();
		dataFile << ", " << systemCentralObject.getObjRadius() << ", " << systemCentralObject.getOrbitalRad() << ", " << systemCentralObject.getOrbitalSpeed() << "\n";

		dataFile << "Orbiting Satellites/Objects \n";
		for (int i = 0; i < SIZE_VECTOR; i++)
		{
			dataFile << systemSatellites[i].getName() << ", " << systemSatellites[i].getObjMass() << ", " << systemSatellites[i].getTemp();
			dataFile << ", " << systemSatellites[i].getObjRadius() <<  ", " << systemSatellites[i].getOrbitalRad() << ", " << systemSatellites[i].getOrbitalSpeed() << "\n";
		}
	}

	// Closes data file - a txt file should then appear in directory containing files
	dataFile.close();
}

System_Container::~System_Container()
{
	
}

