package eg.edu.guc.voting.participants;

public interface Votable {
	public void giveVote();

	public int countVotes();
	
	public String getId();
}
