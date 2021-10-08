#include <iostream>
#include <algorithm>

using namespace std;

#include "DogsVector.h"
#include "Dog.h"

bool Dogs::CheckDogAvailability() {
	if ((Dogs.size() + 1) <= maxDogs) {
		cout << "Space available" << endl;
		return true;
	}
	else {
		cout << "No Space Available" << endl;
		return false;
	}
}

void Dogs::AddDog(Dog dogToAdd) {
	Dogs.push_back(dogToAdd);
}

// function to find dog using space numner
Dog& Dogs::FindDog(int spaceNumber) {

	auto dog_match = [spaceNumber](Dog dog) {
		return dog.GetDogSpaceNumber() == spaceNumber;
	};

	auto it = find_if(begin(Dogs), end(Dogs), dog_match);
	if (it == end(Dogs)) {
		//no match found
		throw runtime_error("ERROR: Dog not found \n");
	}
	else {
		return *it;
	}
}