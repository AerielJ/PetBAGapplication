
public class Dog extends Pet {
	private int dogSpaceNbr;
	private double dogWeight;
	private boolean dogGrooming;
	
    // Constructor
    public Dog() {
    }
      
   //Mutators
    public void setDogSpaceNbr(int spaceNumber) {
    	spaceNumber = dogSpaceNbr;
    }
    public void setDogWeight(double weightOfDog) {
    	weightOfDog = dogWeight;
    }
    public void setGrooming (boolean groomingService) {
    	groomingService = dogGrooming;
    }
    
  //Accessors
    public int getDogSpaceNbr() {
    	return dogSpaceNbr;
    }
    public double getDogWeight() {
    	return dogWeight;
    }
    public boolean getDogGrooming() {
    	return dogGrooming;
    }

}
