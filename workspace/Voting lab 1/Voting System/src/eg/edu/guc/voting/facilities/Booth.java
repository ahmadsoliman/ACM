package eg.edu.guc.voting.facilities;

public class Booth extends SmallSetup {
	protected String address;
	public Booth() {
		super();
		address = "";
	}
	public Booth(String a) {
		super();
		address = a;
	}
	public int getCapacity() {
		return 1;
	}
	public String toString() {
		return "Booth at the address " + address
			+ " has a capacity of " + getCapacity();
	}
}
