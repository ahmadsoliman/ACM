package eg.edu.guc.voting.participants;

import java.util.Calendar;

public class Officer extends Person {

	private String Rank;

	public Officer() {
		super();
		Rank = "";
	}

	public Officer(String id, String fullName, java.util.Calendar birthDate,
			String rank) {

		super(fullName, birthDate, id);
		Rank = rank;

	}

	public boolean isEligibleToVote() {
		return false;
	}

	public String toString() {
		return getRank() + getName() + "Birthday :" + getBirthDate() + "ID :"
				+ getID() + getAge();
	}

	public String getRank() {
		return Rank;
	}

	public void setRank(String rank) {
		Rank = rank;
	}

}
