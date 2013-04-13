package eg.edu.guc.voting.facilities;

public class SmallSetup extends VotingStation {
	public SmallSetup() {
	}
	public SmallSetup(int c) {
		super(c);
	}
	public String toString() {
		return "This Small setup station has a capacity of " + capacity;
	}
}
