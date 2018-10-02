/*/ 
File for main driver functions - this will define all necessary functionality for the simulation
/*/

#include "System_Container.h"
#include "Orbiting_Body.h"
#include "Central_Object.h"
#include "Astro_Object.h"

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Run at beginning of simulation
void startSim()
{
	cout << "--------- Orbiting Body Simulation ---------" << endl;
	cout << "Press 'B' to continue to data input" << endl;
}

// Run after 'B' key is pressed
void getData()
{
	// --------------- User Data Input --------------- //
	int numOrbitingObj;

	cout << "Input Required Number of Orbiting Objects" << endl;

	cin << numOrbitingObj;

	bool inputFinished = false;

	string dataArray[numOrbitingObj];
	string centralObjData;
	string systemName;

	for (int i = 0; i < numOrbitingObj; i++)
	{
		inputFinished = false;
		while (inputFinished == false)
		{	
			cout << "Input Object " << i << " Data" << endl;
			cout << "Format: Name, Mass, Radius, Temperature, Orbital Radius (comma separated values)" << endl;

			cin << dataArray[i];

			inputFinished = true;
		}
	}

	cout << endl;

	cout << "Central Object Data Input - Input Info String" << endl;
	cout << "Format: Name, Mass, Radius, Temperature" << endl;

	cin << centralObjData;

	cout << endl;


	cout << "Input System Name:" << endl;

	cin << systemName;

	// --------------- Object Setup --------------- //
	Orbiting_Body orbitingObjs[numOrbitingObj];
	Central_Object centralBody;

	const int TEMP_SIZE = 5;
	const int TEMP_SIZE_2 = 4;
	string objTempInfo[TEMP_SIZE];
	string centralObjInfo[TEMP_SIZE_2];
	
	char dataStore[numOrbitingObj];

	for (int i = 0; i < numOrbitingObj; i++)
	{
		dataStore[i] = dataArray[i];
	}

	char * tempTokPtr;
	int counter = 0;
	float initPos = {0.0, 0.0};

	for (int i = 0; i < numOrbitingObj; i++)
	{

		tempTokPtr = strtok(dataArray[i], " ,");

		while (tempTokPtr != NULL)
		{
			objTempInfo[counter] = tempTokPtr;
			tempTokPtr = strtok(NULL, " ,");
			counter++
		}
	
		orbitingObjs[i] = Orbiting_Body(stof(objTempInfo[1]), stof(objTempInfo[2]), stof(objTempInfo[3]), stof(objTempInfo[4]), objTempInfo[0], &initPos);			
	}

	tempTokPtr = strtok(centralObjData, " ,");
	counter = 0;

	while (tempTokPtr != NULL)
	{
		centralObjInfo[counter] = tempTokPtr;
		tempTokPtr = strtok(NULL, " ,");
		counter++
	}

	centralBody = Central_Object(centralObjInfo[0], stof(centralObjInfo[2]), stof(centralObjInfo[3]), stof(centralObjInfo[1]));	

	System_Container orbitSystem(systemName);

	for (int i = 0; i < numOrbitingObj; i++)
	{
		orbitSystem.addOrbitingBody(orbitingObjs[i]);
	}

	orbitSystem.addCentralObject(centralBody);
}

// Run if 'h' key is pressed
void viewInstructions()
{
	cout << "******** Simulation Instructions/Help ********" << endl;
	cout << endl;

	cout << "Description:" << endl;
	string description1 = "This is a basic central body simulation of a gravitational system where there are n orbiting bodies.";
	string description2 = "User input allows the addition an removal of orbiting bodies and initial addition of the central body."

	cout << description1 << endl;
	cout << description2 << endl;

	cout << "Key Commands:" << endl;

	const int KEY_COMMAND_SIZE = 6;
	string keyCommands[KEY_COMMAND_SIZE][2] = {{"B", "Start Simulation (Add Data)"}, {"H", "View Help Menu"}, {"S", "Start/Stop Simulation"}, {"C", "Get Object Info Catalogue"}, {"A", "Add Orbiting Object"} {"R", "Remove Orbiting Object"}}

	for (int i = 0; i < KEY_COMMAND_SIZE; i++)
	{
		cout << keyCommands[i][0] << ": " << keyCommands[i][1] << endl;
	}
}

