#include <iostream>
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
}
