#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;
#include "Dog.h"

// Default Constructor
Dog::Dog() {
	grooming = false;
	dogSpaceNumber = -1;
	dogWeight = 0.0;
}


// Setters
void Dog::SetGrooming(bool dogGrooming) {
	grooming = dogGrooming;
}

void Dog::SetDogSpaceNumber(int spaceNumber) {
	dogSpaceNumber = spaceNumber;
}

void Dog::SetDogWeight(double weight) {
	dogWeight = weight;
}


// Getters
bool Dog::GetGrooming() {
	return grooming;
}

int Dog::GetDogSpaceNumber() {
	return dogSpaceNumber;
}

double Dog::GetDogWeight() {
	return dogWeight;
}

// function to print dog info
void Dog::PrintPetInfo() {
	string underLine(50, '-');
	Pet::PrintPetInfo();
	cout << "Grooming: " << boolalpha << grooming << endl;
	cout << "Weight: " << dogWeight << endl;
	cout << "Boarding space: " << dogSpaceNumber << endl;
	cout << "Paid: " << boolalpha << GetPaid() << endl;
	cout << underLine << endl;
}

// function to check-out a dog
void Dog::CheckOut() {
	// Dog boarding fees
	double smallDogBoardingFee = 24.00;
	double medDogBoardingFee = 29.00;
	double largeDogBoardingFee = 34.00;
	double boardingDue = 0.0;

	// Dog grooming fees
	double smallDogGroomingFee = 19.95;
	double medDogGroomingFee = 24.95;
	double largeDogGroomingFee = 29.95;
	double groomingDue = 0.0;

	double amountDue = 0.0;
	char payment;

	if (GetDogWeight() < 20.0) {
		boardingDue = GetDaysStay() * smallDogBoardingFee;
		groomingDue = smallDogGroomingFee;
	}
	else if (GetDogWeight() <= 30.0) {
		boardingDue = GetDaysStay() * medDogBoardingFee;
		groomingDue = medDogGroomingFee;
	}
	else {
		boardingDue = GetDaysStay() * largeDogBoardingFee;
		groomingDue = largeDogGroomingFee;
	}

	if (GetGrooming() == true) {
		amountDue = boardingDue + groomingDue;
	}
	else {
		amountDue = boardingDue;
	}

	PrintPetInfo();
	cout << "Total amount due for " << GetName() << "'s stay: $" << amountDue << endl;
	cout << "Payment recieved? Y/N" << endl;
	cin >> payment;

	if ((payment == 'Y') || (payment == 'y')) {
		SetPaid(true);
		cout << "Check-Out complete!" << endl;
	}
	else if ((payment != 'N') && (payment != 'n')) {
		throw runtime_error("Invalid Input. Type Y for yes or N for no \n");
	}
}

// function to update dog info
void Dog::UpdatePetInfo() { 
	int updateSelection = 0;
	int days;
	char dogGrooming;
	string notes;
	
	string underLine(50, '-');

	PrintPetInfo();

	do {
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

		// Respond to user input based on selection
		switch (updateSelection) {
		case 1:
			system("CLS");              // clear the screen
			cout << "Please enter the new boarding space number: " << endl;
			cin >> dogSpaceNumber;
			//dogSpaceNumber = spaceNumber;
			break;

		case 2:
			system("CLS");              // clear the screen
			cout << "Please enter the dog's weight: " << endl;
			cin >> dogWeight;
			//dogWeight = weight;
			break;

		case 3:
			system("CLS");              // clear the screen

			cout << "Add grooming service? Y/N" << endl;
			cin >> dogGrooming;

			if ((dogGrooming == 'Y') || (dogGrooming == 'y')) {

				cout << "Please enter dogs weight in pounds: ";
				cin >> dogWeight;

				grooming = true;
				//dogWeight = weight;
			}
			else if ((dogGrooming == 'N') || (dogGrooming == 'n')) {
				grooming = false;
			}
			else {
				cout << "Invalid response. Type Y for yes or N for no." << endl;
			}
			break;

		case 4: 
			system("CLS");              // clear the screen

			cout << "Please enter notes for " << GetName() << ": " << endl;
			cin >> notes;

			SetNotes(notes);
			break;

		case 5:
			system("CLS");              // clear the screen

			cout << "Please enter " << GetName() << "'s lenght of stay: " << endl;
			cin >> days;

			SetDaysStay(days);
			break;

		default:
			cout << "ERROR: " << updateSelection << " is not a valid selection." << endl;    // display ERROR message when selection is not valid
			cin.clear();
			cin.ignore(INT_MAX, '\n'); // Remove all remaining [invalid] characters from the stream
			Sleep(2000);               // Pause to give user time to read message
			system("CLS");             // Clear the screen
			break;
		}


	} while (updateSelection > 5);

	cout << underLine << endl;
	cout << "Updated Pet Info" << endl;
	PrintPetInfo();
}
