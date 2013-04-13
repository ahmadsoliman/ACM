package eg.edu.guc.voting.participants;

public class Civilian extends Person {

	private String title;

	public Civilian() {
		super();
		title = "";
	}

	public Civilian(String id, String fullName,
			java.util.Calendar birthDate, String t) {
		super(fullName, birthDate, id);
		title = t;
	}

	public boolean isEligibleToVote() {
		if (getAge() >= 18) {
			return true;
		}
		return false;
	}

	public String toString() {
		return title + " " + getName() + " is a " + getGender() + " "
				+ getAge() + " years old. And ID is: " + getSocialID();
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String t) {
		title = t;
	}
}
