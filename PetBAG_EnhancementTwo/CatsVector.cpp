#include <iostream>
#include <algorithm>

using namespace std;

#include "CatsVector.h"
#include "Cat.h"

// function to check cat space availability
bool Cats::CheckCatAvailability() {
	if ((Cats.size() + 1) <= maxCats) {
		cout << "SpaceAvailable" << endl;
		return true;
	}
	else {
		cout << "No Space Available" << endl;
		return false;
	}
}

void Cats::AddCat(Cat catToAdd) {
	Cats.push_back(catToAdd);
}

// function to find cat using space number
Cat& Cats::FindCat(int spaceNumber) {

	auto cat_match = [spaceNumber](Cat cat) {
		return cat.GetCatSpaceNumber() == spaceNumber;
	};

	auto it = find_if(begin(Cats), end(Cats), cat_match);
	if (it == end(Cats)) {
		//no match found
		throw runtime_error("ERROR: Cat not found \n");
	}
	else {
		return *it;
	}
}

// function to remove cat from vector using space number
void Cats::RemoveCat(int spaceNumber) {
	auto cat_match = [spaceNumber](Cat cat) {
		return cat.GetCatSpaceNumber() == spaceNumber;
	};

	auto it = find_if(begin(Cats), end(Cats), cat_match);
	if (it == end(Cats)) {
		//no match found
		throw runtime_error("ERROR: Cat not found \n");
	}
	else {
		Cats.erase(it);
	}
}

// function to cancel cat reservation using pet owner phone number
void Cats::CancelCat(string petOwnerPhoneNumber) {
	char cancel;

	auto cat_match = [petOwnerPhoneNumber](Cat cat) {
		return cat.GetOwnerPhoneNumber() == petOwnerPhoneNumber;
	};

	auto it = find_if(begin(Cats), end(Cats), cat_match);
	if (it == end(Cats)) {
		//no match found
		throw runtime_error("ERROR: Dog not found \n");
	}
	else {
		it->PrintPetInfo();

		cout << "Continue with cancelation? Y/N" << endl;
		cin >> cancel;

		if ((cancel == 'Y') || (cancel == 'y')) {
			cout << it->GetName() << "'s reservation has been canceled." << endl;
			Cats.erase(it);
		}
		else if ((cancel != 'N') && (cancel != 'n')) {
			cout << "Invalid response. Type Y for yes or N for no." << endl;
		}
	}
}
