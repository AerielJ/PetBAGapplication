#ifndef CAT_H
#define CAT_H

using namespace std;

#include "Pet.h"

// Derived class inherits from Pet
class Cat :
    public Pet
{
    //Private data members
    private:
        int catSpaceNumber;

    // Public class functions
    public:
        Cat();
        void SetCatSpaceNumber(int spaceNumber);
        int GetCatSpaceNumber();
        void PrintPetInfo();
        void CheckOut();
        void UpdatePetInfo();
};

#endif

