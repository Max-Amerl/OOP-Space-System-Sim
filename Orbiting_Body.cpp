/*/
This is a file containing the complete definition for behaviours initialised in the Orbiting_Body
class .h file.
/*/

// Including libraries and classes
#include "Orbiting_Body.h"
#include <string>
#include <cmath>
using namespace std;

const float G_CONST = 6.67408 * pow(10.0, -11.0); // Definition of gravitational constant

// Constructor definitions for orbiting body class
Orbiting_Body::Orbiting_Body() : Astro_Object()
{

}

// Using inheritance from Astro_Object class to define constructor for orbiting body class
Orbiting_Body::Orbiting_Body(float mass, float radius, float temp, float orbitRad, std::string name, float * initPos) : Astro_Object(temp, radius, name, mass, initPos, orbitRad)
{

}

// Function to update orbiting body position
void Orbiting_Body::updatePos(int time)
{
	position[0] = orbitalRadius * cos(sqrt((G_CONST * objectMass) / pow(orbitalRadius, 3.0)) * time);
	position[1] = orbitalRadius * sin(sqrt((G_CONST * objectMass) / pow(orbitalRadius, 3.0)) * time);
}

// Calculates orbital speed
void Orbiting_Body::setOrbitalSpeed()
{
	orbitalSpeed = sqrt((G_CONST * objectMass) / orbitalRadius);
}

// Returns orbital speed - from pure virtual definition
float Orbiting_Body::getOrbitalSpeed()
{
	return orbitalSpeed;
}