#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

#include "Pet.h"
#include "Dog.h"
#include "Cat.h"


// Default Constructor
Pet::Pet() {
	name = "No name";
	type = "No Type";
	age = 0;
	ownerName = "No Owner Name";
	ownerPhoneNumber = "No Owner Phone Number";
	daysStay = 0;
	notes = "No Notes";
	paid = false;
}

// Setters
void Pet::SetName(string petName) {
	name = petName;
}

void Pet::SetType(string petType) {
	type = petType;
}

void Pet::SetAge(int petAge) {
	age = petAge;
}

void Pet::SetOwnerName(string petOwnerName) {
	ownerName = petOwnerName;
}

void Pet::SetOwnerPhoneNumber(string petOwnerPhoneNumber) {
	ownerPhoneNumber = petOwnerPhoneNumber;
}

void Pet::SetDaysStay(int days) {
	daysStay = days;
}
void Pet::SetNotes(string petNotes) {
	notes = petNotes;
}

void Pet::SetPaid(bool petPaid) {
	paid = petPaid;
}


// Getters
string Pet::GetName() {
	return name;
}

string Pet::GetType() {
	return type;
}

int Pet::GetAge() {
	return age;
}

string Pet::GetOwnerName() {
	return ownerName;
}

string Pet::GetOwnerPhoneNumber() {
	return ownerPhoneNumber;
}

int Pet::GetDaysStay() {
	return daysStay;
}

string Pet::GetNotes() {
	return notes;
}

bool Pet::GetPaid() {
	return paid;
}


// function to create a new pet
void Pet::CreatePet() {
	string petName;
	int petAge;
	string petOwnerName;
	string petOwnerPhoneNumber;

	cout << "Please enter the pet's name: " << endl;
	cin >> petName;
	cout << "Please enter the pet's age: " << endl;
	cin >> petAge;
	cout << "Please enter the pet owner's name: " << endl;
	cin >> petOwnerName;
	cout << "Please enter the pet owner's phone number: " << endl;
	cin >> petOwnerPhoneNumber;

	SetName(petName);
	SetAge(petAge);
	SetOwnerName(petOwnerName);
	SetOwnerPhoneNumber(petOwnerPhoneNumber);

	PrintPetInfo();
}

void Pet::UpdatePetInfo() {
	// TODO: Create method for updating pet info - IN PROGRESS
	int updateSelection;
	string underLine(50, '-');

	// Print update options
	cout << setw(43) << setfill(' ') << "Select what you would like to update" << endl;
	cout << underLine << endl;
	cout << "1: Boarding Space Number" << endl;
	cout << "2: Weight" << endl;
	cout << "3: Grooming" << endl;
	cout << "4: Pet Notes" << endl;
	cout << "5: Days Stay" << endl;
	cout << underLine << endl;
	cout << "Enter your selection as a number 1, 2, 3, 4 or 5." << endl;

	cin >> updateSelection;

	// Error checking, numeric input
	if (cin.fail()) {
		throw runtime_error("ERROR: Invalid input. Selection must be a number \n");
	}
}

// function to update a pet's visitor information
void Pet::UpdateVisitorInfo() {
	int updateSelection = 0;
	int petAge;
	string petOwnerName;
	string petOwnerPhoneNumber;
	string underLine(50, '-');

	do {
		// Print update options
		cout << setw(43) << setfill(' ') << "Select what you would like to update" << endl;
		cout << underLine << endl;
		cout << "1: Pet Age" << endl;
		cout << "2: Owner Name" << endl;
		cout << "3: Owner Phone Number" << endl;
		cout << underLine << endl;
		cout << "Enter your selection as a number 1, 2, or 3." << endl;

		cin >> updateSelection;

		// Error checking, numeric input
		if (cin.fail()) {
			throw runtime_error("ERROR: Invalid input. Selection must be a number \n");
		}

		// Respond to user input based on selection
		switch (updateSelection) {
		case 1:
			system("CLS");              // clear the screen
			cout << "Please enter the pet's age: " << endl;
			cin >> petAge;
			SetAge(petAge);
			break;

		case 2:
			system("CLS");              // clear the screen
			cout << "Please enter the pet owner's name: " << endl;
			cin >> petOwnerName;
			SetOwnerName(petOwnerName);
			break;

		case 3:
			system("CLS");              // clear the screen
			cout << "Please enter the pet owner's phone number: " << endl;
			cin >> petOwnerPhoneNumber;
			SetOwnerPhoneNumber(petOwnerPhoneNumber);
			break;

		default:
			cout << "ERROR: " << updateSelection << " is not a valid selection." << endl;    // display ERROR message when selection is not valid
			cin.clear();
			cin.ignore(INT_MAX, '\n'); // Remove all remaining [invalid] characters from the stream
			Sleep(2000);               // Pause to give user time to read message
			system("CLS");             // Clear the screen
			break;
		}

	} while (updateSelection > 3);

	cout << "Updated Visitor Info" << endl;
	cout << underLine << endl;
	PrintPetInfo();
}

// Function to print pet information
void Pet::PrintPetInfo() {
	string underLine(50, '-');
	cout << underLine << endl;
	cout << "Pet Name: " << name << endl;
	cout << "Pet Type: " << type << endl;
	cout << "Age: " << age << endl;
	cout << "Owner Name: " << ownerName << endl;
	cout << "Owner Phone Number: " << ownerPhoneNumber << endl;
	cout << "Lenght of stay: " << daysStay << endl;
	cout << "Pet Notes: " << notes << endl;
}

