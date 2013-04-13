package eg.edu.guc.voting.participants;

public class Worker extends Candidate {
	private int Vote;

	public Worker(String id, String fullname, java.util.Calendar birthDate,
			String title) {

		super(id, fullname, birthDate, title);

	}

	public int getVote() {
		return Vote;
	}

	public void setVote(int vote) {
		Vote = vote;
	}

	public String toString() {
		return "Candidate" + getTitle() + getName() + "Birthday :"
				+ getBirthDate() + "ID :" + getID() + getAge() + getTitle();
	}

	public boolean equals(Object o) {
		if (!(o instanceof Worker))
			return false;
		else {
			Worker O = (Worker) o;
			if (this.getID().equals(O.getID())
					&& this.getName().equals(O.getName())
					&& this.getBirthDate().equals(O.getBirthDate())) {
				return true;

			} else
				return false;

		}
	}

	@Override
	public String getId() {
		// TODO Auto-generated method stub
		return null;
	}

}
