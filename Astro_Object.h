/*/
This is a general class for an astronomical object in the system simulation. Each object has a range of traits encapsulated
in the states for this class. This is a parent class for the orbiting body and central object classes.
/*/

// Guard to ensure class not defined twice
#ifndef ASTRO_OBJECT_H
#define ASTRO_OBJECT_H

// Including necessary libraries
#include <string>

// Asbtract class for a general astro object
// Since most objects have common state this class will encapsulate all necassary states
class Astro_Object
{
	float temperature; // Temperature in Kelvin
	float objectRadius; // Radius of object in m
	std::string objectName; // String for object name - e.g. catalogue no., etc.
	float objectMass; // Object mass in solar masses

	// Protected states that are only accessible in other subclasses 
	protected:
		float orbitalSpeed; // Store orbital speed as floating point value - Speed in km/s
		float orbitalRadius; // Orbital radius in AU
		float objectMass;
		float position[2]; // Store position as a 2 element array (for x and y pos) - Position in AU (astronomical units)

	// Public behaviour for object
	public:
		Astro_Object(); // Abstract class so this is not a necessity but we will define it for convention
		Astro_Object(float temp, float radius, std::string name, float mass, float * initPos, float orbitRad);

		/*/ Pure virtual definition of position update function - so that it is only accessible in orbiting 
		body subclass i.e. will not be callable for a central object /*/
		virtual void updatePos(int time) = 0;

		// Getters to return states
		float * getPosition();
		virtual float getOrbitalSpeed() = 0; // Pure virtual function for definition in orbiting body class
		float getTemp();
		float getObjRadius();
		std::string getName();
		float getObjMass();
		float getOrbitalRad();

		// Setters to set states - sets everything except speed (dependent on calculation)
		void setName(std::string newName);
		void setMass(float newMass);
		void setTemp(float newTemp);
		void setObjRadius(float newRadius);
		void setStartPos(float * newPos);
		void setOrbitalRad(float newOrbitRad);

		// Destructor for use to free dynamic memory allocated on the heap
		~Astro_Object();	
};

#endif ASTRO_OBJECT_H