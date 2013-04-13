package eg.edu.guc.voting.participants;

public class Officer extends Person {
	String specialRank;
	public Officer() {
		super();
		specialRank = "";
	}
	public Officer(String id, String fullName, java.util.Calendar birthDate, String rank) {
		super(fullName, birthDate, id);
		specialRank = rank;
	}
	public boolean isEligibleToVote() {
		return false;
	}
	public String toString() {
		return specialRank + " " + name + " is a " + gender
			+ " " + age + " years old. And ID is: " + socialID ;
	}
}
