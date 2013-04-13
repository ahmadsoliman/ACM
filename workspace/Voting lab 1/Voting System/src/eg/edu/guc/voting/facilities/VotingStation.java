package eg.edu.guc.voting.facilities;

public class VotingStation {
	protected int capacity;
	public VotingStation() {
	}
	public VotingStation(int c) {
		capacity = c;
	}
	public int getCapacity() {
		return capacity;
	}
	public String toString() {
		return "This station has a capacity of " + capacity;
	}
}
