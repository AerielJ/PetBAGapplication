#ifndef DOG_H
#define DOG_H

using namespace std;

#include "Pet.h"

// Derived class inherits from Pet
class Dog :
    public Pet {
    //Private data members
    private:
        bool grooming;
        int dogSpaceNumber;
        double dogWeight;

    // Public class functions
    public:
        Dog();
        void SetGrooming(bool dogGrooming);
        void SetDogSpaceNumber(int spaceNumber);
        void SetDogWeight(double weight);

        bool GetGrooming();
        int GetDogSpaceNumber();
        double GetDogWeight();

        void PrintPetInfo();
        void CheckOut();
};

#endif
