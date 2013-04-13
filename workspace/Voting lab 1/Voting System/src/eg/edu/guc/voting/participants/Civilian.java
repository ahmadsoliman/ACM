package eg.edu.guc.voting.participants;


public class Civilian extends Person{
	protected String title;
	public Civilian() {
		super();
		title = "";
	}
	public Civilian(String id, String fullName, java.util.Calendar birthDate, String t) {
		super(fullName, birthDate, id);
		title = t;
	}
	public boolean isEligibleToVote() {
		if (age >= 18) {
			return true;
		}
		return false;
	}
	public String toString(){
		return title + " " + name + " is a " + gender + " " + age
			+ " years old. And ID is: " + socialID;
	}
}
