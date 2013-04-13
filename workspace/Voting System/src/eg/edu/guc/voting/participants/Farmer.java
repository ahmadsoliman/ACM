package eg.edu.guc.voting.participants;

public class Farmer extends Candidate implements Votable {

	public Farmer() {
		super();
	}

	public Farmer(String id, String fullname, java.util.Calendar birthDate,
			String title) {
		super(id, fullname, birthDate, title);
	}

	public boolean equals(Object o) {
		if (o instanceof Farmer) {
			Candidate c = (Farmer) o;
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
	public String getId(){
		return getSocialID();
	}
}
