
public class Pet {
	private String petType;
	private String petName;
	private int petAge;
	private int dogSpace;
	private int catSpace;
	private int daysStay;
	private double amountDue;
	
	//Constructor
	public Pet() {
		petType = "Unknown type";
		petName = "Unknown name";
	}
	
	//Mutators
	public void setPetType(String animalType) {
		animalType = petType;
	}
	public void setPetName(String nameOfPet) {
		nameOfPet = petName;
	}
	public void setPetAge(int ageOfPet) {
		ageOfPet = petAge;
	}
	public void setDogSpace(int spaceForDog) {
		spaceForDog = dogSpace;
	}
	public void setCatSpace(int spaceForCat) {
		spaceForCat = catSpace;
	}
	public void setDaysStay(int numberOfDays) {
		numberOfDays = daysStay;
	}
	public void setAmountDue(double paymentDue) {
		paymentDue = amountDue;
	}
	
	//Accessors
	public String getPetType() {
		return petType;
	}
	public String getPetName() {
		return petName;
	}
	public int getPetAge() {
		return petAge;
	}
	public int getDogSpace() {
		return dogSpace;
	}
	public int getCatSpace() {
		return catSpace;
	}
	public int getDaysStay() {
		return daysStay;
	}
	public double getAmountDue() {
		return amountDue;
	} 

	public void checkIn() {
		//check-in method
	}
	public void checkOut() {
		//check-out method
	}
	public void createPet() {
		//create pet method
	}
	public void updatePet() {
		//update pet method
	}

}
