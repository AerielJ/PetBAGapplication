#include <iostream>
#include <vector>
#include <iomanip>
#include <Windows.h>

using namespace std;

#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "PetsVector.h"
#include "DogsVector.h"
#include "CatsVector.h"

// function to get visitor information
void GetVisitorInfo(Pet& petToCheckIn, Pets& pets) {
	char newVisitor;
	char updateInfo;
	int numDays;

	cout << "New visitor? Y/N" << endl;
	cin >> newVisitor;

	if ((newVisitor == 'Y') || (newVisitor == 'y')) {
		petToCheckIn.CreatePet();
		pets.AddPet(petToCheckIn);
	}
	else if ((newVisitor == 'N') || (newVisitor == 'n')) {
		string petOwnerPhoneNumber;

		cout << "Please enter the pet owner's phone number: " << endl;
		cin >> petOwnerPhoneNumber;
		
		pets.FindPet(petOwnerPhoneNumber).PrintPetInfo();

		cout << "Do you need to update any information? Y/N" << endl;
		cin >> updateInfo;

		if ((updateInfo == 'Y') || (updateInfo == 'y')) {
			pets.FindPet(petOwnerPhoneNumber).UpdateVisitorInfo();
		}
		else if ((updateInfo != 'N') && (updateInfo != 'n')) {
			throw runtime_error("Invalid Input. Type Y for yes or N for no \n");
		}

		petToCheckIn = pets.FindPet(petOwnerPhoneNumber);
	}
	else {
		throw runtime_error("Invalid Input. Type Y for yes or N for no \n");
	}
	cout << "Please enter pet's length of stay: " << endl;;
	cin >> numDays;

	petToCheckIn.SetDaysStay(numDays);
}
	

