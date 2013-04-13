package eg.edu.guc.voting.participants;

abstract public class Candidate extends Civilian implements Votable {

	private int Vote;

	public int getVote() {
		return Vote;
	}

	public void setVote(int vote) {
		Vote = vote;
	}

	public Candidate() {
		super();

	}

	public Candidate(String id, String fullName, java.util.Calendar birthDate,
			String title) {

		super(id, fullName, birthDate, title);

	}

	public String toString() {
		return "Candidate" + getTitle() + getName() + "Birthday :"
				+ getBirthDate() + "ID :" + getID() + getAge();
	}

	public boolean equals(Object o) {
		return false;
	}

	public void giveVote() {
		Vote = Vote + 1;
	}

	public int countVotes() {
		return Vote;
	}
	public String getID(){
		return super.getID();
	}

}
