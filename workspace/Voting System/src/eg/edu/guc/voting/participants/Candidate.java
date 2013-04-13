package eg.edu.guc.voting.participants;

public abstract class Candidate extends Civilian implements Votable {
	private int votes;

	public Candidate() {
		super();
		votes = 0;
	}

	public Candidate(String id, String fullName, java.util.Calendar birthDate,
			String t) {
		super(id, fullName, birthDate, t);
		votes = 0;
	}

	public void giveVote() {
		votes++;
	}

	public int countVotes() {
		return votes;
	}

	public String toString() {
		return "Candidate " + getTitle() + " " + getName() + " is a "
				+ getGender() + " " + getAge() + " years old. And ID is: "
				+ getSocialID();
	}

	public boolean equals(Object o) {
		if (o instanceof Candidate) {
			Candidate c = (Candidate) o;
			if (!getSocialID().equals(c.getSocialID())) {
				return false;
			}
			if (!getName().equals(c.getName())) {
				return false;
			}
			if (!getBirthDate().equals(c.getBirthDate())) {
				return false;
			}
			if (!getTitle().equals(c.getTitle())) {
				return false;
			}
			return true;
		}
		return false;
	}
}
