/*/
This file defines behaviours specific to the Central_Object class i.e. destructors and constructors.
All state and other behaviours are inherited from the Astro_Object Class.
/*/

// Including libraries
#include "Central_Object.h"
#include <string>
using namespace std;

#include <iostream>

float constPos[2] = {0.0, 0.0}; // Initial position of central body - stays same for all objects

// Default constructor definition with inheritance from Astro_Object
Central_Object::Central_Object() : Astro_Object()
{

}

// Additional constructor to use when given information
Central_Object::Central_Object(string name, float radius, float temp, float mass) : Astro_Object(temp, radius, name, mass, &constPos[0], 0)
{
	// No arguments - orbital speed is 0 in Astro_Object for central body (not considering motion about centre of mass of system)
}

// Defining overloading functions
void Central_Object::setOrbitalSpeed(float centralObjMass)
{
	orbitalSpeed = 0;
	cout << "SET CENTRAL" << endl;

}

void Central_Object::updatePos(float time, float centralObjMass)
{
	for (int i = 0; i < 2; i++)
	{
		position[i] = 0;
	}
}

Central_Object::~Central_Object()
{
	// Empty - no dynamic memory created
}


