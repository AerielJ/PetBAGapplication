#include <iostream>
#include <algorithm>

using namespace std;

#include "CatsVector.h"
#include "Cat.h"

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