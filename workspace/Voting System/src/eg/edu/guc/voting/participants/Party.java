package eg.edu.guc.voting.participants;

public class Party implements Votable {

	private java.util.LinkedList<Civilian> members;
	private String name;
	private int votes;

	public Party() {
		setName("");
		members = new java.util.LinkedList<Civilian>();
		votes = 0;
	}

	public Party(String n) {
		setName(n);
		members = new java.util.LinkedList<Civilian>();
		votes = 0;
	}

	public boolean isMember(Civilian member) {
		if(members.size()==0) return false;
//		for (int i = 0; i < members.size(); i++) {
//			if (members.peekFirst().equals(member)) {
//				return true;
//			}
//			members.addLast(members.removeFirst());
//		}
//		return false;
		return members.contains(member);
	}

	public void addMember(Civilian member) {
		if (!isMember(member)) {
			members.addLast(member);
		}
	}

	public int countMembers() {
		return members.size();
	}

	public String toString() {
		return "The Party " + name + " has " + countMembers() + " members.";
	}

	public void giveVote() {
		votes++;
	}

	public int countVotes() {
		return votes;
	}

	public boolean equals(Object o) {
		if (o instanceof Party) {
			Party p = (Party) o;
			if (!name.equals(p.name)) {
				return false;
			}
			if (members.size() != p.members.size()) {
				return false;
			} else {
				for (int i = 0; i < members.size(); i++) {
					Civilian c = members.peekFirst();
					boolean found = false;
					for (int j = 0; j < members.size(); j++) {
						Civilian c2 = p.members.peekFirst();
						if (c.equals(c2)) {
							found = true;
							break;
						}
						p.members.addLast(p.members.removeFirst());
					}
					if (!found) {
						return false;
					}
					members.addLast(p.members.removeFirst());
				}
			}
			return true;
		}
		return false;
	}

	protected void setName(String n) {
		name = n;
	}

	protected String getName() {
		return name;
	}
	

	public String getId(){
		return name;
	}

}
