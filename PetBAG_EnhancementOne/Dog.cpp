#include <iostream>

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
}
