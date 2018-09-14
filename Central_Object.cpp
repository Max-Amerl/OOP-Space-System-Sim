/*/
This file defines behaviours specific to the Central_Object class i.e. destructors and constructors.
All state and other behaviours are inherited from the Astro_Object Class.
/*/

// Including libraries
#include "Central_Object.h"
#include <string>
using namespace std;


float constPos[2] = {0.0, 0.0}; // Initial position of central body - stays same for all objects

// Default constructor definition with inheritance from Astro_Object
Central_Object::Central_Object() : Astro_Object()
{
	constPos = {0, 0};
}

// Additional constructor to use when given information
Central_Object::Central_Object(string name, float radius, float temp, float mass) : Astro_Object(temp, radius, name, mass, &constPos[0], 0)
{
	// No arguments - orbital speed is 0 in Astro_Object for central body (not considering motion about centre of mass of system)
}

Central_Object::~Central_Object()
{
	// Empty - no dynamic memory created
}


