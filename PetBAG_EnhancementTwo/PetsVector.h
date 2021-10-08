#ifndef PETSVECTOR_H
#define PETSVECTOR_H

#include <vector>

using namespace std;

#include "Pet.h"

// Class for managing vector of Pet objects
class Pets {
	private:
		vector<Pet> allPets;

	public:
		void AddPet(Pet currentPet);
		Pet& FindPet(string phoneNumber);

};
#endif