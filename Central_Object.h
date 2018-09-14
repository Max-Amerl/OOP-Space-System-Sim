/*/
This is the class for a central body that all other objects in the simulation orbit.
The class inherits all its state from Astro_Object, but has its own constructors to initialise
the object.
/*/

// Guard to prevent inclusion of code twice in program
#ifndef CENTRAL_OBJECT_H
#define CENTRAL_OBJECT_H

// Including libraries and Astro_Object class
#include "Astro_Object.h"
#include <string>

// Definition of class - subclass of Astro_Object
class Central_Object : public Astro_Object // Central object class inherits from Astro_Object parent class
{	
	// No state - all state encapsulated in Astro_Object class
	
	// Public behaviours for class - default position in simulation is (0,0)
	public:
		// Constructors
		Central_Object();
		Central_Object(std::string name, float radius, float temp, float mass);

		// Destructors
		~Central_Object();
	
};

#endif CENTRAL_OBJECT_H