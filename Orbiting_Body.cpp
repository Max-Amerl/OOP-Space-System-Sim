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
const float SOLAR_MASS = 1.9891 * pow(10.0, 30.0);
const float ASTRO_UNIT = 1.496 * pow(10.0, 11.0);

// Constructor definitions for orbiting body class
Orbiting_Body::Orbiting_Body() : Astro_Object()
{

}

// Using inheritance from Astro_Object class to define constructor for orbiting body class
Orbiting_Body::Orbiting_Body(float mass, float radius, float temp, float orbitRad, std::string name, float * initPos) : Astro_Object(temp, radius, name, mass, initPos, orbitRad)
{

}

// Function to update orbiting body position
void Orbiting_Body::updatePos(int time, float centralObjMass)
{
	position[0] = ((orbitalRadius * ASTRO_UNIT) * cos(sqrt((G_CONST * (centralObjMass * SOLAR_MASS)) / pow((orbitalRadius * ASTRO_UNIT), 3.0)) * time)) / (ASTRO_UNIT);
	position[1] = ((orbitalRadius * ASTRO_UNIT) * sin(sqrt((G_CONST * (centralObjMass * SOLAR_MASS)) / pow((orbitalRadius * ASTRO_UNIT), 3.0)) * time)) / (ASTRO_UNIT);
}

// Calculates orbital speed
void Orbiting_Body::setOrbitalSpeed(float centralObjMass)
{
	orbitalSpeed = sqrt((G_CONST * (centralObjMass * SOLAR_MASS)) / (orbitalRadius * ASTRO_UNIT));
}

Orbiting_Body::~Orbiting_Body()
{

}