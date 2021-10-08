#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

#include "Cat.h"

// Default constructor
Cat::Cat() {
	catSpaceNumber = -1;
}

// Setter 
void Cat::SetCatSpaceNumber(int spaceNumber) {
	catSpaceNumber = spaceNumber;
}

// Getter
int Cat::GetCatSpaceNumber() {
	return catSpaceNumber;
}

// function to print cat info
void Cat::PrintPetInfo() {
	string underLine(50, '-');
	Pet::PrintPetInfo();
	cout << "Boarding space: " << catSpaceNumber << endl;
	cout << "Paid: " << boolalpha << GetPaid() << endl;
	cout << underLine << endl;
}

// function to check-out a cat
void Cat::CheckOut() {
	double amountDue = 0.0;
	double catBoardingFee = 18.00;
	char payment;
	
	amountDue = GetDaysStay() * catBoardingFee;

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

// function to update cat info
void Cat::UpdatePetInfo() {
	int updateSelection = 0;
	string petNotes;
	int days;
	string underLine(50, '-');

	PrintPetInfo();

	do {
		// Print update options
		cout << setw(43) << setfill(' ') << "Select what you would like to update" << endl;
		cout << underLine << endl;
		cout << "1: Boarding Space Number" << endl;
		cout << "2: Pet Notes" << endl;
		cout << "3: Days Stay" << endl;
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
			cout << "Please enter " << GetName() << "'s new space number: " << endl;
			cin >> catSpaceNumber;

			break;

		case 2:
			system("CLS");              // clear the screen
			cout << "Please enter notes for " << GetName() << ": " << endl;
			cin >> petNotes;
			SetNotes(petNotes);
			break;

		case 3:
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


	} while (updateSelection > 3);

	cout << underLine << endl;
	cout << "Updated Pet Info" << endl;
	PrintPetInfo();
}
