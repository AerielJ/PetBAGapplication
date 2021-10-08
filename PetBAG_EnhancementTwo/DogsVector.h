#ifndef DOGSVECTOR_H
#define DOGSVECTOR_H

#include <vector>

using namespace std;
#include "Dog.h"

// Class for managing vector of Dog objects
class Dogs {
	private:
		vector<Dog> Dogs;
		const int maxDogs = 30;
	public:
		bool CheckDogAvailability();
		void AddDog(Dog dogToAdd);
		Dog& FindDog(int spaceNumber);
		void RemoveDog(int spaceNumber);
		void CancelDog(string petOwnerPhoneNumber);
};
#endif