int main() {

	// String for drawing
	string drawTable(46, '*');

	string petType;
	int spaceNumber;
	string petOwnerPhoneNumber;

	// Objects for managing vectors
	Pets pets;
	Dogs dogs;
	Cats cats;

	bool spaceAvailable = false;

	bool endProgram = false;

	while (!endProgram) {
		try {

			Dog dogToCheckIn;
			dogToCheckIn.SetType("Dog");

			Cat catToCheckIn;
			catToCheckIn.SetType("Cat");

			// initialize menuSelection variable
			int menuSelection = 0;

			// Print menu
			cout << setw(30) << setfill(' ') << "Pet BAG Menu" << endl;
			cout << drawTable << endl;
			cout << "1: Check-in pet" << endl;
			cout << "2: Check-out pet" << endl;
			cout << "3: Update pet information" << endl;
			cout << "4: Cancel pet reservation" << endl;
			cout << "5: Exit" << endl;
			cout << drawTable << endl;
			cout << "Enter your selection as a number 1, 2, 3, 4, or 5." << endl;

			// Get user input
			cin >> menuSelection;

			// Error checking, numeric input
			if (cin.fail()) {
				throw runtime_error("ERROR: Invalid input. Selection must be a number \n");
			}

			// Respond to user input based on menu selection
			switch (menuSelection) {
			case 1:
				system("CLS");              // clear the screen

				cout << "Enter the type of pet you would like to check-in. Dog or Cat?:" << endl;
				cin >> petType;

				// Check availablity based on pet type
				if ((petType == "Dog") || (petType == "dog")) {
					dogToCheckIn.SetType("Dog");
					spaceAvailable = dogs.CheckDogAvailability();
				}
				else if ((petType == "Cat") || (petType == "cat")) {
					catToCheckIn.SetType("Cat");
					spaceAvailable = cats.CheckCatAvailability();
				}
				else {
					throw runtime_error("Pet type not recognized. Pet must be a Dog or Cat.");
				}

				if (spaceAvailable) {
					if ((petType == "Dog") || (petType == "dog")) {
						GetVisitorInfo(dogToCheckIn, pets);
						if (dogToCheckIn.GetDaysStay() >= 2) {
							char grooming;
							cout << "Add grooming service? Y/N" << endl;
							cin >> grooming;
							if ((grooming == 'Y') || (grooming == 'y')) {
								double weight;

								cout << "Please enter dogs weight in pounds: ";
								cin >> weight;

								dogToCheckIn.SetGrooming(true);
								dogToCheckIn.SetDogWeight(weight);
							}
							else if ((grooming != 'N') && (grooming != 'n')) {
								throw runtime_error("Invalid Input. Type Y for yes or N for no \n");
							}
						}

						cout << "Assign Dog space number: " << endl;
						cin >> spaceNumber;

						// Assign dog space number
						dogToCheckIn.SetDogSpaceNumber(spaceNumber);

						// Add dog to dogs vector
						dogs.AddDog(dogToCheckIn);

						// Print dog's info
						dogToCheckIn.PrintPetInfo();
					}
					if ((petType == "Cat") || (petType == "cat")) {
						GetVisitorInfo(catToCheckIn, pets);

						cout << "Assign Cat space number: " << endl;
						cin >> spaceNumber;

						catToCheckIn.SetCatSpaceNumber(spaceNumber);

						// Add cat to cats vector
						cats.AddCat(catToCheckIn);

						// Print cat info
						catToCheckIn.PrintPetInfo();
					}
					cout << "Check-In Complete!" << endl;
					Sleep(2000);               // Pause to give user time to read message
				}
				else {
					cout << "No space available." << endl;
				}
				break;

			case 2:
				system("CLS");              // clear the screen

				cout << "Enter the type of pet you would like to check-out. Dog or Cat?:" << endl;
				cin >> petType;

				cout << "Enter the pet's boarding space number: " << endl;
				cin >> spaceNumber;

				if ((petType == "Dog") || (petType == "dog")) {
					dogs.FindDog(spaceNumber).CheckOut();

					// Remove dog from dog vector
					dogs.RemoveDog(spaceNumber);

					Sleep(2000);               // Pause to give user time to read message
				}
				else if ((petType == "Cat") || (petType == "cat")) {
					cats.FindCat(spaceNumber).CheckOut();

					// Remove cat from cat vector
					cats.RemoveCat(spaceNumber);

					Sleep(2000);               // Pause to give user time to read message
				}
				else {
					throw runtime_error("Pet type not recognized. Pet must be a Dog or Cat.");
				}
				break;

			case 3:
				system("CLS");              // clear the screen

				cout << "Enter the type of pet you would like to update. Dog or Cat?:" << endl;
				cin >> petType;

				cout << "Enter the pet's boarding space number: " << endl;
				cin >> spaceNumber;

				if ((petType == "Dog") || (petType == "dog")) {
					dogs.FindDog(spaceNumber).UpdatePetInfo();
				}
				else if ((petType == "Cat") || (petType == "cat")) {
					cats.FindCat(spaceNumber).UpdatePetInfo();
				}
				else {
					throw runtime_error("Pet type not recognized. Pet must be a Dog or Cat.");
				}

				break;

			case 4:
				system("CLS");                             // clear the screen

				cout << "Enter the type of pet you would like to cancel. Dog or Cat?:" << endl;
				cin >> petType;

				cout << "Please enter the pet owner's phone number: " << endl;
				cin >> petOwnerPhoneNumber;

				if ((petType == "Dog") || (petType == "dog")) {
					dogs.CancelDog(petOwnerPhoneNumber);

					Sleep(2000);               // Pause to give user time to read message
				}
				else if ((petType == "Cat") || (petType == "cat")) {
					
				}
				else {
					throw runtime_error("Pet type not recognized. Pet must be a Dog or Cat.");
				}

				break;

			case 5:
				system("CLS");                             // clear the screen
				cout << "Program ended. Goodbye!" << endl; // print goodbye message
				endProgram = true;                         // end program
				break;

			default:
				cout << "ERROR: " << menuSelection << " is not a valid selection." << endl;    // display ERROR message when selection is not valid
				cin.clear();
				cin.ignore(INT_MAX, '\n'); // Remove all remaining [invalid] characters from the stream
				Sleep(2000);               // Pause to give user time to read message
				system("CLS");             // Clear the screen
				break;

			}
		}

		catch (runtime_error& e) {
			cout << e.what() << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n'); // Remove all remaining [invalid] characters from the stream
			Sleep(2000);               // Pause to give user time to read message
			system("CLS");             // Clear the screen

		}
	}
}