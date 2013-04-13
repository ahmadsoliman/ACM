package eg.edu.guc.voting.participants;

import java.util.LinkedList;

public class Party implements Votable {
	private int Vote;

	public int getVote() {
		return Vote;
	}

	public void setVote(int vote) {
		Vote = vote;
	}

	private String Name;
	private LinkedList<Civilian> Members;

	public String getName() {
		return Name;
	}

	public void setName(String name) {
		Name = name;
	}

	public LinkedList<Civilian> getMembers() {
		return Members;
	}

	public void setMembers(LinkedList<Civilian> Members) {
		this.Members = Members;
	}

	public Party(String name) {
		Name = name;
		Members = new LinkedList<Civilian>();

	}

	public Party(String name, LinkedList<Civilian> members, int vote) {
		Name = name;
		Members = members;
		Vote = vote;
	}

	public boolean isMember(Civilian member) {
		return Members.contains(member);

	}

	public void addMember(Civilian member) {
		if (!Members.contains(member))
			Members.addFirst(member);
		return;
	}

	public int countMembers() {
		if (Members.isEmpty())
			return 0;
		else
			return Members.size();

	}

	public String toString() {
		return Name + countMembers();
	}

	public boolean equals(Object o) {
		Party O = (Party) o;
		if (this.getName().equals(O.getName())
				&& this.getMembers().equals(O.getMembers()))
			return true;
		else
			return false;
	}
	
	public int countVotes() {
		return Vote;
	}

	
	public void giveVote() {
		Vote++;
		
	}

	public String getId() {
		return getName();
	}
}