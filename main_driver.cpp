/*/
This is the primary driver for the system simulation that implements all functionality from the classes
/*/

// Including libraries and classes
#include "System_Container.h"
#include "Orbiting_Body.h"
#include "Central_Object.h"
#include "Astro_Object.h"

#include <string>
#include <iostream>
using namespace std;

extern void startSim();
extern void getData(System_Container * orbitSystem, Orbiting_Body * orbitingObjs, int numOrbitingObj);
extern void viewInstructions();
extern void runSimulation(System_Container * container);

int main(void)
{
	// int numOrbitingBodies;

	// cout << "This is a simulation for an astronomical system, modelling orbits of objects" << endl;
	// cout << "Enter the desired number of orbiting bodies and press enter to continue: " << endl;

	// cin << numOrbitingBodies;

	startSim();
	viewInstructions();

	string checkInput;

	cin >> checkInput;
	cin.get();

	if (checkInput == "B" || checkInput == "b")
	{
		string systemName;

		cout << "Input System Name (no spaces):" << endl;

		cin >> systemName;
		cin.get();
		
		System_Container orbitSystem = System_Container(systemName);
		System_Container * containerPtr = &orbitSystem;

		int numOrbitingObj;

		cout << "Input Required Number of Orbiting Objects: " << endl;
		cin >> numOrbitingObj;
		cout << endl;

		Orbiting_Body * orbitingObjs = new Orbiting_Body[numOrbitingObj];

		getData(containerPtr, orbitingObjs, numOrbitingObj);
		
		cout << "Press 'S' to start simulation" << endl;


		runSimulation(containerPtr);

		delete[] orbitingObjs;
	}
}

