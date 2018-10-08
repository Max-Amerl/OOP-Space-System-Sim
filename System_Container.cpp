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
	systemCentralObject = new Central_Object;
}

System_Container::System_Container(string name)
{
	systemName = name;
	systemCentralObject = new Central_Object;
}

// Function to set system container name
void System_Container::setSystemName(string newName)
{
	systemName = newName;
}

// Function to add an orbiting body to system container
void System_Container::addOrbitingBody(Astro_Object * newSat)
{
	systemSatellites.push_back(newSat);
	// systemSatellites[systemSatellites.size()-1] -> setOrbitalSpeed(systemCentralObject -> getObjMass());
	// cout << systemSatellites[systemSatellites.size()-1].getOrbitalSpeed() << endl;
}

// Function to add a central object to system container - this should only be done once
void System_Container::addCentralObject(Astro_Object * newCentralObject)
{
	systemCentralObject = newCentralObject;
}

float * System_Container::runSim(float * time)
{
	float satPositions[systemSatellites.size()][2];
	float * posPtr;
	float * returnPointer;

	for (int i = 0; i < systemSatellites.size(); i++)
	{
		systemSatellites[i] -> updatePos(time[i], systemCentralObject -> getObjMass());
		posPtr = systemSatellites[i] -> getPosition();
		satPositions[i][0] = *(posPtr + 0);
		satPositions[i][1] = *(posPtr + 1); 
	}

	returnPointer = &satPositions[0][0];
	
	return returnPointer;
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
		if (satName == (systemSatellites[i] -> getName()))
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
		
		dataFile << "\n";

		dataFile << "Central Body/Object \n";
		dataFile << systemCentralObject -> getName() << ", " << systemCentralObject -> getObjMass() << ", " << systemCentralObject -> getTemp();
		dataFile << ", " << systemCentralObject -> getObjRadius() << ", " << systemCentralObject -> getOrbitalRad() << ", " << systemCentralObject -> getOrbitalSpeed() << "\n";

		dataFile << "\n";

		dataFile << "Orbiting Satellites/Objects \n";
		
		for (int i = 0; i < SIZE_VECTOR; i++)
		{
			// Setting orbital speed of objects in case they are not already set - THIS NEEDS WORK
			// systemSatellites[i] -> setOrbitalSpeed(systemCentralObject -> getObjMass());
			// cout << systemSatellites[i] -> getOrbitalSpeed() << endl;
			dataFile << systemSatellites[i] -> getName() << ", " << systemSatellites[i] -> getObjMass() << ", " << systemSatellites[i] -> getTemp();
			dataFile << ", " << systemSatellites[i] -> getObjRadius() <<  ", " << systemSatellites[i] -> getOrbitalRad() << ", " << systemSatellites[i] -> getOrbitalSpeed() << "\n";
		}
	}

	// Closes data file - a txt file should then appear in directory containing files
	dataFile.close();
}

System_Container::~System_Container()
{
	// delete systemCentralObject;
}

