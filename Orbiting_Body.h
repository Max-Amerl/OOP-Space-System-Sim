/*/
This is a class for an orbiting body. Common state is inherited from the Astro_Object class.
Specific states and behaviours are initialised in this class definition.
/*/

// Guard to prevent multiple inclusions of class in code
#ifndef ORBITING_BODY_H
#define ORBITING_BODY_H

// Include necessary libraries and Astro_Object class
#include "Astro_Object.h"
#include <string>

class Orbiting_Body : public Astro_Object
{

	public:
		// Constructors for class
		Orbiting_Body();
		Orbiting_Body(float mass, float radius, float temp, float orbitRad, std::string name, float * initPos);

		// Functions to update position and calculate/return orbital speed
		void updatePos(float time, float centralObjMass);
		void setOrbitalSpeed(float centralObjMass); 

		// Destructor for Orbiting_Body class
		~Orbiting_Body();
};

#endif 