package eg.edu.guc.voting.participants;

public class Officer extends Person {

	private String rank;

	public String getRank() {
		return rank;
	}

	public void setRank(String r) {
		rank = r;
	}

	public Officer() {
		super();
		rank = "";
	}

	public Officer(String id, String fullName, java.util.Calendar birthDate,
			String r) {
		super(fullName, birthDate, id);
		rank = r;
	}

	public boolean isEligibleToVote() {
		return false;
	}

	public String toString() {
		return rank + " " + getName() + " is a " + getGender() + " " + getAge()
				+ " years old. And ID is: " + getSocialID();
	}
}
