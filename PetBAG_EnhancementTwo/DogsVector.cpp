#include <iostream>
#include <algorithm>

using namespace std;

#include "DogsVector.h"
#include "Dog.h"

// function to check dog space availability
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

// function to remove dog from vector using space number
void Dogs::RemoveDog(int spaceNumber) {
	
	auto dog_match = [spaceNumber](Dog dog) {
		return dog.GetDogSpaceNumber() == spaceNumber;
	};

	auto it = find_if(begin(Dogs), end(Dogs), dog_match);
	if (it == end(Dogs)) {
		//no match found
		throw runtime_error("ERROR: Dog not found \n");
	}
	else {
		Dogs.erase(it);
	}
}

// function to cancel dog reservation using pet owner phone number
void Dogs::CancelDog(string petOwnerPhoneNumber) {
	char cancel;
	
	auto dog_match = [petOwnerPhoneNumber](Dog dog) {
		return dog.GetOwnerPhoneNumber() == petOwnerPhoneNumber;
	};

	auto it = find_if(begin(Dogs), end(Dogs), dog_match);
	if (it == end(Dogs)) {
		//no match found
		throw runtime_error("ERROR: Dog not found \n");
	}
	else {
		it->PrintPetInfo();

		cout << "Continue with cancelation? Y/N" << endl;
		cin >> cancel;

		if ((cancel == 'Y') || (cancel == 'y')) {
			cout << it->GetName() << "'s reservation has been canceled." << endl;
			Dogs.erase(it);
		}
		else if ((cancel != 'N') && (cancel != 'n')) {
			cout << "Invalid response. Type Y for yes or N for no." << endl;
		}
	}
}
