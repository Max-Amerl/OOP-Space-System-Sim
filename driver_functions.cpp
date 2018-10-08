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
#include <ctime>
#include <cstdlib>
using namespace std;

// Run at beginning of simulation
void startSim()
{
	cout << endl;
	cout << "--------- Orbiting Body Simulation ---------" << endl;
}

// ------------------------- Data Input Function ------------------------- //

// Run after 'B' key is pressed
void getData(System_Container orbitSystem)
{
	// --------------- User Data Input --------------- //
	int numOrbitingObj;

	cout << "Input Required Number of Orbiting Objects: " << endl;
	cin >> numOrbitingObj;

	bool inputFinished = false;

	string dataArray[numOrbitingObj];
	string centralObjInput;
	
	cout << endl;
	
	for (int i = 0; i < numOrbitingObj; i++)
	{
		cout << "Input Object " << i+1 << " Data" << endl;
		cout << "Format: Name, Mass, Radius, Temperature, Orbital Radius (comma separated values)" << endl;
		cin.get();
		getline(cin, dataArray[i]);
		cout << endl;
	}

	// char * orbitingObjData[numOrbitingObj];

	// for (int i = 0; i < numOrbitingObj; i++)
	// {
	// 	strcpy(orbitingObjData[i], dataArray[i].c_str());
	// }

	cout << "Central Object Data Input - Input Info String" << endl;
	cout << "Format: Name, Mass, Radius, Temperature (comma separated values)" << endl;
	cin.get();
	getline(cin, centralObjInput);
	cout << "LINE 62" << endl;
	char * centralObjData;
	cout << "LINE 64" << endl;

	strcpy(centralObjData, centralObjInput.c_str());
	// centralObjData = &centralObjInput;

	cout << endl;

	// --------------- Object Setup --------------- //
	// Orbiting_Body orbitingObjs[numOrbitingObj];
	cout << "LINE 73" << endl;

	Orbiting_Body * orbitingObjs = new Orbiting_Body[numOrbitingObj];
	Central_Object * centralBody = new Central_Object;
	Central_Object centreObj;
	// Central_Object centralBody;
	cout << "LINE 77" << endl;

	const int TEMP_SIZE = 5;
	const int TEMP_SIZE_2 = 4;
	char objTempInfo[TEMP_SIZE];
	char centralObjInfo[TEMP_SIZE_2];
	
	// char dataStore[numOrbitingObj];

	// for (int i = 0; i < numOrbitingObj; i++)
	// {
	// 	dataStore[i] = dataArray[i];
	// }

	char * tempTokPtr;
	char delimiters[] = " ,";
	int counter = 0;
	float initPos[2] = {0.0, 0.0};

	string::size_type size;
	const int ORBIT_TRAIT_NUM = 5;
	string orbitObjInfo[ORBIT_TRAIT_NUM];

	char * functionDataLine;

	cout << "LINE 98" << endl;
	for (int i = 0; i < numOrbitingObj; i++)
	{
		strcpy(functionDataLine, dataArray[i].c_str());
		tempTokPtr = strtok(functionDataLine, delimiters);

		while (tempTokPtr != NULL)
		{
			objTempInfo[counter] = *tempTokPtr;
			tempTokPtr = strtok(NULL, delimiters);
			counter++;
		}

		for (int j = 0; j < ORBIT_TRAIT_NUM; j++)
		{
			orbitObjInfo[j] = objTempInfo[j]; 		
		}
	
		orbitingObjs[i] = Orbiting_Body(stof(orbitObjInfo[1], &size), stof(orbitObjInfo[2], &size), stof(orbitObjInfo[3], &size), stof(orbitObjInfo[4], &size), orbitObjInfo[0], initPos);			
	}

	cout << "LINE 118" << endl;
	tempTokPtr = strtok(centralObjData, delimiters);
	counter = 0;

	while (tempTokPtr != NULL)
	{
		centralObjInfo[counter] = *tempTokPtr;
		tempTokPtr = strtok(NULL, delimiters);
		counter++;
	}

	cout << "LINE 130" << endl;
	const int NUM_TRAITS_CENTRAL = 4;
	string centralObjString[NUM_TRAITS_CENTRAL];

	for (int i = 0; i < NUM_TRAITS_CENTRAL; i++)
	{
		centralObjString[i] = centralObjInfo[i];
	}

	centreObj = Central_Object(centralObjString[0], stof(centralObjString[2], &size), stof(centralObjString[3], &size), stof(centralObjString[1], &size));	
	centralBody = &centreObj;

	cout << "LINE 142" << endl;
	for (int i = 0; i < numOrbitingObj; i++)
	{
		orbitSystem.addOrbitingBody(orbitingObjs + i);
	}

	orbitSystem.addCentralObject(centralBody);

	delete[] orbitingObjs;
	delete centralBody;
}

void viewInstructions()
{
	cout << endl;
	cout << "******** Simulation Instructions/Help ********" << endl;

	cout << "Description:" << endl;
	string description1 = "This is a basic central body simulation of a gravitational system where there are n orbiting bodies.";
	string description2 = "User input allows the addition an removal of orbiting bodies and initial addition of the central body.";

	cout << description1 << endl;
	cout << description2 << endl;
	cout << endl;

	cout << "Key Commands:" << endl;

	const int KEY_COMMAND_SIZE = 4;
	string keyCommands[KEY_COMMAND_SIZE][2] = {{"B", "Start Simulation (Add Data)"}, {"H", "View Help Menu"}, {"S", "Start/Stop Simulation"}, {"C", "Get Object Info Catalogue"}};

	for (int i = 0; i < KEY_COMMAND_SIZE; i++)
	{
		cout << keyCommands[i][0] << ": " << keyCommands[i][1] << endl;
	}

	cout << endl;
	cout << "Press 'B' to continue to data input" << endl;
}

void runSimulation(System_Container * container)
{
	cout << "RUNNING SIM" << endl;
	float * satellitePositions;
	int numSatellites = (container -> getNumObjects()) - 1;
	float timeValues[numSatellites];
	bool runSim = false;

	srand(time(NULL));

	bool inputTaken = false;
	string inputStart;

	float timeInc = 0.01;

	while (inputTaken == false)
	{
		cin >> inputStart;
		cin.get();

		if (inputStart == "S" || inputStart == "s")
		{
			inputTaken = true;
			runSim = true;
		}
	}

	for (int i = 0; i < numSatellites; i++)
	{
		timeValues[i] = (rand()/RAND_MAX) * 6.2831;
	}

	while (runSim == true)
	{
		satellitePositions = container -> runSim(timeValues);

		// ------------ SOMETHING HERE FOR GRAPHICS -------------- //

		// TEST CODE -- OUTPUT
		for (int i = 0; i < numSatellites; i += 1)
		{
			cout << "-----------------------------" << endl;
			cout << "Satellite " << i << " (" << *(satellitePositions + i) << *(satellitePositions + i + 1) << endl;
		}

		// END TEST CODE

		for (int i = 0; i < numSatellites; i++)
		{
			timeValues[i] += timeInc;
		}

		for (int i = 0; i < numSatellites; i++)
		{
			if (timeValues[i] >= 100000000)
			{
				break;
			}
		}
	}
}


