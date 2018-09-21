/*/
This is a class definition for an object container that all created objects in the system
can be stored in. It does not inherit traits from any class.
/*/

// Guard to prevent inclusion twice in code
#ifndef SYSTEM_CONTAINER_H
#define SYSTEM_CONTAINER_H

// Including libraries
#include "Astro_Object.h"
#include "Orbiting_Body.h"
#include "Central_Object.h"
#include <string>
#include <vector>

// Container class definition
class System_Container
{
	// States
	std::string systemName;
	std::vector<Orbiting_Body> systemSatellites; // Vector of all orbiting bodies
	Central_Object systemCentralObject; // Central object in container

	public:
		// Constructors
		System_Container();
		System_Container(std::string name);

		// Function to set name of system
		void setSystemName(std::string newName);

		// Behaviour to provide container functionality
		void addOrbitingBody(Orbiting_Body newSat); // Add an orbiting body
		void addCentralObject(Central_Object newCentralObject); // Add the system's central object
		int getNumObjects(); // Return no. of objects in system
		bool removeOrbitingBody(std::string satName); // Remove an orbiting body
		void getCatalogue(); // Get a catalogue of all objects in the system

		// Destructor for class - deletes dynamically allocated memory after use
		~System_Container();
};

#endif 
