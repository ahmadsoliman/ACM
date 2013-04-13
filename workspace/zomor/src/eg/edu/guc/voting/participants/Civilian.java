package eg.edu.guc.voting.participants;

public class Civilian extends Person {

	private String Title;

	public String getTitle() {
		return Title;
	}

	public void setTitle(String title) {
		Title = title;
	}

	public Civilian(String id, String fullName, java.util.Calendar birthDate,
			String title) {

		super(fullName, birthDate, id);

		Title = title;
	}

	public Civilian() {
		super();
		Title = "";
	}

	public boolean isEligibleToVote() {
		if (getAge() >= 18)
			return true;
		else
			return false;
	}

	public String toString() {
		return getTitle() + getName() + "Birthday :" + getBirthDate() + "ID :"
				+ getID() + getAge();
	}

}
