#ifndef PET_H
#define PET_H

#include <string>

using namespace std;

class Pet {
	//Private data members
	private:
		string name;
		string type;
		int age;
		string ownerName;
		string ownerPhoneNumber;
		int daysStay;
		string notes;
		bool paid;
	

	// Public class functions
	public:
		Pet();
		void SetName(string petName);
		void SetType(string petType);
		void SetAge(int petAge);
		void SetOwnerName(string petOwnerName);
		void SetOwnerPhoneNumber(string petOwnerPhoneNumber);
		void SetDaysStay(int days);
		void SetNotes(string petNotes);
		void SetPaid(bool paid);

		string GetName();
		string GetType();
		int GetAge();
		string GetOwnerName();
		string GetOwnerPhoneNumber();
		int GetDaysStay();
		string GetNotes();
		bool GetPaid();

		void CreatePet();
		void UpdateVisitorInfo();
		void PrintPetInfo();
};

#endif

