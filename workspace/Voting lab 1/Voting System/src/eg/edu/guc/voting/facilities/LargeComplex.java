package eg.edu.guc.voting.facilities;

public class LargeComplex extends VotingStation {
	public LargeComplex() {
	}
	public LargeComplex(int c) {
		super(c);
	}
	public String toString() {
		return "This large complex station has a capacity of "
			+ capacity;
	}
}
