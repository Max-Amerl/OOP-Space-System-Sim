/*/
This file is a testing file for debugging purposes and to see if each class is working correctly
/*/

// Including libraries and classes
#include "Astro_Object.h"
#include "Central_Object.h"
#include "Orbiting_Body.h"
#include "System_Container.h"

#include <string>
#include <iostream>

using namespace std;

// Main function to test classes
int main(void)
{
	// This line should throw a compile error - it uses an abstract class that cannot be instantiated
	// Astro_Object newAstroObject;

	const int NUM_SAT = 5;
	Orbiting_Body satellites[NUM_SAT];
	System_Container gravSystem = System_Container("Star System");
	Central_Object centralSMBH = Central_Object("Sagitarius A", 1, 8000, 100);
	centralSMBH.setOrbitalSpeed(100);

	Central_Object * centralObj = new Central_Object;

	centralObj = &centralSMBH;

	Orbiting_Body * sysSats = new Orbiting_Body[NUM_SAT];

	string names[NUM_SAT] = {"Star1", "Star2", "Star3", "Star4", "Star5"};
	float temperatures[NUM_SAT] = {2000.383, 5800.473, 19101.374, 8372.245, 2929.781};
	float orbitalRadii[NUM_SAT] = {1.0, 2.5, 3.0, 4.5, 1.8};
	float masses[NUM_SAT] = {1.0, 3.5, 2.0, 10, 4.0};
	float objRadius[NUM_SAT] = {1.9, 3.38, 4.48, 5.52, 2.43};
	float initPos[NUM_SAT][2];

	int timeCounter = 0;

	for (int i = 0; i < NUM_SAT; i++)
	{
		initPos[i][0] = orbitalRadii[i];
		initPos[i][1] = 0.0;
	}

	for (int i = 0; i < NUM_SAT; i++)
	{

		satellites[i] = Orbiting_Body(masses[i], objRadius[i], temperatures[i], orbitalRadii[i], names[i], initPos[i]);
		

		cout << &satellites[i] << endl;
		sysSats[i] = satellites[i];
		sysSats[i].setOrbitalSpeed(100);
		gravSystem.addOrbitingBody(&sysSats[i]);
		// cout << satellites[i].getOrbitalSpeed() << endl;
	}

	gravSystem.addCentralObject(centralObj);
	float * positionPtr;

	while (timeCounter <= 100000)
	{
		for (int i = 0; i < NUM_SAT; i++)
		{
			sysSats[i]. updatePos(timeCounter, centralObj -> getObjMass());
			positionPtr = sysSats[i].getPosition();
			cout << "Star " << i+1 << " (" << *(positionPtr + 0) << ", " << *(positionPtr + 1) << ")" << endl;
		}
		cout << "--------------------------" << endl;

		timeCounter += 1000; 
	}


	// for (int i = 0; i < 5; i++)
	// {
	// 	cout << sysSats[i].getOrbitalSpeed() << endl;
	// }
	gravSystem.getCatalogue();
	delete[] centralObj;
	delete[] sysSats;
	return 0;
}