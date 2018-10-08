/*/ 
This is the definition file for all behaviours of the Astro_Object class
/*/

// Including libraries and setting namespace 
#include "Astro_Object.h"
#include <string>

using namespace std;

// Default constructor for class - will not be called since is an abstract class
Astro_Object::Astro_Object()
{
	/*/ Setting default values of each class - don't expect user to try to use simulation
	without inputting their own data /*/
	// orbitalSpeed = 0;

	for (int i = 0; i < 2; i++)
	{
		position[i] = 0;
	}

	temperature = 0;
	objectRadius = 0;
	objectName = "Default";
	objectMass = 0;
	orbitalRadius = 0;
	orbitalSpeed = 0;

}

Astro_Object::Astro_Object(float temp, float radius, std::string name, float mass, float * initPos, float orbitRad)
{
	// orbitalSpeed = 0; // This is set later (calculated in orbiting body class)
	objectRadius = radius;
	objectName = name;
	objectMass = mass;
	orbitalRadius = orbitRad;
	temperature = temp;

	for (int i = 0; i < 2; i++)
	{
		position[i] = *(initPos + i);
	}
}

// Complete definition of getters from class .h file
// Individual object getters and setters for increased user-interface flexibility
float * Astro_Object::getPosition()
{
	// Returns memory address of first element in position array - a pointer
	return position;
}

float Astro_Object::getTemp()
{
	return temperature;
}

float Astro_Object::getObjRadius()
{
	return objectRadius;
}

string Astro_Object::getName()
{
	return objectName;
}

float Astro_Object::getObjMass()
{
	return objectMass;
}

float Astro_Object::getOrbitalRad()
{
	return orbitalRadius;
}

float Astro_Object::getOrbitalSpeed()
{
	return orbitalSpeed;
}

// // Defining setters initialised in class definition
// void Astro_Object::setName(string newName)
// {
// 	objectName = newName;
// }

// void Astro_Object::setMass(float newMass)
// {
// 	objectMass = newMass;
// }

// void Astro_Object::setTemp(float newTemp)
// {
// 	temperature = newTemp;
// }

// void Astro_Object::setObjRadius(float newRadius)
// {
// 	objectRadius = newRadius;
// }

// void Astro_Object::setStartPos(float * newPos)
// {
// 	// Using for loop to iterate over array
// 	for (int i = 0; i < 2; i++)
// 	{
// 		*(position + i) = *(newPos + i);
// 	}
// }

// void Astro_Object::setOrbitalRad(float newOrbitRad)
// {
// 	orbitalRadius = newOrbitRad;
// }

// Destructor for class - this will be empty since no dynamic memory is used
Astro_Object::~Astro_Object()
{
	
}





