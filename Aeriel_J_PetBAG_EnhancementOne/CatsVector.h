#ifndef CATSVECTOR_H
#define CATSVECTOR_H

#include <vector>

using namespace std;
#include "Cat.h"

// Class for managing vector of Cat objects
class Cats {
	private:
		vector<Cat> Cats;
		const int maxCats = 12;
	public:
		bool CheckCatAvailability();
		void AddCat(Cat catToAdd);
		Cat& FindCat(int spaceNumber);
};
#endif