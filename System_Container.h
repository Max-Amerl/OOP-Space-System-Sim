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
#include "Central_Body.h"
#include <string>
#include <vector>

// Container class definition
class System_Container
{
	// States
	std::string systemName;
	std::vector<Orbiting_Body> systemSatellites; // Vector of all orbiting bodies
	Central_Body systemCentralBody; // Central body in container

	public:
		// Constructor
		System_Container();

		// Function to set name of system
		void setSystemName(std::string newName);

		// Behaviour to provide container functionality
		void addOrbitingBody(Orbiting_Body newSat); // Add an orbiting body
		void addCentralBody(Central_Body newCentralBody); // Add the system's central body
		int getNumObjects(); // Return no. of objects in system
		void removeOrbitingBody(std::string satName); // Remove an orbiting body
		void getCatalogue(); // Get a catalogue of all objects in the system

		// Destructor for class - deletes dynamically allocated memory after use
		~System_Container();
};

#endif SYSTEM_CONTAINER_H
