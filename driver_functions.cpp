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
void getData(System_Container * orbitSystem, Orbiting_Body * orbitingObjs, int numOrbitingObj)
{
	// --------------- User Data Input --------------- //

	string dataArray[numOrbitingObj];
	string centralObjInput;
	

	for (int i = 0; i < numOrbitingObj; i++)
	{
		cout << "Input Object " << i+1 << " Data" << endl;
		cout << "Format: Name, Mass, Radius, Temperature, Orbital Radius (comma separated values)" << endl;
		cin.ignore(1, '\n');
		getline(cin, dataArray[i]);
		cout << endl;
	}

	// char * centralObjCharArray = centralObjInput.c_str();
	// char * orbitingObjData[numOrbitingObj];

	// for (int i = 0; i < numOrbitingObj; i++)
	// {
	// 	strcpy(orbitingObjData[i], dataArray[i].c_str());
	// }

	cout << "Central Object Data Input - Input Info String" << endl;
	cout << "Format: Name, Mass, Radius, Temperature (comma separated values)" << endl;
	cin.ignore(0, '\n');
	getline(cin, centralObjInput);
	
	cout << endl;

	char centralObjData[1000];
	strcpy(centralObjData, centralObjInput.c_str());
	// centralObjData = &centralObjInput;

	

	// --------------- Object Setup --------------- //
	// Orbiting_Body orbitingObjs[numOrbitingObj];
	// Orbiting_Body * orbitingObjs = new Orbiting_Body[numOrbitingObj]; // MOVE THIS TO MAIN
	Central_Object * centralBody;
	Central_Object tempCentral;

	const int TEMP_SIZE = 5;
	const int TEMP_SIZE_2 = 4;
	string objTempInfo[TEMP_SIZE];
	string centralObjInfo[TEMP_SIZE_2];
	
	// char dataStore[numOrbitingObj];

	// for (int i = 0; i < numOrbitingObj; i++)
	// {
	// 	dataStore[i] = dataArray[i];
	// }

	char * tempTokPtr;
	char delimiters[] = ",";
	int counter = 0;
	float initPos[2] = {0.0, 0.0};


	string::size_type size1;
	string::size_type size2;


	// -------------- CENTRAL BODY SETUP -------------- //
	tempTokPtr = strtok(centralObjData, delimiters);

	while (tempTokPtr != NULL)
	{
		centralObjInfo[counter] = tempTokPtr;
		
		tempTokPtr = strtok(NULL, delimiters);
		counter++;
	}

	const int NUM_TRAITS_CENTRAL = 4;
	string centralObjString[NUM_TRAITS_CENTRAL];

	for (int i = 0; i < NUM_TRAITS_CENTRAL; i++)
	{
		centralObjString[i] = *(centralObjInfo + i);
	}

	tempCentral = Central_Object(centralObjString[0], stof(centralObjString[2], &size1), stof(centralObjString[3], &size1), stof(centralObjString[1], &size1));
	centralBody = &tempCentral;

	// -------------- ORBITING BODY SETUP -------------- //
	const int ORBIT_TRAIT_NUM = 5;
	string orbitObjInfo[ORBIT_TRAIT_NUM];
	counter = 0;

	char functionDataLine[1000];
	for (int i = 0; i < numOrbitingObj; i++)
	{
		strcpy(functionDataLine, dataArray[i].c_str());

		tempTokPtr = strtok(functionDataLine, delimiters);

		while (tempTokPtr != NULL)
		{
			objTempInfo[counter] = tempTokPtr;
			tempTokPtr = strtok(NULL, delimiters);
			counter++;
		}

		for (int j = 0; j < ORBIT_TRAIT_NUM; j++)
		{
			orbitObjInfo[j] = objTempInfo[j];
			cout << "INFO " << orbitObjInfo[j] << endl;
		}
		cout << "STRING " << orbitObjInfo[1] << endl;
		cout << "FLOAT CONVERSION " << stof(orbitObjInfo[1], &size2) << endl;

		*(orbitingObjs + i) = Orbiting_Body(stof(orbitObjInfo[1], &size2), stof(orbitObjInfo[2], &size2), stof(orbitObjInfo[3], &size2), stof(orbitObjInfo[4], &size2), orbitObjInfo[0], initPos);
		(orbitingObjs + i) -> setOrbitalSpeed(centralBody -> getObjMass());			
	}

		

	for (int i = 0; i < numOrbitingObj; i++)
	{	

		orbitSystem -> addOrbitingBody(&orbitingObjs[i]);
		
	}

	centralBody -> setOrbitalSpeed(0);
	orbitSystem -> addCentralObject(centralBody);

	// Getting catalogue of bodies
	cout << "See system_catalogue.txt in code directory for a record of all objects and associated information" << endl;
	cout << endl;
	orbitSystem -> getCatalogue();

	// delete[] orbitingObjs;
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
	float * satellitePositions;
	int numSatellites = (container -> getNumObjects()) - 1;
	float timeValues[numSatellites];
	bool runSim = false;

	float * orbitalPeriods = container -> getOrbitalPeriods();

	srand(time(NULL));

	bool timeLimit = false;
	string inputStart;


	float timeInc = 300000;
	
	cin.ignore(1000, '\n');
	cin >> inputStart;

	// // while (inputTaken == false)
	// // {
	// // 	

	// // 	if (inputStart == "S" || inputStart == "s")
	// // 	{
	// // 		inputTaken = true;
	// // 		runSim = true;
	// // 	}
	// // }
	// cout << "LINE 226" << endl;

	if (inputStart == "S" || inputStart == "s")
	{
		for (int i = 0; i < numSatellites; i++)
		{
			timeValues[i] = (float(rand())/float(RAND_MAX)) * orbitalPeriods[i];
			// cout << orbitalPeriods[i] << endl;
			// cout << "Time Value " << i << ": " << timeValues[i] << endl;
		}

		// cout << "ORBITAL PERIOD MEM ADDRESS " << &orbitalPeriods << endl;

		// // while (runSim == true)
		// // {
		// // if (inputStart == "S" || inputStart == "s")
		// // {

		// 		// ------------ SOMETHING HERE FOR GRAPHICS -------------- //

		// 		// TEST CODE -- OUTPUT

		// cout << "LINE 242" << endl;
		while (timeLimit == false)
		{
			// cout << "LINE 250" << endl;
			satellitePositions = container -> runSim(timeValues);

			// for (int i = 0; i < numSatellites; i++)
			// {
			// 	cout << i  <<  " " << numSatellites << " " << "POS " <<  *(satellitePositions + i*2) << " " << *(satellitePositions + i*2 + 1) << endl;
			// }

			// cout << "LINE 247" << endl;
			for (int i = 0; i < numSatellites; i++)
			{
				cout << "-----------------------------" << endl;
				cout << "Satellite " << (i/2)+1 << " (" << *(satellitePositions + i*2) << ", " << *(satellitePositions + i*2 + 1) << ")" << endl;
			}

			for (int j = 0; j < numSatellites; j++)
			{
				timeValues[j] += timeInc;
			}

			for (int i = 0; i < numSatellites; i++)
			{
				if (timeValues[i] >= 1000000000)
				{
					timeLimit = true;
				}
			}

			delete[] satellitePositions;
		}
	}
	// 	// }

	delete[] orbitalPeriods;
		// END TEST CODE
}

