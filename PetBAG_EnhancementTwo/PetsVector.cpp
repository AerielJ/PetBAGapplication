#include <iostream>
#include <algorithm>

using namespace std;

#include "PetsVector.h"

void Pets::AddPet(Pet currentPet) {
	allPets.push_back(currentPet);
}

// function to find pet usig owner's phone number
Pet& Pets::FindPet(string phoneNumber) {

	auto pet_match = [phoneNumber](Pet pet) {
		return pet.GetOwnerPhoneNumber() == phoneNumber;
	};

	auto it = find_if(begin(allPets), end(allPets),pet_match);
	if (it == end(allPets)) {
		//no match found
		throw runtime_error("ERROR: Pet not found \n");
	}
	else {
		return *it;
	}
}
