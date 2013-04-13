package eg.edu.guc.voting.participants;

public class Independent extends Candidate implements Votable {
	public Independent() {
		super();
	}

	public Independent(String id, String fullname,
			java.util.Calendar birthDate, String title) {
		super(id, fullname, birthDate, title);
	}

	public boolean equals(Object o) {
		if (o instanceof Independent) {
			Candidate c = (Independent) o;
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
